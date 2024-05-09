---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FoldableDeque.hpp
    title: Foldable Deque
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#line 2 \"DataStructure/FoldableDeque.hpp\"\n#include <cstddef>\n#include <cstdint>\n\
    #include <stack>\n#include <vector>\n// https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template <class M>\nstruct FoldableQueue {\n    using T = typename M::T;\n   \
    \ std::stack<T> top, bottom, topfold, bottomfold;\n    FoldableQueue() {\n   \
    \     topfold.push(M::e);\n        bottomfold.push(M::e);\n    }\n    void push(T\
    \ v) {\n        bottom.push(v);\n        bottomfold.push(M::op(bottomfold.top(),\
    \ v));\n    }\n    void pop() {\n        if (top.empty()) {\n            while\
    \ (!bottom.empty()) {\n                top.push(bottom.top());\n             \
    \   topfold.push(M::op(bottom.top(), topfold.top()));\n                bottom.pop();\n\
    \                bottomfold.pop();\n            }\n        }\n        top.pop();\n\
    \        topfold.pop();\n    }\n    T front() {\n        if (top.empty()) {\n\
    \            while (!bottom.empty()) {\n                top.push(bottom.top());\n\
    \                topfold.push(M::op(bottom.top(), topfold.top()));\n         \
    \       bottom.pop();\n                bottomfold.pop();\n            }\n    \
    \    }\n        return top.top();\n    }\n    T get_all() { return M::op(topfold.top(),\
    \ bottomfold.top()); }\n    size_t size() { return top.size() + bottom.size();\
    \ }\n    bool empty() { return top.empty() && bottom.empty(); }\n};\ntemplate\
    \ <class M>\nstruct FoldableDeque {\n    using T = typename M::T;\n    std::stack<T>\
    \ top, bottom, topfold, bottomfold;\n    FoldableDeque() {\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push_front(T v) {\n        top.push(v);\n\
    \        topfold.push(M::op(v, topfold.top()));\n    }\n    void push_back(T v)\
    \ {\n        bottom.push(v);\n        bottomfold.push(M::op(bottomfold.top(),\
    \ v));\n    }\n    void pop_front() {\n        if (top.empty()) {\n          \
    \  std::vector<T> change;\n            while (!bottom.empty()) {\n           \
    \     change.emplace_back(bottom.top());\n                bottom.pop();\n    \
    \            bottomfold.pop();\n            }\n            size_t sz = change.size();\n\
    \            for (int32_t i = (sz >> 1); i >= 0; i--) {\n                top.push(change[sz\
    \ - i - 1]);\n                topfold.push(M::op(change[sz - i - 1], topfold.top()));\n\
    \            }\n            for (int32_t i = (sz >> 1) + 1; i < sz; i++) {\n \
    \               bottom.push(change[sz - i - 1]);\n                bottomfold.push(M::op(bottomfold.top(),\
    \ change[sz - i - 1]));\n            }\n        }\n        top.pop();\n      \
    \  topfold.pop();\n    }\n    void pop_back() {\n        if (bottom.empty()) {\n\
    \            std::vector<T> change;\n            while (!top.empty()) {\n    \
    \            change.emplace_back(top.top());\n                top.pop();\n   \
    \             topfold.pop();\n            }\n            size_t sz = change.size();\n\
    \            for (int32_t i = (sz >> 1); i >= 0; i--) {\n                bottom.push(change[sz\
    \ - i - 1]);\n                bottomfold.push(M::op(bottomfold.top(), change[sz\
    \ - i - 1]));\n            }\n            for (int32_t i = (sz >> 1) + 1; i <\
    \ sz; i++) {\n                top.push(change[sz - i - 1]);\n                topfold.push(M::op(change[sz\
    \ - i - 1], topfold.top()));\n            }\n        }\n        bottom.pop();\n\
    \        bottomfold.pop();\n    }\n    T front() {\n        if (top.empty()) {\n\
    \            std::vector<T> change;\n            while (!bottom.empty()) {\n \
    \               change.emplace_back(bottom.top());\n                bottom.pop();\n\
    \                bottomfold.pop();\n            }\n            size_t sz = change.size();\n\
    \            for (uint32_t i = (sz >> 1); i >= 0; i--) {\n                top.push(change[i]);\n\
    \                topfold.push(M::op(change[i], topfold.top()));\n            }\n\
    \            for (uint32_t i = (sz >> 1) + 1; i < sz; i++) {\n               \
    \ bottom.push(change[i]);\n                bottomfold.push(M::op(bottomfold.top(),\
    \ change[i]));\n            }\n        }\n        return top.top();\n    }\n \
    \   T back() {\n        if (bottom.empty()) {\n            std::vector<T> change;\n\
    \            while (!top.empty()) {\n                change.emplace_back(top.top());\n\
    \                top.pop();\n                topfold.pop();\n            }\n \
    \           size_t sz = change.size();\n            for (uint32_t i = (sz >> 1);\
    \ i >= 0; i--) {\n                bottom.push(change[i]);\n                bottomfold.push(M::op(bottomfold.top(),\
    \ change[i]));\n            }\n            for (uint32_t i = (sz >> 1) + 1; i\
    \ < sz; i++) {\n                top.push(change[i]);\n                topfold.push(M::op(change[i],\
    \ topfold.top()));\n            }\n        }\n        return bottom.top();\n \
    \   }\n    T get_all() { return M::op(topfold.top(), bottomfold.top()); }\n  \
    \  size_t size() { return top.size() + bottom.size(); }\n    bool empty() { return\
    \ top.empty() && bottom.empty(); }\n};\n#line 3 \"Modint/Modint.hpp\"\n#include\
    \ <iostream>\ntemplate <uint64_t Mod>\nstruct Modint {\n    uint64_t x;\n    constexpr\
    \ Modint() noexcept { x = 0; }\n    constexpr Modint(int64_t val) noexcept {\n\
    \        x = (val < 0 ? val % (int64_t)(Mod) + Mod : val % Mod);\n    }\n    inline\
    \ uint64_t _get_mod(uint64_t val) noexcept {\n        const static uint64_t m_inv\
    \ = (-1ULL) / Mod + 1;\n        uint64_t ret = ((unsigned __int128)(val)*m_inv)\
    \ >> 64;\n        uint64_t pro = ret * Mod;\n        return (val - pro + (val\
    \ < pro ? Mod : 0));\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, Modint &b) {\n        return os << b.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, Modint &b) {\n        return is >> b.x;\n    }\n\
    \    constexpr uint64_t val() noexcept { return x; }\n    constexpr Modint operator+()\
    \ noexcept { return (*this); }\n    constexpr Modint operator-() noexcept { return\
    \ Modint() - (*this); }\n    constexpr Modint operator+(const Modint rhs) noexcept\
    \ {\n        return Modint(*this) += rhs;\n    }\n    constexpr Modint operator-(const\
    \ Modint rhs) noexcept {\n        return Modint(*this) -= rhs;\n    }\n    constexpr\
    \ Modint operator*(const Modint rhs) noexcept {\n        return Modint(*this)\
    \ *= rhs;\n    }\n    constexpr Modint operator/(const Modint rhs) noexcept {\n\
    \        return Modint(*this) /= rhs;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint rhs) noexcept {\n        x += rhs.x;\n        if (x >= Mod) x -= Mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint rhs)\
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
    \ void scan(Modint<N> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate <int64_t id>\n\
    inline void scan(ArbitraryModint<id> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate\
    \ <uint64_t N>\ninline void print(Modint<N> a) {\n    printf(\"%lu\", a.x);\n\
    }\ntemplate <int64_t id>\ninline void print(ArbitraryModint<id> a) {\n    printf(\"\
    %lu\", a.x);\n}\n#line 2 \"Template/Template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 8 \"Template/InOut.hpp\"\ninline int scan() { return\
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
    \ solve();\n}\nint main() { Halc::solve(); }\n#line 5 \"Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp\"\
    \nusing mint = Modint<MOD>;\nstruct composite {\n    using T = pair<mint, mint>;\n\
    \    static T op(T lf, T ri) { return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se);\
    \ }\n    static inline T e = T(1, 0);\n};\nvoid Halc::solve() {\n    LL(Q);\n\
    \    FoldableQueue<composite> que;\n    rep(i, Q) {\n        LL(t);\n        if\
    \ (t == 0) {\n            LL(a, b);\n            que.push(pll(a, b));\n      \
    \  }\n        if (t == 1) {\n            que.pop();\n        }\n        if (t\
    \ == 2) {\n            LL(x);\n            pair<mint, mint> ope = que.get_all();\n\
    \            out(ope.fi * x + ope.se);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../../DataStructure/FoldableDeque.hpp\"\n#include \"../../Modint/Modint.hpp\"\
    \n#include \"../../Template/Template.hpp\"\nusing mint = Modint<MOD>;\nstruct\
    \ composite {\n    using T = pair<mint, mint>;\n    static T op(T lf, T ri) {\
    \ return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se); }\n    static inline T e = T(1,\
    \ 0);\n};\nvoid Halc::solve() {\n    LL(Q);\n    FoldableQueue<composite> que;\n\
    \    rep(i, Q) {\n        LL(t);\n        if (t == 0) {\n            LL(a, b);\n\
    \            que.push(pll(a, b));\n        }\n        if (t == 1) {\n        \
    \    que.pop();\n        }\n        if (t == 2) {\n            LL(x);\n      \
    \      pair<mint, mint> ope = que.get_all();\n            out(ope.fi * x + ope.se);\n\
    \        }\n    }\n}"
  dependsOn:
  - DataStructure/FoldableDeque.hpp
  - Modint/Modint.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Macro.hpp
  - Template/Util.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-09 20:10:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
- /verify/Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp.html
title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
---
