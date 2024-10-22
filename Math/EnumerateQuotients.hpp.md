---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/MFPrefixSum.hpp
    title: Math/MFPrefixSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-number-theory/enumerate_quotients.test.cpp
    title: Verify/verify-yosupo-number-theory/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/EnumerateQuotients.hpp\"\n#include <math.h>\n\n#include\
    \ <cstdint>\n#include <numeric>\n#include <vector>\nstd::vector<int64_t> enumerate_quotients(uint64_t\
    \ n) {\n    uint64_t x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n \
    \   while (x * x > n) x--;\n    std::vector<int64_t> ret(x);\n    ret.reserve(x\
    \ * 2);\n    std::iota(ret.begin(), ret.end(), 1);\n    for (int32_t i = x; i\
    \ >= 1; i--) {\n        if (ret.back() != n / i) ret.emplace_back(n / i);\n  \
    \  }\n    return ret;\n}\n"
  code: "#pragma once\n#include <math.h>\n\n#include <cstdint>\n#include <numeric>\n\
    #include <vector>\nstd::vector<int64_t> enumerate_quotients(uint64_t n) {\n  \
    \  uint64_t x = sqrt(n);\n    while ((x + 1) * (x + 1) <= n) x++;\n    while (x\
    \ * x > n) x--;\n    std::vector<int64_t> ret(x);\n    ret.reserve(x * 2);\n \
    \   std::iota(ret.begin(), ret.end(), 1);\n    for (int32_t i = x; i >= 1; i--)\
    \ {\n        if (ret.back() != n / i) ret.emplace_back(n / i);\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/EnumerateQuotients.hpp
  requiredBy:
  - Math/MFPrefixSum.hpp
  timestamp: '2024-10-22 16:22:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-number-theory/enumerate_quotients.test.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
documentation_of: Math/EnumerateQuotients.hpp
layout: document
redirect_from:
- /library/Math/EnumerateQuotients.hpp
- /library/Math/EnumerateQuotients.hpp.html
title: Math/EnumerateQuotients.hpp
---
