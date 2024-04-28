---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/ModCombination.hpp\"\ntemplate<typename T>\nstruct\
    \ ModCombination{\n    vector<T> fact={1},rev{1};\n    void resize(uint32_t sz){\n\
    \        sz++;\n        if(fact.size()>=sz)return;\n        uint32_t before=fact.size();\n\
    \        fact.resize(sz);\n        rev.resize(sz);\n        for(uint32_t i=before;\
    \ i<sz; i++){\n            fact[i]=fact[i-1]*i;\n            rev[i]=rev[i-1]/i;\n\
    \        }\n    }\n    T comb(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k]*rev[k];\n    }\n   \
    \ T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n\
    \        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t n,int32_t k){\n\
    \        return comb(n+k-1,k);\n    }\n};\n"
  code: "template<typename T>\nstruct ModCombination{\n    vector<T> fact={1},rev{1};\n\
    \    void resize(uint32_t sz){\n        sz++;\n        if(fact.size()>=sz)return;\n\
    \        uint32_t before=fact.size();\n        fact.resize(sz);\n        rev.resize(sz);\n\
    \        for(uint32_t i=before; i<sz; i++){\n            fact[i]=fact[i-1]*i;\n\
    \            rev[i]=rev[i-1]/i;\n        }\n    }\n    T comb(int32_t n,int32_t\
    \ k){\n        if(n<0||k<0||n<k)return 0;\n        resize(n);\n        return\
    \ fact[n]*rev[n-k]*rev[k];\n    }\n    T perm(int32_t n,int32_t k){\n        if(n<0||k<0||n<k)return\
    \ 0;\n        resize(n);\n        return fact[n]*rev[n-k];\n    }\n    T multi_comb(int32_t\
    \ n,int32_t k){\n        return comb(n+k-1,k);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModCombination.hpp
  requiredBy: []
  timestamp: '2024-04-28 11:29:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
