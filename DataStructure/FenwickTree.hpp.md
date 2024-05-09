---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/FenwickTree.hpp\"\n#include <bit>\n#include\
    \ <cstdint>\n#include <vector>\ntemplate <class T>\nstruct FenwickTree {\n   \
    \ std::vector<T> tree;\n    size_t siz;\n    int32_t start = 0;\n    FenwickTree(int32_t\
    \ sz) {\n        siz = sz;\n        tree.resize(sz + 1, 0);\n        start = 1\
    \ << (31 - std::countl_zero(siz));\n    }\n    FenwickTree(std::vector<T> def)\
    \ {\n        siz = def.size();\n        tree.resize(siz + 1, 0);\n        start\
    \ = 1 << (31 - std::countl_zero(siz));\n        for (int32_t i = 0; i < siz; i++)\
    \ {\n            tree[i + 1] += def[i];\n            if (i + (i & -i) <= siz)\
    \ {\n                tree[i + (i & -i)] += tree[i];\n            }\n        }\n\
    \    }\n    void add(int32_t pos, T val) {\n        pos++;\n        while (pos\
    \ <= siz) {\n            tree[pos] += val;\n            pos += pos & -pos;\n \
    \       }\n    }\n    T _sum(int32_t pos) {\n        T ret = 0;\n        while\
    \ (pos > 0) {\n            ret += tree[pos];\n            pos -= pos & -pos;\n\
    \        }\n        return ret;\n    }\n    T sum(int32_t lf, int32_t ri) { return\
    \ _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T w) {\n        if (w <= 0)\
    \ return 0;\n        int32_t now = 0;\n        T val = 0;\n        for (int32_t\
    \ i = start; i > 0; i >>= 1) {\n            if (now + i <= siz && val + tree[now\
    \ + i] < w) {\n                now += i;\n                val += tree[now];\n\
    \            }\n        }\n        return now + 1;\n    }\n    size_t size() {\
    \ return siz; }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cstdint>\n#include <vector>\ntemplate\
    \ <class T>\nstruct FenwickTree {\n    std::vector<T> tree;\n    size_t siz;\n\
    \    int32_t start = 0;\n    FenwickTree(int32_t sz) {\n        siz = sz;\n  \
    \      tree.resize(sz + 1, 0);\n        start = 1 << (31 - std::countl_zero(siz));\n\
    \    }\n    FenwickTree(std::vector<T> def) {\n        siz = def.size();\n   \
    \     tree.resize(siz + 1, 0);\n        start = 1 << (31 - std::countl_zero(siz));\n\
    \        for (int32_t i = 0; i < siz; i++) {\n            tree[i + 1] += def[i];\n\
    \            if (i + (i & -i) <= siz) {\n                tree[i + (i & -i)] +=\
    \ tree[i];\n            }\n        }\n    }\n    void add(int32_t pos, T val)\
    \ {\n        pos++;\n        while (pos <= siz) {\n            tree[pos] += val;\n\
    \            pos += pos & -pos;\n        }\n    }\n    T _sum(int32_t pos) {\n\
    \        T ret = 0;\n        while (pos > 0) {\n            ret += tree[pos];\n\
    \            pos -= pos & -pos;\n        }\n        return ret;\n    }\n    T\
    \ sum(int32_t lf, int32_t ri) { return _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T\
    \ w) {\n        if (w <= 0) return 0;\n        int32_t now = 0;\n        T val\
    \ = 0;\n        for (int32_t i = start; i > 0; i >>= 1) {\n            if (now\
    \ + i <= siz && val + tree[now + i] < w) {\n                now += i;\n      \
    \          val += tree[now];\n            }\n        }\n        return now + 1;\n\
    \    }\n    size_t size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2024-05-09 10:39:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
documentation_of: DataStructure/FenwickTree.hpp
layout: document
redirect_from:
- /library/DataStructure/FenwickTree.hpp
- /library/DataStructure/FenwickTree.hpp.html
title: DataStructure/FenwickTree.hpp
---
