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
  bundledCode: "#line 2 \"Misc/Random.hpp\"\n#include <climits>\n#include <cstdint>\n\
    uint32_t rand_32bit() {\n    static uint32_t x2 = 12345;\n    static uint32_t\
    \ x3 = 0xcafef00d;\n    static uint64_t c_x1 = uint64_t(0xd15ea5e5) << 32 | 23456;\n\
    \    uint64_t x = (uint64_t)(x3) * 3487286589;\n    uint32_t result = (x3 ^ x2)\
    \ + ((uint32_t)(c_x1) ^ (uint32_t)(x >> 32));\n    x3 = x2;\n    x2 = (uint32_t)(c_x1);\n\
    \    c_x1 = x + (c_x1 >> 32);\n    return result;\n}\n\nuint64_t rand_64bit()\
    \ {\n    static uint64_t x2 = 12345;\n    static uint64_t x3 = 0xcafef00dd15ea5e5;\n\
    \    static unsigned __int128 c_x1 =\n        (unsigned __int128)(0xd15ea5e5)\
    \ << 64 | 23456;\n    unsigned __int128 x = (uint64_t)(x3) * 0xfeb344657c0af413;\n\
    \    uint64_t result = (x3 ^ x2) + ((uint32_t)(c_x1) ^ (uint32_t)(x >> 64));\n\
    \    x3 = x2;\n    x2 = (uint64_t)(c_x1);\n    c_x1 = x + (c_x1 >> 64);\n    return\
    \ result;\n}\n\ninline int32_t randint(int32_t l, int32_t r) {\n    return l +\
    \ (((int64_t)rand_32bit() * (r - l + 1)) >> 32);\n}\n\ninline int64_t randlong(int64_t\
    \ l, int64_t r) {\n    return l + (((unsigned __int128)rand_64bit() * (r - l +\
    \ 1)) >> 32);\n}\n\ninline float rand01() { return (float)rand_32bit() / UINT_MAX;\
    \ }\n\ninline bool randprob(float prob) { return rand_32bit() < UINT_MAX * prob;\
    \ }\n"
  code: "#pragma once\n#include <climits>\n#include <cstdint>\nuint32_t rand_32bit()\
    \ {\n    static uint32_t x2 = 12345;\n    static uint32_t x3 = 0xcafef00d;\n \
    \   static uint64_t c_x1 = uint64_t(0xd15ea5e5) << 32 | 23456;\n    uint64_t x\
    \ = (uint64_t)(x3) * 3487286589;\n    uint32_t result = (x3 ^ x2) + ((uint32_t)(c_x1)\
    \ ^ (uint32_t)(x >> 32));\n    x3 = x2;\n    x2 = (uint32_t)(c_x1);\n    c_x1\
    \ = x + (c_x1 >> 32);\n    return result;\n}\n\nuint64_t rand_64bit() {\n    static\
    \ uint64_t x2 = 12345;\n    static uint64_t x3 = 0xcafef00dd15ea5e5;\n    static\
    \ unsigned __int128 c_x1 =\n        (unsigned __int128)(0xd15ea5e5) << 64 | 23456;\n\
    \    unsigned __int128 x = (uint64_t)(x3) * 0xfeb344657c0af413;\n    uint64_t\
    \ result = (x3 ^ x2) + ((uint32_t)(c_x1) ^ (uint32_t)(x >> 64));\n    x3 = x2;\n\
    \    x2 = (uint64_t)(c_x1);\n    c_x1 = x + (c_x1 >> 64);\n    return result;\n\
    }\n\ninline int32_t randint(int32_t l, int32_t r) {\n    return l + (((int64_t)rand_32bit()\
    \ * (r - l + 1)) >> 32);\n}\n\ninline int64_t randlong(int64_t l, int64_t r) {\n\
    \    return l + (((unsigned __int128)rand_64bit() * (r - l + 1)) >> 32);\n}\n\n\
    inline float rand01() { return (float)rand_32bit() / UINT_MAX; }\n\ninline bool\
    \ randprob(float prob) { return rand_32bit() < UINT_MAX * prob; }"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Random.hpp
  requiredBy: []
  timestamp: '2024-06-20 20:13:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
documentation_of: Misc/Random.hpp
layout: document
redirect_from:
- /library/Misc/Random.hpp
- /library/Misc/Random.hpp.html
title: Misc/Random.hpp
---
