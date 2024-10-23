---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/EnumeratePrimes.hpp
    title: Math/EnumeratePrimes.hpp
  - icon: ':x:'
    path: Math/MFPrefixSum.hpp
    title: Math/MFPrefixSum.hpp
  - icon: ':question:'
    path: Modint/Modint.hpp
    title: Modint/Modint.hpp
  - icon: ':question:'
    path: Template/InOut.hpp
    title: Template/InOut.hpp
  - icon: ':question:'
    path: Template/Macro.hpp
    title: Template/Macro.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  - icon: ':question:'
    path: Template/Util.hpp
    title: Template/Util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    #line 1 \"Math/MFPrefixSum.hpp\"\n#include <math.h>\n\n#include <cstdint>\n#include\
    \ <vector>\n\n#line 4 \"Math/EnumeratePrimes.hpp\"\nstd::vector<int32_t> enumerate_primes(int32_t\
    \ n) {\n    std::vector<bool> flg((n + 1) >> 1, true);\n    std::vector<int32_t>\
    \ ret = {2};\n    for (int32_t i = 3; i <= n; i += 2) {\n        if (!flg[i >>\
    \ 1]) continue;\n        ret.emplace_back(i);\n        if (i * i > n) {\n    \
    \        for (int32_t j = i + 2; j <= n; j += 2) {\n                if (flg[j\
    \ >> 1]) ret.emplace_back(j);\n            }\n            break;\n        }\n\
    \        for (int32_t j = i * i; j <= n; j += i << 1) {\n            flg[j >>\
    \ 1] = false;\n        }\n    }\n    while (!ret.empty() && ret.back() > n) ret.pop_back();\n\
    \    return ret;\n}\n#line 7 \"Math/MFPrefixSum.hpp\"\ntemplate <class T>\nstruct\
    \ MFPrefixSum {\n    int64_t n;\n    int64_t sqrtN;\n    std::vector<int32_t>\
    \ primes;\n    int32_t sz;\n    MFPrefixSum(uint64_t N) {\n        n = N;\n  \
    \      sqrtN = sqrt(n);\n        sz = sqrtN * 2;\n        if (n / sqrtN == sqrtN)\
    \ sz--;\n        while ((sqrtN + 1) * (sqrtN + 1) <= n) sqrtN++;\n        while\
    \ (sqrtN * sqrtN > n) sqrtN--;\n        primes = enumerate_primes(sqrtN);\n  \
    \  }\n    std::vector<T> pi_table() {\n        std::vector<T> dp(sz);\n      \
    \  for (int32_t i = 0; i < sqrtN; i++) {\n            dp[i] = i;\n        }\n\
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
    \ return dp;\n    }\n};\n#line 2 \"Modint/Modint.hpp\"\n#include <assert.h>\n\n\
    #line 5 \"Modint/Modint.hpp\"\n#include <iostream>\ntemplate <uint64_t Mod>\n\
    struct Modint {\n    uint64_t x;\n    constexpr Modint() noexcept { x = 0; }\n\
    \    constexpr Modint(int64_t val) noexcept {\n        x = (val < 0 ? val % (int64_t)(Mod)\
    \ + Mod : val % Mod);\n    }\n    inline uint64_t _get_mod(uint64_t val) noexcept\
    \ {\n        const static uint64_t m_inv = (-1ULL) / Mod + 1;\n        uint64_t\
    \ ret = ((unsigned __int128)(val)*m_inv) >> 64;\n        uint64_t pro = ret *\
    \ Mod;\n        return (val - pro + (val < pro ? Mod : 0));\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, Modint &b) noexcept {\n        return\
    \ os << b.x;\n    }\n    friend std::istream &operator>>(std::istream &is, Modint\
    \ &b) noexcept {\n        return is >> b.x;\n    }\n    constexpr uint64_t val()\
    \ noexcept { return x; }\n    constexpr Modint operator+() noexcept { return (*this);\
    \ }\n    constexpr Modint operator-() noexcept { return Modint() - (*this); }\n\
    \    friend Modint operator+(const Modint lhs, const Modint rhs) noexcept {\n\
    \        return Modint(lhs) += rhs;\n    }\n    friend Modint operator-(const\
    \ Modint lhs, const Modint rhs) noexcept {\n        return Modint(lhs) -= rhs;\n\
    \    }\n    friend Modint operator*(const Modint lhs, const Modint rhs) noexcept\
    \ {\n        return Modint(lhs) *= rhs;\n    }\n    friend Modint operator/(const\
    \ Modint lhs, const Modint rhs) {\n        return Modint(lhs) /= rhs;\n    }\n\
    \    constexpr Modint &operator+=(const Modint rhs) noexcept {\n        x += rhs.x;\n\
    \        if (x >= Mod) x -= Mod;\n        return *this;\n    }\n    constexpr\
    \ Modint &operator-=(const Modint rhs) noexcept {\n        if (x < rhs.x) x +=\
    \ Mod;\n        x -= rhs.x;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator*=(const Modint rhs) noexcept {\n        x = _get_mod(x * rhs.x);\n\
    \        return *this;\n    }\n    friend bool operator==(const Modint lhs, const\
    \ Modint rhs) noexcept {\n        return lhs.x == rhs.x;\n    }\n    friend bool\
    \ operator!=(const Modint lhs, const Modint rhs) noexcept {\n        return rhs.x\
    \ != rhs.x;\n    }\n    constexpr Modint &operator/=(Modint rhs) { return (*this)\
    \ *= rhs.inv(); }\n    constexpr Modint inv() {\n        int64_t a = (*this).x,\
    \ b = get_mod();\n        assert(a != 0);\n        int64_t s = b, t = a;\n   \
    \     int64_t m0 = 0, m1 = 1;\n        while (t) {\n            int64_t u = s\
    \ / t;\n            s -= t * u;\n            m0 -= m1 * u;\n            int64_t\
    \ tmp = s;\n            s = t;\n            t = tmp;\n            tmp = m0;\n\
    \            m0 = m1;\n            m1 = tmp;\n        }\n        assert(s == 1);\n\
    \        if (m0 < 0) m0 += b;\n        return Modint(m0);\n    }\n    constexpr\
    \ Modint pow(uint64_t x) noexcept {\n        Modint ret = 1;\n        Modint bin\
    \ = (*this);\n        while (x) {\n            if (x & 1) ret *= bin;\n      \
    \      bin *= bin;\n            x >>= 1;\n        }\n        return ret;\n   \
    \ }\n    static uint64_t get_mod() noexcept { return Mod; }\n};\n\ntemplate <int64_t\
    \ id>\nstruct ArbitraryModint {\n    uint64_t x;\n    static uint64_t &mod() noexcept\
    \ {\n        static uint64_t Mod = 0;\n        return Mod;\n    }\n    constexpr\
    \ ArbitraryModint() noexcept { x = 0; }\n    constexpr ArbitraryModint(int64_t\
    \ val) noexcept {\n        x = (val < 0 ? val % (int64_t)(get_mod()) + get_mod()\n\
    \                     : val % get_mod());\n    }\n    inline uint64_t _get_mod(uint64_t\
    \ val) noexcept {\n        const static uint64_t m_inv = (-1ULL) / get_mod() +\
    \ 1;\n        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;\n       \
    \ uint64_t pro = ret * get_mod();\n        return (val - pro + (val < pro ? get_mod()\
    \ : 0));\n    }\n    friend std::ostream &operator<<(std::ostream &os,\n     \
    \                               ArbitraryModint &b) noexcept {\n        return\
    \ os << b.x;\n    }\n    friend std::istream &operator>>(std::istream &is,\n \
    \                                   ArbitraryModint &b) noexcept {\n        return\
    \ is >> b.x;\n    }\n    constexpr uint64_t val() noexcept { return x; }\n   \
    \ constexpr ArbitraryModint operator+() noexcept { return (*this); }\n    constexpr\
    \ ArbitraryModint operator-() noexcept {\n        return ArbitraryModint() - (*this);\n\
    \    }\n    friend ArbitraryModint operator+(const ArbitraryModint lhs,\n    \
    \                                 const ArbitraryModint rhs) noexcept {\n    \
    \    return ArbitraryModint(lhs) += rhs;\n    }\n    friend ArbitraryModint operator-(const\
    \ ArbitraryModint lhs,\n                                     const ArbitraryModint\
    \ rhs) noexcept {\n        return ArbitraryModint(lhs) -= rhs;\n    }\n    friend\
    \ ArbitraryModint operator*(const ArbitraryModint lhs,\n                     \
    \                const ArbitraryModint rhs) noexcept {\n        return ArbitraryModint(lhs)\
    \ *= rhs;\n    }\n    friend ArbitraryModint operator/(const ArbitraryModint lhs,\n\
    \                                     const ArbitraryModint rhs) {\n        return\
    \ ArbitraryModint(lhs) /= rhs;\n    }\n    constexpr ArbitraryModint &operator+=(const\
    \ ArbitraryModint rhs) noexcept {\n        x += rhs.x;\n        if (x >= mod())\
    \ x -= mod();\n        return *this;\n    }\n    constexpr ArbitraryModint &operator-=(const\
    \ ArbitraryModint rhs) noexcept {\n        if (x < rhs.x) x += mod();\n      \
    \  x -= rhs.x;\n        return *this;\n    }\n    constexpr ArbitraryModint &operator*=(const\
    \ ArbitraryModint rhs) noexcept {\n        x = _get_mod(x * rhs.x);\n        return\
    \ *this;\n    }\n    friend bool operator==(const ArbitraryModint lhs,\n     \
    \                      const ArbitraryModint rhs) noexcept {\n        return lhs.x\
    \ == rhs.x;\n    }\n    friend bool operator!=(const ArbitraryModint lhs,\n  \
    \                         const ArbitraryModint rhs) noexcept {\n        return\
    \ rhs.x != rhs.x;\n    }\n    constexpr ArbitraryModint &operator/=(ArbitraryModint\
    \ rhs) {\n        return (*this) *= rhs.inv();\n    }\n    constexpr ArbitraryModint\
    \ inv() {\n        int64_t a = (*this).x, b = get_mod();\n        assert(a !=\
    \ 0);\n        int64_t s = b, t = a;\n        int64_t m0 = 0, m1 = 1;\n      \
    \  while (t) {\n            int64_t u = s / t;\n            s -= t * u;\n    \
    \        m0 -= m1 * u;\n            int64_t tmp = s;\n            s = t;\n   \
    \         t = tmp;\n            tmp = m0;\n            m0 = m1;\n            m1\
    \ = tmp;\n        }\n        assert(s == 1);\n        if (m0 < 0) m0 += b;\n \
    \       return ArbitraryModint(m0);\n    }\n    constexpr ArbitraryModint pow(uint64_t\
    \ x) noexcept {\n        ArbitraryModint ret = 1;\n        ArbitraryModint bin\
    \ = (*this);\n        while (x) {\n            if (x & 1) ret *= bin;\n      \
    \      bin *= bin;\n            x >>= 1;\n        }\n        return ret;\n   \
    \ }\n    static void set_mod(const uint64_t x) noexcept { mod() = x; }\n    static\
    \ uint64_t get_mod() noexcept { return mod(); }\n};\ntemplate <uint64_t N>\ninline\
    \ void scan(Modint<N> &a) {\n    std::cin >> a.x;\n}\ntemplate <int64_t id>\n\
    inline void scan(ArbitraryModint<id> &a) {\n    std::cin >> a.x;\n}\ntemplate\
    \ <uint64_t N>\ninline void print(Modint<N> a) {\n    std::cout << a.x;\n}\ntemplate\
    \ <int64_t id>\ninline void print(ArbitraryModint<id> a) {\n    std::cout << a.x;\n\
    }\n#line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 8 \"Template/InOut.hpp\"\ninline void scan() {}\ninline void scan(int32_t\
    \ &a) { std::cin >> a; }\ninline void scan(uint32_t &a) { std::cin >> a; }\ninline\
    \ void scan(int64_t &a) { std::cin >> a; }\ninline void scan(uint64_t &a) { std::cin\
    \ >> a; }\ninline void scan(char &a) { std::cin >> a; }\ninline void scan(float\
    \ &a) { std::cin >> a; }\ninline void scan(double &a) { std::cin >> a; }\ninline\
    \ void scan(long double &a) { std::cin >> a; }\ninline void scan(std::vector<bool>\
    \ &vec) {\n    for (int32_t i = 0; i < vec.size(); i++) {\n        int a;\n  \
    \      scan(a);\n        vec[i] = a;\n    }\n}\ninline void scan(std::string &a)\
    \ { std::cin >> a; }\ntemplate <class T>\ninline void scan(std::vector<T> &vec);\n\
    template <class T, size_t size>\ninline void scan(std::array<T, size> &vec);\n\
    template <class T, class L>\ninline void scan(std::pair<T, L> &p);\ntemplate <class\
    \ T, size_t size>\ninline void scan(T (&vec)[size]);\ntemplate <class T>\ninline\
    \ void scan(std::vector<T> &vec) {\n    for (auto &i : vec) scan(i);\n}\ntemplate\
    \ <class T>\ninline void scan(std::deque<T> &vec) {\n    for (auto &i : vec) scan(i);\n\
    }\ntemplate <class T, size_t size>\ninline void scan(std::array<T, size> &vec)\
    \ {\n    for (auto &i : vec) scan(i);\n}\ntemplate <class T, class L>\ninline\
    \ void scan(std::pair<T, L> &p) {\n    scan(p.first);\n    scan(p.second);\n}\n\
    template <class T, size_t size>\ninline void scan(T (&vec)[size]) {\n    for (auto\
    \ &i : vec) scan(i);\n}\ntemplate <class T>\ninline void scan(T &a) {\n    std::cin\
    \ >> a;\n}\ninline void in() {}\ntemplate <class Head, class... Tail>\ninline\
    \ void in(Head &head, Tail &...tail) {\n    scan(head);\n    in(tail...);\n}\n\
    inline void print() { std::cout << ' '; }\ninline void print(const bool &a) {\
    \ std::cout << a; }\ninline void print(const int32_t &a) { std::cout << a; }\n\
    inline void print(const uint32_t &a) { std::cout << a; }\ninline void print(const\
    \ int64_t &a) { std::cout << a; }\ninline void print(const uint64_t &a) { std::cout\
    \ << a; }\ninline void print(const char &a) { std::cout << a; }\ninline void print(const\
    \ char a[]) { std::cout << a; }\ninline void print(const float &a) { std::cout\
    \ << a; }\ninline void print(const double &a) { std::cout << a; }\ninline void\
    \ print(const long double &a) { std::cout << a; }\ninline void print(const std::string\
    \ &a) {\n    for (auto &&i : a) print(i);\n}\ntemplate <class T>\ninline void\
    \ print(const std::vector<T> &vec);\ntemplate <class T, size_t size>\ninline void\
    \ print(const std::array<T, size> &vec);\ntemplate <class T, class L>\ninline\
    \ void print(const std::pair<T, L> &p);\ntemplate <class T, size_t size>\ninline\
    \ void print(const T (&vec)[size]);\ntemplate <class T>\ninline void print(const\
    \ std::vector<T> &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n \
    \   for (auto i = vec.begin(); ++i != vec.end();) {\n        std::cout << ' ';\n\
    \        print(*i);\n    }\n}\ntemplate <class T>\ninline void print(const std::deque<T>\
    \ &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n    for (auto i =\
    \ vec.begin(); ++i != vec.end();) {\n        std::cout << ' ';\n        print(*i);\n\
    \    }\n}\ntemplate <class T, size_t size>\ninline void print(const std::array<T,\
    \ size> &vec) {\n    print(vec[0]);\n    for (auto i = vec.begin(); ++i != vec.end();)\
    \ {\n        std::cout << ' ';\n        print(*i);\n    }\n}\ntemplate <class\
    \ T, class L>\ninline void print(const std::pair<T, L> &p) {\n    print(p.first);\n\
    \    std::cout << ' ';\n    print(p.second);\n}\ntemplate <class T, size_t size>\n\
    inline void print(const T (&vec)[size]) {\n    print(vec[0]);\n    for (auto i\
    \ = vec; ++i != end(vec);) {\n        std::cout << ' ';\n        print(*i);\n\
    \    }\n}\ntemplate <class T>\ninline void print(const T &a) {\n    std::cout\
    \ << a;\n}\ninline void out() { std::cout << '\\n'; }\ntemplate <class T>\ninline\
    \ void out(const T &t) {\n    print(t);\n    std::cout << '\\n';\n}\ntemplate\
    \ <class Head, class... Tail>\ninline void out(const Head &head, const Tail &...tail)\
    \ {\n    print(head);\n    std::cout << ' ';\n    out(tail...);\n}\ninline void\
    \ Yes(bool i = true) { out(i ? \"Yes\" : \"No\"); }\ninline void No(bool i = true)\
    \ { out(i ? \"No\" : \"Yes\"); }\ninline void Takahashi(bool i = true) { out(i\
    \ ? \"Takahashi\" : \"Aoki\"); }\ninline void Aoki(bool i = true) { out(i ? \"\
    Aoki\" : \"Takahashi\"); }\ninline void Alice(bool i = true) { out(i ? \"Alice\"\
    \ : \"Bob\"); }\ninline void Bob(bool i = true) { out(i ? \"Bob\" : \"Alice\"\
    ); }\ninline void First(bool i = true) { out(i ? \"First\" : \"Second\"); }\n\
    inline void Second(bool i = true) { out(i ? \"Second\" : \"First\"); }\ninline\
    \ void Possible(bool i = true) { out(i ? \"Possible\" : \"Impossible\"); }\ninline\
    \ void Impossible(bool i = true) { out(i ? \"Impossible\" : \"Possible\"); }\n\
    inline void fls() { std::flush(std::cout); }\nstruct IOsetup {\n    IOsetup()\
    \ {\n        std::ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        std::cout << std::fixed << std::setprecision(16);\n    }\n} iosetup;\n\
    #line 9 \"Template/Util.hpp\"\nusing ll = int64_t;\nusing ld = long double;\n\
    using ull = uint64_t;\nusing uint = uint32_t;\nusing pll = std::pair<ll, ll>;\n\
    using pii = std::pair<int32_t, int32_t>;\nusing vl = std::vector<ll>;\nusing vvl\
    \ = std::vector<std::vector<ll>>;\nusing pdd = std::pair<ld, ld>;\nusing tuplis\
    \ = std::array<ll, 3>;\ntemplate <class T>\nusing pq = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\nconstexpr ll LINF = (1LL << 62) - (1LL <<\
    \ 31);\nconstexpr int32_t INF = INT_MAX >> 1;\nconstexpr ll MINF = 1LL << 40;\n\
    constexpr ld DINF = std::numeric_limits<ld>::infinity();\nconstexpr int32_t MODD\
    \ = 1000000007;\nconstexpr int32_t MOD = 998244353;\nconstexpr ld EPS = 1e-9;\n\
    constexpr ld PI = 3.1415926535897932;\nconst ll four[] = {0, 1, 0, -1, 0};\nconst\
    \ ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};\ntemplate <class T>\nbool chmin(T\
    \ &a, const T &b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    } else\n        return false;\n}\ntemplate <class T>\nbool chmax(T &a, const\
    \ T &b) {\n    if (a < b) {\n        a = b;\n        return true;\n    } else\n\
    \        return false;\n}\ntemplate <class T>\nll sum(const T &a) {\n    return\
    \ accumulate(std::begin(a), std::end(a), 0LL);\n}\ntemplate <class T>\nld dsum(const\
    \ T &a) {\n    return accumulate(std::begin(a), std::end(a), 0.0L);\n}\ntemplate\
    \ <class T>\nauto min(const T &a) {\n    return *min_element(std::begin(a), std::end(a));\n\
    }\ntemplate <class T>\nauto max(const T &a) {\n    return *max_element(std::begin(a),\
    \ std::end(a));\n}\n#line 1 \"Template/Macro.hpp\"\n#define _overload3(_1, _2,\
    \ _3, name, ...) name\n#define _overload4(_1, _2, _3, _4, name, ...) name\n#define\
    \ _rep1(i, n) for (int64_t i = 0; i < (n); i++)\n#define _rep2(i, a, b) for (int64_t\
    \ i = (a); i < (b); i++)\n#define _rep3(i, a, b, c) for (int64_t i = (a); i <\
    \ (b); i += (c))\n#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define _rrep1(i, n) for (int64_t i = (n) - 1; i >= 0; i--)\n#define _rrep2(i,\
    \ a, b) for (int64_t i = (b) - 1; i >= (a); i--)\n#define rrep(...) _overload3(__VA_ARGS__,\
    \ _rrep2, _rrep1)(__VA_ARGS__)\n#define each(i, ...) for (auto&& i : __VA_ARGS__)\n\
    #define all(i) std::begin(i), std::end(i)\n#define rall(i) std::rbegin(i), std::rend(i)\n\
    #define len(x) ((int64_t)(x).size())\n#define fi first\n#define se second\n#define\
    \ uniq(x) x.erase(unique(all(x)), std::end(x))\n#define vec(type, name, ...) vector<type>\
    \ name(__VA_ARGS__);\n#define vv(type, name, h, ...) std::vector<std::vector<type>>\
    \ name(h, std::vector<type>(__VA_ARGS__));\n#define INT(...) int32_t __VA_ARGS__;\
    \ in(__VA_ARGS__)\n#define LL(...) int64_t __VA_ARGS__; in(__VA_ARGS__)\n#define\
    \ ULL(...) uint64_t __VA_ARGS__; in(__VA_ARGS__)\n#define STR(...) std::string\
    \ __VA_ARGS__; in(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)\n\
    #define LD(...) long double __VA_ARGS__; in(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) std::vector<type> name(size); in(name)\n#define VV(type, name, h, w) std::vector<std::vector<type>>\
    \ name(h, std::vector<type>(w)); in(name)\n#line 5 \"Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp\"\
    \nusing mint = Modint<MOD>;\nvoid solve() {\n    LL(N);\n    MFPrefixSum<mint>\
    \ mf(N);\n    auto pi = mf.pi_table(), prime_sum = mf.prime_sum_table();\n   \
    \ rep(i, len(pi)) prime_sum[i] -= pi[i];\n    out(mf.min25_sieve(prime_sum, [](ll\
    \ x, ll c) {\n              mint ret = 1;\n              rep(i, c) ret *= x;\n\
    \              return ret - ret / x;\n          }).back());\n}\nint main() { solve();\
    \ }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include \"../../Math/MFPrefixSum.hpp\"\n#include \"../../Modint/Modint.hpp\"\
    \n#include \"../../Template/Template.hpp\"\nusing mint = Modint<MOD>;\nvoid solve()\
    \ {\n    LL(N);\n    MFPrefixSum<mint> mf(N);\n    auto pi = mf.pi_table(), prime_sum\
    \ = mf.prime_sum_table();\n    rep(i, len(pi)) prime_sum[i] -= pi[i];\n    out(mf.min25_sieve(prime_sum,\
    \ [](ll x, ll c) {\n              mint ret = 1;\n              rep(i, c) ret *=\
    \ x;\n              return ret - ret / x;\n          }).back());\n}\nint main()\
    \ { solve(); }"
  dependsOn:
  - Math/MFPrefixSum.hpp
  - Math/EnumeratePrimes.hpp
  - Modint/Modint.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2024-10-23 17:50:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
- /verify/Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp.html
title: Verify/verify-yosupo-number-theory/sum_of_totient_function.test.cpp
---
