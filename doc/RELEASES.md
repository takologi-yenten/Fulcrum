# Fulcrum-YTN Release Notes

Release notes for the Yenten fork of [cculianu/Fulcrum](https://github.com/cculianu/Fulcrum).

Version scheme: `<upstream-baseline>-ytn.<N>`, where `<upstream-baseline>` is the
upstream Fulcrum version this build is rebased on, and `<N>` is the fork-release
counter. The counter resets to `1` on every upstream baseline bump.

The banner reported via Electrum `server.version` is:

```
Fulcrum-YTN <fork-version> (Fulcrum <upstream-version>)
```

The upstream baseline component is exposed deliberately so that downstream
wallets and security advisories can map any upstream CVE directly to the
corresponding Fulcrum-YTN build.

---

## 2.1.1-ytn.1 — 2026-05-26

Upstream baseline: Fulcrum **2.1.1** (commit `4b38a75`, tag `v2.1.1`).

First tagged Fulcrum-YTN release. Built on top of the previous unreleased
YTN fork tip (`c811093`, yentend subversion detection fix) and synced to
upstream Fulcrum `v2.1.1`.

### Upstream changes pulled

- Bumped to upstream tag **v2.1.1** (`f06d28f`).
- BCHN sync for `bitcoin/token.h`; token-test extra check and minor C++
  nits in `Mempool.cpp`, `BlockProc.cpp`, and `Storage/Compat.cpp`
  (no behaviour change).
- Windows build script: `wine64` → `wine`.
- `electrum-cash-protocol` submodule bump.

See `git log v2.1.0..HEAD` for the full upstream commit list.

### Fork-side changes

- `src/Common.h`: introduced `UPSTREAM_VERSION` macro and set
  `VERSION = 2.1.1-ytn.1` per the documented `<upstream-baseline>-ytn.<N>`
  scheme.
- `src/ServerMisc.cpp`: banner now reports
  `Fulcrum-YTN 2.1.1-ytn.1 (Fulcrum 2.1.1)`.
- README: new **Runtime dependencies** section with the exact `apt-get`
  command (`libqt5network5 libqt5core5a libzmq5 libbz2-1.0 zlib1g`) and
  Fedora/RHEL equivalent. Build-time deps updated to include
  `libargon2-dev`. Library versions in the README now reflect the
  release build matrix (Qt 5.15.8, gcc 12.2.0, etc.).
- `doc/fulcrum-ytn.conf`: top comment block points operators at the
  same `apt-get` line.
- `resources/ytn/servers.json`: switched seed peers to
  `peer{1,2,3}.rincoin.tech` (YTN SSL port `51002`), protocol version
  `1.4.2`.

### Compatibility

- No on-disk format change relative to the previous YTN fork tip.
- Electrum-protocol-visible banner is now
  `Fulcrum-YTN 2.1.1-ytn.1 (Fulcrum 2.1.1)`.
