---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Verify/verify-yosupo-datastructure/associative_array.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393?locale=en
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ DataStructure/Hashmap.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include\"../Template.hpp\"\n#pragma once\n#include<ext/pb_ds/assoc_container.hpp>\n\
    //https://codeforces.com/blog/entry/62393?locale=en\nstruct custom_hash {\n  \
    \  //http://xorshift.di.unimi.it/splitmix64.c\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x+=0x9e3779b97f4a7c15;\n        x=(x^(x>>30))*0xbf58476d1ce4e5b9;\n\
    \        x=(x^(x>>27))*0x94d049bb133111eb;\n        return x^(x>>31);\n    }\n\
    \    uint64_t operator()(uint64_t x) const {\n        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x+FIXED_RANDOM);\n    }\n};\ntemplate<typename Key,typename\
    \ Val>using Hashmap=__gnu_pbds::gp_hash_table<Key,Val,custom_hash>;"
  dependsOn:
  - Template.hpp
  isVerificationFile: false
  path: DataStructure/Hashmap.hpp
  requiredBy:
  - Verify/verify-yosupo-datastructure/associative_array.cpp
  timestamp: '2024-03-10 11:56:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/Hashmap.hpp
- /library/DataStructure/Hashmap.hpp.html
title: DataStructure/Hashmap.hpp
---
