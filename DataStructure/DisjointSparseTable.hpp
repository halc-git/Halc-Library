#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
template <class M>
struct DisjointSparseTable {
    using T = typename M::T;
    size_t siz;
    std::vector<T> table;
    DisjointSparseTable(std::vector<T> def) {
        siz = def.size();
        int32_t bitlen = 0;
        while (1 << bitlen <= siz - 1) bitlen++;
        swap(table, def);
        table.resize(siz * std::max(1, bitlen));
        for (int32_t i = siz; i < siz * bitlen; i++) {
            table[i] = table[i % siz];
        }
        int32_t index = siz;
        for (int32_t i = 1; i < bitlen; i++) {
            for (int32_t j = 0; j < siz; j++) {
                if (((j >> i) << i) == j) continue;
                if ((j >> i) & 1) {
                    table[j + index] =
                        M::op(table[j - 1 + index], table[j, index]);
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
        int32_t nbl = 0;
        while (1 << (nbl + 1) <= (lf ^ (ri - 1))) nbl++;
        int32_t pos = nbl * siz;
        return M::op(table[pos + lf], table[pos + ri - 1]);
    }
};