#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
template <class M>
struct DisjointSparseTable {
    using T = typename M::T;
    size_t siz;
    std::vector<T> table;
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
    DisjointSparseTable(std::vector<T> def) {
        siz = def.size();
        int32_t bitlen = _bit_length(siz - 1);
        table.resize(siz * std::max(1, bitlen));
        for (int32_t i = 0; i < table.size(); i++) {
            table[i] = def[i % siz];
        }
        int32_t index = siz;
        for (int32_t i = 1; i < bitlen; i++) {
            for (int32_t j = 0; j < siz; j++) {
                if (((j >> i) << i) == j) continue;
                if ((j >> i) & 1) {
                    table[j + index] =
                        M::op(table[j - 1 + index], table[j + index]);
                } else {
                    int32_t pos =
                        ((j >> i) << i) + ((1 << i) - 1) - (j & ((1 << i) - 1));
                    if (pos < siz) {
                        table[pos + index] =
                            M::op(table[pos + index], table[pos + 1 + index]);
                    }
                }
            }
            index += siz;
        }
    }
    T get(int32_t p) { return table[p]; }
    T prod(int32_t lf, int32_t ri) {
        if (lf == ri) return M::e;
        if (lf + 1 == ri) return table[lf];
        int32_t pos = (_bit_length(lf ^ (ri - 1)) - 1) * siz;
        return M::op(table[pos + lf], table[pos + ri - 1]);
    }
};