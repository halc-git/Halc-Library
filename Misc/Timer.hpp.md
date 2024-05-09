---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Misc/Timer.hpp\"\n#include <chrono>\nstatic auto startTime\
    \ = std::chrono::system_clock::now();\ninline int32_t getTime() {\n    return\
    \ std::chrono::duration_cast<std::chrono::microseconds>(\n               std::chrono::system_clock::now()\
    \ - startTime)\n        .count();\n}\n"
  code: "#pragma once\n#include <chrono>\nstatic auto startTime = std::chrono::system_clock::now();\n\
    inline int32_t getTime() {\n    return std::chrono::duration_cast<std::chrono::microseconds>(\n\
    \               std::chrono::system_clock::now() - startTime)\n        .count();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Timer.hpp
  requiredBy: []
  timestamp: '2024-05-09 15:56:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Timer.hpp
layout: document
redirect_from:
- /library/Misc/Timer.hpp
- /library/Misc/Timer.hpp.html
title: Misc/Timer.hpp
---
