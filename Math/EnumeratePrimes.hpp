#pragma once
#include <cstdint>
#include <vector>
std::vector<int32_t> enumerate_primes(int32_t n) {
    std::vector<bool> flg((n + 1) >> 1, true);
    std::vector<int32_t> ret = {2};
    for (int32_t i = 3; i <= n; i += 2) {
        if (!flg[i >> 1]) continue;
        ret.emplace_back(i);
        if (i * i > n) {
            for (int32_t j = i + 2; j <= n; j += 2) {
                if (flg[j >> 1]) ret.emplace_back(j);
            }
            break;
        }
        for (int32_t j = i * i; j <= n; j += i << 1) {
            flg[j >> 1] = false;
        }
    }
    while (!ret.empty() && ret.back() > n) ret.pop_back();
    return ret;
}