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
    \ siz;\n    std::vector<T> tree;\n    SegmentTree(int32_t sz){\n        siz=sz;\n\
    \        tree=std::vector<T>(siz*2,M::e);\n    }\n    SegmentTree(std::vector<T>\
    \ def){\n        siz=def.size();\n        tree=vector<T>(siz*2,M::e);\n      \
    \  for(int32_t i=0; i<siz; i++){\n            tree[i+siz]=def[i];\n        }\n\
    \        for(int32_t i=siz-1; i>0; i--){\n            tree[i]=M::op(tree[i<<1],tree[(i<<1)+1]);\n\
    \        }\n    }\n    void set(int32_t p,T v){\n        p+=siz;\n        tree[p]=v;\n\
    \        p>>=1;\n        while(p>0){\n            tree[p]=M::op(tree[p<<1],tree[(p<<1)+1]);\n\
    \            p>>=1;\n        }\n    }\n    T prod(int32_t lf,int32_t ri){\n  \
    \      lf+=siz;\n        ri+=siz;\n        T rel=M::e;\n        T rer=M::e;\n\
    \        while(lf<ri){\n            if(lf&1){\n                rel=M::op(rel,tree[lf]);\n\
    \                lf++;\n            }\n            if(ri&1){\n               \
    \ ri--;\n                rer=M::op(tree[ri],rer);\n            }\n           \
    \ lf>>=1;\n            ri>>=1;\n        }\n        return M::op(rel,rer);\n  \
    \  }\n    size_t size(){\n        return siz;\n    }\n};\n"
  code: "#pragma once\n#include<cstdint>\n#include<vector>\ntemplate<class M>\nstruct\
    \ SegmentTree{\n    using T=typename M::T;\n    int32_t siz;\n    std::vector<T>\
    \ tree;\n    SegmentTree(int32_t sz){\n        siz=sz;\n        tree=std::vector<T>(siz*2,M::e);\n\
    \    }\n    SegmentTree(std::vector<T> def){\n        siz=def.size();\n      \
    \  tree=vector<T>(siz*2,M::e);\n        for(int32_t i=0; i<siz; i++){\n      \
    \      tree[i+siz]=def[i];\n        }\n        for(int32_t i=siz-1; i>0; i--){\n\
    \            tree[i]=M::op(tree[i<<1],tree[(i<<1)+1]);\n        }\n    }\n   \
    \ void set(int32_t p,T v){\n        p+=siz;\n        tree[p]=v;\n        p>>=1;\n\
    \        while(p>0){\n            tree[p]=M::op(tree[p<<1],tree[(p<<1)+1]);\n\
    \            p>>=1;\n        }\n    }\n    T prod(int32_t lf,int32_t ri){\n  \
    \      lf+=siz;\n        ri+=siz;\n        T rel=M::e;\n        T rer=M::e;\n\
    \        while(lf<ri){\n            if(lf&1){\n                rel=M::op(rel,tree[lf]);\n\
    \                lf++;\n            }\n            if(ri&1){\n               \
    \ ri--;\n                rer=M::op(tree[ri],rer);\n            }\n           \
    \ lf>>=1;\n            ri>>=1;\n        }\n        return M::op(rel,rer);\n  \
    \  }\n    size_t size(){\n        return siz;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2024-05-08 20:19:18+09:00'
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
