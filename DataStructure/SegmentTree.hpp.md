---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/SegmentTree.hpp\"\n#include<cstdint>\n#include<vector>\n\
    template<class M>\nstruct SegmentTree{\n    using T=typename M::T;\n    int32_t\
    \ size;\n    std::vector<T> tree;\n    SegmentTree(int32_t sz){\n        size=sz;\n\
    \        tree=vector<T>(size*2,M::e);\n    }\n    void set(int32_t p,T v){\n \
    \       p+=size;\n        tree[p]=v;\n        p>>=1;\n        while(p>0){\n  \
    \          tree[p]=M::op(tree[p<<1],tree[(p<<1)+1]);\n            p>>=1;\n   \
    \     }\n    }\n    T prod(int32_t lf,int32_t ri){\n        lf+=size;\n      \
    \  ri+=size;\n        T rel=M::e;\n        T rer=M::e;\n        while(lf<ri){\n\
    \            if(lf%2==1){\n                rel=M::op(rel,tree[lf]);\n        \
    \        lf++;\n            }\n            if(ri%2==1){\n                ri--;\n\
    \                rer=M::op(tree[ri],rer);\n            }\n            lf>>=1;\n\
    \            ri>>=1;\n        }\n        return M::op(rel,rer);\n    }\n};\n"
  code: "#pragma once\n#include<cstdint>\n#include<vector>\ntemplate<class M>\nstruct\
    \ SegmentTree{\n    using T=typename M::T;\n    int32_t size;\n    std::vector<T>\
    \ tree;\n    SegmentTree(int32_t sz){\n        size=sz;\n        tree=vector<T>(size*2,M::e);\n\
    \    }\n    void set(int32_t p,T v){\n        p+=size;\n        tree[p]=v;\n \
    \       p>>=1;\n        while(p>0){\n            tree[p]=M::op(tree[p<<1],tree[(p<<1)+1]);\n\
    \            p>>=1;\n        }\n    }\n    T prod(int32_t lf,int32_t ri){\n  \
    \      lf+=size;\n        ri+=size;\n        T rel=M::e;\n        T rer=M::e;\n\
    \        while(lf<ri){\n            if(lf%2==1){\n                rel=M::op(rel,tree[lf]);\n\
    \                lf++;\n            }\n            if(ri%2==1){\n            \
    \    ri--;\n                rer=M::op(tree[ri],rer);\n            }\n        \
    \    lf>>=1;\n            ri>>=1;\n        }\n        return M::op(rel,rer);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2024-05-07 22:08:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
documentation_of: DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.hpp
- /library/DataStructure/SegmentTree.hpp.html
title: DataStructure/SegmentTree.hpp
---
