---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ,./Template/Heuristic.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include<ext/pb_ds/assoc_container.hpp>\n#include\",./Template/Heuristic.hpp\"\
    \n//https://codeforces.com/blog/entry/62393?locale=en\nstruct custom_hash {\n\
    \    //http://xorshift.di.unimi.it/splitmix64.c\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x+=0x9e3779b97f4a7c15;\n        x=(x^(x>>30))*0xbf58476d1ce4e5b9;\n\
    \        x=(x^(x>>27))*0x94d049bb133111eb;\n        return x^(x>>31);\n    }\n\
    \    uint64_t operator()(uint64_t x) const {\n        mt19937_64 mt(pcg32_fast());\n\
    \        uniform_int_distribution<uint64_t> rand(0,1ULL<<63);\n        static\
    \ const uint64_t FIXED_RANDOM=rand(mt);\n        return splitmix64(x+FIXED_RANDOM);\n\
    \    }\n};\ntemplate<typename Key,typename Val>using Hashmap=__gnu_pbds::gp_hash_table<Key,Val,custom_hash>;\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Hashmap.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/Hashmap.hpp
- /library/DataStructure/Hashmap.hpp.html
title: DataStructure/Hashmap.hpp
---
