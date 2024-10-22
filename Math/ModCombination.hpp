#pragma once
#include <cstdint>
#include <vector>
template <typename T>
struct ModCombination {
    std::vector<T> fact = {1}, rev{1};
    ModCombination(uint32_t sz = 0) {
        fact.reserve(sz+1);
        rev.reserve(sz+1);
    }
    void resize(uint32_t sz) {
        sz++;
        if (fact.size() >= sz) return;
        uint32_t before = fact.size();
        fact.resize(sz);
        rev.resize(sz);
        for (uint32_t i = before; i < sz; i++) {
            fact[i] = fact[i - 1] * i;
            rev[i] = rev[i - 1] / i;
        }
    }
    T comb(int32_t n, int32_t k) {
        if (n < 0 || k < 0 || n < k) return 0;
        resize(n);
        return fact[n] * rev[n - k] * rev[k];
    }
    T perm(int32_t n, int32_t k) {
        if (n < 0 || k < 0 || n < k) return 0;
        resize(n);
        return fact[n] * rev[n - k];
    }
    T multi_comb(int32_t n, int32_t k) {
        if (k == 0) return 1;
        return comb(n + k - 1, k);
    }
};