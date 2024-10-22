---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.hpp
    title: String/RollingHash.hpp
  - icon: ':heavy_check_mark:'
    path: Template/InOut.hpp
    title: Template/InOut.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Macro.hpp
    title: Template/Macro.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Util.hpp
    title: Template/Util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#line 2 \"String/RollingHash.hpp\"\n#include <chrono>\n#include <random>\n#include\
    \ <vector>\n\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\ntemplate\
    \ <typename S>\nstruct RollingHash {\n    using u64 = uint64_t;\n    static const\
    \ u64 MOD = (1ULL << 61) - 1;\n    static const u64 MASK31 = (1ULL << 31) - 1;\n\
    \    static const u64 MASK30 = (1ULL << 30) - 1;\n    std::vector<u64> powers;\n\
    \    u64 base, fixed;\n    static inline u64 add(u64 a, u64 b) {\n        if ((a\
    \ += b) >= MOD) a -= MOD;\n        return a;\n    }\n    static inline u64 calc_mod(u64\
    \ x) {\n        u64 xu = x >> 61, xd = x & MOD;\n        u64 ret = xu + xd;\n\
    \        if (ret >= MOD) ret -= MOD;\n        return ret;\n    }\n    static inline\
    \ u64 mul(u64 a, u64 b) {\n        u64 au = a >> 31, ad = a & MASK31, bu = b >>\
    \ 31, bd = b & MASK31;\n        u64 mid = ad * bu + au * bd;\n        u64 midu\
    \ = mid >> 30, midd = mid & MASK30;\n        return calc_mod(((au * bu) << 1)\
    \ + midu + (midd << 31) + ad * bd);\n    }\n    static inline u64 generate_base()\
    \ {\n        std::mt19937_64 mt(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<u64> rand(1ULL << 60, MOD - 1);\n     \
    \   return rand(mt);\n    }\n    explicit RollingHash(u64 base_number = generate_base(),\n\
    \                         u64 fixed_number = 1ULL << 31) {\n        base = base_number;\n\
    \        fixed = fixed_number;\n        powers = {1};\n    }\n    std::vector<u64>\
    \ build(const S &s) {\n        uint32_t sz = s.size();\n        std::vector<u64>\
    \ hashed(sz + 1, 0);\n        while (powers.size() <= sz) {\n            powers.emplace_back(mul(powers.back(),\
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
    \ void scan(int32_t &a) { std::cin >> a; }\ninline void scan(uint32_t &a) { std::cin\
    \ >> a; }\ninline void scan(int64_t &a) { std::cin >> a; }\ninline void scan(uint64_t\
    \ &a) { std::cin >> a; }\ninline void scan(char &a) { std::cin >> a; }\ninline\
    \ void scan(float &a) { std::cin >> a; }\ninline void scan(double &a) { std::cin\
    \ >> a; }\ninline void scan(long double &a) { std::cin >> a; }\ninline void scan(std::vector<bool>\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 4 \"Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp\"\
    \nvoid solve() {\n    STR(T);\n    STR(P);\n    RollingHash<string> roll;\n  \
    \  auto tb = roll.build(T);\n    auto pb = roll.build(P);\n    ll hash = roll.query(pb,\
    \ 0, len(P));\n    rep(i, len(T) - len(P) + 1) {\n        if (roll.query(tb, i,\
    \ i + len(P)) == hash) out(i);\n    }\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include \"../../String/RollingHash.hpp\"\n#include \"../../Template/Template.hpp\"\
    \nvoid solve() {\n    STR(T);\n    STR(P);\n    RollingHash<string> roll;\n  \
    \  auto tb = roll.build(T);\n    auto pb = roll.build(P);\n    ll hash = roll.query(pb,\
    \ 0, len(P));\n    rep(i, len(T) - len(P) + 1) {\n        if (roll.query(tb, i,\
    \ i + len(P)) == hash) out(i);\n    }\n}\nint main() { solve(); }"
  dependsOn:
  - String/RollingHash.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  requiredBy: []
  timestamp: '2024-10-22 20:46:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
- /verify/Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp.html
title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
---
