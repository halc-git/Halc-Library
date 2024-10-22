---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/ModCombination.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\ntemplate <typename T>\nstruct ModCombination {\n    std::vector<T>\
    \ fact = {1}, rev{1};\n    ModCombination(uint32_t sz = 0) {\n        fact.reserve(sz+1);\n\
    \        rev.reserve(sz+1);\n    }\n    void resize(uint32_t sz) {\n        sz++;\n\
    \        if (fact.size() >= sz) return;\n        uint32_t before = fact.size();\n\
    \        fact.resize(sz);\n        rev.resize(sz);\n        for (uint32_t i =\
    \ before; i < sz; i++) {\n            fact[i] = fact[i - 1] * i;\n           \
    \ rev[i] = rev[i - 1] / i;\n        }\n    }\n    T comb(int32_t n, int32_t k)\
    \ {\n        if (n < 0 || k < 0 || n < k) return 0;\n        resize(n);\n    \
    \    return fact[n] * rev[n - k] * rev[k];\n    }\n    T perm(int32_t n, int32_t\
    \ k) {\n        if (n < 0 || k < 0 || n < k) return 0;\n        resize(n);\n \
    \       return fact[n] * rev[n - k];\n    }\n    T multi_comb(int32_t n, int32_t\
    \ k) {\n        if (k == 0) return 1;\n        return comb(n + k - 1, k);\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\ntemplate <typename T>\n\
    struct ModCombination {\n    std::vector<T> fact = {1}, rev{1};\n    ModCombination(uint32_t\
    \ sz = 0) {\n        fact.reserve(sz+1);\n        rev.reserve(sz+1);\n    }\n\
    \    void resize(uint32_t sz) {\n        sz++;\n        if (fact.size() >= sz)\
    \ return;\n        uint32_t before = fact.size();\n        fact.resize(sz);\n\
    \        rev.resize(sz);\n        for (uint32_t i = before; i < sz; i++) {\n \
    \           fact[i] = fact[i - 1] * i;\n            rev[i] = rev[i - 1] / i;\n\
    \        }\n    }\n    T comb(int32_t n, int32_t k) {\n        if (n < 0 || k\
    \ < 0 || n < k) return 0;\n        resize(n);\n        return fact[n] * rev[n\
    \ - k] * rev[k];\n    }\n    T perm(int32_t n, int32_t k) {\n        if (n < 0\
    \ || k < 0 || n < k) return 0;\n        resize(n);\n        return fact[n] * rev[n\
    \ - k];\n    }\n    T multi_comb(int32_t n, int32_t k) {\n        if (k == 0)\
    \ return 1;\n        return comb(n + k - 1, k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModCombination.hpp
  requiredBy: []
  timestamp: '2024-10-22 20:55:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-yuki/117.test.cpp
documentation_of: Math/ModCombination.hpp
layout: document
redirect_from:
- /library/Math/ModCombination.hpp
- /library/Math/ModCombination.hpp.html
title: Math/ModCombination.hpp
---
