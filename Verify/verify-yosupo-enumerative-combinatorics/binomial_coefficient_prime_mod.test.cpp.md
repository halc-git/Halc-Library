---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/ModCombination.hpp
    title: Math/ModCombination.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#line 2 \"Math/ModCombination.hpp\"\n#include <cstdint>\n#include <vector>\n\
    template <typename T>\nstruct ModCombination {\n    std::vector<T> fact = {1},\
    \ rev{1};\n    ModCombination(uint32_t sz = 0) {\n        fact.reserve(sz+1);\n\
    \        rev.reserve(sz+1);\n    }\n    void resize(uint32_t sz) {\n        sz++;\n\
    \        if (fact.size() >= sz) return;\n        uint32_t before = fact.size();\n\
    \        fact.resize(sz);\n        rev.resize(sz);\n        for (uint32_t i =\
    \ before; i < sz; i++) {\n            fact[i] = fact[i - 1] * i;\n           \
    \ rev[i] = rev[i - 1] / i;\n        }\n    }\n    T comb(int32_t n, int32_t k)\
    \ {\n        if (n < 0 || k < 0 || n < k) return 0;\n        resize(n);\n    \
    \    return fact[n] * rev[n - k] * rev[k];\n    }\n    T perm(int32_t n, int32_t\
    \ k) {\n        if (n < 0 || k < 0 || n < k) return 0;\n        resize(n);\n \
    \       return fact[n] * rev[n - k];\n    }\n    T multi_comb(int32_t n, int32_t\
    \ k) {\n        if (k == 0) return 1;\n        return comb(n + k - 1, k);\n  \
    \  }\n};\n#line 2 \"Modint/Modint.hpp\"\n#include <assert.h>\n\n#line 5 \"Modint/Modint.hpp\"\
    \n#include <iostream>\ntemplate <uint64_t Mod>\nstruct Modint {\n    uint64_t\
    \ x;\n    constexpr Modint() noexcept { x = 0; }\n    constexpr Modint(int64_t\
    \ val) noexcept {\n        x = (val < 0 ? val % (int64_t)(Mod) + Mod : val % Mod);\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val) noexcept {\n        const static\
    \ uint64_t m_inv = (-1ULL) / Mod + 1;\n        uint64_t ret = ((unsigned __int128)(val)*m_inv)\
    \ >> 64;\n        uint64_t pro = ret * Mod;\n        return (val - pro + (val\
    \ < pro ? Mod : 0));\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, Modint &b) noexcept {\n        return os << b.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &b) noexcept {\n        return is >> b.x;\n\
    \    }\n    constexpr uint64_t val() noexcept { return x; }\n    constexpr Modint\
    \ operator+() noexcept { return (*this); }\n    constexpr Modint operator-() noexcept\
    \ { return Modint() - (*this); }\n    friend Modint operator+(const Modint lhs,\
    \ const Modint rhs) noexcept {\n        return Modint(lhs) += rhs;\n    }\n  \
    \  friend Modint operator-(const Modint lhs, const Modint rhs) noexcept {\n  \
    \      return Modint(lhs) -= rhs;\n    }\n    friend Modint operator*(const Modint\
    \ lhs, const Modint rhs) noexcept {\n        return Modint(lhs) *= rhs;\n    }\n\
    \    friend Modint operator/(const Modint lhs, const Modint rhs) {\n        return\
    \ Modint(lhs) /= rhs;\n    }\n    constexpr Modint &operator+=(const Modint rhs)\
    \ noexcept {\n        x += rhs.x;\n        if (x >= Mod) x -= Mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator-=(const Modint rhs) noexcept {\n\
    \        if (x < rhs.x) x += Mod;\n        x -= rhs.x;\n        return *this;\n\
    \    }\n    constexpr Modint &operator*=(const Modint rhs) noexcept {\n      \
    \  x = _get_mod(x * rhs.x);\n        return *this;\n    }\n    friend bool operator==(const\
    \ Modint lhs, const Modint rhs) noexcept {\n        return lhs.x == rhs.x;\n \
    \   }\n    friend bool operator!=(const Modint lhs, const Modint rhs) noexcept\
    \ {\n        return rhs.x != rhs.x;\n    }\n    constexpr Modint &operator/=(Modint\
    \ rhs) { return (*this) *= rhs.inv(); }\n    constexpr Modint inv() {\n      \
    \  int64_t a = (*this).x, b = get_mod();\n        assert(a != 0);\n        int64_t\
    \ s = b, t = a;\n        int64_t m0 = 0, m1 = 1;\n        while (t) {\n      \
    \      int64_t u = s / t;\n            s -= t * u;\n            m0 -= m1 * u;\n\
    \            int64_t tmp = s;\n            s = t;\n            t = tmp;\n    \
    \        tmp = m0;\n            m0 = m1;\n            m1 = tmp;\n        }\n \
    \       assert(s == 1);\n        if (m0 < 0) m0 += b;\n        return Modint(m0);\n\
    \    }\n    constexpr Modint pow(uint64_t x) noexcept {\n        Modint ret =\
    \ 1;\n        Modint bin = (*this);\n        while (x) {\n            if (x &\
    \ 1) ret *= bin;\n            bin *= bin;\n            x >>= 1;\n        }\n \
    \       return ret;\n    }\n    static uint64_t get_mod() noexcept { return Mod;\
    \ }\n};\n\ntemplate <int64_t id>\nstruct ArbitraryModint {\n    uint64_t x;\n\
    \    static uint64_t &mod() noexcept {\n        static uint64_t Mod = 0;\n   \
    \     return Mod;\n    }\n    constexpr ArbitraryModint() noexcept { x = 0; }\n\
    \    constexpr ArbitraryModint(int64_t val) noexcept {\n        x = (val < 0 ?\
    \ val % (int64_t)(get_mod()) + get_mod()\n                     : val % get_mod());\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val) noexcept {\n        const static\
    \ uint64_t m_inv = (-1ULL) / get_mod() + 1;\n        uint64_t ret = ((unsigned\
    \ __int128)(val)*m_inv) >> 64;\n        uint64_t pro = ret * get_mod();\n    \
    \    return (val - pro + (val < pro ? get_mod() : 0));\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os,\n                                    ArbitraryModint\
    \ &b) noexcept {\n        return os << b.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is,\n                                    ArbitraryModint &b) noexcept {\n \
    \       return is >> b.x;\n    }\n    constexpr uint64_t val() noexcept { return\
    \ x; }\n    constexpr ArbitraryModint operator+() noexcept { return (*this); }\n\
    \    constexpr ArbitraryModint operator-() noexcept {\n        return ArbitraryModint()\
    \ - (*this);\n    }\n    friend ArbitraryModint operator+(const ArbitraryModint\
    \ lhs,\n                                     const ArbitraryModint rhs) noexcept\
    \ {\n        return ArbitraryModint(lhs) += rhs;\n    }\n    friend ArbitraryModint\
    \ operator-(const ArbitraryModint lhs,\n                                     const\
    \ ArbitraryModint rhs) noexcept {\n        return ArbitraryModint(lhs) -= rhs;\n\
    \    }\n    friend ArbitraryModint operator*(const ArbitraryModint lhs,\n    \
    \                                 const ArbitraryModint rhs) noexcept {\n    \
    \    return ArbitraryModint(lhs) *= rhs;\n    }\n    friend ArbitraryModint operator/(const\
    \ ArbitraryModint lhs,\n                                     const ArbitraryModint\
    \ rhs) {\n        return ArbitraryModint(lhs) /= rhs;\n    }\n    constexpr ArbitraryModint\
    \ &operator+=(const ArbitraryModint rhs) noexcept {\n        x += rhs.x;\n   \
    \     if (x >= mod()) x -= mod();\n        return *this;\n    }\n    constexpr\
    \ ArbitraryModint &operator-=(const ArbitraryModint rhs) noexcept {\n        if\
    \ (x < rhs.x) x += mod();\n        x -= rhs.x;\n        return *this;\n    }\n\
    \    constexpr ArbitraryModint &operator*=(const ArbitraryModint rhs) noexcept\
    \ {\n        x = _get_mod(x * rhs.x);\n        return *this;\n    }\n    friend\
    \ bool operator==(const ArbitraryModint lhs,\n                           const\
    \ ArbitraryModint rhs) noexcept {\n        return lhs.x == rhs.x;\n    }\n   \
    \ friend bool operator!=(const ArbitraryModint lhs,\n                        \
    \   const ArbitraryModint rhs) noexcept {\n        return rhs.x != rhs.x;\n  \
    \  }\n    constexpr ArbitraryModint &operator/=(ArbitraryModint rhs) {\n     \
    \   return (*this) *= rhs.inv();\n    }\n    constexpr ArbitraryModint inv() {\n\
    \        int64_t a = (*this).x, b = get_mod();\n        assert(a != 0);\n    \
    \    int64_t s = b, t = a;\n        int64_t m0 = 0, m1 = 1;\n        while (t)\
    \ {\n            int64_t u = s / t;\n            s -= t * u;\n            m0 -=\
    \ m1 * u;\n            int64_t tmp = s;\n            s = t;\n            t = tmp;\n\
    \            tmp = m0;\n            m0 = m1;\n            m1 = tmp;\n        }\n\
    \        assert(s == 1);\n        if (m0 < 0) m0 += b;\n        return ArbitraryModint(m0);\n\
    \    }\n    constexpr ArbitraryModint pow(uint64_t x) noexcept {\n        ArbitraryModint\
    \ ret = 1;\n        ArbitraryModint bin = (*this);\n        while (x) {\n    \
    \        if (x & 1) ret *= bin;\n            bin *= bin;\n            x >>= 1;\n\
    \        }\n        return ret;\n    }\n    static void set_mod(const uint64_t\
    \ x) noexcept { mod() = x; }\n    static uint64_t get_mod() noexcept { return\
    \ mod(); }\n};\ntemplate <uint64_t N>\ninline void scan(Modint<N> &a) {\n    std::cin\
    \ >> a.x;\n}\ntemplate <int64_t id>\ninline void scan(ArbitraryModint<id> &a)\
    \ {\n    std::cin >> a.x;\n}\ntemplate <uint64_t N>\ninline void print(Modint<N>\
    \ a) {\n    std::cout << a.x;\n}\ntemplate <int64_t id>\ninline void print(ArbitraryModint<id>\
    \ a) {\n    std::cout << a.x;\n}\n#line 2 \"Template/Template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 8 \"Template/InOut.hpp\"\ninline\
    \ void scan() {}\ninline void scan(int32_t &a) { std::cin >> a; }\ninline void\
    \ scan(uint32_t &a) { std::cin >> a; }\ninline void scan(int64_t &a) { std::cin\
    \ >> a; }\ninline void scan(uint64_t &a) { std::cin >> a; }\ninline void scan(char\
    \ &a) { std::cin >> a; }\ninline void scan(float &a) { std::cin >> a; }\ninline\
    \ void scan(double &a) { std::cin >> a; }\ninline void scan(long double &a) {\
    \ std::cin >> a; }\ninline void scan(std::vector<bool> &vec) {\n    for (int32_t\
    \ i = 0; i < vec.size(); i++) {\n        int a;\n        scan(a);\n        vec[i]\
    \ = a;\n    }\n}\ninline void scan(std::string &a) { std::cin >> a; }\ntemplate\
    \ <class T>\ninline void scan(std::vector<T> &vec);\ntemplate <class T, size_t\
    \ size>\ninline void scan(std::array<T, size> &vec);\ntemplate <class T, class\
    \ L>\ninline void scan(std::pair<T, L> &p);\ntemplate <class T, size_t size>\n\
    inline void scan(T (&vec)[size]);\ntemplate <class T>\ninline void scan(std::vector<T>\
    \ &vec) {\n    for (auto &i : vec) scan(i);\n}\ntemplate <class T>\ninline void\
    \ scan(std::deque<T> &vec) {\n    for (auto &i : vec) scan(i);\n}\ntemplate <class\
    \ T, size_t size>\ninline void scan(std::array<T, size> &vec) {\n    for (auto\
    \ &i : vec) scan(i);\n}\ntemplate <class T, class L>\ninline void scan(std::pair<T,\
    \ L> &p) {\n    scan(p.first);\n    scan(p.second);\n}\ntemplate <class T, size_t\
    \ size>\ninline void scan(T (&vec)[size]) {\n    for (auto &i : vec) scan(i);\n\
    }\ntemplate <class T>\ninline void scan(T &a) {\n    std::cin >> a;\n}\ninline\
    \ void in() {}\ntemplate <class Head, class... Tail>\ninline void in(Head &head,\
    \ Tail &...tail) {\n    scan(head);\n    in(tail...);\n}\ninline void print()\
    \ { std::cout << ' '; }\ninline void print(const bool &a) { std::cout << a; }\n\
    inline void print(const int32_t &a) { std::cout << a; }\ninline void print(const\
    \ uint32_t &a) { std::cout << a; }\ninline void print(const int64_t &a) { std::cout\
    \ << a; }\ninline void print(const uint64_t &a) { std::cout << a; }\ninline void\
    \ print(const char &a) { std::cout << a; }\ninline void print(const char a[])\
    \ { std::cout << a; }\ninline void print(const float &a) { std::cout << a; }\n\
    inline void print(const double &a) { std::cout << a; }\ninline void print(const\
    \ long double &a) { std::cout << a; }\ninline void print(const std::string &a)\
    \ {\n    for (auto &&i : a) print(i);\n}\ntemplate <class T>\ninline void print(const\
    \ std::vector<T> &vec);\ntemplate <class T, size_t size>\ninline void print(const\
    \ std::array<T, size> &vec);\ntemplate <class T, class L>\ninline void print(const\
    \ std::pair<T, L> &p);\ntemplate <class T, size_t size>\ninline void print(const\
    \ T (&vec)[size]);\ntemplate <class T>\ninline void print(const std::vector<T>\
    \ &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n    for (auto i =\
    \ vec.begin(); ++i != vec.end();) {\n        std::cout << ' ';\n        print(*i);\n\
    \    }\n}\ntemplate <class T>\ninline void print(const std::deque<T> &vec) {\n\
    \    if (vec.empty()) return;\n    print(vec[0]);\n    for (auto i = vec.begin();\
    \ ++i != vec.end();) {\n        std::cout << ' ';\n        print(*i);\n    }\n\
    }\ntemplate <class T, size_t size>\ninline void print(const std::array<T, size>\
    \ &vec) {\n    print(vec[0]);\n    for (auto i = vec.begin(); ++i != vec.end();)\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 5 \"Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp\"\
    \nusing mint = ArbitraryModint<0>;\nvoid solve() {\n    LL(T, m);\n    mint::set_mod(m);\n\
    \    ModCombination<mint> comb(10000000);\n    rep(i, T) {\n        LL(n, k);\n\
    \        out(comb.comb(n, k));\n    }\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include \"../../Math/ModCombination.hpp\"\n#include \"../../Modint/Modint.hpp\"\
    \n#include \"../../Template/Template.hpp\"\nusing mint = ArbitraryModint<0>;\n\
    void solve() {\n    LL(T, m);\n    mint::set_mod(m);\n    ModCombination<mint>\
    \ comb(10000000);\n    rep(i, T) {\n        LL(n, k);\n        out(comb.comb(n,\
    \ k));\n    }\n}\nint main() { solve(); }"
  dependsOn:
  - Math/ModCombination.hpp
  - Modint/Modint.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-10-22 20:55:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
- /verify/Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp.html
title: Verify/verify-yosupo-enumerative-combinatorics/binomial_coefficient_prime_mod.test.cpp
---