---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.hpp
    title: Union Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"DataStructure/UnionFind.hpp\"\
    \n#include <cstdint>\n#include <vector>\ntemplate <class M>\nstruct MonoidUnionFind\
    \ {\n    using T = typename M::T;\n    std::vector<std::pair<int32_t, T>> tree;\n\
    \    MonoidUnionFind(int32_t sz) { tree.resize(sz, {-1, M::e}); }\n    int32_t\
    \ root(int32_t pos) {\n        int32_t ret = pos;\n        while (tree[ret].first\
    \ >= 0) {\n            ret = tree[ret].first;\n        }\n        while (tree[pos].first\
    \ >= 0) {\n            int32_t now = pos;\n            pos = tree[pos].first;\n\
    \            tree[now].first = ret;\n        }\n        return ret;\n    }\n \
    \   void set(int32_t pos, T val) { tree[root(pos)].second = val; }\n    T get(int32_t\
    \ pos) { return tree[root(pos)].second; }\n    bool same(int32_t a, int32_t b)\
    \ { return root(a) == root(b); }\n    bool merge(int32_t a, int32_t b) {\n   \
    \     a = root(a);\n        b = root(b);\n        if (a == b) return false;\n\
    \        if (tree[a].first > tree[b].first) std::swap(a, b);\n        tree[a]\
    \ = {tree[a].first + tree[b].first,\n                   M::op(tree[a].second,\
    \ tree[b].second)};\n        tree[b].first = a;\n        return true;\n    }\n\
    \    int32_t size(int32_t pos) { return -tree[root(pos)].first; }\n    std::vector<std::vector<int32_t>>\
    \ groups() {\n        std::vector<std::vector<int32_t>> members(tree.size());\n\
    \        for (int32_t i = 0; i < tree.size(); i++) {\n            members[root(i)].emplace_back(i);\n\
    \        }\n        std::vector<std::vector<int32_t>> ret;\n        for (int32_t\
    \ i = 0; i < tree.size(); i++) {\n            if (!members[i].empty()) ret.emplace_back(members[i]);\n\
    \        }\n        return ret;\n    }\n};\nnamespace union_find_void {\nstruct\
    \ void_monoid {\n    using T = bool;\n    constexpr static inline T op(T a, T\
    \ b) { return 0; }\n    constexpr static inline T e = 0;\n};\n}  // namespace\
    \ union_find_void\nusing UnionFind = MonoidUnionFind<union_find_void::void_monoid>;\n\
    #line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ No(bool i = true) { out(i ? \"No\" : \"Yes\"); }\nstruct IOsetup {\n    IOsetup()\
    \ {\n        std::ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        std::cout << std::setprecision(10);\n    }\n} iosetup;\n#line 8 \"Template/Util.hpp\"\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    using uint = unsigned int;\nusing pll = std::pair<ll, ll>;\nusing pii = std::pair<int,\
    \ int>;\nusing vl = std::vector<ll>;\nusing vvl = std::vector<std::vector<ll>>;\n\
    using pdd = std::pair<ld, ld>;\nusing tuplis = std::array<ll, 3>;\ntemplate <class\
    \ T>\nusing pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\nconstexpr\
    \ ll LINF = (1LL << 62) - (1LL << 31);\nconstexpr int32_t INF = INT_MAX >> 1;\n\
    constexpr ll MINF = 1LL << 40;\nconstexpr ld DINF = std::numeric_limits<ld>::infinity();\n\
    constexpr int32_t MODD = 1000000007;\nconstexpr int32_t MOD = 998244353;\nconstexpr\
    \ ld EPS = 1e-9;\nconstexpr ld PI = 3.1415926535897932;\nconst ll four[] = {0,\
    \ 1, 0, -1, 0};\nconst ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};\ntemplate\
    \ <class T>\nbool chmin(T &a, const T &b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    } else\n        return false;\n}\ntemplate <class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    } else\n        return false;\n}\ntemplate <class T>\nll sum(const\
    \ T &a) {\n    return accumulate(std::begin(a), std::end(a), 0LL);\n}\ntemplate\
    \ <class T>\nld dsum(const T &a) {\n    return accumulate(std::begin(a), std::end(a),\
    \ 0.0L);\n}\ntemplate <class T>\nauto min(const T &a) {\n    return *min_element(std::begin(a),\
    \ std::end(a));\n}\ntemplate <class T>\nauto max(const T &a) {\n    return *max_element(std::begin(a),\
    \ std::end(a));\n}\n#line 1 \"Template/Macro.hpp\"\n#define _overload3(_1, _2,\
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
    \ name, h, ...) std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__));\n\
    #define INT(...) int __VA_ARGS__; in(__VA_ARGS__)\n#define LL(...) long long __VA_ARGS__;\
    \ in(__VA_ARGS__)\n#define ULL(...) unsigned long long __VA_ARGS__; in(__VA_ARGS__)\n\
    #define STR(...) std::string __VA_ARGS__; in(__VA_ARGS__)\n#define CHR(...) char\
    \ __VA_ARGS__; in(__VA_ARGS__)\n#define LD(...) long double __VA_ARGS__; in(__VA_ARGS__)\n\
    #define VEC(type, name, size) std::vector<type> name(size); in(name)\n#define\
    \ VV(type, name, h, w) std::vector<std::vector<type>> name(h, std::vector<type>(w));\
    \ in(name)\n#line 4 \"Verify/verify-yosupo-datastructure/unionfind.test.cpp\"\n\
    void solve() {\n    LL(N, Q);\n    UnionFind uni(N);\n    rep(i, Q) {\n      \
    \  LL(t, u, v);\n        if (t == 0) {\n            uni.merge(u, v);\n       \
    \ } else {\n            out(uni.same(u, v));\n        }\n    }\n}\nint main()\
    \ { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../DataStructure/UnionFind.hpp\"\n#include \"../../Template/Template.hpp\"\n\
    void solve() {\n    LL(N, Q);\n    UnionFind uni(N);\n    rep(i, Q) {\n      \
    \  LL(t, u, v);\n        if (t == 0) {\n            uni.merge(u, v);\n       \
    \ } else {\n            out(uni.same(u, v));\n        }\n    }\n}\nint main()\
    \ { solve(); }"
  dependsOn:
  - DataStructure/UnionFind.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-05-14 08:14:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/unionfind.test.cpp
- /verify/Verify/verify-yosupo-datastructure/unionfind.test.cpp.html
title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
---
