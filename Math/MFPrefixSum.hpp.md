---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/EnumeratePrimes.hpp
    title: Math/EnumeratePrimes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
    title: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/MFPrefixSum.hpp\"\n#include <math.h>\n\n#include <cstdint>\n\
    #include <vector>\n\n#line 4 \"Math/EnumeratePrimes.hpp\"\nstd::vector<int32_t>\
    \ enumerate_primes(int32_t n) {\n    std::vector<bool> flg((n + 1) >> 1, true);\n\
    \    std::vector<int32_t> ret = {2};\n    for (int32_t i = 3; i <= n; i += 2)\
    \ {\n        if (!flg[i >> 1]) continue;\n        ret.emplace_back(i);\n     \
    \   if (i * i > n) {\n            for (int32_t j = i + 2; j <= n; j += 2) {\n\
    \                if (flg[j >> 1]) ret.emplace_back(j);\n            }\n      \
    \      break;\n        }\n        for (int32_t j = i * i; j <= n; j += i << 1)\
    \ {\n            flg[j >> 1] = false;\n        }\n    }\n    while (!ret.empty()\
    \ && ret.back() > n) ret.pop_back();\n    return ret;\n}\n#line 7 \"Math/MFPrefixSum.hpp\"\
    \ntemplate <class T>\nstruct MFPrefixSum {\n    int64_t n;\n    int64_t sqrtN;\n\
    \    std::vector<int32_t> primes;\n    int32_t sz;\n    MFPrefixSum(uint64_t N)\
    \ {\n        n = N;\n        sqrtN = sqrt(n);\n        sz = sqrtN * 2;\n     \
    \   if (n / sqrtN == sqrtN) sz--;\n        while ((sqrtN + 1) * (sqrtN + 1) <=\
    \ n) sqrtN++;\n        while (sqrtN * sqrtN > n) sqrtN--;\n        primes = enumerate_primes(sqrtN);\n\
    \    }\n    std::vector<T> pi_table() {\n        std::vector<T> dp(sz);\n    \
    \    for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] = i;\n        }\n\
    \        for (int32_t i = sqrtN; i < sz; i++) {\n            dp[i] = n / (sz -\
    \ i) - 1;\n        }\n        for (int64_t x : primes) {\n            for (int32_t\
    \ i = sz - 1; i >= sqrtN; i--) {\n                if (n < x * x * (sz - i)) break;\n\
    \                if (sz - (sz - i) * x < sqrtN) {\n                    dp[i] -=\
    \ (dp[n / (x * (sz - i)) - 1] - dp[x - 2]);\n                } else {\n      \
    \              dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]);\n               \
    \ }\n            }\n            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n \
    \               if (i + 1 < x * x) break;\n                dp[i] -= (dp[(i + 1)\
    \ / x - 1] - dp[x - 2]);\n            }\n        }\n        return dp;\n    }\n\
    \    std::vector<T> prime_sum_table() {\n        std::vector<T> dp(sz);\n    \
    \    for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] = T(i + 1) * T(i\
    \ + 2) / 2 - 1;\n        }\n        for (int32_t i = sqrtN; i < sz; i++) {\n \
    \           dp[i] = T(n / (sz - i)) * T(n / (sz - i) + 1) / 2 - 1;\n        }\n\
    \        for (int64_t x : primes) {\n            for (int32_t i = sz - 1; i >=\
    \ sqrtN; i--) {\n                if (n < x * x * (sz - i)) break;\n          \
    \      if (sz - (sz - i) * x < sqrtN) {\n                    dp[i] -= (dp[n /\
    \ (x * (sz - i)) - 1] - dp[x - 2]) * x;\n                } else {\n          \
    \          dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]) * x;\n               \
    \ }\n            }\n            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n \
    \               if (i + 1 < x * x) break;\n                dp[i] -= (dp[(i + 1)\
    \ / x - 1] - dp[x - 2]) * x;\n            }\n        }\n        return dp;\n \
    \   }\n    std::vector<T> prefix_prime_table(auto f) {\n        std::vector<T>\
    \ dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] =\
    \ f(i + 1);\n        }\n        for (int32_t i = sqrtN; i < sz; i++) {\n     \
    \       dp[i] = f(n / (sz - i));\n        }\n        for (int64_t x : primes)\
    \ {\n            for (int32_t i = sz - 1; i >= sqrtN; i--) {\n               \
    \ if (n < x * x * (sz - i)) break;\n                if (sz - (sz - i) * x < sqrtN)\
    \ {\n                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) *\n\
    \                             (f(x) - f(x - 1));\n                } else {\n \
    \                   dp[i] -=\n                        (dp[sz - (sz - i) * x] -\
    \ dp[x - 2]) * (f(x) - f(x - 1));\n                }\n            }\n        \
    \    for (int32_t i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 < x\
    \ * x) break;\n                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) * (f(x)\
    \ - f(x - 1));\n            }\n        }\n        return dp;\n    }\n    std::vector<T>\
    \ min25_sieve(std::vector<T> table, auto f) {\n        std::vector<T> dp = table;\n\
    \        for (auto it = primes.rbegin(); it != primes.rend(); it++) {\n      \
    \      int64_t x = *it;\n            for (int32_t i = sz - 1; i >= sqrtN; i--)\
    \ {\n                if (n < x * x * (sz - i)) break;\n                int64_t\
    \ xp = x;\n                int32_t c = 1;\n                while (xp * x * (sz\
    \ - i) <= n) {\n                    if (sz - (sz - i) * xp < sqrtN) {\n      \
    \                  dp[i] += f(x, c) * (dp[n / (xp * (sz - i)) - 1] -\n       \
    \                                     table[x - 1]) +\n                      \
    \           f(x, c + 1);\n                    } else {\n                     \
    \   dp[i] +=\n                            f(x, c) * (dp[sz - (sz - i) * xp] -\
    \ table[x - 1]) +\n                            f(x, c + 1);\n                \
    \    }\n                    c++;\n                    xp *= x;\n             \
    \   }\n            }\n            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n\
    \                if (i + 1 < x * x) break;\n                int64_t xp = x;\n\
    \                int32_t c = 1;\n                while (xp * x <= i + 1) {\n \
    \                   dp[i] += f(x, c) * (dp[(i + 1) / xp - 1] - table[x - 1]) +\n\
    \                             f(x, c + 1);\n                    c++;\n       \
    \             xp *= x;\n                }\n            }\n        }\n        for\
    \ (int32_t i = 0; i < sz; i++) {\n            dp[i] += 1;\n        }\n       \
    \ return dp;\n    }\n};\n"
  code: "#include <math.h>\n\n#include <cstdint>\n#include <vector>\n\n#include \"\
    EnumeratePrimes.hpp\"\ntemplate <class T>\nstruct MFPrefixSum {\n    int64_t n;\n\
    \    int64_t sqrtN;\n    std::vector<int32_t> primes;\n    int32_t sz;\n    MFPrefixSum(uint64_t\
    \ N) {\n        n = N;\n        sqrtN = sqrt(n);\n        sz = sqrtN * 2;\n  \
    \      if (n / sqrtN == sqrtN) sz--;\n        while ((sqrtN + 1) * (sqrtN + 1)\
    \ <= n) sqrtN++;\n        while (sqrtN * sqrtN > n) sqrtN--;\n        primes =\
    \ enumerate_primes(sqrtN);\n    }\n    std::vector<T> pi_table() {\n        std::vector<T>\
    \ dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] =\
    \ i;\n        }\n        for (int32_t i = sqrtN; i < sz; i++) {\n            dp[i]\
    \ = n / (sz - i) - 1;\n        }\n        for (int64_t x : primes) {\n       \
    \     for (int32_t i = sz - 1; i >= sqrtN; i--) {\n                if (n < x *\
    \ x * (sz - i)) break;\n                if (sz - (sz - i) * x < sqrtN) {\n   \
    \                 dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]);\n       \
    \         } else {\n                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x\
    \ - 2]);\n                }\n            }\n            for (int32_t i = sqrtN\
    \ - 1; i >= 0; i--) {\n                if (i + 1 < x * x) break;\n           \
    \     dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]);\n            }\n        }\n\
    \        return dp;\n    }\n    std::vector<T> prime_sum_table() {\n        std::vector<T>\
    \ dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] =\
    \ T(i + 1) * T(i + 2) / 2 - 1;\n        }\n        for (int32_t i = sqrtN; i <\
    \ sz; i++) {\n            dp[i] = T(n / (sz - i)) * T(n / (sz - i) + 1) / 2 -\
    \ 1;\n        }\n        for (int64_t x : primes) {\n            for (int32_t\
    \ i = sz - 1; i >= sqrtN; i--) {\n                if (n < x * x * (sz - i)) break;\n\
    \                if (sz - (sz - i) * x < sqrtN) {\n                    dp[i] -=\
    \ (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) * x;\n                } else {\n  \
    \                  dp[i] -= (dp[sz - (sz - i) * x] - dp[x - 2]) * x;\n       \
    \         }\n            }\n            for (int32_t i = sqrtN - 1; i >= 0; i--)\
    \ {\n                if (i + 1 < x * x) break;\n                dp[i] -= (dp[(i\
    \ + 1) / x - 1] - dp[x - 2]) * x;\n            }\n        }\n        return dp;\n\
    \    }\n    std::vector<T> prefix_prime_table(auto f) {\n        std::vector<T>\
    \ dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] =\
    \ f(i + 1);\n        }\n        for (int32_t i = sqrtN; i < sz; i++) {\n     \
    \       dp[i] = f(n / (sz - i));\n        }\n        for (int64_t x : primes)\
    \ {\n            for (int32_t i = sz - 1; i >= sqrtN; i--) {\n               \
    \ if (n < x * x * (sz - i)) break;\n                if (sz - (sz - i) * x < sqrtN)\
    \ {\n                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) *\n\
    \                             (f(x) - f(x - 1));\n                } else {\n \
    \                   dp[i] -=\n                        (dp[sz - (sz - i) * x] -\
    \ dp[x - 2]) * (f(x) - f(x - 1));\n                }\n            }\n        \
    \    for (int32_t i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 < x\
    \ * x) break;\n                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) * (f(x)\
    \ - f(x - 1));\n            }\n        }\n        return dp;\n    }\n    std::vector<T>\
    \ min25_sieve(std::vector<T> table, auto f) {\n        std::vector<T> dp = table;\n\
    \        for (auto it = primes.rbegin(); it != primes.rend(); it++) {\n      \
    \      int64_t x = *it;\n            for (int32_t i = sz - 1; i >= sqrtN; i--)\
    \ {\n                if (n < x * x * (sz - i)) break;\n                int64_t\
    \ xp = x;\n                int32_t c = 1;\n                while (xp * x * (sz\
    \ - i) <= n) {\n                    if (sz - (sz - i) * xp < sqrtN) {\n      \
    \                  dp[i] += f(x, c) * (dp[n / (xp * (sz - i)) - 1] -\n       \
    \                                     table[x - 1]) +\n                      \
    \           f(x, c + 1);\n                    } else {\n                     \
    \   dp[i] +=\n                            f(x, c) * (dp[sz - (sz - i) * xp] -\
    \ table[x - 1]) +\n                            f(x, c + 1);\n                \
    \    }\n                    c++;\n                    xp *= x;\n             \
    \   }\n            }\n            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n\
    \                if (i + 1 < x * x) break;\n                int64_t xp = x;\n\
    \                int32_t c = 1;\n                while (xp * x <= i + 1) {\n \
    \                   dp[i] += f(x, c) * (dp[(i + 1) / xp - 1] - table[x - 1]) +\n\
    \                             f(x, c + 1);\n                    c++;\n       \
    \             xp *= x;\n                }\n            }\n        }\n        for\
    \ (int32_t i = 0; i < sz; i++) {\n            dp[i] += 1;\n        }\n       \
    \ return dp;\n    }\n};\n"
  dependsOn:
  - Math/EnumeratePrimes.hpp
  isVerificationFile: false
  path: Math/MFPrefixSum.hpp
  requiredBy: []
  timestamp: '2024-10-23 17:47:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function.test.cpp
documentation_of: Math/MFPrefixSum.hpp
layout: document
redirect_from:
- /library/Math/MFPrefixSum.hpp
- /library/Math/MFPrefixSum.hpp.html
title: Math/MFPrefixSum.hpp
---