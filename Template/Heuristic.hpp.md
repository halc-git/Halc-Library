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
  bundledCode: "#line 2 \"Template/Heuristic.hpp\"\n#include <chrono>\n#include <cstdint>\n\
    inline uint32_t pcg32_fast() {\n    static uint64_t state =\n        (std::chrono::steady_clock::now().time_since_epoch().count()\
    \ << 1) + 1;\n    uint64_t x = state;\n    uint8_t count = x >> 61;\n    state\
    \ *= 0xf13283ad;\n    x ^= x >> 22;\n    return (uint32_t)(x >> (22 + count));\n\
    }\ninline int32_t randint(int32_t l, int32_t r) {\n    return l + (((int64_t)pcg32_fast()\
    \ * (r - l + 1)) >> 32);\n}\nstatic auto startTime = std::chrono::system_clock::now();\n\
    inline int32_t getTime() {\n    return std::chrono::duration_cast<std::chrono::microseconds>(\n\
    \               std::chrono::system_clock::now() - startTime)\n        .count();\n\
    }\n"
  code: "#pragma once\n#include <chrono>\n#include <cstdint>\ninline uint32_t pcg32_fast()\
    \ {\n    static uint64_t state =\n        (std::chrono::steady_clock::now().time_since_epoch().count()\
    \ << 1) + 1;\n    uint64_t x = state;\n    uint8_t count = x >> 61;\n    state\
    \ *= 0xf13283ad;\n    x ^= x >> 22;\n    return (uint32_t)(x >> (22 + count));\n\
    }\ninline int32_t randint(int32_t l, int32_t r) {\n    return l + (((int64_t)pcg32_fast()\
    \ * (r - l + 1)) >> 32);\n}\nstatic auto startTime = std::chrono::system_clock::now();\n\
    inline int32_t getTime() {\n    return std::chrono::duration_cast<std::chrono::microseconds>(\n\
    \               std::chrono::system_clock::now() - startTime)\n        .count();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Template/Heuristic.hpp
  requiredBy: []
  timestamp: '2024-05-08 20:46:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Template/Heuristic.hpp
layout: document
redirect_from:
- /library/Template/Heuristic.hpp
- /library/Template/Heuristic.hpp.html
title: Template/Heuristic.hpp
---
