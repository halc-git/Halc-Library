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
    - https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1
  bundledCode: "#line 2 \"DataStructure/FoldableDeque.hpp\"\n//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template<class M>\nstruct FoldableQueue{\n    using T=typename M::T;\n    stack<T>\
    \ top,bottom,topfold,bottomfold;\n    FoldableQueue(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push(T v){\n        bottom.push(v);\n\
    \        bottomfold.push(M::op(bottomfold.top(),v));\n    }\n    void pop(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        top.pop();\n        topfold.pop();\n    }\n    T front(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        return top.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\ntemplate<class M>\nstruct FoldableDeque{\n    using T=typename M::T;\n\
    \    stack<T> top,bottom,topfold,bottomfold;\n    FoldableDeque(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push_front(T v){\n        top.push(v);\n\
    \        topfold.push(M::op(v,topfold.top()));\n    }\n    void push_back(T v){\n\
    \        bottom.push(v);\n        bottomfold.push(M::op(bottomfold.top(),v));\n\
    \    }\n    void pop_front(){\n        if(top.empty()){\n            vector<T>\
    \ change;\n            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(int32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n        }\n        top.pop();\n        topfold.pop();\n    }\n\
    \    void pop_back(){\n        if(bottom.empty()){\n            vector<T> change;\n\
    \            while(!top.empty()){\n                change.emplace_back(top.top());\n\
    \                top.pop();\n                topfold.pop();\n            }\n \
    \           size_t sz=change.size();\n            for(int32_t i=(sz>>1); i>=0;\
    \ i--){\n                bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n        }\n        bottom.pop();\n        bottomfold.pop();\n\
    \    }\n    T front(){\n        if(top.empty()){\n            vector<T> change;\n\
    \            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(uint32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[i]);\n                topfold.push(M::op(change[i],topfold.top()));\n\
    \            }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n          \
    \      bottom.push(change[i]);\n                bottomfold.push(M::op(bottomfold.top(),change[i]));\n\
    \            }\n        }\n        return top.top();\n    }\n    T back(){\n \
    \       if(bottom.empty()){\n            vector<T> change;\n            while(!top.empty()){\n\
    \                change.emplace_back(top.top());\n                top.pop();\n\
    \                topfold.pop();\n            }\n            size_t sz=change.size();\n\
    \            for(uint32_t i=(sz>>1); i>=0; i--){\n                bottom.push(change[i]);\n\
    \                bottomfold.push(M::op(bottomfold.top(),change[i]));\n       \
    \     }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n                top.push(change[i]);\n\
    \                topfold.push(M::op(change[i],topfold.top()));\n            }\n\
    \        }\n        return bottom.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\n"
  code: "#pragma once\n//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template<class M>\nstruct FoldableQueue{\n    using T=typename M::T;\n    stack<T>\
    \ top,bottom,topfold,bottomfold;\n    FoldableQueue(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push(T v){\n        bottom.push(v);\n\
    \        bottomfold.push(M::op(bottomfold.top(),v));\n    }\n    void pop(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        top.pop();\n        topfold.pop();\n    }\n    T front(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        return top.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\ntemplate<class M>\nstruct FoldableDeque{\n    using T=typename M::T;\n\
    \    stack<T> top,bottom,topfold,bottomfold;\n    FoldableDeque(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push_front(T v){\n        top.push(v);\n\
    \        topfold.push(M::op(v,topfold.top()));\n    }\n    void push_back(T v){\n\
    \        bottom.push(v);\n        bottomfold.push(M::op(bottomfold.top(),v));\n\
    \    }\n    void pop_front(){\n        if(top.empty()){\n            vector<T>\
    \ change;\n            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(int32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n        }\n        top.pop();\n        topfold.pop();\n    }\n\
    \    void pop_back(){\n        if(bottom.empty()){\n            vector<T> change;\n\
    \            while(!top.empty()){\n                change.emplace_back(top.top());\n\
    \                top.pop();\n                topfold.pop();\n            }\n \
    \           size_t sz=change.size();\n            for(int32_t i=(sz>>1); i>=0;\
    \ i--){\n                bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n        }\n        bottom.pop();\n        bottomfold.pop();\n\
    \    }\n    T front(){\n        if(top.empty()){\n            vector<T> change;\n\
    \            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(uint32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[i]);\n                topfold.push(M::op(change[i],topfold.top()));\n\
    \            }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n          \
    \      bottom.push(change[i]);\n                bottomfold.push(M::op(bottomfold.top(),change[i]));\n\
    \            }\n        }\n        return top.top();\n    }\n    T back(){\n \
    \       if(bottom.empty()){\n            vector<T> change;\n            while(!top.empty()){\n\
    \                change.emplace_back(top.top());\n                top.pop();\n\
    \                topfold.pop();\n            }\n            size_t sz=change.size();\n\
    \            for(uint32_t i=(sz>>1); i>=0; i--){\n                bottom.push(change[i]);\n\
    \                bottomfold.push(M::op(bottomfold.top(),change[i]));\n       \
    \     }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n                top.push(change[i]);\n\
    \                topfold.push(M::op(change[i],topfold.top()));\n            }\n\
    \        }\n        return bottom.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FoldableDeque.hpp
  requiredBy: []
  timestamp: '2024-03-10 09:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/FoldableDeque.hpp
layout: document
redirect_from:
- /library/DataStructure/FoldableDeque.hpp
- /library/DataStructure/FoldableDeque.hpp.html
title: DataStructure/FoldableDeque.hpp
---
