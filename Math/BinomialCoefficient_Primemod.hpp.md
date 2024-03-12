---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Verify/verify-yuki/yuki-117.cpp
    title: Verify/verify-yuki/yuki-117.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/BinomialCoefficient_Primemod.hpp\"\ntemplate<typename\
    \ T>\nstruct BinomialCoefficient_Primemod{\n    vector<T> fact={1},rev{1};\n \
    \   void resize(uint32_t sz){\n        sz++;\n        if(fact.size()>=sz)return;\n\
    \        uint32_t before=fact.size();\n        fact.resize(sz);\n        rev.resize(sz);\n\
    \        for(uint32_t i=before; i<sz; i++){\n            fact[i]=fact[i-1]*i;\n\
    \            rev[i]=rev[i-1]/i;\n        }\n    }\n    T comb(int32_t n,int32_t\
    \ k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n        return\
    \ fact[n]*rev[n-k]*rev[k];\n    }\n    T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t\
    \ n,int32_t k){\n        return comb(n+k-1,k);\n    }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct BinomialCoefficient_Primemod{\n\
    \    vector<T> fact={1},rev{1};\n    void resize(uint32_t sz){\n        sz++;\n\
    \        if(fact.size()>=sz)return;\n        uint32_t before=fact.size();\n  \
    \      fact.resize(sz);\n        rev.resize(sz);\n        for(uint32_t i=before;\
    \ i<sz; i++){\n            fact[i]=fact[i-1]*i;\n            rev[i]=rev[i-1]/i;\n\
    \        }\n    }\n    T comb(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k]*rev[k];\n    }\n   \
    \ T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n\
    \        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t n,int32_t k){\n\
    \        return comb(n+k-1,k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/BinomialCoefficient_Primemod.hpp
  requiredBy:
  - Verify/verify-yuki/yuki-117.cpp
  timestamp: '2024-03-12 16:50:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
documentation_of: Math/BinomialCoefficient_Primemod.hpp
layout: document
redirect_from:
- /library/Math/BinomialCoefficient_Primemod.hpp
- /library/Math/BinomialCoefficient_Primemod.hpp.html
title: Math/BinomialCoefficient_Primemod.hpp
---
