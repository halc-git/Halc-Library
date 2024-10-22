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
    path: Verify/verify-yosupo-number-theory/enumerate_quotients.cpp
    title: Verify/verify-yosupo-number-theory/enumerate_quotients.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - Verify/verify-yosupo-number-theory/enumerate_quotients.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function.cpp
  timestamp: '2024-10-22 16:22:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/EnumerateQuotients.hpp
layout: document
redirect_from:
- /library/Math/EnumerateQuotients.hpp
- /library/Math/EnumerateQuotients.hpp.html
title: Math/EnumerateQuotients.hpp
---
