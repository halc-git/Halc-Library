---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1
  bundledCode: "#line 2 \"DataStructure/FoldableDeque.hpp\"\n//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template<class M>\nstruct FoldableQueue{\n    using T=typename M::T;\n    stack<T>\
    \ top,bottom,topfold,bottomfold;\n    FoldableQueue(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push(T v){\n        bottom.push(v);\n\
    \        bottomfold.push(M::op(bottomfold.top(),v));\n    }\n    void pop(){\n\
    \        if(top.size()==0){\n            while(!bottom.empty()){\n           \
    \     top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        top.pop();\n        topfold.pop();\n    }\n    T front(){\n\
    \        if(top.size()==0){\n            while(!bottom.empty()){\n           \
    \     top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        return top.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\n"
  code: "#pragma once\n//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template<class M>\nstruct FoldableQueue{\n    using T=typename M::T;\n    stack<T>\
    \ top,bottom,topfold,bottomfold;\n    FoldableQueue(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push(T v){\n        bottom.push(v);\n\
    \        bottomfold.push(M::op(bottomfold.top(),v));\n    }\n    void pop(){\n\
    \        if(top.size()==0){\n            while(!bottom.empty()){\n           \
    \     top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        top.pop();\n        topfold.pop();\n    }\n    T front(){\n\
    \        if(top.size()==0){\n            while(!bottom.empty()){\n           \
    \     top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        return top.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FoldableDeque.hpp
  requiredBy: []
  timestamp: '2024-03-10 08:12:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
documentation_of: DataStructure/FoldableDeque.hpp
layout: document
redirect_from:
- /library/DataStructure/FoldableDeque.hpp
- /library/DataStructure/FoldableDeque.hpp.html
title: DataStructure/FoldableDeque.hpp
---
