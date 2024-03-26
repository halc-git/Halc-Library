---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393?locale=en
  bundledCode: "#line 2 \"DataStructure/Hashmap.hpp\"\n#include<ext/pb_ds/assoc_container.hpp>\n\
    //https://codeforces.com/blog/entry/62393?locale=en\nstruct custom_hash {\n  \
    \  //http://xorshift.di.unimi.it/splitmix64.c\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x+=0x9e3779b97f4a7c15;\n        x=(x^(x>>30))*0xbf58476d1ce4e5b9;\n\
    \        x=(x^(x>>27))*0x94d049bb133111eb;\n        return x^(x>>31);\n    }\n\
    \    uint64_t operator()(uint64_t x) const {\n        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x+FIXED_RANDOM);\n    }\n};\ntemplate<typename Key,typename\
    \ Val>using Hashmap=gp_hash_table<Key,Val,custom_hash>;\n"
  code: "#pragma once\n#include<ext/pb_ds/assoc_container.hpp>\n//https://codeforces.com/blog/entry/62393?locale=en\n\
    struct custom_hash {\n    //http://xorshift.di.unimi.it/splitmix64.c\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        x+=0x9e3779b97f4a7c15;\n        x=(x^(x>>30))*0xbf58476d1ce4e5b9;\n\
    \        x=(x^(x>>27))*0x94d049bb133111eb;\n        return x^(x>>31);\n    }\n\
    \    uint64_t operator()(uint64_t x) const {\n        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x+FIXED_RANDOM);\n    }\n};\ntemplate<typename Key,typename\
    \ Val>using Hashmap=gp_hash_table<Key,Val,custom_hash>;\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Hashmap.hpp
  requiredBy: []
  timestamp: '2024-03-26 14:02:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
documentation_of: DataStructure/Hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/Hashmap.hpp
- /library/DataStructure/Hashmap.hpp.html
title: DataStructure/Hashmap.hpp
---
