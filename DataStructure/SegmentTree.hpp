#pragma once
#include <cstdint>
#include <queue>
#include <stack>
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
        tree = std::vector<T>(siz << 1, M::e);
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
    T get(int32_t p) { return tree[p + siz]; }
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
    template <class F>
    int32_t max_right(int32_t lf, F f) {
        lf += siz;
        int32_t ri = siz << 1;
        std::queue<int32_t> lfp;
        std::stack<int32_t> rip;
        while (lf < ri) {
            if (lf & 1) {
                lfp.push(lf);
                lf++;
            }
            if (ri & 1) {
                ri--;
                rip.push(ri);
            }
            lf >>= 1;
            ri >>= 1;
        }
        T val = M::e;
        while (!lfp.empty()) {
            int32_t i = lfp.front();
            lfp.pop();
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
        while (!rip.empty()) {
            int32_t i = rip.top();
            rip.pop();
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
    template <class F>
    int32_t min_left(int32_t ri, F f) {
        ri += siz;
        int32_t lf = siz;
        std::queue<int32_t> rip;
        std::stack<int32_t> lfp;
        while (lf < ri) {
            if (lf & 1) {
                lfp.push(lf);
                lf++;
            }
            if (ri & 1) {
                ri--;
                rip.push(ri);
            }
            lf >>= 1;
            ri >>= 1;
        }
        T val = M::e;
        while (!rip.empty()) {
            int32_t i = rip.front();
            rip.pop();
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
        while (!lfp.empty()) {
            int32_t i = lfp.top();
            lfp.pop();
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
    int32_t size() { return siz; }
};