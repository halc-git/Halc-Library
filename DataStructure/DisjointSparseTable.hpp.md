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
  bundledCode: "#line 2 \"DataStructure/DisjointSparseTable.hpp\"\n#include <bit>\n\
    #include <cstdint>\n#include <vector>\ntemplate <class M>\nstruct DisjointSparseTable\
    \ {\n    using T = typename M::T;\n    int32_t siz;\n    std::vector<T> table;\n\
    \    DisjointSparseTable(std::vector<T> def) {\n        siz = def.size();\n  \
    \      int32_t bitlen = 32 - std::countl_zero((uint32_t)siz - 1);\n        table.resize(siz\
    \ * std::max(1, bitlen));\n        int32_t pos = 0;\n        for (int32_t i =\
    \ 0; i < table.size(); i++) {\n            if (i < siz) {\n                table[i]\
    \ = def[i];\n            } else {\n                table[i] = table[i - siz];\n\
    \            }\n        }\n        int32_t index = siz;\n        for (int32_t\
    \ i = 1; i < bitlen; i++) {\n            for (int32_t j = 0; j < siz; j++) {\n\
    \                if (((j >> i) << i) == j) continue;\n                if ((j >>\
    \ i) & 1) {\n                    table[j + index] =\n                        M::op(table[j\
    \ - 1 + index], table[j + index]);\n                } else {\n               \
    \     int32_t pos =\n                        ((j >> i) << i) + ((1 << i) - 1)\
    \ - (j & ((1 << i) - 1));\n                    if (pos < siz) {\n            \
    \            table[pos + index] =\n                            M::op(table[pos\
    \ + index], table[pos + 1 + index]);\n                    }\n                }\n\
    \            }\n            index += siz;\n        }\n    }\n    T get(int32_t\
    \ p) { return table[p]; }\n    T prod(int32_t lf, int32_t ri) {\n        if (lf\
    \ == ri) return M::e;\n        if (lf + 1 == ri) return table[lf];\n        int32_t\
    \ pos = (31 - std::countl_zero((uint32_t)lf ^ (ri - 1))) * siz;\n        return\
    \ M::op(table[pos + lf], table[pos + ri - 1]);\n    }\n    int32_t size() { return\
    \ siz; }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cstdint>\n#include <vector>\ntemplate\
    \ <class M>\nstruct DisjointSparseTable {\n    using T = typename M::T;\n    int32_t\
    \ siz;\n    std::vector<T> table;\n    DisjointSparseTable(std::vector<T> def)\
    \ {\n        siz = def.size();\n        int32_t bitlen = 32 - std::countl_zero((uint32_t)siz\
    \ - 1);\n        table.resize(siz * std::max(1, bitlen));\n        int32_t pos\
    \ = 0;\n        for (int32_t i = 0; i < table.size(); i++) {\n            if (i\
    \ < siz) {\n                table[i] = def[i];\n            } else {\n       \
    \         table[i] = table[i - siz];\n            }\n        }\n        int32_t\
    \ index = siz;\n        for (int32_t i = 1; i < bitlen; i++) {\n            for\
    \ (int32_t j = 0; j < siz; j++) {\n                if (((j >> i) << i) == j) continue;\n\
    \                if ((j >> i) & 1) {\n                    table[j + index] =\n\
    \                        M::op(table[j - 1 + index], table[j + index]);\n    \
    \            } else {\n                    int32_t pos =\n                   \
    \     ((j >> i) << i) + ((1 << i) - 1) - (j & ((1 << i) - 1));\n             \
    \       if (pos < siz) {\n                        table[pos + index] =\n     \
    \                       M::op(table[pos + index], table[pos + 1 + index]);\n \
    \                   }\n                }\n            }\n            index +=\
    \ siz;\n        }\n    }\n    T get(int32_t p) { return table[p]; }\n    T prod(int32_t\
    \ lf, int32_t ri) {\n        if (lf == ri) return M::e;\n        if (lf + 1 ==\
    \ ri) return table[lf];\n        int32_t pos = (31 - std::countl_zero((uint32_t)lf\
    \ ^ (ri - 1))) * siz;\n        return M::op(table[pos + lf], table[pos + ri -\
    \ 1]);\n    }\n    int32_t size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2024-05-10 16:22:37+09:00'
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