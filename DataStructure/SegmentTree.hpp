#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>
template <class M>
struct SegmentTree {
    using T = typename M::T;
    int32_t siz;
    std::vector<T> tree;
    SegmentTree(int32_t sz) {
        siz = sz;
        tree = std::vector<T>(siz << 1, M::e);
    }
    SegmentTree(std::vector<T> def) {
        siz = def.size();
        tree = vector<T>(siz << 1, M::e);
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
    template <bool (*f)(T)>
    int32_t max_right(int lf) {
        return max_right(lf, [](T x) { return f(x); });
    }
    template <class F>
    int32_t max_right(int32_t lf, F f) {
        lf += siz;
        int32_t ri = siz << 1;
        std::vector<int32_t> lfp, rip;
        while (lf < ri) {
            if (lf & 1) {
                lfp.emplace_back(lf);
                lf++;
            }
            if (ri & 1) {
                ri--;
                rip.emplace_back(ri);
            }
            lf >>= 1;
            ri >>= 1;
        }
        T val = M::e;
        for (int32_t i : lfp) {
            if (!f(M::op(val, tree[i]))) {
                while (i < siz) {
                    i <<= 1;
                    if (f(M::op(val, tree[i]))) {
                        val = M::op(val, tree[i]);
                        i++;
                    }
                }
                return i - siz;
            }
            val = M::op(val, tree[i]);
        }
        std::reverse(rip.begin(), rip.end());
        for (int32_t i : rip) {
            if (!f(M::op(val, tree[i]))) {
                while (i < siz) {
                    i <<= 1;
                    if (f(M::op(val, tree[i]))) {
                        val = M::op(val, tree[i]);
                        i++;
                    }
                }
                return i - siz;
            }
            val = M::op(val, tree[i]);
        }
        return siz;
    }
    template <bool (*f)(T)>
    int32_t min_left(int ri) {
        return min_left(ri, [](T x) { return f(x); });
    }
    template <class F>
    int32_t min_left(int32_t ri, F f) {
        ri += siz;
        int32_t lf = siz;
        std::vector<int32_t> lfp, rip;
        while (lf < ri) {
            if (lf & 1) {
                lfp.emplace_back(lf);
                lf++;
            }
            if (ri & 1) {
                ri--;
                rip.emplace_back(ri);
            }
            lf >>= 1;
            ri >>= 1;
        }
        T val = M::e;
        for (int32_t i : rip) {
            if (!f(M::op(val, tree[i]))) {
                while (i < siz) {
                    i <<= 1;
                    i++;
                    if (f(M::op(tree[i], val))) {
                        val = M::op(tree[i], val);
                        i--;
                    }
                }
                return i - siz + 1;
            }
            val = M::op(tree[i], val);
        }
        std::reverse(lfp.begin(), lfp.end());
        for (int32_t i : lfp) {
            if (!f(M::op(val, tree[i]))) {
                while (i < siz) {
                    i <<= 1;
                    i++;
                    if (f(M::op(tree[i], val))) {
                        val = M::op(tree[i], val);
                        i--;
                    }
                }
                return i - siz + 1;
            }
            val = M::op(tree[i], val);
        }
        return 0;
    }
    size_t size() { return siz; }
};