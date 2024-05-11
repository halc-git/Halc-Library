---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
    title: Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Misc/Timer.hpp\"\n#include <chrono>\nstatic auto StartTime\
    \ = std::chrono::system_clock::now();\ninline int32_t get_time() {\n    return\
    \ std::chrono::duration_cast<std::chrono::microseconds>(\n               std::chrono::system_clock::now()\
    \ - StartTime)\n        .count();\n}\n"
  code: "#pragma once\n#include <chrono>\nstatic auto StartTime = std::chrono::system_clock::now();\n\
    inline int32_t get_time() {\n    return std::chrono::duration_cast<std::chrono::microseconds>(\n\
    \               std::chrono::system_clock::now() - StartTime)\n        .count();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Timer.hpp
  requiredBy: []
  timestamp: '2024-05-11 13:30:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
documentation_of: Misc/Timer.hpp
layout: document
redirect_from:
- /library/Misc/Timer.hpp
- /library/Misc/Timer.hpp.html
title: Misc/Timer.hpp
---
