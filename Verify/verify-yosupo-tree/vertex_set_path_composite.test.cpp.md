---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Graph/Graph.hpp
    title: Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Modint/Modint.hpp
    title: Modint/Modint.hpp
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
  - icon: ':heavy_check_mark:'
    path: Tree/HLDecomposition.hpp
    title: Tree/HLDecomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#line 2 \"DataStructure/SegmentTree.hpp\"\n#include <cstdint>\n#include <queue>\n\
    #include <stack>\n#include <vector>\ntemplate <class M>\nstruct SegmentTree {\n\
    \    using T = typename M::T;\n    int32_t siz;\n    std::vector<T> tree;\n  \
    \  SegmentTree(int32_t sz) {\n        siz = sz;\n        tree = std::vector<T>(siz\
    \ << 1, M::e);\n    }\n    SegmentTree(std::vector<T> def) {\n        siz = def.size();\n\
    \        tree = std::vector<T>(siz << 1, M::e);\n        for (int32_t i = 0; i\
    \ < siz; i++) {\n            tree[i + siz] = def[i];\n        }\n        for (int32_t\
    \ i = siz - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i\
    \ << 1) + 1]);\n        }\n    }\n    void set(int32_t p, T v) {\n        p +=\
    \ siz;\n        tree[p] = v;\n        p >>= 1;\n        while (p > 0) {\n    \
    \        tree[p] = M::op(tree[p << 1], tree[(p << 1) + 1]);\n            p >>=\
    \ 1;\n        }\n    }\n    T get(int32_t p) { return tree[p + siz]; }\n    T\
    \ prod(int32_t lf, int32_t ri) {\n        lf += siz;\n        ri += siz;\n   \
    \     T rel = M::e;\n        T rer = M::e;\n        while (lf < ri) {\n      \
    \      if (lf & 1) {\n                rel = M::op(rel, tree[lf]);\n          \
    \      lf++;\n            }\n            if (ri & 1) {\n                ri--;\n\
    \                rer = M::op(tree[ri], rer);\n            }\n            lf >>=\
    \ 1;\n            ri >>= 1;\n        }\n        return M::op(rel, rer);\n    }\n\
    \    template <class F>\n    int32_t max_right(int32_t lf, F f) {\n        lf\
    \ += siz;\n        int32_t ri = siz << 1;\n        std::queue<int32_t> lfp;\n\
    \        std::stack<int32_t> rip;\n        while (lf < ri) {\n            if (lf\
    \ & 1) {\n                lfp.push(lf);\n                lf++;\n            }\n\
    \            if (ri & 1) {\n                ri--;\n                rip.push(ri);\n\
    \            }\n            lf >>= 1;\n            ri >>= 1;\n        }\n    \
    \    T val = M::e;\n        while (!lfp.empty()) {\n            int32_t i = lfp.front();\n\
    \            lfp.pop();\n            if (!f(M::op(val, tree[i]))) {\n        \
    \        while (i < siz) {\n                    i <<= 1;\n                   \
    \ if (f(M::op(val, tree[i]))) {\n                        val = M::op(val, tree[i]);\n\
    \                        i++;\n                    }\n                }\n    \
    \            return i - siz;\n            }\n            val = M::op(val, tree[i]);\n\
    \        }\n        while (!rip.empty()) {\n            int32_t i = rip.top();\n\
    \            rip.pop();\n            if (!f(M::op(val, tree[i]))) {\n        \
    \        while (i < siz) {\n                    i <<= 1;\n                   \
    \ if (f(M::op(val, tree[i]))) {\n                        val = M::op(val, tree[i]);\n\
    \                        i++;\n                    }\n                }\n    \
    \            return i - siz;\n            }\n            val = M::op(val, tree[i]);\n\
    \        }\n        return siz;\n    }\n    template <class F>\n    int32_t min_left(int32_t\
    \ ri, F f) {\n        ri += siz;\n        int32_t lf = siz;\n        std::queue<int32_t>\
    \ rip;\n        std::stack<int32_t> lfp;\n        while (lf < ri) {\n        \
    \    if (lf & 1) {\n                lfp.push(lf);\n                lf++;\n   \
    \         }\n            if (ri & 1) {\n                ri--;\n              \
    \  rip.push(ri);\n            }\n            lf >>= 1;\n            ri >>= 1;\n\
    \        }\n        T val = M::e;\n        while (!rip.empty()) {\n          \
    \  int32_t i = rip.front();\n            rip.pop();\n            if (!f(M::op(val,\
    \ tree[i]))) {\n                while (i < siz) {\n                    i <<= 1;\n\
    \                    i++;\n                    if (f(M::op(tree[i], val))) {\n\
    \                        val = M::op(tree[i], val);\n                        i--;\n\
    \                    }\n                }\n                return i - siz + 1;\n\
    \            }\n            val = M::op(tree[i], val);\n        }\n        while\
    \ (!lfp.empty()) {\n            int32_t i = lfp.top();\n            lfp.pop();\n\
    \            if (!f(M::op(val, tree[i]))) {\n                while (i < siz) {\n\
    \                    i <<= 1;\n                    i++;\n                    if\
    \ (f(M::op(tree[i], val))) {\n                        val = M::op(tree[i], val);\n\
    \                        i--;\n                    }\n                }\n    \
    \            return i - siz + 1;\n            }\n            val = M::op(tree[i],\
    \ val);\n        }\n        return 0;\n    }\n    int32_t size() { return siz;\
    \ }\n};\n#line 4 \"Graph/Graph.hpp\"\ntemplate <class T = int32_t>\nstruct Edge\
    \ {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n    Edge() = default;\n\
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
    \        }\n    }\n    return ret;\n}\n#line 2 \"Modint/Modint.hpp\"\n#include\
    \ <assert.h>\n\n#line 5 \"Modint/Modint.hpp\"\n#include <iostream>\ntemplate <uint64_t\
    \ Mod>\nstruct Modint {\n    uint64_t x;\n    constexpr Modint() noexcept { x\
    \ = 0; }\n    constexpr Modint(int64_t val) noexcept {\n        x = (val < 0 ?\
    \ val % (int64_t)(Mod) + Mod : val % Mod);\n    }\n    inline uint64_t _get_mod(uint64_t\
    \ val) noexcept {\n        const static uint64_t m_inv = (-1ULL) / Mod + 1;\n\
    \        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;\n        uint64_t\
    \ pro = ret * Mod;\n        return (val - pro + (val < pro ? Mod : 0));\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, Modint &b) noexcept {\n\
    \        return os << b.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &b) noexcept {\n        return is >> b.x;\n    }\n    constexpr\
    \ uint64_t val() noexcept { return x; }\n    constexpr Modint operator+() noexcept\
    \ { return (*this); }\n    constexpr Modint operator-() noexcept { return Modint()\
    \ - (*this); }\n    friend Modint operator+(const Modint lhs, const Modint rhs)\
    \ noexcept {\n        return Modint(lhs) += rhs;\n    }\n    friend Modint operator-(const\
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
    }\n#line 5 \"Tree/HLDecomposition.hpp\"\n\n#line 7 \"Tree/HLDecomposition.hpp\"\
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
    #define _rrep1(i, n) for (ll i = (n) - 1; i >= 0; i--)\n#define _rrep2(i, a, b)\
    \ for (ll i = (b) - 1; i >= (a); i--)\n#define rrep(...) _overload3(__VA_ARGS__,\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 7 \"Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp\"\
    \nusing mint = Modint<MOD>;\nstruct composite {\n    using T = pair<mint, mint>;\n\
    \    static T op(T lf, T ri) { return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se);\
    \ }\n    static inline T e = T(1, 0);\n};\nstruct rev_composite : composite {\n\
    \    static T op(T ri, T lf) { return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se);\
    \ }\n};\nvoid solve() {\n    LL(N, Q);\n    VEC(composite::T, ab, N);\n    Graph\
    \ gr(N);\n    rep(i, N - 1) {\n        LL(u, v);\n        gr.add_edge(u, v);\n\
    \    }\n    SegmentTree<composite> rig(N);\n    SegmentTree<rev_composite> rev(N);\n\
    \    HLDecomposition hld(gr);\n    rep(i, N) {\n        rig.set(hld[i], ab[i]);\n\
    \        rev.set(hld[i], ab[i]);\n    }\n    rep(i, Q) {\n        LL(t);\n   \
    \     if (t == 0) {\n            LL(p, c, d);\n            rig.set(hld[p], {c,\
    \ d});\n            rev.set(hld[p], {c, d});\n        }\n        if (t == 1) {\n\
    \            LL(u, v, x);\n            pair<mint, mint> ans = {1, 0};\n      \
    \      for (auto &[s, t, r] : hld.path(u, v)) {\n                if (!r) {\n \
    \                   ans = composite::op(ans, rig.prod(s, t));\n              \
    \  } else {\n                    ans = composite::op(ans, rev.prod(s, t));\n \
    \               }\n            }\n            out(ans.fi * x + ans.se);\n    \
    \    }\n    }\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../DataStructure/SegmentTree.hpp\"\n#include \"../../Graph/Graph.hpp\"\
    \n#include \"../../Modint/Modint.hpp\"\n#include \"../../Tree/HLDecomposition.hpp\"\
    \n#include \"../../Template/Template.hpp\"\nusing mint = Modint<MOD>;\nstruct\
    \ composite {\n    using T = pair<mint, mint>;\n    static T op(T lf, T ri) {\
    \ return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se); }\n    static inline T e = T(1,\
    \ 0);\n};\nstruct rev_composite : composite {\n    static T op(T ri, T lf) { return\
    \ T(lf.fi * ri.fi, lf.se * ri.fi + ri.se); }\n};\nvoid solve() {\n    LL(N, Q);\n\
    \    VEC(composite::T, ab, N);\n    Graph gr(N);\n    rep(i, N - 1) {\n      \
    \  LL(u, v);\n        gr.add_edge(u, v);\n    }\n    SegmentTree<composite> rig(N);\n\
    \    SegmentTree<rev_composite> rev(N);\n    HLDecomposition hld(gr);\n    rep(i,\
    \ N) {\n        rig.set(hld[i], ab[i]);\n        rev.set(hld[i], ab[i]);\n   \
    \ }\n    rep(i, Q) {\n        LL(t);\n        if (t == 0) {\n            LL(p,\
    \ c, d);\n            rig.set(hld[p], {c, d});\n            rev.set(hld[p], {c,\
    \ d});\n        }\n        if (t == 1) {\n            LL(u, v, x);\n         \
    \   pair<mint, mint> ans = {1, 0};\n            for (auto &[s, t, r] : hld.path(u,\
    \ v)) {\n                if (!r) {\n                    ans = composite::op(ans,\
    \ rig.prod(s, t));\n                } else {\n                    ans = composite::op(ans,\
    \ rev.prod(s, t));\n                }\n            }\n            out(ans.fi *\
    \ x + ans.se);\n        }\n    }\n}\nint main() { solve(); }"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Graph/Graph.hpp
  - Modint/Modint.hpp
  - Tree/HLDecomposition.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 14:20:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
- /verify/Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp.html
title: Verify/verify-yosupo-tree/vertex_set_path_composite.test.cpp
---
