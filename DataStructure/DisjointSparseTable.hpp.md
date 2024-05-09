---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
    title: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/DisjointSparseTable.hpp\"\n#include <cstddef>\n\
    #include <cstdint>\n#include <vector>\ntemplate <class M>\nstruct DisjointSparseTable\
    \ {\n    using T = typename M::T;\n    size_t siz;\n    int8_t bitlen = 0;\n \
    \   std::vector<T> table;\n    DisjointSparseTable(std::vector<T> def) {\n   \
    \     siz = def.size();\n        while (1 << bitlen <= siz - 1) bitlen++;\n  \
    \      ;\n        swap(table, def);\n        table.resize(siz * std::max((int8_t)1,\
    \ bitlen));\n        for (int32_t i = siz; i < siz * bitlen; i++) {\n        \
    \    table[i] = table[i % siz];\n        }\n        int32_t index = siz;\n   \
    \     for (int8_t i = 1; i < bitlen; i++) {\n            for (int32_t j = 0; j\
    \ < siz; j++) {\n                if (((j >> i) << i) == j) continue;\n       \
    \         if ((j >> i) & 1) {\n                    table[j + index] =\n      \
    \                  M::op(table[j - 1 + index], table[j, index]);\n           \
    \     } else {\n                    int32_t pos =\n                        ((j\
    \ >> i) << i) + ((1 << i) - 1) - (j & ((1 << i) - 1));\n                    if\
    \ (pos < siz) {\n                        table[pos + index] =\n              \
    \              M::op(table[pos + index], table[pos + 1 + index]);\n          \
    \          }\n                }\n            }\n            index += siz;\n  \
    \      }\n    }\n    T get(int32_t p) { return table[p]; }\n    T prod(int32_t\
    \ lf, int32_t ri) {\n        if (lf == ri) return M::e;\n        if (lf + 1 ==\
    \ ri) return table[lf];\n        int8_t nbl = 0;\n        while (1 << (nbl + 1)\
    \ <= (lf ^ (ri - 1))) nbl++;\n        int32_t pos = nbl * siz;\n        return\
    \ M::op(table[pos + lf], table[pos + ri - 1]);\n    }\n};\n"
  code: "#pragma once\n#include <cstddef>\n#include <cstdint>\n#include <vector>\n\
    template <class M>\nstruct DisjointSparseTable {\n    using T = typename M::T;\n\
    \    size_t siz;\n    int8_t bitlen = 0;\n    std::vector<T> table;\n    DisjointSparseTable(std::vector<T>\
    \ def) {\n        siz = def.size();\n        while (1 << bitlen <= siz - 1) bitlen++;\n\
    \        ;\n        swap(table, def);\n        table.resize(siz * std::max((int8_t)1,\
    \ bitlen));\n        for (int32_t i = siz; i < siz * bitlen; i++) {\n        \
    \    table[i] = table[i % siz];\n        }\n        int32_t index = siz;\n   \
    \     for (int8_t i = 1; i < bitlen; i++) {\n            for (int32_t j = 0; j\
    \ < siz; j++) {\n                if (((j >> i) << i) == j) continue;\n       \
    \         if ((j >> i) & 1) {\n                    table[j + index] =\n      \
    \                  M::op(table[j - 1 + index], table[j, index]);\n           \
    \     } else {\n                    int32_t pos =\n                        ((j\
    \ >> i) << i) + ((1 << i) - 1) - (j & ((1 << i) - 1));\n                    if\
    \ (pos < siz) {\n                        table[pos + index] =\n              \
    \              M::op(table[pos + index], table[pos + 1 + index]);\n          \
    \          }\n                }\n            }\n            index += siz;\n  \
    \      }\n    }\n    T get(int32_t p) { return table[p]; }\n    T prod(int32_t\
    \ lf, int32_t ri) {\n        if (lf == ri) return M::e;\n        if (lf + 1 ==\
    \ ri) return table[lf];\n        int8_t nbl = 0;\n        while (1 << (nbl + 1)\
    \ <= (lf ^ (ri - 1))) nbl++;\n        int32_t pos = nbl * siz;\n        return\
    \ M::op(table[pos + lf], table[pos + ri - 1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2024-05-09 11:31:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - Verify/verify-yosupo-datastructure/staticrmq.test.cpp
documentation_of: DataStructure/DisjointSparseTable.hpp
layout: document
title: Disjoint Sparse Table
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
* `T op(T x,T y)`: 演算です。モノイドであることを要求します。
* `T e`: 単位元です。