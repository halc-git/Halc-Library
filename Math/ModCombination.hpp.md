---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/ModCombination.hpp\"\n#include<vector>\n#include<cstdint>\n\
    template<typename T>\nstruct ModCombination{\n    std::vector<T> fact={1},rev{1};\n\
    \    void resize(uint32_t sz){\n        sz++;\n        if(fact.size()>=sz)return;\n\
    \        uint32_t before=fact.size();\n        fact.resize(sz);\n        rev.resize(sz);\n\
    \        for(uint32_t i=before; i<sz; i++){\n            fact[i]=fact[i-1]*i;\n\
    \            rev[i]=rev[i-1]/i;\n        }\n    }\n    T comb(int32_t n,int32_t\
    \ k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n        return\
    \ fact[n]*rev[n-k]*rev[k];\n    }\n    T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t\
    \ n,int32_t k){\n        if(k==0)return 1;\n        return comb(n+k-1,k);\n  \
    \  }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<cstdint>\ntemplate<typename T>\n\
    struct ModCombination{\n    std::vector<T> fact={1},rev{1};\n    void resize(uint32_t\
    \ sz){\n        sz++;\n        if(fact.size()>=sz)return;\n        uint32_t before=fact.size();\n\
    \        fact.resize(sz);\n        rev.resize(sz);\n        for(uint32_t i=before;\
    \ i<sz; i++){\n            fact[i]=fact[i-1]*i;\n            rev[i]=rev[i-1]/i;\n\
    \        }\n    }\n    T comb(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k]*rev[k];\n    }\n   \
    \ T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n\
    \        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t n,int32_t k){\n\
    \        if(k==0)return 1;\n        return comb(n+k-1,k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModCombination.hpp
  requiredBy: []
  timestamp: '2024-05-01 17:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-yuki/117.test.cpp
documentation_of: Math/ModCombination.hpp
layout: document
redirect_from:
- /library/Math/ModCombination.hpp
- /library/Math/ModCombination.hpp.html
title: Math/ModCombination.hpp
---
