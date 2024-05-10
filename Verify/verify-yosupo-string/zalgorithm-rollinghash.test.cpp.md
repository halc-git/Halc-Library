---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/Random.hpp
    title: Misc/Random.hpp
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.hpp
    title: String/RollingHash.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"String/RollingHash.hpp\"\
    \n#include <random>\n#include <vector>\n\n#line 2 \"Misc/Random.hpp\"\n#include\
    \ <chrono>\n#include <cstdint>\ninline uint32_t pcg32_fast() {\n    static uint64_t\
    \ state =\n        (std::chrono::steady_clock::now().time_since_epoch().count()\
    \ << 1) + 1;\n    uint64_t x = state;\n    uint8_t count = x >> 61;\n    state\
    \ *= 0xf13283ad;\n    x ^= x >> 22;\n    return (uint32_t)(x >> (22 + count));\n\
    }\ninline int32_t randint(int32_t l, int32_t r) {\n    return l + (((int64_t)pcg32_fast()\
    \ * (r - l + 1)) >> 32);\n}\n#line 6 \"String/RollingHash.hpp\"\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    template <typename S>\nstruct RollingHash {\n    using u64 = uint64_t;\n    static\
    \ const u64 MOD = (1ULL << 61) - 1;\n    static const u64 MASK31 = (1ULL << 31)\
    \ - 1;\n    static const u64 MASK30 = (1ULL << 30) - 1;\n    std::vector<u64>\
    \ powers;\n    u64 base, fixed;\n    static inline u64 add(u64 a, u64 b) {\n \
    \       if ((a += b) >= MOD) a -= MOD;\n        return a;\n    }\n    static inline\
    \ u64 calc_mod(u64 x) {\n        u64 xu = x >> 61, xd = x & MOD;\n        u64\
    \ ret = xu + xd;\n        if (ret >= MOD) ret -= MOD;\n        return ret;\n \
    \   }\n    static inline u64 mul(u64 a, u64 b) {\n        u64 au = a >> 31, ad\
    \ = a & MASK31, bu = b >> 31, bd = b & MASK31;\n        u64 mid = ad * bu + au\
    \ * bd;\n        u64 midu = mid >> 30, midd = mid & MASK30;\n        return calc_mod(((au\
    \ * bu) << 1) + midu + (midd << 31) + ad * bd);\n    }\n    static inline u64\
    \ generate_base() {\n        std::mt19937_64 mt(pcg32_fast());\n        std::uniform_int_distribution<u64>\
    \ rand(1ULL << 60, MOD - 1);\n        return rand(mt);\n    }\n    explicit RollingHash(u64\
    \ base_number = generate_base(),\n                         u64 fixed_number =\
    \ 1ULL << 31) {\n        base = base_number;\n        fixed = fixed_number;\n\
    \        powers = {1};\n    }\n    std::vector<u64> build(const S &s) {\n    \
    \    uint32_t sz = s.size();\n        std::vector<u64> hashed(sz + 1, 0);\n  \
    \      while (powers.size() <= sz) {\n            powers.emplace_back(mul(powers.back(),\
    \ base));\n        }\n        for (uint32_t i = 0; i < sz; i++) {\n          \
    \  hashed[i + 1] = add(mul(hashed[i], base), s[i] + fixed);\n        }\n     \
    \   return hashed;\n    }\n    u64 query(const std::vector<u64> &s, uint32_t lf,\
    \ uint32_t ri) {\n        int64_t ret = s[ri] - mul(s[lf], powers[ri - lf]);\n\
    \        if (ret < 0) ret += MOD;\n        return ret;\n    }\n    u64 combine(u64\
    \ h1, u64 h2, uint32_t h2len) {\n        return add(mul(h1, powers[h2len]), h2);\n\
    \    }\n    uint32_t lcp(const std::vector<u64> &a, uint32_t l1, uint32_t r1,\n\
    \                 const std::vector<u64> &b, uint32_t l2, uint32_t r2) {\n   \
    \     uint32_t ok = 0, ng = std::min((r1 - l1), (r2 - l2)) + 1;\n        while\
    \ (ng - ok > 1) {\n            uint32_t mid = (ok + ng) >> 1;\n            if\
    \ (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n                ok = mid;\n\
    \            else\n                ng = mid;\n        }\n        return ok;\n\
    \    }\n};\n#line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 8 \"Template/InOut.hpp\"\ninline void scan() {}\ninline\
    \ void scan(int &a) { std::cin >> a; }\ninline void scan(unsigned &a) { std::cin\
    \ >> a; }\ninline void scan(long &a) { std::cin >> a; }\ninline void scan(long\
    \ long &a) { std::cin >> a; }\ninline void scan(unsigned long long &a) { std::cin\
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
    \ std::cout << a; }\ninline void print(const int &a) { std::cout << a; }\ninline\
    \ void print(const unsigned &a) { std::cout << a; }\ninline void print(const long\
    \ &a) { std::cout << a; }\ninline void print(const long long &a) { std::cout <<\
    \ a; }\ninline void print(const unsigned long long &a) { std::cout << a; }\ninline\
    \ void print(const char &a) { std::cout << a; }\ninline void print(const char\
    \ a[]) { std::cout << a; }\ninline void print(const float &a) { std::cout << a;\
    \ }\ninline void print(const double &a) { std::cout << a; }\ninline void print(const\
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
    \ { out(i ? \"No\" : \"Yes\"); }\nstruct IOsetup {\n    IOsetup() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        std::cout << std::setprecision(10);\n\
    \    }\n} iosetup;\n#line 1 \"Template/Macro.hpp\"\n#define _overload3(_1, _2,\
    \ _3, name, ...) name\n#define _overload4(_1, _2, _3, _4, name, ...) name\n#define\
    \ _rep1(i, n) for (ll i = 0; i < (n); i++)\n#define _rep2(i, a, b) for (ll i =\
    \ (a); i < (b); i++)\n#define _rep3(i, a, b, c) for (ll i = (a); i < (b); i +=\
    \ (c))\n#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define _rrep1(i, n) for (ll i = (n); i-- > 0;)\n#define _rrep2(i, a, b) for (ll\
    \ i = (b); i-- > (a);)\n#define rrep(...) _overload3(__VA_ARGS__, _rrep2, _rrep1)(__VA_ARGS__)\n\
    #define each(i, ...) for (auto&& i : __VA_ARGS__)\n#define all(i) std::begin(i),\
    \ std::end(i)\n#define rall(i) std::rbegin(i), std::rend(i)\n#define len(x) ((int)(x).size())\n\
    #define fi first\n#define se second\n#define uniq(x) x.erase(unique(all(x)), std::end(x))\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__);\n#define vv(type,\
    \ name, h, ...) \\\n    std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__));\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define ULL(...)\
    \     \\\n    ull __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define STR(...)     \
    \   \\\n    string __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define CHR(...)    \
    \  \\\n    char __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define LD(...)     \\\n\
    \    ld __VA_ARGS__; \\\n    in(__VA_ARGS__)\n#define VEC(type, name, size)  \
    \   \\\n    std::vector<type> name(size); \\\n    in(name)\n#define VV(type, name,\
    \ h, w)                                      \\\n    std::vector<std::vector<type>>\
    \ name(h, std::vector<type>(w)); \\\n    in(name)\n#line 8 \"Template/Util.hpp\"\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    using uint = unsigned int;\nusing pll = std::pair<ll, ll>;\nusing pii = std::pair<int,\
    \ int>;\nusing vl = std::vector<ll>;\nusing vll = std::vector<ll>;\nusing pdd\
    \ = std::pair<ld, ld>;\nusing tuplis = std::array<ll, 3>;\ntemplate <class T>\n\
    using pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\nconst ll\
    \ LINF = 1LL << 60;\nconstexpr int INF = INT_MAX >> 1;\nconstexpr ll MINF = 1LL\
    \ << 40;\nconstexpr ld DINF = std::numeric_limits<ld>::infinity();\nconstexpr\
    \ int MODD = 1000000007;\nconstexpr int MOD = 998244353;\nconstexpr ld EPS = 1e-9;\n\
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
    \ std::end(a));\n}\n#line 4 \"Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp\"\
    \nvoid solve() {\n    STR(S);\n    vec(ll, ans, len(S));\n    RollingHash<string>\
    \ roll;\n    auto table = roll.build(S);\n    rep(i, len(S)) { ans[i] = roll.lcp(table,\
    \ i, len(S), table, 0, len(S)); }\n    out(ans);\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../../String/RollingHash.hpp\"\n#include \"../../Template/Template.hpp\"\n\
    void solve() {\n    STR(S);\n    vec(ll, ans, len(S));\n    RollingHash<string>\
    \ roll;\n    auto table = roll.build(S);\n    rep(i, len(S)) { ans[i] = roll.lcp(table,\
    \ i, len(S), table, 0, len(S)); }\n    out(ans);\n}\nint main() { solve(); }"
  dependsOn:
  - String/RollingHash.hpp
  - Misc/Random.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Macro.hpp
  - Template/Util.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  requiredBy: []
  timestamp: '2024-05-10 17:02:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
- /verify/Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp.html
title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
---
