---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Hashmap.hpp
    title: DataStructure/Hashmap.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#line\
    \ 2 \"DataStructure/Hashmap.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <chrono>\n\n// https://codeforces.com/blog/entry/62393?locale=en\nstruct\
    \ custom_hash {\n    // http://xorshift.di.unimi.it/splitmix64.c\n    static uint64_t\
    \ splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^\
    \ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n    uint64_t operator()(uint64_t x) const\
    \ {\n        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\ntemplate <typename Key,\
    \ typename Val>\nusing Hashmap = __gnu_pbds::gp_hash_table<Key, Val, custom_hash>;\n\
    #line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#line 8 \"Template/InOut.hpp\"\ninline void scan() {}\ninline void scan(int32_t\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 4 \"Verify/verify-yosupo-datastructure/associative_array.test.cpp\"\
    \nvoid solve() {\n    LL(Q);\n    Hashmap<ll, ll> a;\n    rep(i, Q) {\n      \
    \  LL(t, k);\n        if (t == 0) {\n            LL(v);\n            a[k] = v;\n\
    \        } else {\n            out(a[k]);\n        }\n    }\n}\nint main() { solve();\
    \ }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../../DataStructure/Hashmap.hpp\"\n#include \"../../Template/Template.hpp\"\
    \nvoid solve() {\n    LL(Q);\n    Hashmap<ll, ll> a;\n    rep(i, Q) {\n      \
    \  LL(t, k);\n        if (t == 0) {\n            LL(v);\n            a[k] = v;\n\
    \        } else {\n            out(a[k]);\n        }\n    }\n}\nint main() { solve();\
    \ }"
  dependsOn:
  - DataStructure/Hashmap.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-10-22 20:46:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/associative_array.test.cpp
- /verify/Verify/verify-yosupo-datastructure/associative_array.test.cpp.html
title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
---
