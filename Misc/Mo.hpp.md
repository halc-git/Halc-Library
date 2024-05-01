---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/2338.test.cpp
    title: Verify/verify-yuki/2338.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Misc/Mo.hpp\"\n#include<vector>\n#include<numeric>\n#include<cmath>\n\
    template<class M>\nstruct Mo{\n    using T=typename M::T;\n    int32_t backet;\n\
    \    std::vector<int32_t> left,right,order;\n    Mo(int32_t N,int32_t Q){\n  \
    \      order.resize(Q);\n        backet=std::max<int32_t>(1,(double)(N)/std::max<double>(1,std::sqrt(Q*2.0/3)));\n\
    \        std::iota(order.begin(),order.end(),0);\n    }\n    void add_query(int32_t\
    \ lf,int32_t ri){\n        left.emplace_back(lf);\n        right.emplace_back(ri);\n\
    \    }\n    std::vector<T> run(){\n        std::vector<T> answer(order.size());\n\
    \        sort(order.begin(),order.end(),[&](int32_t a,int32_t b){\n          \
    \  int32_t ab=left[a]/backet,bb=left[b]/backet;\n            if(ab!=bb)return\
    \ ab<bb;\n            if(ab&1)return right[a]<right[b];\n            return right[a]>right[b];\n\
    \        });\n        int32_t nl=0,nr=0;\n        for(int32_t i:order){\n    \
    \        while(nl>left[i]){\n                nl--;\n                M::add_left(nl);\n\
    \            }\n            while(right[i]>nr){\n                M::add_right(nr);\n\
    \                nr++;\n            }\n            while(nl<left[i]){\n      \
    \          M::delete_left(nl);\n                nl++;\n            }\n       \
    \     while(right[i]<nr){\n                nr--;\n                M::delete_right(nr);\n\
    \            }\n            answer[i]=M::rem();\n        }\n        return answer;\n\
    \    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<numeric>\n#include<cmath>\ntemplate<class\
    \ M>\nstruct Mo{\n    using T=typename M::T;\n    int32_t backet;\n    std::vector<int32_t>\
    \ left,right,order;\n    Mo(int32_t N,int32_t Q){\n        order.resize(Q);\n\
    \        backet=std::max<int32_t>(1,(double)(N)/std::max<double>(1,std::sqrt(Q*2.0/3)));\n\
    \        std::iota(order.begin(),order.end(),0);\n    }\n    void add_query(int32_t\
    \ lf,int32_t ri){\n        left.emplace_back(lf);\n        right.emplace_back(ri);\n\
    \    }\n    std::vector<T> run(){\n        std::vector<T> answer(order.size());\n\
    \        sort(order.begin(),order.end(),[&](int32_t a,int32_t b){\n          \
    \  int32_t ab=left[a]/backet,bb=left[b]/backet;\n            if(ab!=bb)return\
    \ ab<bb;\n            if(ab&1)return right[a]<right[b];\n            return right[a]>right[b];\n\
    \        });\n        int32_t nl=0,nr=0;\n        for(int32_t i:order){\n    \
    \        while(nl>left[i]){\n                nl--;\n                M::add_left(nl);\n\
    \            }\n            while(right[i]>nr){\n                M::add_right(nr);\n\
    \                nr++;\n            }\n            while(nl<left[i]){\n      \
    \          M::delete_left(nl);\n                nl++;\n            }\n       \
    \     while(right[i]<nr){\n                nr--;\n                M::delete_right(nr);\n\
    \            }\n            answer[i]=M::rem();\n        }\n        return answer;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Mo.hpp
  requiredBy: []
  timestamp: '2024-05-01 17:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yuki/2338.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
documentation_of: Misc/Mo.hpp
layout: document
title: Mo's Algorithm
---

## 関数の設定
```cpp
struct M{
    using T;
    static void add_left(int pos){
    }
    static void delete_left(int pos){
    }
    static void add_right(int pos){
    }
    static void delete_right(int pos){
    }
    static T rem(){
    }
};
```
* `T`: 答えの型です。
* `void add_left(int pos)`: `pos` 番目の要素を左に追加するときの処理です。
* `void delete_left(int pos)`: `pos` 番目の要素を左から削除するときの処理です。
* `void add_right(int pos)`: `pos` 番目の要素を右に追加するときの処理です。
* `void delete_right(int pos)`: `pos` 番目の要素を右から削除するときの処理です。
* `T rem()`: 現時点でのクエリに対する答えを返す処理です。