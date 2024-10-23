---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/EnumeratePrimes.hpp
    title: Math/EnumeratePrimes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function-black_algorithm.test.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function-black_algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-new/sum_of_multiplicative_function-min25_sieve.test.cpp
    title: Verify/verify-yosupo-new/sum_of_multiplicative_function-min25_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
    title: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/MFPrefixSum.hpp\"\n#include <math.h>\n\n#include <cstdint>\n\
    #include <vector>\n#include <stack>\n\n#line 4 \"Math/EnumeratePrimes.hpp\"\n\
    std::vector<int32_t> enumerate_primes(int32_t n) {\n    std::vector<bool> flg((n\
    \ + 1) >> 1, true);\n    std::vector<int32_t> ret = {2};\n    for (int32_t i =\
    \ 3; i <= n; i += 2) {\n        if (!flg[i >> 1]) continue;\n        ret.emplace_back(i);\n\
    \        if (i * i > n) {\n            for (int32_t j = i + 2; j <= n; j += 2)\
    \ {\n                if (flg[j >> 1]) ret.emplace_back(j);\n            }\n  \
    \          break;\n        }\n        for (int32_t j = i * i; j <= n; j += i <<\
    \ 1) {\n            flg[j >> 1] = false;\n        }\n    }\n    while (!ret.empty()\
    \ && ret.back() > n) ret.pop_back();\n    return ret;\n}\n#line 9 \"Math/MFPrefixSum.hpp\"\
    \ntemplate <class T>\nstruct MFPrefixSum {\n    int64_t n;\n    int64_t sqrtN;\n\
    \    std::vector<int32_t> primes;\n    int32_t sz;\n    int32_t prisz;\n    MFPrefixSum(uint64_t\
    \ N) {\n        n = N;\n        sqrtN = sqrt(n);\n        sz = sqrtN * 2;\n  \
    \      if (n / sqrtN == sqrtN) sz--;\n        while ((sqrtN + 1) * (sqrtN + 1)\
    \ <= n) sqrtN++;\n        while (sqrtN * sqrtN > n) sqrtN--;\n        primes =\
    \ enumerate_primes(sqrtN);\n        prisz = primes.size();\n    }\n    std::vector<T>\
    \ pi_table() {\n        std::vector<T> dp(sz);\n        for (int32_t i = 0; i\
    \ < sqrtN; i++) {\n            dp[i] = i;\n        }\n        for (int32_t i =\
    \ sqrtN; i < sz; i++) {\n            dp[i] = n / (sz - i) - 1;\n        }\n  \
    \      for (int64_t x : primes) {\n            for (int32_t i = sz - 1; i >= sqrtN;\
    \ i--) {\n                if (n < x * x * (sz - i)) break;\n                if\
    \ (sz - (sz - i) * x < sqrtN) {\n                    dp[i] -= (dp[n / (x * (sz\
    \ - i)) - 1] - dp[x - 2]);\n                } else {\n                    dp[i]\
    \ -= (dp[sz - (sz - i) * x] - dp[x - 2]);\n                }\n            }\n\
    \            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n                if (i\
    \ + 1 < x * x) break;\n                dp[i] -= (dp[(i + 1) / x - 1] - dp[x -\
    \ 2]);\n            }\n        }\n        return dp;\n    }\n    std::vector<T>\
    \ prime_sum_table() {\n        std::vector<T> dp(sz);\n        for (int32_t i\
    \ = 0; i < sqrtN; i++) {\n            dp[i] = T(i + 1) * T(i + 2) / 2 - 1;\n \
    \       }\n        for (int32_t i = sqrtN; i < sz; i++) {\n            dp[i] =\
    \ T(n / (sz - i)) * T(n / (sz - i) + 1) / 2 - 1;\n        }\n        for (int64_t\
    \ x : primes) {\n            for (int32_t i = sz - 1; i >= sqrtN; i--) {\n   \
    \             if (n < x * x * (sz - i)) break;\n                if (sz - (sz -\
    \ i) * x < sqrtN) {\n                    dp[i] -= (dp[n / (x * (sz - i)) - 1]\
    \ - dp[x - 2]) * x;\n                } else {\n                    dp[i] -= (dp[sz\
    \ - (sz - i) * x] - dp[x - 2]) * x;\n                }\n            }\n      \
    \      for (int32_t i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 <\
    \ x * x) break;\n                dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) *\
    \ x;\n            }\n        }\n        return dp;\n    }\n    std::vector<T>\
    \ prefix_prime_table(auto f) {\n        std::vector<T> dp(sz);\n        for (int32_t\
    \ i = 0; i < sqrtN; i++) {\n            dp[i] = f(i + 1);\n        }\n       \
    \ for (int32_t i = sqrtN; i < sz; i++) {\n            dp[i] = f(n / (sz - i));\n\
    \        }\n        for (int64_t x : primes) {\n            for (int32_t i = sz\
    \ - 1; i >= sqrtN; i--) {\n                if (n < x * x * (sz - i)) break;\n\
    \                if (sz - (sz - i) * x < sqrtN) {\n                    dp[i] -=\
    \ (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) *\n                             (f(x)\
    \ - f(x - 1));\n                } else {\n                    dp[i] -=\n     \
    \                   (dp[sz - (sz - i) * x] - dp[x - 2]) * (f(x) - f(x - 1));\n\
    \                }\n            }\n            for (int32_t i = sqrtN - 1; i >=\
    \ 0; i--) {\n                if (i + 1 < x * x) break;\n                dp[i]\
    \ -= (dp[(i + 1) / x - 1] - dp[x - 2]) * (f(x) - f(x - 1));\n            }\n \
    \       }\n        return dp;\n    }\n    struct _Node{\n        int64_t x;\n\
    \        int32_t gpf;\n        int32_t c;\n        int32_t cnt;\n        T fx;\n\
    \        T ret;\n    };\n    T black_algorithm(std::vector<T> &table, auto f)\
    \ {\n        //x,gpf(x),c,f(x),cnt,ret\n        if(n==1)return 1;\n        std::stack<_Node>\
    \ dfs;\n        dfs.push({1,-1,0,0,1,0});\n        while(true){\n            _Node\
    \ *tp=&dfs.top();\n            if(tp->cnt==tp->gpf){\n                if(tp->x*primes[tp->gpf]*primes[tp->gpf]<=n){\n\
    \                    dfs.push({tp->x*primes[tp->gpf],tp->gpf,tp->c+1,tp->cnt,tp->fx,0});\n\
    \                }\n                tp->ret+=tp->fx*f(primes[tp->gpf],tp->c+1);\n\
    \                tp->fx*=f(primes[tp->gpf],tp->c);\n                tp->cnt++;\n\
    \            }\n            else{\n                if(tp->cnt<prisz&&tp->x*primes[tp->cnt]*primes[tp->cnt]<=n){\n\
    \                    dfs.push({tp->x*primes[tp->cnt],tp->cnt,1,tp->cnt,tp->fx,0});\n\
    \                    tp->cnt++;\n                }\n                else{\n  \
    \                  if(tp->gpf==-1){\n                        if(sz-tp->x<sqrtN)return\
    \ tp->ret+tp->fx*table[n/tp->x-1]+1;\n                        else return tp->ret+tp->fx*table[sz-tp->x]+1;\n\
    \                    }\n                    T nret=tp->ret;\n                \
    \    if(sz-tp->x<sqrtN)nret+=tp->fx*(table[n/tp->x-1]-table[primes[tp->gpf]-1]);\n\
    \                    else nret+=tp->fx*(table[sz-tp->x]-table[primes[tp->gpf]-1]);\n\
    \                    dfs.pop();\n                    if(dfs.empty())return nret+1;\n\
    \                    dfs.top().ret+=nret;\n                }\n            }\n\
    \        }\n    }\n    std::vector<T> min25_sieve(std::vector<T> &table, auto\
    \ f) {\n        std::vector<T> dp = table;\n        for (auto it = primes.rbegin();\
    \ it != primes.rend(); it++) {\n            int64_t x = *it;\n            for\
    \ (int32_t i = sz - 1; i >= sqrtN; i--) {\n                if (n < x * x * (sz\
    \ - i)) break;\n                int64_t xp = x;\n                int32_t c = 1;\n\
    \                while (xp * x * (sz - i) <= n) {\n                    if (sz\
    \ - (sz - i) * xp < sqrtN) {\n                        dp[i] += f(x, c) * (dp[n\
    \ / (xp * (sz - i)) - 1] -\n                                            table[x\
    \ - 1]) +\n                                 f(x, c + 1);\n                   \
    \ } else {\n                        dp[i] +=\n                            f(x,\
    \ c) * (dp[sz - (sz - i) * xp] - table[x - 1]) +\n                           \
    \ f(x, c + 1);\n                    }\n                    c++;\n            \
    \        xp *= x;\n                }\n            }\n            for (int32_t\
    \ i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 < x * x) break;\n \
    \               int64_t xp = x;\n                int32_t c = 1;\n            \
    \    while (xp * x <= i + 1) {\n                    dp[i] += f(x, c) * (dp[(i\
    \ + 1) / xp - 1] - table[x - 1]) +\n                             f(x, c + 1);\n\
    \                    c++;\n                    xp *= x;\n                }\n \
    \           }\n        }\n        for (int32_t i = 0; i < sz; i++) {\n       \
    \     dp[i] += 1;\n        }\n        return dp;\n    }\n};\n"
  code: "#pragma once\n#include <math.h>\n\n#include <cstdint>\n#include <vector>\n\
    #include <stack>\n\n#include \"EnumeratePrimes.hpp\"\ntemplate <class T>\nstruct\
    \ MFPrefixSum {\n    int64_t n;\n    int64_t sqrtN;\n    std::vector<int32_t>\
    \ primes;\n    int32_t sz;\n    int32_t prisz;\n    MFPrefixSum(uint64_t N) {\n\
    \        n = N;\n        sqrtN = sqrt(n);\n        sz = sqrtN * 2;\n        if\
    \ (n / sqrtN == sqrtN) sz--;\n        while ((sqrtN + 1) * (sqrtN + 1) <= n) sqrtN++;\n\
    \        while (sqrtN * sqrtN > n) sqrtN--;\n        primes = enumerate_primes(sqrtN);\n\
    \        prisz = primes.size();\n    }\n    std::vector<T> pi_table() {\n    \
    \    std::vector<T> dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n \
    \           dp[i] = i;\n        }\n        for (int32_t i = sqrtN; i < sz; i++)\
    \ {\n            dp[i] = n / (sz - i) - 1;\n        }\n        for (int64_t x\
    \ : primes) {\n            for (int32_t i = sz - 1; i >= sqrtN; i--) {\n     \
    \           if (n < x * x * (sz - i)) break;\n                if (sz - (sz - i)\
    \ * x < sqrtN) {\n                    dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x\
    \ - 2]);\n                } else {\n                    dp[i] -= (dp[sz - (sz\
    \ - i) * x] - dp[x - 2]);\n                }\n            }\n            for (int32_t\
    \ i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 < x * x) break;\n \
    \               dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]);\n            }\n \
    \       }\n        return dp;\n    }\n    std::vector<T> prime_sum_table() {\n\
    \        std::vector<T> dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++) {\n\
    \            dp[i] = T(i + 1) * T(i + 2) / 2 - 1;\n        }\n        for (int32_t\
    \ i = sqrtN; i < sz; i++) {\n            dp[i] = T(n / (sz - i)) * T(n / (sz -\
    \ i) + 1) / 2 - 1;\n        }\n        for (int64_t x : primes) {\n          \
    \  for (int32_t i = sz - 1; i >= sqrtN; i--) {\n                if (n < x * x\
    \ * (sz - i)) break;\n                if (sz - (sz - i) * x < sqrtN) {\n     \
    \               dp[i] -= (dp[n / (x * (sz - i)) - 1] - dp[x - 2]) * x;\n     \
    \           } else {\n                    dp[i] -= (dp[sz - (sz - i) * x] - dp[x\
    \ - 2]) * x;\n                }\n            }\n            for (int32_t i = sqrtN\
    \ - 1; i >= 0; i--) {\n                if (i + 1 < x * x) break;\n           \
    \     dp[i] -= (dp[(i + 1) / x - 1] - dp[x - 2]) * x;\n            }\n       \
    \ }\n        return dp;\n    }\n    std::vector<T> prefix_prime_table(auto f)\
    \ {\n        std::vector<T> dp(sz);\n        for (int32_t i = 0; i < sqrtN; i++)\
    \ {\n            dp[i] = f(i + 1);\n        }\n        for (int32_t i = sqrtN;\
    \ i < sz; i++) {\n            dp[i] = f(n / (sz - i));\n        }\n        for\
    \ (int64_t x : primes) {\n            for (int32_t i = sz - 1; i >= sqrtN; i--)\
    \ {\n                if (n < x * x * (sz - i)) break;\n                if (sz\
    \ - (sz - i) * x < sqrtN) {\n                    dp[i] -= (dp[n / (x * (sz - i))\
    \ - 1] - dp[x - 2]) *\n                             (f(x) - f(x - 1));\n     \
    \           } else {\n                    dp[i] -=\n                        (dp[sz\
    \ - (sz - i) * x] - dp[x - 2]) * (f(x) - f(x - 1));\n                }\n     \
    \       }\n            for (int32_t i = sqrtN - 1; i >= 0; i--) {\n          \
    \      if (i + 1 < x * x) break;\n                dp[i] -= (dp[(i + 1) / x - 1]\
    \ - dp[x - 2]) * (f(x) - f(x - 1));\n            }\n        }\n        return\
    \ dp;\n    }\n    struct _Node{\n        int64_t x;\n        int32_t gpf;\n  \
    \      int32_t c;\n        int32_t cnt;\n        T fx;\n        T ret;\n    };\n\
    \    T black_algorithm(std::vector<T> &table, auto f) {\n        //x,gpf(x),c,f(x),cnt,ret\n\
    \        if(n==1)return 1;\n        std::stack<_Node> dfs;\n        dfs.push({1,-1,0,0,1,0});\n\
    \        while(true){\n            _Node *tp=&dfs.top();\n            if(tp->cnt==tp->gpf){\n\
    \                if(tp->x*primes[tp->gpf]*primes[tp->gpf]<=n){\n             \
    \       dfs.push({tp->x*primes[tp->gpf],tp->gpf,tp->c+1,tp->cnt,tp->fx,0});\n\
    \                }\n                tp->ret+=tp->fx*f(primes[tp->gpf],tp->c+1);\n\
    \                tp->fx*=f(primes[tp->gpf],tp->c);\n                tp->cnt++;\n\
    \            }\n            else{\n                if(tp->cnt<prisz&&tp->x*primes[tp->cnt]*primes[tp->cnt]<=n){\n\
    \                    dfs.push({tp->x*primes[tp->cnt],tp->cnt,1,tp->cnt,tp->fx,0});\n\
    \                    tp->cnt++;\n                }\n                else{\n  \
    \                  if(tp->gpf==-1){\n                        if(sz-tp->x<sqrtN)return\
    \ tp->ret+tp->fx*table[n/tp->x-1]+1;\n                        else return tp->ret+tp->fx*table[sz-tp->x]+1;\n\
    \                    }\n                    T nret=tp->ret;\n                \
    \    if(sz-tp->x<sqrtN)nret+=tp->fx*(table[n/tp->x-1]-table[primes[tp->gpf]-1]);\n\
    \                    else nret+=tp->fx*(table[sz-tp->x]-table[primes[tp->gpf]-1]);\n\
    \                    dfs.pop();\n                    if(dfs.empty())return nret+1;\n\
    \                    dfs.top().ret+=nret;\n                }\n            }\n\
    \        }\n    }\n    std::vector<T> min25_sieve(std::vector<T> &table, auto\
    \ f) {\n        std::vector<T> dp = table;\n        for (auto it = primes.rbegin();\
    \ it != primes.rend(); it++) {\n            int64_t x = *it;\n            for\
    \ (int32_t i = sz - 1; i >= sqrtN; i--) {\n                if (n < x * x * (sz\
    \ - i)) break;\n                int64_t xp = x;\n                int32_t c = 1;\n\
    \                while (xp * x * (sz - i) <= n) {\n                    if (sz\
    \ - (sz - i) * xp < sqrtN) {\n                        dp[i] += f(x, c) * (dp[n\
    \ / (xp * (sz - i)) - 1] -\n                                            table[x\
    \ - 1]) +\n                                 f(x, c + 1);\n                   \
    \ } else {\n                        dp[i] +=\n                            f(x,\
    \ c) * (dp[sz - (sz - i) * xp] - table[x - 1]) +\n                           \
    \ f(x, c + 1);\n                    }\n                    c++;\n            \
    \        xp *= x;\n                }\n            }\n            for (int32_t\
    \ i = sqrtN - 1; i >= 0; i--) {\n                if (i + 1 < x * x) break;\n \
    \               int64_t xp = x;\n                int32_t c = 1;\n            \
    \    while (xp * x <= i + 1) {\n                    dp[i] += f(x, c) * (dp[(i\
    \ + 1) / xp - 1] - table[x - 1]) +\n                             f(x, c + 1);\n\
    \                    c++;\n                    xp *= x;\n                }\n \
    \           }\n        }\n        for (int32_t i = 0; i < sz; i++) {\n       \
    \     dp[i] += 1;\n        }\n        return dp;\n    }\n};\n"
  dependsOn:
  - Math/EnumeratePrimes.hpp
  isVerificationFile: false
  path: Math/MFPrefixSum.hpp
  requiredBy: []
  timestamp: '2024-10-23 21:39:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function-min25_sieve.test.cpp
  - Verify/verify-yosupo-new/sum_of_multiplicative_function-black_algorithm.test.cpp
documentation_of: Math/MFPrefixSum.hpp
layout: document
redirect_from:
- /library/Math/MFPrefixSum.hpp
- /library/Math/MFPrefixSum.hpp.html
title: Math/MFPrefixSum.hpp
---
