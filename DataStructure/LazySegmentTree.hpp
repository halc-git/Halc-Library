#pragma once
#include <bit>
#include <cstdint>
#include <queue>
#include <stack>
#include <vector>
template <class M>
struct LazySegmentTree {
    using T = typename M::T;
    using F = typename M::F;
    int32_t siz;
    std::vector<T> tree;
    std::vector<F> del;
    LazySegmentTree(int32_t sz) {
        siz = sz;
        tree = std::vector<T>(siz << 1, M::e);
        del = std::vector<F>(siz << 1, M::id);
    }
    LazySegmentTree(std::vector<T> def) {
        siz = def.size();
        tree = std::vector<T>(siz << 1, M::e);
        del = std::vector<F>(siz << 1, M::id);
        for (int32_t i = 0; i < siz; i++) {
            tree[i + siz] = def[i];
        }
        for (int32_t i = siz - 1; i > 0; i--) {
            tree[i] = M::op(tree[i << 1], tree[(i << 1) + 1]);
        }
    }
    inline T _get(int32_t pos) { return tree[pos]; }
    void _calc(int32_t p) {
        p >>= 1;
        while (p > 0) {
            tree[p] = M::op(_get(p << 1), _get((p << 1) + 1));
            p >>= 1;
        }
    }
    inline void _del_segment(int32_t p) {
        tree[p << 1] = M::mapp(del[p], tree[p << 1]);
        del[p << 1] = M::comp(del[p], del[p << 1]);
        tree[(p << 1) + 1] = M::mapp(del[p], tree[(p << 1) + 1]);
        del[(p << 1) + 1] = M::comp(del[p], del[(p << 1) + 1]);
        del[p] = M::id;
    }
    void _delay(int32_t p) {
        int32_t length = 32 - std::countl_zero((uint32_t)p);
        for (int32_t i = length - 1; i >= 1; i--) {
            _del_segment(p >> i);
        }
    }
    void set(int32_t p, T v) {
        p += siz;
        _delay(p);
        tree[p] = v;
        del[p] = M::id;
        _calc(p);
    }
    T get(int32_t p) {
        _delay(p + siz);
        return _get(p + siz);
    }
    void apply(int32_t lf, int32_t ri, F f) {
        lf += siz;
        ri += siz;
        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));
        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));
        _delay(dl);
        _delay(dr - 1);
        while (lf < ri) {
            if (lf & 1) {
                tree[lf] = M::mapp(f, tree[lf]);
                del[lf] = M::comp(f, del[lf]);
                lf++;
            }
            if (ri & 1) {
                ri--;
                tree[ri] = M::mapp(f, tree[ri]);
                del[ri] = M::comp(f, del[ri]);
            }
            lf >>= 1;
            ri >>= 1;
        }
        _calc(dl);
        _calc(dr - 1);
    }
    T prod(int32_t lf, int32_t ri) {
        lf += siz;
        ri += siz;
        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));
        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));
        _delay(dl);
        _delay(dr - 1);
        T rel = M::e;
        T rer = M::e;
        while (lf < ri) {
            if (lf & 1) {
                rel = M::op(rel, _get(lf));
                lf++;
            }
            if (ri & 1) {
                ri--;
                rer = M::op(_get(ri), rer);
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
        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));
        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));
        _delay(dl);
        _delay(dr - 1);
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
            if (!f(M::op(val, _get(i)))) {
                while (i < siz) {
                    _del_segment(i);
                    i <<= 1;
                    if (f(M::op(val, _get(i)))) {
                        val = M::op(val, _get(i));
                        i++;
                    }
                }
                return i - siz;
            }
            val = M::op(val, _get(i));
        }
        while (!rip.empty()) {
            int32_t i = rip.top();
            rip.pop();
            if (!f(M::op(val, _get(i)))) {
                while (i < siz) {
                    _del_segment(i);
                    i <<= 1;
                    if (f(M::op(val, _get(i)))) {
                        val = M::op(val, _get(i));
                        i++;
                    }
                }
                return i - siz;
            }
            val = M::op(val, _get(i));
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
        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));
        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));
        _delay(dl);
        _delay(dr - 1);
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
            if (!f(M::op(val, _get(i)))) {
                while (i < siz) {
                    _del_segment(i);
                    i <<= 1;
                    i++;
                    if (f(M::op(_get(i), val))) {
                        val = M::op(_get(i), val);
                        i--;
                    }
                }
                return i - siz + 1;
            }
            val = M::op(_get(i), val);
        }
        while (!lfp.empty()) {
            int32_t i = lfp.top();
            lfp.pop();
            if (!f(M::op(val, _get(i)))) {
                while (i < siz) {
                    _del_segment(i);
                    i <<= 1;
                    i++;
                    if (f(M::op(_get(i), val))) {
                        val = M::op(_get(i), val);
                        i--;
                    }
                }
                return i - siz + 1;
            }
            val = M::op(_get(i), val);
        }
        return 0;
    }
    int32_t size() { return siz; }
};