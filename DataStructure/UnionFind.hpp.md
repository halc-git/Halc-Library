---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
    title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/UnionFind.hpp\"\n#include<cstdint>\n#include<vector>\n\
    template<class M>\nstruct MonoidUnionFind{\n    using T=typename M::T;\n    std::vector<std::pair<int32_t,T>>\
    \ tree;\n    MonoidUnionFind(int32_t sz){\n        tree.resize(sz,{-1,M::e});\n\
    \    }\n    int32_t root(int32_t pos){\n        int32_t ret=pos;\n        while(tree[ret].first>=0){\n\
    \            ret=tree[ret].first;\n        }\n        while(tree[pos].first>=0){\n\
    \            int32_t now=pos;\n            pos=tree[pos].first;\n            tree[now].first=ret;\n\
    \        }\n        return ret;\n    }\n    void set(int32_t pos,T val){\n   \
    \     tree[root(pos)].second=val;\n    }\n    T get(int32_t pos){\n        return\
    \ tree[root(pos)].second;\n    }\n    bool same(int32_t a,int32_t b){\n      \
    \  return root(a)==root(b);\n    }\n    bool merge(int32_t a,int32_t b){\n   \
    \     a=root(a);\n        b=root(b);\n        if(a==b)return false;\n        if(tree[a].first>tree[b].first)std::swap(a,b);\n\
    \        tree[a]={tree[a].first+tree[b].first,M::op(tree[a].second,tree[b].second)};\n\
    \        tree[b].first=a;\n        return true;\n    }\n    size_t size(int32_t\
    \ pos){\n        return -tree[root(pos)].first;\n    }\n    std::vector<std::vector<int32_t>>\
    \ groups(){\n        std::vector<std::vector<int32_t>> members(tree.size());\n\
    \        for(int32_t i=0; i<tree.size(); i++){\n            members[root(i)].emplace_back(i);\n\
    \        }\n        std::vector<std::vector<int32_t>> ret;\n        for(int32_t\
    \ i=0; i<tree.size(); i++){\n            if(!members[i].empty())ret.emplace_back(members[i]);\n\
    \        }\n        return ret;\n    }\n};\nstruct void_monoid{\n    using T=bool;\n\
    \    constexpr static inline T op(T a,T b){return 0;}\n    constexpr static inline\
    \ T e=0;\n};\nusing UnionFind=MonoidUnionFind<void_monoid>;\n"
  code: "#pragma once\n#include<cstdint>\n#include<vector>\ntemplate<class M>\nstruct\
    \ MonoidUnionFind{\n    using T=typename M::T;\n    std::vector<std::pair<int32_t,T>>\
    \ tree;\n    MonoidUnionFind(int32_t sz){\n        tree.resize(sz,{-1,M::e});\n\
    \    }\n    int32_t root(int32_t pos){\n        int32_t ret=pos;\n        while(tree[ret].first>=0){\n\
    \            ret=tree[ret].first;\n        }\n        while(tree[pos].first>=0){\n\
    \            int32_t now=pos;\n            pos=tree[pos].first;\n            tree[now].first=ret;\n\
    \        }\n        return ret;\n    }\n    void set(int32_t pos,T val){\n   \
    \     tree[root(pos)].second=val;\n    }\n    T get(int32_t pos){\n        return\
    \ tree[root(pos)].second;\n    }\n    bool same(int32_t a,int32_t b){\n      \
    \  return root(a)==root(b);\n    }\n    bool merge(int32_t a,int32_t b){\n   \
    \     a=root(a);\n        b=root(b);\n        if(a==b)return false;\n        if(tree[a].first>tree[b].first)std::swap(a,b);\n\
    \        tree[a]={tree[a].first+tree[b].first,M::op(tree[a].second,tree[b].second)};\n\
    \        tree[b].first=a;\n        return true;\n    }\n    size_t size(int32_t\
    \ pos){\n        return -tree[root(pos)].first;\n    }\n    std::vector<std::vector<int32_t>>\
    \ groups(){\n        std::vector<std::vector<int32_t>> members(tree.size());\n\
    \        for(int32_t i=0; i<tree.size(); i++){\n            members[root(i)].emplace_back(i);\n\
    \        }\n        std::vector<std::vector<int32_t>> ret;\n        for(int32_t\
    \ i=0; i<tree.size(); i++){\n            if(!members[i].empty())ret.emplace_back(members[i]);\n\
    \        }\n        return ret;\n    }\n};\nstruct void_monoid{\n    using T=bool;\n\
    \    constexpr static inline T op(T a,T b){return 0;}\n    constexpr static inline\
    \ T e=0;\n};\nusing UnionFind=MonoidUnionFind<void_monoid>;"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2024-05-06 21:09:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/unionfind.test.cpp
documentation_of: DataStructure/UnionFind.hpp
layout: document
title: Union Find
---

## 関数の設定
```cpp
struct M{
    using T;

    static T op(T x,T y){
    }

    static inline T e;
};
```
* `T`: モノイドの型です。
* `T op(T x,T y)`: 演算です。可換モノイドであることを要求します。
* `T e`: 単位元です。

`UnionFind` は `MonoidUnionFind<M>` に意味のない演算を載せたものです。