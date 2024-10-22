---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
    title: Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/650.test.cpp
    title: Verify/verify-yuki/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/SegmentTree.hpp\"\n#include <cstdint>\n#include\
    \ <queue>\n#include <stack>\n#include <vector>\ntemplate <class M>\nstruct SegmentTree\
    \ {\n    using T = typename M::T;\n    int32_t siz;\n    std::vector<T> tree;\n\
    \    SegmentTree(int32_t sz) {\n        siz = sz;\n        tree = std::vector<T>(siz\
    \ << 1, M::e);\n    }\n    SegmentTree(std::vector<T> def) {\n        siz = def.size();\n\
    \        tree = std::vector<T>(siz << 1, M::e);\n        for (int32_t i = 0; i\
    \ < siz; i++) {\n            tree[i + siz] = def[i];\n        }\n        for (int32_t\
    \ i = siz - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i\
    \ << 1) + 1]);\n        }\n    }\n    void set(int32_t p, T v) {\n        p +=\
    \ siz;\n        tree[p] = v;\n        p >>= 1;\n        while (p > 0) {\n    \
    \        tree[p] = M::op(tree[p << 1], tree[(p << 1) + 1]);\n            p >>=\
    \ 1;\n        }\n    }\n    T get(int32_t p) { return tree[p + siz]; }\n    T\
    \ prod(int32_t lf, int32_t ri) {\n        lf += siz;\n        ri += siz;\n   \
    \     T rel = M::e;\n        T rer = M::e;\n        while (lf < ri) {\n      \
    \      if (lf & 1) {\n                rel = M::op(rel, tree[lf]);\n          \
    \      lf++;\n            }\n            if (ri & 1) {\n                ri--;\n\
    \                rer = M::op(tree[ri], rer);\n            }\n            lf >>=\
    \ 1;\n            ri >>= 1;\n        }\n        return M::op(rel, rer);\n    }\n\
    \    int32_t max_right(int32_t lf, auto f) {\n        lf += siz;\n        int32_t\
    \ ri = siz << 1;\n        std::queue<int32_t> lfp;\n        std::stack<int32_t>\
    \ rip;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!lfp.empty()) {\n            int32_t i = lfp.front();\n      \
    \      lfp.pop();\n            if (!f(M::op(val, tree[i]))) {\n              \
    \  while (i < siz) {\n                    i <<= 1;\n                    if (f(M::op(val,\
    \ tree[i]))) {\n                        val = M::op(val, tree[i]);\n         \
    \               i++;\n                    }\n                }\n             \
    \   return i - siz;\n            }\n            val = M::op(val, tree[i]);\n \
    \       }\n        while (!rip.empty()) {\n            int32_t i = rip.top();\n\
    \            rip.pop();\n            if (!f(M::op(val, tree[i]))) {\n        \
    \        while (i < siz) {\n                    i <<= 1;\n                   \
    \ if (f(M::op(val, tree[i]))) {\n                        val = M::op(val, tree[i]);\n\
    \                        i++;\n                    }\n                }\n    \
    \            return i - siz;\n            }\n            val = M::op(val, tree[i]);\n\
    \        }\n        return siz;\n    }\n    int32_t min_left(int32_t ri, auto\
    \ f) {\n        ri += siz;\n        int32_t lf = siz;\n        std::queue<int32_t>\
    \ rip;\n        std::stack<int32_t> lfp;\n        while (lf < ri) {\n        \
    \    if (lf & 1) {\n                lfp.push(lf);\n                lf++;\n   \
    \         }\n            if (ri & 1) {\n                ri--;\n              \
    \  rip.push(ri);\n            }\n            lf >>= 1;\n            ri >>= 1;\n\
    \        }\n        T val = M::e;\n        while (!rip.empty()) {\n          \
    \  int32_t i = rip.front();\n            rip.pop();\n            if (!f(M::op(val,\
    \ tree[i]))) {\n                while (i < siz) {\n                    i <<= 1;\n\
    \                    i++;\n                    if (f(M::op(tree[i], val))) {\n\
    \                        val = M::op(tree[i], val);\n                        i--;\n\
    \                    }\n                }\n                return i - siz + 1;\n\
    \            }\n            val = M::op(tree[i], val);\n        }\n        while\
    \ (!lfp.empty()) {\n            int32_t i = lfp.top();\n            lfp.pop();\n\
    \            if (!f(M::op(val, tree[i]))) {\n                while (i < siz) {\n\
    \                    i <<= 1;\n                    i++;\n                    if\
    \ (f(M::op(tree[i], val))) {\n                        val = M::op(tree[i], val);\n\
    \                        i--;\n                    }\n                }\n    \
    \            return i - siz + 1;\n            }\n            val = M::op(tree[i],\
    \ val);\n        }\n        return 0;\n    }\n    int32_t size() { return siz;\
    \ }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <queue>\n#include <stack>\n#include\
    \ <vector>\ntemplate <class M>\nstruct SegmentTree {\n    using T = typename M::T;\n\
    \    int32_t siz;\n    std::vector<T> tree;\n    SegmentTree(int32_t sz) {\n \
    \       siz = sz;\n        tree = std::vector<T>(siz << 1, M::e);\n    }\n   \
    \ SegmentTree(std::vector<T> def) {\n        siz = def.size();\n        tree =\
    \ std::vector<T>(siz << 1, M::e);\n        for (int32_t i = 0; i < siz; i++) {\n\
    \            tree[i + siz] = def[i];\n        }\n        for (int32_t i = siz\
    \ - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i << 1)\
    \ + 1]);\n        }\n    }\n    void set(int32_t p, T v) {\n        p += siz;\n\
    \        tree[p] = v;\n        p >>= 1;\n        while (p > 0) {\n           \
    \ tree[p] = M::op(tree[p << 1], tree[(p << 1) + 1]);\n            p >>= 1;\n \
    \       }\n    }\n    T get(int32_t p) { return tree[p + siz]; }\n    T prod(int32_t\
    \ lf, int32_t ri) {\n        lf += siz;\n        ri += siz;\n        T rel = M::e;\n\
    \        T rer = M::e;\n        while (lf < ri) {\n            if (lf & 1) {\n\
    \                rel = M::op(rel, tree[lf]);\n                lf++;\n        \
    \    }\n            if (ri & 1) {\n                ri--;\n                rer\
    \ = M::op(tree[ri], rer);\n            }\n            lf >>= 1;\n            ri\
    \ >>= 1;\n        }\n        return M::op(rel, rer);\n    }\n    int32_t max_right(int32_t\
    \ lf, auto f) {\n        lf += siz;\n        int32_t ri = siz << 1;\n        std::queue<int32_t>\
    \ lfp;\n        std::stack<int32_t> rip;\n        while (lf < ri) {\n        \
    \    if (lf & 1) {\n                lfp.push(lf);\n                lf++;\n   \
    \         }\n            if (ri & 1) {\n                ri--;\n              \
    \  rip.push(ri);\n            }\n            lf >>= 1;\n            ri >>= 1;\n\
    \        }\n        T val = M::e;\n        while (!lfp.empty()) {\n          \
    \  int32_t i = lfp.front();\n            lfp.pop();\n            if (!f(M::op(val,\
    \ tree[i]))) {\n                while (i < siz) {\n                    i <<= 1;\n\
    \                    if (f(M::op(val, tree[i]))) {\n                        val\
    \ = M::op(val, tree[i]);\n                        i++;\n                    }\n\
    \                }\n                return i - siz;\n            }\n         \
    \   val = M::op(val, tree[i]);\n        }\n        while (!rip.empty()) {\n  \
    \          int32_t i = rip.top();\n            rip.pop();\n            if (!f(M::op(val,\
    \ tree[i]))) {\n                while (i < siz) {\n                    i <<= 1;\n\
    \                    if (f(M::op(val, tree[i]))) {\n                        val\
    \ = M::op(val, tree[i]);\n                        i++;\n                    }\n\
    \                }\n                return i - siz;\n            }\n         \
    \   val = M::op(val, tree[i]);\n        }\n        return siz;\n    }\n    int32_t\
    \ min_left(int32_t ri, auto f) {\n        ri += siz;\n        int32_t lf = siz;\n\
    \        std::queue<int32_t> rip;\n        std::stack<int32_t> lfp;\n        while\
    \ (lf < ri) {\n            if (lf & 1) {\n                lfp.push(lf);\n    \
    \            lf++;\n            }\n            if (ri & 1) {\n               \
    \ ri--;\n                rip.push(ri);\n            }\n            lf >>= 1;\n\
    \            ri >>= 1;\n        }\n        T val = M::e;\n        while (!rip.empty())\
    \ {\n            int32_t i = rip.front();\n            rip.pop();\n          \
    \  if (!f(M::op(val, tree[i]))) {\n                while (i < siz) {\n       \
    \             i <<= 1;\n                    i++;\n                    if (f(M::op(tree[i],\
    \ val))) {\n                        val = M::op(tree[i], val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(tree[i], val);\n      \
    \  }\n        while (!lfp.empty()) {\n            int32_t i = lfp.top();\n   \
    \         lfp.pop();\n            if (!f(M::op(val, tree[i]))) {\n           \
    \     while (i < siz) {\n                    i <<= 1;\n                    i++;\n\
    \                    if (f(M::op(tree[i], val))) {\n                        val\
    \ = M::op(tree[i], val);\n                        i--;\n                    }\n\
    \                }\n                return i - siz + 1;\n            }\n     \
    \       val = M::op(tree[i], val);\n        }\n        return 0;\n    }\n    int32_t\
    \ size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2024-10-22 20:31:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
  - Verify/verify-yuki/650.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
documentation_of: DataStructure/SegmentTree.hpp
layout: document
title: Segment Tree
---

## 関数の設定
```cpp
struct M {
    using T;
    static T op(T x, T y) {}
    static inline T e;
};
```
* `T`: モノイドの型です。
* `T op(T x,T y)`: 演算です。モノイドであることを要求します。
* `T e`: 単位元です。