---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Template/InOut.hpp
    title: Template/InOut.hpp
  - icon: ':x:'
    path: Template/Macro.hpp
    title: Template/Macro.hpp
  - icon: ':x:'
    path: Template/Util.hpp
    title: Template/Util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
    title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
    title: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
    title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-string/zalgorithm.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/1092.test.cpp
    title: Verify/verify-yuki/1092.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/2338.test.cpp
    title: Verify/verify-yuki/2338.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 8 \"Template/InOut.hpp\"\ninline int scan() { return\
    \ getchar(); }\ninline void scan(int &a) { scanf(\"%d\", &a); }\ninline void scan(unsigned\
    \ &a) { scanf(\"%u\", &a); }\ninline void scan(long &a) { scanf(\"%ld\", &a);\
    \ }\ninline void scan(long long &a) { scanf(\"%lld\", &a); }\ninline void scan(unsigned\
    \ long long &a) { scanf(\"%llu\", &a); }\ninline void scan(char &a) { std::cin\
    \ >> a; }\ninline void scan(float &a) { scanf(\"%f\", &a); }\ninline void scan(double\
    \ &a) { scanf(\"%lf\", &a); }\ninline void scan(long double &a) { scanf(\"%Lf\"\
    , &a); }\ninline void scan(std::vector<bool> &vec) {\n    for (unsigned i = 0;\
    \ i < vec.size(); i++) {\n        int a;\n        scan(a);\n        vec[i] = a;\n\
    \    }\n}\ninline void scan(char a[]) { scanf(\"%s\", a); }\ninline void scan(std::string\
    \ &a) { std::cin >> a; }\ntemplate <class T>\ninline void scan(std::vector<T>\
    \ &vec);\ntemplate <class T, size_t size>\ninline void scan(std::array<T, size>\
    \ &vec);\ntemplate <class T, class L>\ninline void scan(std::pair<T, L> &p);\n\
    template <class T, size_t size>\ninline void scan(T (&vec)[size]);\ntemplate <class\
    \ T>\ninline void scan(std::vector<T> &vec) {\n    for (auto &i : vec) scan(i);\n\
    }\ntemplate <class T>\ninline void scan(std::deque<T> &vec) {\n    for (auto &i\
    \ : vec) scan(i);\n}\ntemplate <class T, size_t size>\ninline void scan(std::array<T,\
    \ size> &vec) {\n    for (auto &i : vec) scan(i);\n}\ntemplate <class T, class\
    \ L>\ninline void scan(std::pair<T, L> &p) {\n    scan(p.first);\n    scan(p.second);\n\
    }\ntemplate <class T, size_t size>\ninline void scan(T (&vec)[size]) {\n    for\
    \ (auto &i : vec) scan(i);\n}\ntemplate <class T>\ninline void scan(T &a) {\n\
    \    std::cin >> a;\n}\ninline void in() {}\ntemplate <class Head, class... Tail>\n\
    inline void in(Head &head, Tail &...tail) {\n    scan(head);\n    in(tail...);\n\
    }\ninline void print() { putchar(' '); }\ninline void print(const bool &a) { printf(\"\
    %d\", a); }\ninline void print(const int &a) { printf(\"%d\", a); }\ninline void\
    \ print(const unsigned &a) { printf(\"%u\", a); }\ninline void print(const long\
    \ &a) { printf(\"%ld\", a); }\ninline void print(const long long &a) { printf(\"\
    %lld\", a); }\ninline void print(const unsigned long long &a) { printf(\"%llu\"\
    , a); }\ninline void print(const char &a) { printf(\"%c\", a); }\ninline void\
    \ print(const char a[]) { printf(\"%s\", a); }\ninline void print(const float\
    \ &a) { printf(\"%.15f\", a); }\ninline void print(const double &a) { printf(\"\
    %.15f\", a); }\ninline void print(const long double &a) { printf(\"%.15Lf\", a);\
    \ }\ninline void print(const std::string &a) {\n    for (auto &&i : a) print(i);\n\
    }\ntemplate <class T>\ninline void print(const std::vector<T> &vec);\ntemplate\
    \ <class T, size_t size>\ninline void print(const std::array<T, size> &vec);\n\
    template <class T, class L>\ninline void print(const std::pair<T, L> &p);\ntemplate\
    \ <class T, size_t size>\ninline void print(const T (&vec)[size]);\ntemplate <class\
    \ T>\ninline void print(const std::vector<T> &vec) {\n    if (vec.empty()) return;\n\
    \    print(vec[0]);\n    for (auto i = vec.begin(); ++i != vec.end();) {\n   \
    \     putchar(' ');\n        print(*i);\n    }\n}\ntemplate <class T>\ninline\
    \ void print(const std::deque<T> &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n\
    \    for (auto i = vec.begin(); ++i != vec.end();) {\n        putchar(' ');\n\
    \        print(*i);\n    }\n}\ntemplate <class T, size_t size>\ninline void print(const\
    \ std::array<T, size> &vec) {\n    print(vec[0]);\n    for (auto i = vec.begin();\
    \ ++i != vec.end();) {\n        putchar(' ');\n        print(*i);\n    }\n}\n\
    template <class T, class L>\ninline void print(const std::pair<T, L> &p) {\n \
    \   print(p.first);\n    putchar(' ');\n    print(p.second);\n}\ntemplate <class\
    \ T, size_t size>\ninline void print(const T (&vec)[size]) {\n    print(vec[0]);\n\
    \    for (auto i = vec; ++i != end(vec);) {\n        putchar(' ');\n        print(*i);\n\
    \    }\n}\ntemplate <class T>\ninline void print(const T &a) {\n    std::cout\
    \ << a;\n}\ninline void out() { putchar('\\n'); }\ntemplate <class T>\ninline\
    \ void out(const T &t) {\n    print(t);\n    putchar('\\n');\n}\ntemplate <class\
    \ Head, class... Tail>\ninline void out(const Head &head, const Tail &...tail)\
    \ {\n    print(head);\n    putchar(' ');\n    out(tail...);\n}\ninline void Yes(bool\
    \ i = true) { out(i ? \"Yes\" : \"No\"); }\ninline void No(bool i = true) { out(i\
    \ ? \"No\" : \"Yes\"); }\n#line 1 \"Template/Macro.hpp\"\n#define _overload3(_1,\
    \ _2, _3, name, ...) name\n#define _overload4(_1, _2, _3, _4, name, ...) name\n\
    #define _rep1(i, n) for (ll i = 0; i < (n); i++)\n#define _rep2(i, a, b) for (ll\
    \ i = (a); i < (b); i++)\n#define _rep3(i, a, b, c) for (ll i = (a); i < (b);\
    \ i += (c))\n#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
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
    \ std::end(a));\n}\n#line 8 \"Template/Template.hpp\"\n"
  code: '#pragma once

    #include <bits/stdc++.h>

    using namespace std;


    #include "InOut.hpp"

    #include "Macro.hpp"

    #include "Util.hpp"'
  dependsOn:
  - Template/InOut.hpp
  - Template/Macro.hpp
  - Template/Util.hpp
  isVerificationFile: false
  path: Template/Template.hpp
  requiredBy: []
  timestamp: '2024-05-10 16:22:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - Verify/verify-yuki/1092.test.cpp
  - Verify/verify-yuki/117.test.cpp
  - Verify/verify-yuki/2338.test.cpp
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - Verify/verify-yosupo-datastructure/unionfind.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - Verify/verify-yosupo-string/zalgorithm.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
documentation_of: Template/Template.hpp
layout: document
redirect_from:
- /library/Template/Template.hpp
- /library/Template/Template.hpp.html
title: Template/Template.hpp
---
