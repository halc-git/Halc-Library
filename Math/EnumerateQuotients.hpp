#pragma once
#include <math.h>

#include <cstdint>
#include <numeric>
#include <vector>
std::vector<int64_t> enumerate_quotients(uint64_t n) {
    uint64_t x = sqrt(n);
    while ((x + 1) * (x + 1) <= n) x++;
    while (x * x > n) x--;
    std::vector<int64_t> ret(x);
    ret.reserve(x * 2);
    std::iota(ret.begin(), ret.end(), 1);
    for (int32_t i = x; i >= 1; i--) {
        if (ret.back() != n / i) ret.emplace_back(n / i);
    }
    return ret;
}