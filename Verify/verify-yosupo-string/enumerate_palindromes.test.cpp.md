---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Manacher.hpp
    title: String/Manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"Verify/verify-yosupo-string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #line 2 \"String/Manacher.hpp\"\n#include <cstdint>\n#include <vector>\n// https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template <typename S>\nstd::vector<int32_t> manacher(S s, bool is_even = true)\
    \ {\n    int32_t i = 0, j = 0, k, sz = (s.size() << is_even) - is_even;\n    std::vector<int32_t>\
    \ ret(sz);\n    while (i < sz) {\n        if (is_even) {\n            while (i\
    \ - j >= -1 && i + j <= sz &&\n                   (((i - j) & 1) || s[(i - j)\
    \ >> 1] == s[(i + j) >> 1]))\n                j++;\n        } else {\n       \
    \     while (i - j >= 0 && i + j < sz && s[i - j] == s[i + j]) j++;\n        }\n\
    \        ret[i] = j;\n        k = 1;\n        while (i - k >= 0 && k + ret[i -\
    \ k] < j) {\n            ret[i + k] = ret[i - k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    for (int32_t i = 0; i < sz; i++)\
    \ {\n        if (is_even) {\n            ret[i]--;\n        } else {\n       \
    \     ret[i] = (ret[i] << 1) - 1;\n        }\n    }\n    return ret;\n}\n#line\
    \ 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#line 8 \"Template/InOut.hpp\"\ninline void scan() {}\ninline void scan(int\
    \ &a) { std::cin >> a; }\ninline void scan(unsigned &a) { std::cin >> a; }\ninline\
    \ void scan(long &a) { std::cin >> a; }\ninline void scan(long long &a) { std::cin\
    \ >> a; }\ninline void scan(unsigned long long &a) { std::cin >> a; }\ninline\
    \ void scan(char &a) { std::cin >> a; }\ninline void scan(float &a) { std::cin\
    \ >> a; }\ninline void scan(double &a) { std::cin >> a; }\ninline void scan(long\
    \ double &a) { std::cin >> a; }\ninline void scan(std::vector<bool> &vec) {\n\
    \    for (int32_t i = 0; i < vec.size(); i++) {\n        int a;\n        scan(a);\n\
    \        vec[i] = a;\n    }\n}\ninline void scan(std::string &a) { std::cin >>\
    \ a; }\ntemplate <class T>\ninline void scan(std::vector<T> &vec);\ntemplate <class\
    \ T, size_t size>\ninline void scan(std::array<T, size> &vec);\ntemplate <class\
    \ T, class L>\ninline void scan(std::pair<T, L> &p);\ntemplate <class T, size_t\
    \ size>\ninline void scan(T (&vec)[size]);\ntemplate <class T>\ninline void scan(std::vector<T>\
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
    inline void print(const int &a) { std::cout << a; }\ninline void print(const unsigned\
    \ &a) { std::cout << a; }\ninline void print(const long &a) { std::cout << a;\
    \ }\ninline void print(const long long &a) { std::cout << a; }\ninline void print(const\
    \ unsigned long long &a) { std::cout << a; }\ninline void print(const char &a)\
    \ { std::cout << a; }\ninline void print(const char a[]) { std::cout << a; }\n\
    inline void print(const float &a) { std::cout << a; }\ninline void print(const\
    \ double &a) { std::cout << a; }\ninline void print(const long double &a) { std::cout\
    \ << a; }\ninline void print(const std::string &a) {\n    for (auto &&i : a) print(i);\n\
    }\ntemplate <class T>\ninline void print(const std::vector<T> &vec);\ntemplate\
    \ <class T, size_t size>\ninline void print(const std::array<T, size> &vec);\n\
    template <class T, class L>\ninline void print(const std::pair<T, L> &p);\ntemplate\
    \ <class T, size_t size>\ninline void print(const T (&vec)[size]);\ntemplate <class\
    \ T>\ninline void print(const std::vector<T> &vec) {\n    if (vec.empty()) return;\n\
    \    print(vec[0]);\n    for (auto i = vec.begin(); ++i != vec.end();) {\n   \
    \     std::cout << ' ';\n        print(*i);\n    }\n}\ntemplate <class T>\ninline\
    \ void print(const std::deque<T> &vec) {\n    if (vec.empty()) return;\n    print(vec[0]);\n\
    \    for (auto i = vec.begin(); ++i != vec.end();) {\n        std::cout << ' ';\n\
    \        print(*i);\n    }\n}\ntemplate <class T, size_t size>\ninline void print(const\
    \ std::array<T, size> &vec) {\n    print(vec[0]);\n    for (auto i = vec.begin();\
    \ ++i != vec.end();) {\n        std::cout << ' ';\n        print(*i);\n    }\n\
    }\ntemplate <class T, class L>\ninline void print(const std::pair<T, L> &p) {\n\
    \    print(p.first);\n    std::cout << ' ';\n    print(p.second);\n}\ntemplate\
    \ <class T, size_t size>\ninline void print(const T (&vec)[size]) {\n    print(vec[0]);\n\
    \    for (auto i = vec; ++i != end(vec);) {\n        std::cout << ' ';\n     \
    \   print(*i);\n    }\n}\ntemplate <class T>\ninline void print(const T &a) {\n\
    \    std::cout << a;\n}\ninline void out() { std::cout << '\\n'; }\ntemplate <class\
    \ T>\ninline void out(const T &t) {\n    print(t);\n    std::cout << '\\n';\n\
    }\ntemplate <class Head, class... Tail>\ninline void out(const Head &head, const\
    \ Tail &...tail) {\n    print(head);\n    std::cout << ' ';\n    out(tail...);\n\
    }\ninline void Yes(bool i = true) { out(i ? \"Yes\" : \"No\"); }\ninline void\
    \ No(bool i = true) { out(i ? \"No\" : \"Yes\"); }\ninline void Takahashi(bool\
    \ i = true) { out(i ? \"Takahashi\" : \"Aoki\"); }\ninline void Aoki(bool i =\
    \ true) { out(i ? \"Aoki\" : \"Takahashi\"); }\ninline void First(bool i = true)\
    \ { out(i ? \"First\" : \"Second\"); }\ninline void Second(bool i = true) { out(i\
    \ ? \"Second\" : \"First\"); }\ninline void Possible(bool i = true) { out(i ?\
    \ \"Possible\" : \"Impossible\"); }\ninline void Impossible(bool i = true) { out(i\
    \ ? \"Impossible\" : \"Possible\"); }\ninline void fls() { std::flush(std::cout);\
    \ }\nstruct IOsetup {\n    IOsetup() {\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        std::cout << std::fixed << std::setprecision(16);\n\
    \    }\n} iosetup;\n#line 8 \"Template/Util.hpp\"\nusing ll = long long;\nusing\
    \ ld = long double;\nusing ull = unsigned long long;\nusing uint = unsigned int;\n\
    using pll = std::pair<ll, ll>;\nusing pii = std::pair<int, int>;\nusing vl = std::vector<ll>;\n\
    using vvl = std::vector<std::vector<ll>>;\nusing pdd = std::pair<ld, ld>;\nusing\
    \ tuplis = std::array<ll, 3>;\ntemplate <class T>\nusing pq = std::priority_queue<T,\
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
    \ _rep1(i, n) for (ll i = 0; i < (n); i++)\n#define _rep2(i, a, b) for (ll i =\
    \ (a); i < (b); i++)\n#define _rep3(i, a, b, c) for (ll i = (a); i < (b); i +=\
    \ (c))\n#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define _rrep1(i, n) for (int i = (n) - 1; i >= 0; i--)\n#define _rrep2(i, a,\
    \ b) for (int i = (b) - 1; i >= (a); i--)\n#define rrep(...) _overload3(__VA_ARGS__,\
    \ _rrep2, _rrep1)(__VA_ARGS__)\n#define each(i, ...) for (auto&& i : __VA_ARGS__)\n\
    #define all(i) std::begin(i), std::end(i)\n#define rall(i) std::rbegin(i), std::rend(i)\n\
    #define len(x) ((ll)(x).size())\n#define fi first\n#define se second\n#define\
    \ uniq(x) x.erase(unique(all(x)), std::end(x))\n#define vec(type, name, ...) vector<type>\
    \ name(__VA_ARGS__);\n#define vv(type, name, h, ...) std::vector<std::vector<type>>\
    \ name(h, std::vector<type>(__VA_ARGS__));\n#define INT(...) int __VA_ARGS__;\
    \ in(__VA_ARGS__)\n#define LL(...) long long __VA_ARGS__; in(__VA_ARGS__)\n#define\
    \ ULL(...) unsigned long long __VA_ARGS__; in(__VA_ARGS__)\n#define STR(...) std::string\
    \ __VA_ARGS__; in(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)\n\
    #define LD(...) long double __VA_ARGS__; in(__VA_ARGS__)\n#define VEC(type, name,\
    \ size) std::vector<type> name(size); in(name)\n#define VV(type, name, h, w) std::vector<std::vector<type>>\
    \ name(h, std::vector<type>(w)); in(name)\n#line 4 \"Verify/verify-yosupo-string/enumerate_palindromes.test.cpp\"\
    \nvoid solve() {\n    STR(S);\n    out(manacher(S));\n}\nint main() { solve();\
    \ }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../../String/Manacher.hpp\"\n#include \"../../Template/Template.hpp\"\
    \nvoid solve() {\n    STR(S);\n    out(manacher(S));\n}\nint main() { solve();\
    \ }"
  dependsOn:
  - String/Manacher.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 17:44:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
- /verify/Verify/verify-yosupo-string/enumerate_palindromes.test.cpp.html
title: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
---
