---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/FenwickTree.hpp\"\n#include <bit>\n#include\
    \ <cstdint>\n#include <vector>\ntemplate <class T>\nstruct FenwickTree {\n   \
    \ std::vector<T> tree;\n    int32_t start = 1;\n    int32_t siz;\n    FenwickTree(int32_t\
    \ sz) {\n        siz = sz;\n        tree.resize(sz + 1, 0);\n        start = 1\
    \ << ((32 - std::countl_zero((uint32_t)siz)) - 1);\n    }\n    FenwickTree(std::vector<T>\
    \ def) {\n        siz = def.size();\n        tree.resize(siz + 1, 0);\n      \
    \  start = 1 << ((32 - std::countl_zero((uint32_t)siz)) - 1);\n        for (int32_t\
    \ i = 0; i < siz; i++) {\n            tree[i + 1] += def[i];\n            if (i\
    \ + (i & -i) <= siz) {\n                tree[i + (i & -i)] += tree[i];\n     \
    \       }\n        }\n    }\n    void add(int32_t pos, T val) {\n        pos++;\n\
    \        while (pos <= siz) {\n            tree[pos] += val;\n            pos\
    \ += pos & -pos;\n        }\n    }\n    T _sum(int32_t pos) {\n        T ret =\
    \ 0;\n        while (pos > 0) {\n            ret += tree[pos];\n            pos\
    \ -= pos & -pos;\n        }\n        return ret;\n    }\n    T sum(int32_t lf,\
    \ int32_t ri) { return _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T w) {\n\
    \        if (w <= 0) return 0;\n        int32_t now = 0;\n        T val = 0;\n\
    \        for (int32_t i = start; i > 0; i >>= 1) {\n            if (now + i <=\
    \ siz && val + tree[now + i] < w) {\n                now += i;\n             \
    \   val += tree[now];\n            }\n        }\n        return now + 1;\n   \
    \ }\n    int32_t size() { return siz; }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cstdint>\n#include <vector>\ntemplate\
    \ <class T>\nstruct FenwickTree {\n    std::vector<T> tree;\n    int32_t start\
    \ = 1;\n    int32_t siz;\n    FenwickTree(int32_t sz) {\n        siz = sz;\n \
    \       tree.resize(sz + 1, 0);\n        start = 1 << ((32 - std::countl_zero((uint32_t)siz))\
    \ - 1);\n    }\n    FenwickTree(std::vector<T> def) {\n        siz = def.size();\n\
    \        tree.resize(siz + 1, 0);\n        start = 1 << ((32 - std::countl_zero((uint32_t)siz))\
    \ - 1);\n        for (int32_t i = 0; i < siz; i++) {\n            tree[i + 1]\
    \ += def[i];\n            if (i + (i & -i) <= siz) {\n                tree[i +\
    \ (i & -i)] += tree[i];\n            }\n        }\n    }\n    void add(int32_t\
    \ pos, T val) {\n        pos++;\n        while (pos <= siz) {\n            tree[pos]\
    \ += val;\n            pos += pos & -pos;\n        }\n    }\n    T _sum(int32_t\
    \ pos) {\n        T ret = 0;\n        while (pos > 0) {\n            ret += tree[pos];\n\
    \            pos -= pos & -pos;\n        }\n        return ret;\n    }\n    T\
    \ sum(int32_t lf, int32_t ri) { return _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T\
    \ w) {\n        if (w <= 0) return 0;\n        int32_t now = 0;\n        T val\
    \ = 0;\n        for (int32_t i = start; i > 0; i >>= 1) {\n            if (now\
    \ + i <= siz && val + tree[now + i] < w) {\n                now += i;\n      \
    \          val += tree[now];\n            }\n        }\n        return now + 1;\n\
    \    }\n    int32_t size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2024-05-10 16:22:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
documentation_of: DataStructure/FenwickTree.hpp
layout: document
redirect_from:
- /library/DataStructure/FenwickTree.hpp
- /library/DataStructure/FenwickTree.hpp.html
title: DataStructure/FenwickTree.hpp
---
