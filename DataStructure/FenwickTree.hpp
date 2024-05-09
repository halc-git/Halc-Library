#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
template <class T>
struct FenwickTree {
    std::vector<T> tree;
    int32_t start = 1;
    size_t siz;
    constexpr inline int32_t _bit_length(int32_t x) {
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x = (x & 0x55555555) + (x >> 1 & 0x55555555);
        x = (x & 0x33333333) + (x >> 2 & 0x33333333);
        x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);
        x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);
        return (x & 0x0000ffff) + (x >> 16);
    }
    FenwickTree(int32_t sz) {
        siz = sz;
        tree.resize(sz + 1, 0);
        start = 1 << (_bit_length(siz) - 1);
    }
    FenwickTree(std::vector<T> def) {
        siz = def.size();
        tree.resize(siz + 1, 0);
        start = 1 << (_bit_length(siz) - 1);
        for (int32_t i = 0; i < siz; i++) {
            tree[i + 1] += def[i];
            if (i + (i & -i) <= siz) {
                tree[i + (i & -i)] += tree[i];
            }
        }
    }
    void add(int32_t pos, T val) {
        pos++;
        while (pos <= siz) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    T _sum(int32_t pos) {
        T ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
    T sum(int32_t lf, int32_t ri) { return _sum(ri) - _sum(lf); }
    int32_t lower_bound(T w) {
        if (w <= 0) return 0;
        int32_t now = 0;
        T val = 0;
        for (int32_t i = start; i > 0; i >>= 1) {
            if (now + i <= siz && val + tree[now + i] < w) {
                now += i;
                val += tree[now];
            }
        }
        return now + 1;
    }
    size_t size() { return siz; }
};