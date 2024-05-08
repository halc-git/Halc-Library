#pragma once
#include <cstdint>
#include <vector>
template <class M>
struct SegmentTree {
    using T = typename M::T;
    int32_t siz;
    std::vector<T> tree;
    SegmentTree(int32_t sz) {
        siz = sz;
        tree = std::vector<T>(siz * 2, M::e);
    }
    SegmentTree(std::vector<T> def) {
        siz = def.size();
        tree = vector<T>(siz * 2, M::e);
        for (int32_t i = 0; i < siz; i++) {
            tree[i + siz] = def[i];
        }
        for (int32_t i = siz - 1; i > 0; i--) {
            tree[i] = M::op(tree[i << 1], tree[(i << 1) + 1]);
        }
    }
    void set(int32_t p, T v) {
        p += siz;
        tree[p] = v;
        p >>= 1;
        while (p > 0) {
            tree[p] = M::op(tree[p << 1], tree[(p << 1) + 1]);
            p >>= 1;
        }
    }
    T prod(int32_t lf, int32_t ri) {
        lf += siz;
        ri += siz;
        T rel = M::e;
        T rer = M::e;
        while (lf < ri) {
            if (lf & 1) {
                rel = M::op(rel, tree[lf]);
                lf++;
            }
            if (ri & 1) {
                ri--;
                rer = M::op(tree[ri], rer);
            }
            lf >>= 1;
            ri >>= 1;
        }
        return M::op(rel, rer);
    }
    size_t size() { return siz; }
};