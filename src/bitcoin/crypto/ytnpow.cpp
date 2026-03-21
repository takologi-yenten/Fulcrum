// Copyright (c) 2026 The Yenten developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ytnpow.h"

#include "../block.h"
#include "../hash.h"
#include "../streams.h"
#include "../version.h"
#include "yespower/sysendian.h"

#include <cstdint>
#include <stdexcept>

namespace bitcoin {

extern "C" int yespower_hash(const char* input, char* output);

uint256 YtnPoWHash(const CBlockHeader& block)
{
    CDataStream ss(SER_GETHASH, PROTOCOL_VERSION);
    ss << block;

    if (ss.size() < 72) {
        throw std::runtime_error("YtnPoWHash: serialized header too short");
    }

    const auto* raw = reinterpret_cast<const uint8_t*>(&ss[0]);
    const uint32_t time = le32dec(raw + 68);

    // Match yentencore behavior in src/primitives/block.cpp::GetHash().
    if (time > 1675036800U) {
        return SerializeHash(block);
    }

    uint256 out;
    if (yespower_hash(reinterpret_cast<const char*>(raw), reinterpret_cast<char*>(&out)) != 0) {
        throw std::runtime_error("YtnPoWHash: yespower_hash failed");
    }
    return out;
}

} // namespace bitcoin
