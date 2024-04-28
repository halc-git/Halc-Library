---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Math/MontgomeryModint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include\"../../Template.hpp\"\n#include\"../../DataStructure/FoldableDeque.hpp\"\
    \n#include\"../../Math/MontgomeryModint.hpp\"\nusing mint=MontgomeryModint<MOD>;\n\
    struct composite{\n    using T=pair<mint,mint>;\n    static T op(T lf,T ri){\n\
    \        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);\n    }\n    static inline T\
    \ e=T(1,0);\n};\nvoid solve(){\n    LL(Q);\n    FoldableQueue<composite> que;\n\
    \    rep(i,Q){\n        LL(t);\n        if(t==0){\n            LL(a,b);\n    \
    \        que.push(pll(a,b));\n        }\n        if(t==1){\n            que.pop();\n\
    \        }\n        if(t==2){\n            LL(x);\n            pair<mint,mint>\
    \ ope=que.get_all();\n            out(ope.fi*x+ope.se);\n        }\n    }\n}\n\
    int main(){\n    solve();\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
- /verify/Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp.html
title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
---
