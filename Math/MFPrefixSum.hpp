#include <math.h>

#include <cstdint>
#include <vector>

#include "EnumeratePrimes.hpp"
#include "EnumerateQuotients.hpp"
template <class T>
struct MFPrefixSum {
    uint64_t n;
    uint64_t sqrtN;
    std::vector<int64_t> Q;
    std::vector<int32_t> primes;
    int32_t sz;
    mf_prefix_sum(uint64_t N) {
        n = N;
        sqrtN = sqrt(n);
        while ((sqrtN + 1) * (sqrtN + 1) <= n) sqrtN++;
        while (sqrtN * sqrtN > n) sqrtN--;
        Q = enumerate_quotients(n);
        sz = Q.size();
        primes = enumerate_primes(sqrtN);
    }
    std::vector<T> pi_table() {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sz; i++) {
            dp[i] = Q[i] - 1;
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= 0; i--) {
                if (Q[i] < x * x) break;
                if (Q[i] / x <= sqrtN) {
                    dp[i] -= (dp[Q[i] / x - 1] - dp[x - 2]);
                } else {
                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]);
                }
            }
        }
        return dp;
    }
    std::vector<T> prime_sum_table() {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sz; i++) {
            dp[i] = T(Q[i]) * (Q[i] + 1) / 2 - 1;
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= 0; i--) {
                if (Q[i] < x * x) break;
                if (Q[i] / x <= sqrtN) {
                    dp[i] -= (dp[Q[i] / x - 1] - dp[x - 2]) * x;
                } else {
                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]) * x;
                }
            }
        }
        return dp;
    }
    std::vector<T> prefix_prime_table(auto f) {
        std::vector<T> dp(sz);
        for (int32_t i = 0; i < sz; i++) {
            dp[i] = f(Q[i]);
        }
        for (int64_t x : primes) {
            for (int32_t i = sz - 1; i >= 0; i--) {
                if (Q[i] < x * x) break;
                if (Q[i] / x <= sqrtN) {
                    dp[i] -= (dp[Q[i] / x - 1] - dp[x - 2]) * (f(x) - f(x - 1));
                } else {
                    dp[i] -=
                        (dp[sz - (sz - i) * x] - dp[x - 2]) * (f(x) - f(x - 1));
                }
            }
        }
        return dp;
    }
    std::vector<T> run(std::vector<T> table, auto f) {
        std::vector<T> dp = table;
        for (auto it = primes.rbegin(); it != primes.rend(); it++) {
            int64_t x = *it;
            for (int32_t i = sz - 1; i >= 0; i--) {
                if (Q[i] < x * x) break;
                int64_t xp = x;
                int32_t c = 1;
                while (xp * x <= Q[i]) {
                    if (Q[i] / xp <= sqrtN) {
                        dp[i] += f(x, c) * (dp[Q[i] / xp - 1] - table[x - 1]) +
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
        }
        for (int32_t i = 0; i < sz; i++) {
            dp[i] += 1;
        }
        return dp;
    }
};
