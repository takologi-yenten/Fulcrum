// Copyright (c) 2026 The Yenten developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "../uint256.h"

namespace bitcoin {

class CBlockHeader;

/// Computes Yenten's block hash as implemented by upstream yentencore (yenten-6).
///
/// Behavior:
/// - For header.nTime > 1675036800: SHA256d (SerializeHash)
/// - Otherwise: YesPower hash (with legacy/personality switch handled internally)
uint256 YtnPoWHash(const CBlockHeader& block);

} // namespace bitcoin
