#include <math.h>

#include <cstdint>
#include <vector>

#include "EnumeratePrimes.hpp"
template <class T>
struct MFPrefixSum {
    int64_t n;
    int64_t sqrtN;
    std::vector<int32_t> primes;
    int32_t sz;
    MFPrefixSum(uint64_t N) {
        n = N;
        sqrtN = sqrt(n);
        sz = sqrtN * 2;
        if (n / sqrtN == sqrtN) sz--;
        while ((sqrtN + 1) * (sqrtN + 1) <= n) sqrtN++;
        while (sqrtN * sqrtN > n) sqrtN--;
        primes = enumerate_primes(sqrtN);
    }
    std::vector<T> pi_table() {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sqrtN; i++) {
            dp[i] = i;
        }
        for (int32_t i = sqrtN; i < sz; i++) {
            dp[i] = n / (sz - i) - 1;
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= sqrtN; i--) {
                if (n < x * x * (sz - i)) break;
                if (sz - (sz - i) * x < sqrtN) {
                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]);
                } else {
                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]);
                }
            }
            for (int32_t i = sqrtN - 1; i >= 0; i--) {
                if (i + 1 < x * x) break;
                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]);
            }
        }
        return dp;
    }
    std::vector<T> prime_sum_table() {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sqrtN; i++) {
            dp[i] = T(i + 1) * T(i + 2) / 2 - 1;
        }
        for (int32_t i = sqrtN; i < sz; i++) {
            dp[i] = T(n / (sz - i)) * T(n / (sz - i) + 1) / 2 - 1;
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= sqrtN; i--) {
                if (n < x * x * (sz - i)) break;
                if (sz - (sz - i) * x < sqrtN) {
                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) * x;
                } else {
                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]) * x;
                }
            }
            for (int32_t i = sqrtN - 1; i >= 0; i--) {
                if (i + 1 < x * x) break;
                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) * x;
            }
        }
        return dp;
    }
    std::vector<T> prefix_prime_table(auto f) {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sqrtN; i++) {
            dp[i] = f(i + 1);
        }
        for (int32_t i = sqrtN; i < sz; i++) {
            dp[i] = f(n / (sz - i));
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= sqrtN; i--) {
                if (n < x * x * (sz - i)) break;
                if (sz - (sz - i) * x < sqrtN) {
                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) *
                             (f(x) - f(x - 1));
                } else {
                    dp[i] -=
                        (dp[sz - (sz - i) * x] - dp[x - 2]) * (f(x) - f(x - 1));
                }
            }
            for (int32_t i = sqrtN - 1; i >= 0; i--) {
                if (i + 1 < x * x) break;
                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) * (f(x) - f(x - 1));
            }
        }
        return dp;
    }
    std::vector<T> min25_sieve(std::vector<T> table, auto f) {
        std::vector<T> dp = table;
        for (auto it = primes.rbegin(); it != primes.rend(); it++) {
            int64_t x = *it;
            for (int32_t i = sz - 1; i >= sqrtN; i--) {
                if (n < x * x * (sz - i)) break;
                int64_t xp = x;
                int32_t c = 1;
                while (xp * x * (sz - i) <= n) {
                    if (sz - (sz - i) * xp < sqrtN) {
                        dp[i] += f(x, c) * (dp[n / (xp * (sz - i)) - 1] -
                                            table[x - 1]) +
                                 f(x, c + 1);
                    } else {
                        dp[i] +=
                            f(x, c) * (dp[sz - (sz - i) * xp] - table[x - 1]) +
                            f(x, c + 1);
                    }
                    c++;
                    xp *= x;
                }
            }
            for (int32_t i = sqrtN - 1; i >= 0; i--) {
                if (i + 1 < x * x) break;
                int64_t xp = x;
                int32_t c = 1;
                while (xp * x <= i + 1) {
                    dp[i] += f(x, c) * (dp[(i + 1) / xp - 1] - table[x - 1]) +
                             f(x, c + 1);
                    c++;
                    xp *= x;
                }
            }
        }
        for (int32_t i = 0; i < sz; i++) {
            dp[i] += 1;
        }
        return dp;
    }
};
