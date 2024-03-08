---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/HashTable.hpp
    title: DataStructure/HashTable.hpp
  - icon: ':question:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Template.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\"\
    ../Template.hpp\"\n#include\"../DataStructure/HashTable.hpp\"\nint main(){\n \
    \   LL(Q);\n    HashMap<ll,ll> table;\n    rep(i,Q){\n        LL(t);\n       \
    \ if(t==0){\n            LL(k,v);\n            table[k]=v;\n        }\n      \
    \  if(t==1){\n            LL(k);\n            out(table[k]);\n        }\n    }\n\
    }"
  dependsOn:
  - Template.hpp
  - DataStructure/HashTable.hpp
  isVerificationFile: true
  path: Verify/assosiative_array.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 10:50:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/assosiative_array.test.cpp
layout: document
redirect_from:
- /verify/Verify/assosiative_array.test.cpp
- /verify/Verify/assosiative_array.test.cpp.html
title: Verify/assosiative_array.test.cpp
---
