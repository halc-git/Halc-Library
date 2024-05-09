---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
    title: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/DisjointSparseTable.hpp\"\n#include <cstddef>\n\
    #include <cstdint>\n#include <vector>\ntemplate <class M>\nstruct DisjointSparseTable\
    \ {\n    using T = typename M::T;\n    size_t siz;\n    std::vector<T> table;\n\
    \    constexpr inline int32_t _bit_length(int32_t x) {\n        x |= x >> 1;\n\
    \        x |= x >> 2;\n        x |= x >> 4;\n        x |= x >> 8;\n        x |=\
    \ x >> 16;\n        x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n        x =\
    \ (x & 0x33333333) + (x >> 2 & 0x33333333);\n        x = (x & 0x0f0f0f0f) + (x\
    \ >> 4 & 0x0f0f0f0f);\n        x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\
    \        return (x & 0x0000ffff) + (x >> 16);\n    }\n    DisjointSparseTable(std::vector<T>\
    \ def) {\n        siz = def.size();\n        int32_t bitlen = _bit_length(siz\
    \ - 1);\n        table.resize(siz * std::max(1, bitlen));\n        for (int32_t\
    \ i = 0; i < table.size(); i++) {\n            table[i] = def[i % siz];\n    \
    \    }\n        int32_t index = siz;\n        for (int32_t i = 1; i < bitlen;\
    \ i++) {\n            for (int32_t j = 0; j < siz; j++) {\n                if\
    \ (((j >> i) << i) == j) continue;\n                if ((j >> i) & 1) {\n    \
    \                table[j + index] =\n                        M::op(table[j - 1\
    \ + index], table[j + index]);\n                } else {\n                   \
    \ int32_t pos =\n                        ((j >> i) << i) + ((1 << i) - 1) - (j\
    \ & ((1 << i) - 1));\n                    if (pos < siz) {\n                 \
    \       table[pos + index] =\n                            M::op(table[pos + index],\
    \ table[pos + 1 + index]);\n                    }\n                }\n       \
    \     }\n            index += siz;\n        }\n    }\n    T get(int32_t p) { return\
    \ table[p]; }\n    T prod(int32_t lf, int32_t ri) {\n        if (lf == ri) return\
    \ M::e;\n        if (lf + 1 == ri) return table[lf];\n        int32_t pos = (_bit_length(lf\
    \ ^ (ri - 1)) - 1) * siz;\n        return M::op(table[pos + lf], table[pos + ri\
    \ - 1]);\n    }\n};\n"
  code: "#pragma once\n#include <cstddef>\n#include <cstdint>\n#include <vector>\n\
    template <class M>\nstruct DisjointSparseTable {\n    using T = typename M::T;\n\
    \    size_t siz;\n    std::vector<T> table;\n    constexpr inline int32_t _bit_length(int32_t\
    \ x) {\n        x |= x >> 1;\n        x |= x >> 2;\n        x |= x >> 4;\n   \
    \     x |= x >> 8;\n        x |= x >> 16;\n        x = (x & 0x55555555) + (x >>\
    \ 1 & 0x55555555);\n        x = (x & 0x33333333) + (x >> 2 & 0x33333333);\n  \
    \      x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n        x = (x & 0x00ff00ff)\
    \ + (x >> 8 & 0x00ff00ff);\n        return (x & 0x0000ffff) + (x >> 16);\n   \
    \ }\n    DisjointSparseTable(std::vector<T> def) {\n        siz = def.size();\n\
    \        int32_t bitlen = _bit_length(siz - 1);\n        table.resize(siz * std::max(1,\
    \ bitlen));\n        for (int32_t i = 0; i < table.size(); i++) {\n          \
    \  table[i] = def[i % siz];\n        }\n        int32_t index = siz;\n       \
    \ for (int32_t i = 1; i < bitlen; i++) {\n            for (int32_t j = 0; j <\
    \ siz; j++) {\n                if (((j >> i) << i) == j) continue;\n         \
    \       if ((j >> i) & 1) {\n                    table[j + index] =\n        \
    \                M::op(table[j - 1 + index], table[j + index]);\n            \
    \    } else {\n                    int32_t pos =\n                        ((j\
    \ >> i) << i) + ((1 << i) - 1) - (j & ((1 << i) - 1));\n                    if\
    \ (pos < siz) {\n                        table[pos + index] =\n              \
    \              M::op(table[pos + index], table[pos + 1 + index]);\n          \
    \          }\n                }\n            }\n            index += siz;\n  \
    \      }\n    }\n    T get(int32_t p) { return table[p]; }\n    T prod(int32_t\
    \ lf, int32_t ri) {\n        if (lf == ri) return M::e;\n        if (lf + 1 ==\
    \ ri) return table[lf];\n        int32_t pos = (_bit_length(lf ^ (ri - 1)) - 1)\
    \ * siz;\n        return M::op(table[pos + lf], table[pos + ri - 1]);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2024-05-09 15:56:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
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