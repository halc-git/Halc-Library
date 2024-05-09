---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FenwickTree.hpp
    title: DataStructure/FenwickTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"DataStructure/FenwickTree.hpp\"\n#include <bit>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <vector>\ntemplate <class T>\nstruct FenwickTree {\n   \
    \ std::vector<T> tree;\n    int32_t start = 1;\n    size_t siz;\n    FenwickTree(int32_t\
    \ sz) {\n        siz = sz;\n        tree.resize(sz + 1, 0);\n        start = 1\
    \ << ((32-std::countl_zero(siz)) - 1);\n    }\n    FenwickTree(std::vector<T>\
    \ def) {\n        siz = def.size();\n        tree.resize(siz + 1, 0);\n      \
    \  start = 1 << ((32-std::countl_zero(siz)) - 1);\n        for (int32_t i = 0;\
    \ i < siz; i++) {\n            tree[i + 1] += def[i];\n            if (i + (i\
    \ & -i) <= siz) {\n                tree[i + (i & -i)] += tree[i];\n          \
    \  }\n        }\n    }\n    void add(int32_t pos, T val) {\n        pos++;\n \
    \       while (pos <= siz) {\n            tree[pos] += val;\n            pos +=\
    \ pos & -pos;\n        }\n    }\n    T _sum(int32_t pos) {\n        T ret = 0;\n\
    \        while (pos > 0) {\n            ret += tree[pos];\n            pos -=\
    \ pos & -pos;\n        }\n        return ret;\n    }\n    T sum(int32_t lf, int32_t\
    \ ri) { return _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T w) {\n      \
    \  if (w <= 0) return 0;\n        int32_t now = 0;\n        T val = 0;\n     \
    \   for (int32_t i = start; i > 0; i >>= 1) {\n            if (now + i <= siz\
    \ && val + tree[now + i] < w) {\n                now += i;\n                val\
    \ += tree[now];\n            }\n        }\n        return now + 1;\n    }\n  \
    \  size_t size() { return siz; }\n};\n#line 2 \"Template/Template.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 8 \"Template/InOut.hpp\"\ninline\
    \ int scan() { return getchar(); }\ninline void scan(int &a) { scanf(\"%d\", &a);\
    \ }\ninline void scan(unsigned &a) { scanf(\"%u\", &a); }\ninline void scan(long\
    \ &a) { scanf(\"%ld\", &a); }\ninline void scan(long long &a) { scanf(\"%lld\"\
    , &a); }\ninline void scan(unsigned long long &a) { scanf(\"%llu\", &a); }\ninline\
    \ void scan(char &a) { std::cin >> a; }\ninline void scan(float &a) { scanf(\"\
    %f\", &a); }\ninline void scan(double &a) { scanf(\"%lf\", &a); }\ninline void\
    \ scan(long double &a) { scanf(\"%Lf\", &a); }\ninline void scan(std::vector<bool>\
    \ &vec) {\n    for (unsigned i = 0; i < vec.size(); i++) {\n        int a;\n \
    \       scan(a);\n        vec[i] = a;\n    }\n}\ninline void scan(char a[]) {\
    \ scanf(\"%s\", a); }\ninline void scan(std::string &a) { std::cin >> a; }\ntemplate\
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
    \ { putchar(' '); }\ninline void print(const bool &a) { printf(\"%d\", a); }\n\
    inline void print(const int &a) { printf(\"%d\", a); }\ninline void print(const\
    \ unsigned &a) { printf(\"%u\", a); }\ninline void print(const long &a) { printf(\"\
    %ld\", a); }\ninline void print(const long long &a) { printf(\"%lld\", a); }\n\
    inline void print(const unsigned long long &a) { printf(\"%llu\", a); }\ninline\
    \ void print(const char &a) { printf(\"%c\", a); }\ninline void print(const char\
    \ a[]) { printf(\"%s\", a); }\ninline void print(const float &a) { printf(\"%.15f\"\
    , a); }\ninline void print(const double &a) { printf(\"%.15f\", a); }\ninline\
    \ void print(const long double &a) { printf(\"%.15Lf\", a); }\ninline void print(const\
    \ std::string &a) {\n    for (auto &&i : a) print(i);\n}\ntemplate <class T>\n\
    inline void print(const std::vector<T> &vec);\ntemplate <class T, size_t size>\n\
    inline void print(const std::array<T, size> &vec);\ntemplate <class T, class L>\n\
    inline void print(const std::pair<T, L> &p);\ntemplate <class T, size_t size>\n\
    inline void print(const T (&vec)[size]);\ntemplate <class T>\ninline void print(const\
    \ std::vector<T> &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n \
    \   for (auto i = vec.begin(); ++i != vec.end();) {\n        putchar(' ');\n \
    \       print(*i);\n    }\n}\ntemplate <class T>\ninline void print(const std::deque<T>\
    \ &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n    for (auto i =\
    \ vec.begin(); ++i != vec.end();) {\n        putchar(' ');\n        print(*i);\n\
    \    }\n}\ntemplate <class T, size_t size>\ninline void print(const std::array<T,\
    \ size> &vec) {\n    print(vec[0]);\n    for (auto i = vec.begin(); ++i != vec.end();)\
    \ {\n        putchar(' ');\n        print(*i);\n    }\n}\ntemplate <class T, class\
    \ L>\ninline void print(const std::pair<T, L> &p) {\n    print(p.first);\n   \
    \ putchar(' ');\n    print(p.second);\n}\ntemplate <class T, size_t size>\ninline\
    \ void print(const T (&vec)[size]) {\n    print(vec[0]);\n    for (auto i = vec;\
    \ ++i != end(vec);) {\n        putchar(' ');\n        print(*i);\n    }\n}\ntemplate\
    \ <class T>\ninline void print(const T &a) {\n    std::cout << a;\n}\ninline void\
    \ out() { putchar('\\n'); }\ntemplate <class T>\ninline void out(const T &t) {\n\
    \    print(t);\n    putchar('\\n');\n}\ntemplate <class Head, class... Tail>\n\
    inline void out(const Head &head, const Tail &...tail) {\n    print(head);\n \
    \   putchar(' ');\n    out(tail...);\n}\ninline void Yes(bool i = true) { out(i\
    \ ? \"Yes\" : \"No\"); }\ninline void No(bool i = true) { out(i ? \"No\" : \"\
    Yes\"); }\n#line 1 \"Template/Macro.hpp\"\n#define _overload3(_1, _2, _3, name,\
    \ ...) name\n#define _overload4(_1, _2, _3, _4, name, ...) name\n#define _rep1(i,\
    \ n) for (ll i = 0; i < (n); i++)\n#define _rep2(i, a, b) for (ll i = (a); i <\
    \ (b); i++)\n#define _rep3(i, a, b, c) for (ll i = (a); i < (b); i += (c))\n#define\
    \ rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define\
    \ _rrep1(i, n) for (ll i = (n); i-- > 0;)\n#define _rrep2(i, a, b) for (ll i =\
    \ (b); i-- > (a);)\n#define rrep(...) _overload3(__VA_ARGS__, _rrep2, _rrep1)(__VA_ARGS__)\n\
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
    \ ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};\nstatic ll intpow(ll a, ll b) {\n\
    \    ll ret = 1;\n    while (b) {\n        if (b & 1) ret *= a;\n        a *=\
    \ a;\n        b >>= 1;\n    }\n    return ret;\n}\ntemplate <class T>\nbool chmin(T\
    \ &a, const T &b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    } else\n        return false;\n}\ntemplate <class T>\nbool chmax(T &a, const\
    \ T &b) {\n    if (a < b) {\n        a = b;\n        return true;\n    } else\n\
    \        return false;\n}\ntemplate <class T>\nll sum(const T &a) {\n    return\
    \ accumulate(std::begin(a), std::end(a), 0LL);\n}\ntemplate <class T>\nld dsum(const\
    \ T &a) {\n    return accumulate(std::begin(a), std::end(a), 0.0L);\n}\ntemplate\
    \ <class T>\nauto min(const T &a) {\n    return *min_element(std::begin(a), std::end(a));\n\
    }\ntemplate <class T>\nauto max(const T &a) {\n    return *max_element(std::begin(a),\
    \ std::end(a));\n}\n#line 8 \"Template/Template.hpp\"\nnamespace Halc {\nvoid\
    \ solve();\n}\nint main() { Halc::solve(); }\n#line 4 \"Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp\"\
    \nvoid Halc::solve() {\n    LL(N, Q);\n    VEC(ll, A, N);\n    FenwickTree<ll>\
    \ a(A);\n    rep(i, Q) {\n        LL(t, x, y);\n        if (t == 0) {\n      \
    \      a.add(x, y);\n        } else {\n            out(a.sum(x, y));\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../../DataStructure/FenwickTree.hpp\"\n#include \"../../Template/Template.hpp\"\
    \nvoid Halc::solve() {\n    LL(N, Q);\n    VEC(ll, A, N);\n    FenwickTree<ll>\
    \ a(A);\n    rep(i, Q) {\n        LL(t, x, y);\n        if (t == 0) {\n      \
    \      a.add(x, y);\n        } else {\n            out(a.sum(x, y));\n       \
    \ }\n    }\n}"
  dependsOn:
  - DataStructure/FenwickTree.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Macro.hpp
  - Template/Util.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-09 20:10:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
- /verify/Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp.html
title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
---
