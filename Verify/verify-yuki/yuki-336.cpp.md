---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Modint/MontgomeryModint.hpp
    title: Modint/MontgomeryModint.hpp
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
    - https://yukicoder.me/problems/no/336
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
  code: "#define PROBREM \"https://yukicoder.me/problems/no/336\"\n#include\"../../Template.hpp\"\
    \n#include\"../../Modint/MontgomeryModint.hpp\"\nusing mint=MontgomeryModint<MODD>;\n\
    int main(){\n    LL(N);\n    if(N<=2){\n        return out(0);\n    }\n    vec(mint,dp,1,1);\n\
    \    rep(i,1,N){\n        vec(mint,ndp,i+1,0);\n        if(i&1){\n           \
    \ mint now=0;\n            rep(j,i){\n                now+=dp[j];\n          \
    \      ndp[j+1]+=now;\n            }\n        }\n        else{\n            mint\
    \ now=0;\n            rrep(j,i){\n                now+=dp[j];\n              \
    \  ndp[j]+=now;\n            }\n        }\n        dp=move(ndp);\n    }\n    mint\
    \ ans=0;\n    each(i,dp)ans+=i;\n    out((ans*2).val());\n}"
  dependsOn:
  - Template.hpp
  - Modint/MontgomeryModint.hpp
  isVerificationFile: false
  path: Verify/verify-yuki/yuki-336.cpp
  requiredBy: []
  timestamp: '2024-03-08 20:29:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Verify/verify-yuki/yuki-336.cpp
layout: document
redirect_from:
- /library/Verify/verify-yuki/yuki-336.cpp
- /library/Verify/verify-yuki/yuki-336.cpp.html
title: Verify/verify-yuki/yuki-336.cpp
---
