---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/Hashmap.hpp
    title: DataStructure/Hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ DataStructure/Hashmap.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\"\
    ../../Template.hpp\"\n#include\"../../DataStructure/Hashmap.hpp\"\nvoid solve(){\n\
    \    LL(Q);\n    Hashmap<ll,ll> a;\n    rep(i,Q){\n        LL(t,k);\n        if(t==0){\n\
    \            LL(v);\n            a[k]=v;\n        }\n        else{\n         \
    \   out(a[k]);\n        }\n    }\n}\nint main(){\n    solve();\n    return 0;\n\
    }"
  dependsOn:
  - Template.hpp
  - DataStructure/Hashmap.hpp
  isVerificationFile: false
  path: Verify/verify-yosupo-datastructure/associative_array.cpp
  requiredBy: []
  timestamp: '2024-03-10 11:56:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/associative_array.cpp
layout: document
redirect_from:
- /library/Verify/verify-yosupo-datastructure/associative_array.cpp
- /library/Verify/verify-yosupo-datastructure/associative_array.cpp.html
title: Verify/verify-yosupo-datastructure/associative_array.cpp
---
