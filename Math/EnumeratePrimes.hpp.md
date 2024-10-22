---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/MFPrefixSum.hpp
    title: Math/MFPrefixSum.hpp
  - icon: ':warning:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function.cpp
  - icon: ':warning:'
    path: Verify/verify-yosupo-number-theory/enumerate_primes.cpp
    title: Verify/verify-yosupo-number-theory/enumerate_primes.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/EnumeratePrimes.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\nstd::vector<int32_t> enumerate_primes(int32_t n) {\n    std::vector<bool>\
    \ flg((n + 1) >> 1, true);\n    std::vector<int32_t> ret = {2};\n    for (int32_t\
    \ i = 3; i <= n; i += 2) {\n        if (!flg[i >> 1]) continue;\n        ret.emplace_back(i);\n\
    \        if (i * i > n) {\n            for (int32_t j = i + 2; j <= n; j += 2)\
    \ {\n                if (flg[j >> 1]) ret.emplace_back(j);\n            }\n  \
    \          break;\n        }\n        for (int32_t j = i * i; j <= n; j += i <<\
    \ 1) {\n            flg[j >> 1] = false;\n        }\n    }\n    while (!ret.empty()\
    \ && ret.back() > n) ret.pop_back();\n    return ret;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\nstd::vector<int32_t>\
    \ enumerate_primes(int32_t n) {\n    std::vector<bool> flg((n + 1) >> 1, true);\n\
    \    std::vector<int32_t> ret = {2};\n    for (int32_t i = 3; i <= n; i += 2)\
    \ {\n        if (!flg[i >> 1]) continue;\n        ret.emplace_back(i);\n     \
    \   if (i * i > n) {\n            for (int32_t j = i + 2; j <= n; j += 2) {\n\
    \                if (flg[j >> 1]) ret.emplace_back(j);\n            }\n      \
    \      break;\n        }\n        for (int32_t j = i * i; j <= n; j += i << 1)\
    \ {\n            flg[j >> 1] = false;\n        }\n    }\n    while (!ret.empty()\
    \ && ret.back() > n) ret.pop_back();\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/EnumeratePrimes.hpp
  requiredBy:
  - Math/MFPrefixSum.hpp
  - Verify/verify-yosupo-number-theory/enumerate_primes.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function.cpp
  timestamp: '2024-10-22 17:25:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/EnumeratePrimes.hpp
layout: document
redirect_from:
- /library/Math/EnumeratePrimes.hpp
- /library/Math/EnumeratePrimes.hpp.html
title: Math/EnumeratePrimes.hpp
---
