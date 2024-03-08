---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Modint/MontgomeryModint.hpp
    title: Modint/MontgomeryModint.hpp
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
  isVerificationFile: true
  path: Verify/verify-yuki/yuki-336.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 20:31:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/verify-yuki/yuki-336.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yuki/yuki-336.test.cpp
- /verify/Verify/verify-yuki/yuki-336.test.cpp.html
title: Verify/verify-yuki/yuki-336.test.cpp
---
