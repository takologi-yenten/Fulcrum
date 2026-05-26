#include "Common.h"
#include "ServerMisc.h"

namespace ServerMisc
{
    const QString AppVersion(VERSION);
    // Banner format: "Fulcrum-YTN <fork-version> (Fulcrum <upstream-version>)".
    // Exposing the upstream baseline lets downstream wallets map any
    // upstream advisory to the corresponding fork build.
    const QString AppSubVersion = QString("%1 %2 (Fulcrum %3)").arg(FORK_NAME, VERSION, UPSTREAM_VERSION);
}
