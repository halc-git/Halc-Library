---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Graph.hpp
    title: Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: Tree/StaticTopTree.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#line 2 \"Graph/Graph.hpp\"\n#include <cstdint>\n#include <vector>\ntemplate\
    \ <class T = int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n   \
    \ int32_t idx;\n    Edge() = default;\n    Edge(int32_t from, int32_t to, T cost\
    \ = 1, int32_t idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n\
    \    operator int32_t() { return to; }\n    void reverse() { std::swap(from, to);\
    \ }\n};\ntemplate <class T = int32_t>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>>\
    \ gr;\n    int32_t eds = 0;\n    Graph() = default;\n    Graph(int32_t n) { gr.resize(n);\
    \ }\n    void add_edge(int32_t from, int32_t to, T cost = 1, bool directed = false)\
    \ {\n        gr[from].emplace_back(from, to, cost, eds);\n        if (!directed)\
    \ {\n            gr[to].emplace_back(to, from, cost, eds);\n        }\n      \
    \  eds++;\n    }\n    void add_directed_edge(int32_t from, int32_t to, T cost\
    \ = 1) {\n        gr[from].emplace_back(from, to, cost, eds);\n        eds++;\n\
    \    }\n    inline std::vector<Edge<T>> &operator[](const int32_t &p) { return\
    \ gr[p]; }\n    int32_t size() { return gr.size(); }\n};\ntemplate <class T>\n\
    Graph<T> reverse_edges(Graph<T> &gr) {\n    Graph<T> ret(gr.size());\n    for\
    \ (int32_t i = 0; i < gr.size(); i++) {\n        for (Edge<T> j : gr[i]) {\n \
    \           ret[j].emplace_back(j);\n            ret[j].back().reverse();\n  \
    \      }\n    }\n    return ret;\n}\n#line 3 \"Modint/Modint.hpp\"\n#include <iostream>\n\
    template <uint64_t Mod>\nstruct Modint {\n    uint64_t x;\n    constexpr Modint()\
    \ noexcept { x = 0; }\n    constexpr Modint(int64_t val) noexcept {\n        x\
    \ = (val < 0 ? val % (int64_t)(Mod) + Mod : val % Mod);\n    }\n    inline uint64_t\
    \ _get_mod(uint64_t val) noexcept {\n        const static uint64_t m_inv = (-1ULL)\
    \ / Mod + 1;\n        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;\n\
    \        uint64_t pro = ret * Mod;\n        return (val - pro + (val < pro ? Mod\
    \ : 0));\n    }\n    friend std::ostream &operator<<(std::ostream &os, Modint\
    \ &b) {\n        return os << b.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &b) {\n        return is >> b.x;\n    }\n    constexpr uint64_t\
    \ val() noexcept { return x; }\n    constexpr Modint operator+() noexcept { return\
    \ (*this); }\n    constexpr Modint operator-() noexcept { return Modint() - (*this);\
    \ }\n    constexpr Modint operator+(const Modint rhs) noexcept {\n        return\
    \ Modint(*this) += rhs;\n    }\n    constexpr Modint operator-(const Modint rhs)\
    \ noexcept {\n        return Modint(*this) -= rhs;\n    }\n    constexpr Modint\
    \ operator*(const Modint rhs) noexcept {\n        return Modint(*this) *= rhs;\n\
    \    }\n    constexpr Modint operator/(const Modint rhs) noexcept {\n        return\
    \ Modint(*this) /= rhs;\n    }\n    constexpr Modint &operator+=(const Modint\
    \ rhs) noexcept {\n        x += rhs.x;\n        if (x >= Mod) x -= Mod;\n    \
    \    return *this;\n    }\n    constexpr Modint &operator-=(const Modint rhs)\
    \ noexcept {\n        if (x < rhs.x) x += Mod;\n        x -= rhs.x;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint rhs) noexcept {\n\
    \        x = _get_mod(x * rhs.x);\n        return *this;\n    }\n    constexpr\
    \ bool operator==(Modint rhs) noexcept { return x == rhs.x; }\n    constexpr bool\
    \ operator!=(Modint rhs) noexcept { return x != rhs.x; }\n    constexpr Modint\
    \ &operator/=(Modint rhs) noexcept {\n        return (*this) *= rhs.inv();\n \
    \   }\n    constexpr Modint inv() noexcept { return (*this).pow(Mod - 2); }\n\
    \    constexpr Modint pow(uint64_t x) noexcept {\n        Modint ret = 1;\n  \
    \      Modint bin = (*this);\n        while (x) {\n            if (x & 1) ret\
    \ *= bin;\n            bin *= bin;\n            x >>= 1;\n        }\n        return\
    \ ret;\n    }\n    static uint64_t get_mod() noexcept { return Mod; }\n};\n\n\
    template <int64_t id>\nstruct ArbitraryModint {\n    uint64_t x;\n    static uint64_t\
    \ &mod() noexcept {\n        static uint64_t Mod = 0;\n        return Mod;\n \
    \   }\n    constexpr ArbitraryModint() noexcept { x = 0; }\n    constexpr ArbitraryModint(int64_t\
    \ val) noexcept {\n        x = (val < 0 ? val % (int64_t)(get_mod()) + get_mod()\n\
    \                     : val % get_mod());\n    }\n    inline uint64_t _get_mod(uint64_t\
    \ val) noexcept {\n        const static uint64_t m_inv = (-1ULL) / get_mod() +\
    \ 1;\n        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;\n       \
    \ uint64_t pro = ret * get_mod();\n        return (val - pro + (val < pro ? get_mod()\
    \ : 0));\n    }\n    friend std::ostream &operator<<(std::ostream &os, ArbitraryModint\
    \ &b) {\n        return os << b.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, ArbitraryModint &b) {\n        return is >> b.x;\n    }\n    constexpr\
    \ uint64_t val() noexcept { return x; }\n    constexpr ArbitraryModint operator+()\
    \ noexcept { return (*this); }\n    constexpr ArbitraryModint operator-() noexcept\
    \ {\n        return ArbitraryModint() - (*this);\n    }\n    constexpr ArbitraryModint\
    \ operator+(const ArbitraryModint rhs) noexcept {\n        return ArbitraryModint(*this)\
    \ += rhs;\n    }\n    constexpr ArbitraryModint operator-(const ArbitraryModint\
    \ rhs) noexcept {\n        return ArbitraryModint(*this) -= rhs;\n    }\n    constexpr\
    \ ArbitraryModint operator*(const ArbitraryModint rhs) noexcept {\n        return\
    \ ArbitraryModint(*this) *= rhs;\n    }\n    constexpr ArbitraryModint operator/(const\
    \ ArbitraryModint rhs) noexcept {\n        return ArbitraryModint(*this) /= rhs;\n\
    \    }\n    constexpr ArbitraryModint &operator+=(const ArbitraryModint rhs) noexcept\
    \ {\n        x += rhs.x;\n        if (x >= get_mod()) x -= get_mod();\n      \
    \  return *this;\n    }\n    constexpr ArbitraryModint &operator-=(const ArbitraryModint\
    \ rhs) noexcept {\n        if (x < rhs.x) x += get_mod();\n        x -= rhs.x;\n\
    \        return *this;\n    }\n    constexpr ArbitraryModint &operator*=(const\
    \ ArbitraryModint rhs) noexcept {\n        x = _get_mod(x * rhs.x);\n        return\
    \ *this;\n    }\n    constexpr ArbitraryModint &operator/=(ArbitraryModint rhs)\
    \ noexcept {\n        return (*this) *= rhs.inv();\n    }\n    constexpr bool\
    \ operator==(ArbitraryModint rhs) noexcept {\n        return x == rhs.x;\n   \
    \ }\n    constexpr bool operator!=(ArbitraryModint rhs) noexcept {\n        return\
    \ x != rhs.x;\n    }\n    constexpr ArbitraryModint inv() noexcept {\n       \
    \ return (*this).pow(get_mod() - 2);\n    }\n    constexpr ArbitraryModint pow(uint64_t\
    \ x) noexcept {\n        ArbitraryModint ret = 1;\n        ArbitraryModint bin\
    \ = (*this);\n        while (x) {\n            if (x & 1) ret *= bin;\n      \
    \      bin *= bin;\n            x >>= 1;\n        }\n        return ret;\n   \
    \ }\n    static void set_mod(const uint64_t x) noexcept { mod() = x; }\n    static\
    \ uint64_t get_mod() noexcept { return mod(); }\n};\ntemplate <uint64_t N>\ninline\
    \ void scan(Modint<N> &a) {\n    std::cin >> a.x;\n}\ntemplate <int64_t id>\n\
    inline void scan(ArbitraryModint<id> &a) {\n    std::cin >> a.x;\n}\ntemplate\
    \ <uint64_t N>\ninline void print(Modint<N> a) {\n    std::cout << a.x;\n}\ntemplate\
    \ <int64_t id>\ninline void print(ArbitraryModint<id> a) {\n    std::cout << a.x;\n\
    }\n#line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 8 \"Template/InOut.hpp\"\ninline void scan() {}\ninline void scan(int\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 5 \"Tree/StaticTopTree.hpp\"\n\
    \n#line 7 \"Tree/StaticTopTree.hpp\"\ntemplate <class M>\nstruct StaticTopTree\
    \ {\n    using point = typename M::point;\n    using path = typename M::path;\n\
    \    struct Node {\n        bool is_path;\n        point point_val;\n        path\
    \ path_val;\n        int32_t pos;\n        int32_t left;\n        int32_t right;\n\
    \        int32_t parent;\n        Node(bool pat, int32_t po = -1, int32_t lf =\
    \ -1, int32_t ri = -1) {\n            is_path = pat;\n            pos = po;\n\
    \            left = lf;\n            right = ri;\n            parent = -1;\n \
    \       }\n    };\n    int32_t sz;\n    std::vector<int32_t> node_pos;\n    std::vector<Node>\
    \ nodes;\n    int32_t rt;\n    template <class T>\n    StaticTopTree(Graph<T>\
    \ gr, int32_t root) {\n        sz = gr.size();\n        node_pos.resize(sz);\n\
    \        _build(root, gr);\n    }\n    template <class T>\n    int32_t _path_cluster(int32_t\
    \ pos, std::vector<int32_t> &tree_sz,\n                          Graph<T> &tree)\
    \ {\n        if (tree[pos].empty()) {\n            node_pos[pos] = nodes.size();\n\
    \            nodes.emplace_back(Node(1, pos));\n            _calc_val(nodes.size()\
    \ - 1);\n            return nodes.size() - 1;\n        }\n        std::vector<int32_t>\
    \ address;\n        std::vector<int32_t> sizes;\n        while (!tree[pos].empty())\
    \ {\n            int32_t max_size = -1;\n            int32_t next_pos = -1;\n\
    \            for (int i = 0; i < tree[pos].size(); i++) {\n                if\
    \ (tree_sz[tree[pos][i]] > max_size) {\n                    max_size = tree_sz[tree[pos][i]];\n\
    \                    next_pos = i;\n                }\n            }\n       \
    \     std::swap(tree[pos][next_pos], tree[pos].back());\n            next_pos\
    \ = tree[pos].back();\n            tree[pos].pop_back();\n            tree_sz[pos]\
    \ -= tree_sz[next_pos];\n            sizes.emplace_back(tree_sz[pos]);\n     \
    \       address.emplace_back(_point_cluster(pos, tree_sz, tree));\n          \
    \  pos = next_pos;\n        }\n        address.emplace_back(_point_cluster(pos,\
    \ tree_sz, tree));\n        sizes.emplace_back(tree_sz[pos]);\n        return\
    \ _merge(address, sizes, 0, address.size(), 1);\n    }\n    template <class T>\n\
    \    int32_t _point_cluster(int32_t pos, std::vector<int32_t> &tree_sz,\n    \
    \                       Graph<T> &tree) {\n        if (tree[pos].empty()) {\n\
    \            node_pos[pos] = nodes.size();\n            nodes.emplace_back(Node(1,\
    \ pos));\n            _calc_val(nodes.size() - 1);\n            return nodes.size()\
    \ - 1;\n        }\n        std::vector<int32_t> address;\n        std::vector<int32_t>\
    \ sizes;\n        for (int32_t i : tree[pos]) {\n            sizes.emplace_back(tree_sz[i]);\n\
    \            int32_t vert = _path_cluster(i, tree_sz, tree);\n            nodes.emplace_back(Node(0,\
    \ -1, vert));\n            nodes[vert].parent = nodes.size() - 1;\n          \
    \  address.emplace_back(nodes.size() - 1);\n            _calc_val(nodes.size()\
    \ - 1);\n        }\n        int32_t vert = _merge(address, sizes, 0, address.size(),\
    \ 0);\n        node_pos[pos] = nodes.size();\n        nodes.emplace_back(Node(1,\
    \ pos, vert));\n        nodes[vert].parent = nodes.size() - 1;\n        _calc_val(nodes.size()\
    \ - 1);\n        return nodes.size() - 1;\n    }\n    int32_t _merge(std::vector<int32_t>\
    \ &address, std::vector<int32_t> &sizes,\n                   int32_t lf, int32_t\
    \ ri, bool pat) {\n        if (lf + 1 == ri) return address[lf];\n        int32_t\
    \ add = 0;\n        for (int32_t i = lf; i < ri; i++) {\n            add += sizes[i];\n\
    \        }\n        int32_t now = 0;\n        int32_t bef = add + 1;\n       \
    \ for (int32_t i = lf; i < ri; i++) {\n            now += sizes[i];\n        \
    \    if (now > add - now) {\n                if (now + now - add > bef) i--;\n\
    \                int32_t left = _merge(address, sizes, lf, i + 1, pat);\n    \
    \            int32_t right = _merge(address, sizes, i + 1, ri, pat);\n       \
    \         nodes.emplace_back(Node(pat, -1, left, right));\n                nodes[left].parent\
    \ = nodes.size() - 1;\n                nodes[right].parent = nodes.size() - 1;\n\
    \                _calc_val(nodes.size() - 1);\n                return nodes.size()\
    \ - 1;\n            }\n            bef = add - now - now;\n        }\n       \
    \ assert(false);\n    }\n    void _calc_val(int32_t pos) {\n        if (nodes[pos].is_path)\
    \ {\n            if ((nodes[pos].left == -1) && (nodes[pos].right == -1)) {\n\
    \                nodes[pos].path_val = M::vertex(nodes[pos].pos);\n          \
    \  } else if ((nodes[pos].left != -1) && (nodes[pos].right != -1)) {\n       \
    \         nodes[pos].path_val =\n                    M::compress(nodes[nodes[pos].left].path_val,\n\
    \                                nodes[nodes[pos].right].path_val);\n        \
    \    } else {\n                nodes[pos].path_val = M::add_vertex(\n        \
    \            nodes[nodes[pos].left].point_val, nodes[pos].pos);\n            }\n\
    \        } else {\n            if ((nodes[pos].left != -1) && (nodes[pos].right\
    \ != -1)) {\n                nodes[pos].point_val =\n                    M::rake(nodes[nodes[pos].left].point_val,\n\
    \                            nodes[nodes[pos].right].point_val);\n           \
    \ } else {\n                nodes[pos].point_val =\n                    M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    template <class T>\n    void _build(int32_t\
    \ root, Graph<T> &tree) {\n        std::vector<int32_t> vert(sz);\n        std::vector<int32_t>\
    \ tree_sz(sz, -1);\n        vert[0] = root;\n        tree_sz[root] = 0;\n    \
    \    int32_t cnt = 1;\n        for (int32_t i = 0; i < sz; i++) {\n          \
    \  for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j]) {\n    \
    \                tree_sz[j] = 0;\n                    vert[cnt] = j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for\
    \ (int32_t i = sz - 1; i >= 0; i--) {\n            int32_t parent = 0;\n     \
    \       for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j] == 0)\
    \ {\n                    parent = -parent - 1;\n                }\n          \
    \      if (parent >= 0) parent++;\n                tree_sz[vert[i]] += tree_sz[j];\n\
    \            }\n            if (parent < 0) {\n                std::swap(tree[vert[i]][-parent\
    \ - 1], tree[vert[i]].back());\n                tree[vert[i]].pop_back();\n  \
    \          }\n            tree_sz[vert[i]]++;\n        }\n        rt = _path_cluster(root,\
    \ tree_sz, tree);\n    }\n    path root_value() { return nodes[rt].path_val; }\n\
    \    void calc(int32_t pos) {\n        int32_t change = node_pos[pos];\n     \
    \   while (nodes[change].parent != -1) {\n            _calc_val(change);\n   \
    \         change = nodes[change].parent;\n        }\n        _calc_val(change);\n\
    \    }\n    int32_t size() { return sz; }\n};\n#line 6 \"Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \nusing mint = Modint<MOD>;\nusing edge_type = array<ll, 4>;\nusing func_type\
    \ = pair<mint, mint>;\nvoid solve() {\n    LL(N, Q);\n    static VEC(mint, a,\
    \ N);\n    Graph<func_type> gr(N);\n    rep(i, N - 1) {\n        LL(u, v, b, c);\n\
    \        gr.add_edge(v, u, {b, c});\n    }\n    stack<ll> vert;\n    vert.push(0);\n\
    \    static vec(func_type, func, N, {1, 0});\n    vec(ll, change, N - 1, -1);\n\
    \    while (!vert.empty()) {\n        ll pos = vert.top();\n        vert.pop();\n\
    \        each(i, gr[pos]) {\n            if (change[i.idx] == -1) {\n        \
    \        func[i] = i.cost;\n                change[i.idx] = i;\n             \
    \   vert.push(i);\n            }\n        }\n    }\n    struct ops {\n       \
    \ using point = array<mint, 2>;\n        using path = array<mint, 4>;\n      \
    \  static path vertex(int v) {\n            return {1, a[v] * func[v].fi + func[v].se,\
    \ func[v].fi, func[v].se};\n        }\n        static path compress(path p, path\
    \ c) {\n            return {p[0] + c[0], p[1] + c[1] * p[2] + c[0] * p[3], p[2]\
    \ * c[2],\n                    p[2] * c[3] + p[3]};\n        }\n        static\
    \ path add_vertex(point t, int v) {\n            return {t[0] + 1,\n         \
    \           (a[v] + t[1]) * func[v].fi + (t[0] + 1) * func[v].se,\n          \
    \          func[v].fi, func[v].se};\n        }\n        static point rake(point\
    \ x, point y) {\n            return {x[0] + y[0], x[1] + y[1]};\n        }\n \
    \       static point add_edge(path t) { return {t[0], t[1]}; }\n    };\n    StaticTopTree<ops>\
    \ tree(gr, 0);\n    rep(_, Q) {\n        LL(t);\n        if (t == 0) {\n     \
    \       LL(w, x);\n            a[w] = x;\n            tree.calc(w);\n        }\
    \ else {\n            LL(e, y, z);\n            func[change[e]] = {y, z};\n  \
    \          tree.calc(change[e]);\n        }\n        out(tree.root_value()[1]);\n\
    \    }\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#include \"../../Graph/Graph.hpp\"\n#include \"../../Modint/Modint.hpp\"\n#include\
    \ \"../../Template/Template.hpp\"\n#include \"../../Tree/StaticTopTree.hpp\"\n\
    using mint = Modint<MOD>;\nusing edge_type = array<ll, 4>;\nusing func_type =\
    \ pair<mint, mint>;\nvoid solve() {\n    LL(N, Q);\n    static VEC(mint, a, N);\n\
    \    Graph<func_type> gr(N);\n    rep(i, N - 1) {\n        LL(u, v, b, c);\n \
    \       gr.add_edge(v, u, {b, c});\n    }\n    stack<ll> vert;\n    vert.push(0);\n\
    \    static vec(func_type, func, N, {1, 0});\n    vec(ll, change, N - 1, -1);\n\
    \    while (!vert.empty()) {\n        ll pos = vert.top();\n        vert.pop();\n\
    \        each(i, gr[pos]) {\n            if (change[i.idx] == -1) {\n        \
    \        func[i] = i.cost;\n                change[i.idx] = i;\n             \
    \   vert.push(i);\n            }\n        }\n    }\n    struct ops {\n       \
    \ using point = array<mint, 2>;\n        using path = array<mint, 4>;\n      \
    \  static path vertex(int v) {\n            return {1, a[v] * func[v].fi + func[v].se,\
    \ func[v].fi, func[v].se};\n        }\n        static path compress(path p, path\
    \ c) {\n            return {p[0] + c[0], p[1] + c[1] * p[2] + c[0] * p[3], p[2]\
    \ * c[2],\n                    p[2] * c[3] + p[3]};\n        }\n        static\
    \ path add_vertex(point t, int v) {\n            return {t[0] + 1,\n         \
    \           (a[v] + t[1]) * func[v].fi + (t[0] + 1) * func[v].se,\n          \
    \          func[v].fi, func[v].se};\n        }\n        static point rake(point\
    \ x, point y) {\n            return {x[0] + y[0], x[1] + y[1]};\n        }\n \
    \       static point add_edge(path t) { return {t[0], t[1]}; }\n    };\n    StaticTopTree<ops>\
    \ tree(gr, 0);\n    rep(_, Q) {\n        LL(t);\n        if (t == 0) {\n     \
    \       LL(w, x);\n            a[w] = x;\n            tree.calc(w);\n        }\
    \ else {\n            LL(e, y, z);\n            func[change[e]] = {y, z};\n  \
    \          tree.calc(change[e]);\n        }\n        out(tree.root_value()[1]);\n\
    \    }\n}\nint main() { solve(); }"
  dependsOn:
  - Graph/Graph.hpp
  - Modint/Modint.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  - Tree/StaticTopTree.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 20:13:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
