---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/Graph.hpp
    title: Graph/Graph.hpp
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
  - icon: ':question:'
    path: Tree/HLDecomposition.hpp
    title: Tree/HLDecomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"Graph/Graph.hpp\"\
    \n#include <cstdint>\n#include <vector>\ntemplate <class T = int32_t>\nstruct\
    \ Edge {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n    Edge() = default;\n\
    \    Edge(int32_t from, int32_t to, T cost = 1, int32_t idx = -1)\n        : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n    operator int32_t() { return to; }\n   \
    \ void reverse() { std::swap(from, to); }\n};\ntemplate <class T = int32_t>\n\
    struct Graph {\n    std::vector<std::vector<Edge<T>>> gr;\n    int32_t eds = 0;\n\
    \    Graph() = default;\n    Graph(int32_t n) { gr.resize(n); }\n    void add_edge(int32_t\
    \ from, int32_t to, T cost = 1, bool directed = false) {\n        gr[from].emplace_back(from,\
    \ to, cost, eds);\n        if (!directed) {\n            gr[to].emplace_back(to,\
    \ from, cost, eds);\n        }\n        eds++;\n    }\n    void add_directed_edge(int32_t\
    \ from, int32_t to, T cost = 1) {\n        gr[from].emplace_back(from, to, cost,\
    \ eds);\n        eds++;\n    }\n    inline std::vector<Edge<T>> &operator[](const\
    \ int32_t &p) { return gr[p]; }\n    int32_t size() { return gr.size(); }\n};\n\
    template <class T>\nGraph<T> reverse_edges(Graph<T> &gr) {\n    Graph<T> ret(gr.size());\n\
    \    for (int32_t i = 0; i < gr.size(); i++) {\n        for (Edge<T> j : gr[i])\
    \ {\n            ret[j].emplace_back(j);\n            ret[j].back().reverse();\n\
    \        }\n    }\n    return ret;\n}\n#line 3 \"Tree/HLDecomposition.hpp\"\n\
    #include <stack>\n#line 5 \"Tree/HLDecomposition.hpp\"\n\n#line 7 \"Tree/HLDecomposition.hpp\"\
    \nstruct HLDecomposition {\n    struct Segment {\n        int32_t lf, ri;\n  \
    \      bool rev;\n    };\n    int32_t sz;\n    std::vector<int32_t> tree_sz;\n\
    \    std::vector<int32_t> depth;\n    std::vector<int32_t> order;\n    std::vector<int32_t>\
    \ path_roots;\n    std::vector<int32_t> parent;\n    std::vector<int32_t> out;\n\
    \    template <class T>\n    void _build(int32_t pos, Graph<T> &tree) {\n    \
    \    order[pos] = sz;\n        sz++;\n        int32_t mx = -1, mp = -1;\n    \
    \    for (int32_t i : tree[pos]) {\n            if (i == parent[pos]) continue;\n\
    \            if (mx < tree_sz[i]) {\n                mx = tree_sz[i];\n      \
    \          mp = i;\n            }\n        }\n        if (mx == -1) {\n      \
    \      out[pos] = sz;\n            return;\n        }\n        path_roots[mp]\
    \ = path_roots[pos];\n        _build(mp, tree);\n        for (int32_t i : tree[pos])\
    \ {\n            if (i == parent[pos]) continue;\n            if (i == mp) continue;\n\
    \            path_roots[i] = i;\n            _build(i, tree);\n        }\n   \
    \     out[pos] = sz;\n    }\n    template <class T>\n    int32_t _calc_sz(int32_t\
    \ pos, Graph<T> &tree) {\n        if (tree_sz[pos] != -1) return tree_sz[pos];\n\
    \        tree_sz[pos] = 1;\n        for (int32_t i : tree[pos]) {\n          \
    \  if (parent[pos] != i) {\n                parent[i] = pos;\n               \
    \ depth[i] = depth[pos] + 1;\n                tree_sz[pos] += _calc_sz(i, tree);\n\
    \            }\n        }\n        return tree_sz[pos];\n    }\n    template <class\
    \ T>\n    HLDecomposition(Graph<T> &tree, int32_t root = 0) {\n        sz = tree.size();\n\
    \        tree_sz.resize(sz, -1);\n        depth.resize(sz, -1);\n        parent.resize(sz,\
    \ -1);\n        depth[root] = 0;\n        _calc_sz(root, tree);\n        order.resize(sz,\
    \ -1);\n        out.resize(sz, -1);\n        path_roots.resize(sz, -1);\n    \
    \    sz = 0;\n        path_roots[root] = root;\n        _build(root, tree);\n\
    \    }\n    int32_t operator[](int32_t p) { return order[p]; }\n    Segment subtree(int32_t\
    \ pos) { return {order[pos], out[pos], false}; }\n    std::vector<Segment> path(int32_t\
    \ s, int32_t t) {\n        std::vector<Segment> ret;\n        std::stack<Segment>\
    \ right;\n        while (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]]\
    \ > depth[path_roots[t]]) {\n                ret.emplace_back(\n             \
    \       Segment{order[path_roots[s]], order[s] + 1, true});\n                s\
    \ = parent[path_roots[s]];\n            } else {\n                right.push({order[path_roots[t]],\
    \ order[t] + 1, false});\n                t = parent[path_roots[t]];\n       \
    \     }\n        }\n        if (depth[s] < depth[t]) {\n            ret.emplace_back(Segment{order[s],\
    \ order[t] + 1, false});\n        } else {\n            ret.emplace_back(Segment{order[t],\
    \ order[s] + 1, true});\n        }\n        while (!right.empty()) {\n       \
    \     ret.push_back(right.top());\n            right.pop();\n        }\n     \
    \   return ret;\n    }\n    int32_t lca(int32_t s, int32_t t) {\n        while\
    \ (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]] > depth[path_roots[t]])\
    \ {\n                s = parent[path_roots[s]];\n            } else {\n      \
    \          t = parent[path_roots[t]];\n            }\n        }\n        if (depth[s]\
    \ < depth[t]) return s;\n        return t;\n    }\n};\n#line 2 \"Template/Template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 8 \"Template/InOut.hpp\"\
    \ninline void scan() {}\ninline void scan(int &a) { std::cin >> a; }\ninline void\
    \ scan(unsigned &a) { std::cin >> a; }\ninline void scan(long &a) { std::cin >>\
    \ a; }\ninline void scan(long long &a) { std::cin >> a; }\ninline void scan(unsigned\
    \ long long &a) { std::cin >> a; }\ninline void scan(char &a) { std::cin >> a;\
    \ }\ninline void scan(float &a) { std::cin >> a; }\ninline void scan(double &a)\
    \ { std::cin >> a; }\ninline void scan(long double &a) { std::cin >> a; }\ninline\
    \ void scan(std::vector<bool> &vec) {\n    for (int32_t i = 0; i < vec.size();\
    \ i++) {\n        int a;\n        scan(a);\n        vec[i] = a;\n    }\n}\ninline\
    \ void scan(std::string &a) { std::cin >> a; }\ntemplate <class T>\ninline void\
    \ scan(std::vector<T> &vec);\ntemplate <class T, size_t size>\ninline void scan(std::array<T,\
    \ size> &vec);\ntemplate <class T, class L>\ninline void scan(std::pair<T, L>\
    \ &p);\ntemplate <class T, size_t size>\ninline void scan(T (&vec)[size]);\ntemplate\
    \ <class T>\ninline void scan(std::vector<T> &vec) {\n    for (auto &i : vec)\
    \ scan(i);\n}\ntemplate <class T>\ninline void scan(std::deque<T> &vec) {\n  \
    \  for (auto &i : vec) scan(i);\n}\ntemplate <class T, size_t size>\ninline void\
    \ scan(std::array<T, size> &vec) {\n    for (auto &i : vec) scan(i);\n}\ntemplate\
    \ <class T, class L>\ninline void scan(std::pair<T, L> &p) {\n    scan(p.first);\n\
    \    scan(p.second);\n}\ntemplate <class T, size_t size>\ninline void scan(T (&vec)[size])\
    \ {\n    for (auto &i : vec) scan(i);\n}\ntemplate <class T>\ninline void scan(T\
    \ &a) {\n    std::cin >> a;\n}\ninline void in() {}\ntemplate <class Head, class...\
    \ Tail>\ninline void in(Head &head, Tail &...tail) {\n    scan(head);\n    in(tail...);\n\
    }\ninline void print() { std::cout << ' '; }\ninline void print(const bool &a)\
    \ { std::cout << a; }\ninline void print(const int &a) { std::cout << a; }\ninline\
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
    \ { out(i ? \"No\" : \"Yes\"); }\ninline void Takahashi(bool i = true) { out(i\
    \ ? \"Takahashi\" : \"Aoki\"); }\ninline void Aoki(bool i = true) { out(i ? \"\
    Aoki\" : \"Takahashi\"); }\ninline void First(bool i = true) { out(i ? \"First\"\
    \ : \"Second\"); }\ninline void Second(bool i = true) { out(i ? \"Second\" : \"\
    First\"); }\ninline void Possible(bool i = true) { out(i ? \"Possible\" : \"Impossible\"\
    ); }\ninline void Impossible(bool i = true) { out(i ? \"Impossible\" : \"Possible\"\
    ); }\ninline void fls() { std::flush(std::cout); }\nstruct IOsetup {\n    IOsetup()\
    \ {\n        std::ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        std::cout << std::fixed << std::setprecision(16);\n    }\n} iosetup;\n\
    #line 8 \"Template/Util.hpp\"\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\nusing uint = unsigned int;\nusing pll = std::pair<ll,\
    \ ll>;\nusing pii = std::pair<int, int>;\nusing vl = std::vector<ll>;\nusing vvl\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 5 \"Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp\"\
    \nvoid solve() {\n    LL(N, Q);\n    Graph gr(N);\n    VEC(ll, p, N - 1);\n  \
    \  rep(i, N - 1) { gr.add_edge(i + 1, p[i]); }\n    HLDecomposition hld(gr);\n\
    \    rep(i, Q) {\n        LL(u, v);\n        out(hld.lca(u, v));\n    }\n}\nint\
    \ main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../Graph/Graph.hpp\"\
    \n#include \"../../Tree/HLDecomposition.hpp\"\n#include \"../../Template/Template.hpp\"\
    \nvoid solve() {\n    LL(N, Q);\n    Graph gr(N);\n    VEC(ll, p, N - 1);\n  \
    \  rep(i, N - 1) { gr.add_edge(i + 1, p[i]); }\n    HLDecomposition hld(gr);\n\
    \    rep(i, Q) {\n        LL(u, v);\n        out(hld.lca(u, v));\n    }\n}\nint\
    \ main() { solve(); }"
  dependsOn:
  - Graph/Graph.hpp
  - Tree/HLDecomposition.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 17:44:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
- /verify/Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp.html
title: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
---
