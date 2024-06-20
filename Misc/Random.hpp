#pragma once
#include <climits>
#include <cstdint>
uint32_t rand_32bit() {
    static uint32_t x2 = 12345;
    static uint32_t x3 = 0xcafef00d;
    static uint64_t c_x1 = uint64_t(0xd15ea5e5) << 32 | 23456;
    uint64_t x = (uint64_t)(x3) * 3487286589;
    uint32_t result = (x3 ^ x2) + ((uint32_t)(c_x1) ^ (uint32_t)(x >> 32));
    x3 = x2;
    x2 = (uint32_t)(c_x1);
    c_x1 = x + (c_x1 >> 32);
    return result;
}

uint64_t rand_64bit() {
    static uint64_t x2 = 12345;
    static uint64_t x3 = 0xcafef00dd15ea5e5;
    static unsigned __int128 c_x1 =
        (unsigned __int128)(0xd15ea5e5) << 64 | 23456;
    unsigned __int128 x = (uint64_t)(x3) * 0xfeb344657c0af413;
    uint64_t result = (x3 ^ x2) + ((uint32_t)(c_x1) ^ (uint32_t)(x >> 64));
    x3 = x2;
    x2 = (uint64_t)(c_x1);
    c_x1 = x + (c_x1 >> 64);
    return result;
}

inline int32_t randint(int32_t l, int32_t r) {
    return l + (((int64_t)rand_32bit() * (r - l + 1)) >> 32);
}

inline int64_t randlong(int64_t l, int64_t r) {
    return l + (((unsigned __int128)rand_64bit() * (r - l + 1)) >> 32);
}

inline float rand01() { return (float)rand_32bit() / UINT_MAX; }

inline bool randprob(float prob) { return rand_32bit() < UINT_MAX * prob; }