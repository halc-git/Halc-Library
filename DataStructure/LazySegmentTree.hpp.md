---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj/2667.test.cpp
    title: Verify/verify-aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/range_affine_point_get.test.cpp
    title: Verify/verify-yosupo-datastructure/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/LazySegmentTree.hpp\"\n#include <bit>\n#include\
    \ <cstdint>\n#include <queue>\n#include <stack>\n#include <vector>\ntemplate <class\
    \ M>\nstruct LazySegmentTree {\n    using T = typename M::T;\n    using F = typename\
    \ M::F;\n    int32_t siz;\n    std::vector<T> tree;\n    std::vector<F> del;\n\
    \    LazySegmentTree(int32_t sz) {\n        siz = sz;\n        tree = std::vector<T>(siz\
    \ << 1, M::e);\n        del = std::vector<F>(siz << 1, M::id);\n    }\n    LazySegmentTree(std::vector<T>\
    \ def) {\n        siz = def.size();\n        tree = std::vector<T>(siz << 1, M::e);\n\
    \        del = std::vector<F>(siz << 1, M::id);\n        for (int32_t i = 0; i\
    \ < siz; i++) {\n            tree[i + siz] = def[i];\n        }\n        for (int32_t\
    \ i = siz - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i\
    \ << 1) + 1]);\n        }\n    }\n    inline T _get(int32_t pos) { return tree[pos];\
    \ }\n    void _calc(int32_t p) {\n        p >>= 1;\n        while (p > 0) {\n\
    \            tree[p] = M::op(_get(p << 1), _get((p << 1) + 1));\n            p\
    \ >>= 1;\n        }\n    }\n    inline void _del_segment(int32_t p) {\n      \
    \  tree[p << 1] = M::mapp(del[p], tree[p << 1]);\n        del[p << 1] = M::comp(del[p],\
    \ del[p << 1]);\n        tree[(p << 1) + 1] = M::mapp(del[p], tree[(p << 1) +\
    \ 1]);\n        del[(p << 1) + 1] = M::comp(del[p], del[(p << 1) + 1]);\n    \
    \    del[p] = M::id;\n    }\n    void _delay(int32_t p) {\n        int32_t length\
    \ = 32 - std::countl_zero((uint32_t)p);\n        for (int32_t i = length - 1;\
    \ i >= 1; i--) {\n            _del_segment(p >> i);\n        }\n    }\n    void\
    \ set(int32_t p, T v) {\n        p += siz;\n        _delay(p);\n        tree[p]\
    \ = v;\n        del[p] = M::id;\n        _calc(p);\n    }\n    T get(int32_t p)\
    \ {\n        _delay(p + siz);\n        return _get(p + siz);\n    }\n    void\
    \ apply(int32_t lf, int32_t ri, F f) {\n        lf += siz;\n        ri += siz;\n\
    \        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n        int32_t\
    \ dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n        _delay(dr\
    \ - 1);\n        while (lf < ri) {\n            if (lf & 1) {\n              \
    \  tree[lf] = M::mapp(f, tree[lf]);\n                del[lf] = M::comp(f, del[lf]);\n\
    \                lf++;\n            }\n            if (ri & 1) {\n           \
    \     ri--;\n                tree[ri] = M::mapp(f, tree[ri]);\n              \
    \  del[ri] = M::comp(f, del[ri]);\n            }\n            lf >>= 1;\n    \
    \        ri >>= 1;\n        }\n        _calc(dl);\n        _calc(dr - 1);\n  \
    \  }\n    T prod(int32_t lf, int32_t ri) {\n        lf += siz;\n        ri +=\
    \ siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n       \
    \ int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        T rel = M::e;\n        T rer = M::e;\n     \
    \   while (lf < ri) {\n            if (lf & 1) {\n                rel = M::op(rel,\
    \ _get(lf));\n                lf++;\n            }\n            if (ri & 1) {\n\
    \                ri--;\n                rer = M::op(_get(ri), rer);\n        \
    \    }\n            lf >>= 1;\n            ri >>= 1;\n        }\n        return\
    \ M::op(rel, rer);\n    }\n    template <bool (*f)(T)>\n    int32_t max_right(int\
    \ lf) {\n        return max_right(lf, [](T x) { return f(x); });\n    }\n    template\
    \ <class F>\n    int32_t max_right(int32_t lf, F f) {\n        lf += siz;\n  \
    \      int32_t ri = siz << 1;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n\
    \        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        std::queue<int32_t> lfp;\n        std::stack<int32_t>\
    \ rip;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!lfp.empty()) {\n            int32_t i = lfp.front();\n      \
    \      lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n              \
    \  while (i < siz) {\n                    _del_segment(i);\n                 \
    \   i <<= 1;\n                    if (f(M::op(val, _get(i)))) {\n            \
    \            val = M::op(val, _get(i));\n                        i++;\n      \
    \              }\n                }\n                return i - siz;\n       \
    \     }\n            val = M::op(val, _get(i));\n        }\n        while (!rip.empty())\
    \ {\n            int32_t i = rip.top();\n            rip.pop();\n            if\
    \ (!f(M::op(val, _get(i)))) {\n                while (i < siz) {\n           \
    \         _del_segment(i);\n                    i <<= 1;\n                   \
    \ if (f(M::op(val, _get(i)))) {\n                        val = M::op(val, _get(i));\n\
    \                        i++;\n                    }\n                }\n    \
    \            return i - siz;\n            }\n            val = M::op(val, _get(i));\n\
    \        }\n        return siz;\n    }\n    template <bool (*f)(T)>\n    int32_t\
    \ min_left(int ri) {\n        return min_left(ri, [](T x) { return f(x); });\n\
    \    }\n    template <class F>\n    int32_t min_left(int32_t ri, F f) {\n    \
    \    ri += siz;\n        int32_t lf = siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n\
    \        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        std::queue<int32_t> rip;\n        std::stack<int32_t>\
    \ lfp;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!rip.empty()) {\n            int32_t i = rip.front();\n      \
    \      rip.pop();\n            if (!f(M::op(val, _get(i)))) {\n              \
    \  while (i < siz) {\n                    _del_segment(i);\n                 \
    \   i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        while (!lfp.empty()) {\n            int32_t i = lfp.top();\n   \
    \         lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n           \
    \     while (i < siz) {\n                    _del_segment(i);\n              \
    \      i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        return 0;\n    }\n    int32_t size() { return siz; }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cstdint>\n#include <queue>\n#include\
    \ <stack>\n#include <vector>\ntemplate <class M>\nstruct LazySegmentTree {\n \
    \   using T = typename M::T;\n    using F = typename M::F;\n    int32_t siz;\n\
    \    std::vector<T> tree;\n    std::vector<F> del;\n    LazySegmentTree(int32_t\
    \ sz) {\n        siz = sz;\n        tree = std::vector<T>(siz << 1, M::e);\n \
    \       del = std::vector<F>(siz << 1, M::id);\n    }\n    LazySegmentTree(std::vector<T>\
    \ def) {\n        siz = def.size();\n        tree = std::vector<T>(siz << 1, M::e);\n\
    \        del = std::vector<F>(siz << 1, M::id);\n        for (int32_t i = 0; i\
    \ < siz; i++) {\n            tree[i + siz] = def[i];\n        }\n        for (int32_t\
    \ i = siz - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i\
    \ << 1) + 1]);\n        }\n    }\n    inline T _get(int32_t pos) { return tree[pos];\
    \ }\n    void _calc(int32_t p) {\n        p >>= 1;\n        while (p > 0) {\n\
    \            tree[p] = M::op(_get(p << 1), _get((p << 1) + 1));\n            p\
    \ >>= 1;\n        }\n    }\n    inline void _del_segment(int32_t p) {\n      \
    \  tree[p << 1] = M::mapp(del[p], tree[p << 1]);\n        del[p << 1] = M::comp(del[p],\
    \ del[p << 1]);\n        tree[(p << 1) + 1] = M::mapp(del[p], tree[(p << 1) +\
    \ 1]);\n        del[(p << 1) + 1] = M::comp(del[p], del[(p << 1) + 1]);\n    \
    \    del[p] = M::id;\n    }\n    void _delay(int32_t p) {\n        int32_t length\
    \ = 32 - std::countl_zero((uint32_t)p);\n        for (int32_t i = length - 1;\
    \ i >= 1; i--) {\n            _del_segment(p >> i);\n        }\n    }\n    void\
    \ set(int32_t p, T v) {\n        p += siz;\n        _delay(p);\n        tree[p]\
    \ = v;\n        del[p] = M::id;\n        _calc(p);\n    }\n    T get(int32_t p)\
    \ {\n        _delay(p + siz);\n        return _get(p + siz);\n    }\n    void\
    \ apply(int32_t lf, int32_t ri, F f) {\n        lf += siz;\n        ri += siz;\n\
    \        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n        int32_t\
    \ dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n        _delay(dr\
    \ - 1);\n        while (lf < ri) {\n            if (lf & 1) {\n              \
    \  tree[lf] = M::mapp(f, tree[lf]);\n                del[lf] = M::comp(f, del[lf]);\n\
    \                lf++;\n            }\n            if (ri & 1) {\n           \
    \     ri--;\n                tree[ri] = M::mapp(f, tree[ri]);\n              \
    \  del[ri] = M::comp(f, del[ri]);\n            }\n            lf >>= 1;\n    \
    \        ri >>= 1;\n        }\n        _calc(dl);\n        _calc(dr - 1);\n  \
    \  }\n    T prod(int32_t lf, int32_t ri) {\n        lf += siz;\n        ri +=\
    \ siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n       \
    \ int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        T rel = M::e;\n        T rer = M::e;\n     \
    \   while (lf < ri) {\n            if (lf & 1) {\n                rel = M::op(rel,\
    \ _get(lf));\n                lf++;\n            }\n            if (ri & 1) {\n\
    \                ri--;\n                rer = M::op(_get(ri), rer);\n        \
    \    }\n            lf >>= 1;\n            ri >>= 1;\n        }\n        return\
    \ M::op(rel, rer);\n    }\n    template <bool (*f)(T)>\n    int32_t max_right(int\
    \ lf) {\n        return max_right(lf, [](T x) { return f(x); });\n    }\n    template\
    \ <class F>\n    int32_t max_right(int32_t lf, F f) {\n        lf += siz;\n  \
    \      int32_t ri = siz << 1;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n\
    \        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        std::queue<int32_t> lfp;\n        std::stack<int32_t>\
    \ rip;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!lfp.empty()) {\n            int32_t i = lfp.front();\n      \
    \      lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n              \
    \  while (i < siz) {\n                    _del_segment(i);\n                 \
    \   i <<= 1;\n                    if (f(M::op(val, _get(i)))) {\n            \
    \            val = M::op(val, _get(i));\n                        i++;\n      \
    \              }\n                }\n                return i - siz;\n       \
    \     }\n            val = M::op(val, _get(i));\n        }\n        while (!rip.empty())\
    \ {\n            int32_t i = rip.top();\n            rip.pop();\n            if\
    \ (!f(M::op(val, _get(i)))) {\n                while (i < siz) {\n           \
    \         _del_segment(i);\n                    i <<= 1;\n                   \
    \ if (f(M::op(val, _get(i)))) {\n                        val = M::op(val, _get(i));\n\
    \                        i++;\n                    }\n                }\n    \
    \            return i - siz;\n            }\n            val = M::op(val, _get(i));\n\
    \        }\n        return siz;\n    }\n    template <bool (*f)(T)>\n    int32_t\
    \ min_left(int ri) {\n        return min_left(ri, [](T x) { return f(x); });\n\
    \    }\n    template <class F>\n    int32_t min_left(int32_t ri, F f) {\n    \
    \    ri += siz;\n        int32_t lf = siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n\
    \        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        std::queue<int32_t> rip;\n        std::stack<int32_t>\
    \ lfp;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!rip.empty()) {\n            int32_t i = rip.front();\n      \
    \      rip.pop();\n            if (!f(M::op(val, _get(i)))) {\n              \
    \  while (i < siz) {\n                    _del_segment(i);\n                 \
    \   i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        while (!lfp.empty()) {\n            int32_t i = lfp.top();\n   \
    \         lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n           \
    \     while (i < siz) {\n                    _del_segment(i);\n              \
    \      i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        return 0;\n    }\n    int32_t size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2024-05-14 18:42:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-aoj/2667.test.cpp
  - Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/range_affine_point_get.test.cpp
documentation_of: DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.hpp
- /library/DataStructure/LazySegmentTree.hpp.html
title: DataStructure/LazySegmentTree.hpp
---
