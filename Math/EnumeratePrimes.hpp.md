---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Math/MFPrefixSum.hpp
    title: Math/MFPrefixSum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-number-theory/enumerate_primes.test.cpp
    title: Verify/verify-yosupo-number-theory/enumerate_primes.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
    title: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  timestamp: '2024-10-22 17:25:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  - Verify/verify-yosupo-number-theory/enumerate_primes.test.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
documentation_of: Math/EnumeratePrimes.hpp
layout: document
redirect_from:
- /library/Math/EnumeratePrimes.hpp
- /library/Math/EnumeratePrimes.hpp.html
title: Math/EnumeratePrimes.hpp
---
