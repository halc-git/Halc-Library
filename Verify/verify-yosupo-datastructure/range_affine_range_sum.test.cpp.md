---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"DataStructure/LazySegmentTree.hpp\"\n#include <bit>\n#include <cstdint>\n\
    #include <queue>\n#include <stack>\n#include <vector>\ntemplate <class M>\nstruct\
    \ LazySegmentTree {\n    using T = typename M::T;\n    using F = typename M::F;\n\
    \    int32_t siz;\n    std::vector<T> tree;\n    std::vector<F> del;\n    LazySegmentTree(int32_t\
    \ sz) {\n        siz = sz;\n        tree = std::vector<T>(siz << 1, M::e);\n \
    \       del = std::vector<F>(siz << 1, M::id);\n    }\n    LazySegmentTree(std::vector<T>\
    \ def) {\n        siz = def.size();\n        tree = std::vector<T>(siz << 1, M::e);\n\
    \        del = std::vector<F>(siz << 1, M::id);\n        for (int32_t i = 0; i\
    \ < siz; i++) {\n            tree[i + siz] = def[i];\n        }\n        for (int32_t\
    \ i = siz - 1; i > 0; i--) {\n            tree[i] = M::op(tree[i << 1], tree[(i\
    \ << 1) + 1]);\n        }\n    }\n    inline T _get(int32_t pos) { return tree[pos];\
    \ }\n    void _calc(int32_t p) {\n        p >>= 1;\n        while (p > 0) {\n\
    \            tree[p] = M::op(_get(p << 1), _get((p << 1) + 1));\n            p\
    \ >>= 1;\n        }\n    }\n    inline void _del_segment(int32_t p) {\n      \
    \  tree[p << 1] = M::mapp(del[p], tree[p << 1]);\n        del[p << 1] = M::comp(del[p],\
    \ del[p << 1]);\n        tree[(p << 1) + 1] = M::mapp(del[p], tree[(p << 1) +\
    \ 1]);\n        del[(p << 1) + 1] = M::comp(del[p], del[(p << 1) + 1]);\n    \
    \    del[p] = M::id;\n    }\n    void _delay(int32_t p) {\n        int32_t length\
    \ = 32 - std::countl_zero((uint32_t)p);\n        for (int32_t i = length - 1;\
    \ i >= 1; i--) {\n            _del_segment(p >> i);\n        }\n    }\n    void\
    \ set(int32_t p, T v) {\n        p += siz;\n        _delay(p);\n        tree[p]\
    \ = v;\n        del[p] = M::id;\n        _calc(p);\n    }\n    T get(int32_t p)\
    \ {\n        _delay(p + siz);\n        return _get(p + siz);\n    }\n    void\
    \ apply(int32_t lf, int32_t ri, F f) {\n        lf += siz;\n        ri += siz;\n\
    \        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n        int32_t\
    \ dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n        _delay(dr\
    \ - 1);\n        while (lf < ri) {\n            if (lf & 1) {\n              \
    \  tree[lf] = M::mapp(f, tree[lf]);\n                del[lf] = M::comp(f, del[lf]);\n\
    \                lf++;\n            }\n            if (ri & 1) {\n           \
    \     ri--;\n                tree[ri] = M::mapp(f, tree[ri]);\n              \
    \  del[ri] = M::comp(f, del[ri]);\n            }\n            lf >>= 1;\n    \
    \        ri >>= 1;\n        }\n        _calc(dl);\n        _calc(dr - 1);\n  \
    \  }\n    T prod(int32_t lf, int32_t ri) {\n        lf += siz;\n        ri +=\
    \ siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n       \
    \ int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        T rel = M::e;\n        T rer = M::e;\n     \
    \   while (lf < ri) {\n            if (lf & 1) {\n                rel = M::op(rel,\
    \ _get(lf));\n                lf++;\n            }\n            if (ri & 1) {\n\
    \                ri--;\n                rer = M::op(_get(ri), rer);\n        \
    \    }\n            lf >>= 1;\n            ri >>= 1;\n        }\n        return\
    \ M::op(rel, rer);\n    }\n    template <class F>\n    int32_t max_right(int32_t\
    \ lf, F f) {\n        lf += siz;\n        int32_t ri = siz << 1;\n        int32_t\
    \ dl = lf >> (std::countr_zero((uint32_t)lf));\n        int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n\
    \        _delay(dl);\n        _delay(dr - 1);\n        std::queue<int32_t> lfp;\n\
    \        std::stack<int32_t> rip;\n        while (lf < ri) {\n            if (lf\
    \ & 1) {\n                lfp.push(lf);\n                lf++;\n            }\n\
    \            if (ri & 1) {\n                ri--;\n                rip.push(ri);\n\
    \            }\n            lf >>= 1;\n            ri >>= 1;\n        }\n    \
    \    T val = M::e;\n        while (!lfp.empty()) {\n            int32_t i = lfp.front();\n\
    \            lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n        \
    \        while (i < siz) {\n                    _del_segment(i);\n           \
    \         i <<= 1;\n                    if (f(M::op(val, _get(i)))) {\n      \
    \                  val = M::op(val, _get(i));\n                        i++;\n\
    \                    }\n                }\n                return i - siz;\n \
    \           }\n            val = M::op(val, _get(i));\n        }\n        while\
    \ (!rip.empty()) {\n            int32_t i = rip.top();\n            rip.pop();\n\
    \            if (!f(M::op(val, _get(i)))) {\n                while (i < siz) {\n\
    \                    _del_segment(i);\n                    i <<= 1;\n        \
    \            if (f(M::op(val, _get(i)))) {\n                        val = M::op(val,\
    \ _get(i));\n                        i++;\n                    }\n           \
    \     }\n                return i - siz;\n            }\n            val = M::op(val,\
    \ _get(i));\n        }\n        return siz;\n    }\n    template <class F>\n \
    \   int32_t min_left(int32_t ri, F f) {\n        ri += siz;\n        int32_t lf\
    \ = siz;\n        int32_t dl = lf >> (std::countr_zero((uint32_t)lf));\n     \
    \   int32_t dr = ri >> (std::countr_zero((uint32_t)ri));\n        _delay(dl);\n\
    \        _delay(dr - 1);\n        std::queue<int32_t> rip;\n        std::stack<int32_t>\
    \ lfp;\n        while (lf < ri) {\n            if (lf & 1) {\n               \
    \ lfp.push(lf);\n                lf++;\n            }\n            if (ri & 1)\
    \ {\n                ri--;\n                rip.push(ri);\n            }\n   \
    \         lf >>= 1;\n            ri >>= 1;\n        }\n        T val = M::e;\n\
    \        while (!rip.empty()) {\n            int32_t i = rip.front();\n      \
    \      rip.pop();\n            if (!f(M::op(val, _get(i)))) {\n              \
    \  while (i < siz) {\n                    _del_segment(i);\n                 \
    \   i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        while (!lfp.empty()) {\n            int32_t i = lfp.top();\n   \
    \         lfp.pop();\n            if (!f(M::op(val, _get(i)))) {\n           \
    \     while (i < siz) {\n                    _del_segment(i);\n              \
    \      i <<= 1;\n                    i++;\n                    if (f(M::op(_get(i),\
    \ val))) {\n                        val = M::op(_get(i), val);\n             \
    \           i--;\n                    }\n                }\n                return\
    \ i - siz + 1;\n            }\n            val = M::op(_get(i), val);\n      \
    \  }\n        return 0;\n    }\n    int32_t size() { return siz; }\n};\n#line\
    \ 3 \"Modint/Modint.hpp\"\n#include <iostream>\ntemplate <uint64_t Mod>\nstruct\
    \ Modint {\n    uint64_t x;\n    constexpr Modint() noexcept { x = 0; }\n    constexpr\
    \ Modint(int64_t val) noexcept {\n        x = (val < 0 ? val % (int64_t)(Mod)\
    \ + Mod : val % Mod);\n    }\n    inline uint64_t _get_mod(uint64_t val) noexcept\
    \ {\n        const static uint64_t m_inv = (-1ULL) / Mod + 1;\n        uint64_t\
    \ ret = ((unsigned __int128)(val)*m_inv) >> 64;\n        uint64_t pro = ret *\
    \ Mod;\n        return (val - pro + (val < pro ? Mod : 0));\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, Modint &b) {\n        return os <<\
    \ b.x;\n    }\n    friend std::istream &operator>>(std::istream &is, Modint &b)\
    \ {\n        return is >> b.x;\n    }\n    constexpr uint64_t val() noexcept {\
    \ return x; }\n    constexpr Modint operator+() noexcept { return (*this); }\n\
    \    constexpr Modint operator-() noexcept { return Modint() - (*this); }\n  \
    \  constexpr Modint operator+(const Modint rhs) noexcept {\n        return Modint(*this)\
    \ += rhs;\n    }\n    constexpr Modint operator-(const Modint rhs) noexcept {\n\
    \        return Modint(*this) -= rhs;\n    }\n    constexpr Modint operator*(const\
    \ Modint rhs) noexcept {\n        return Modint(*this) *= rhs;\n    }\n    constexpr\
    \ Modint operator/(const Modint rhs) noexcept {\n        return Modint(*this)\
    \ /= rhs;\n    }\n    constexpr Modint &operator+=(const Modint rhs) noexcept\
    \ {\n        x += rhs.x;\n        if (x >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n    constexpr Modint &operator-=(const Modint rhs) noexcept {\n      \
    \  if (x < rhs.x) x += Mod;\n        x -= rhs.x;\n        return *this;\n    }\n\
    \    constexpr Modint &operator*=(const Modint rhs) noexcept {\n        x = _get_mod(x\
    \ * rhs.x);\n        return *this;\n    }\n    constexpr bool operator==(Modint\
    \ rhs) noexcept { return x == rhs.x; }\n    constexpr bool operator!=(Modint rhs)\
    \ noexcept { return x != rhs.x; }\n    constexpr Modint &operator/=(Modint rhs)\
    \ noexcept {\n        return (*this) *= rhs.inv();\n    }\n    constexpr Modint\
    \ inv() noexcept { return (*this).pow(Mod - 2); }\n    constexpr Modint pow(uint64_t\
    \ x) noexcept {\n        Modint ret = 1;\n        Modint bin = (*this);\n    \
    \    while (x) {\n            if (x & 1) ret *= bin;\n            bin *= bin;\n\
    \            x >>= 1;\n        }\n        return ret;\n    }\n    static uint64_t\
    \ get_mod() noexcept { return Mod; }\n};\n\ntemplate <int64_t id>\nstruct ArbitraryModint\
    \ {\n    uint64_t x;\n    static uint64_t &mod() noexcept {\n        static uint64_t\
    \ Mod = 0;\n        return Mod;\n    }\n    constexpr ArbitraryModint() noexcept\
    \ { x = 0; }\n    constexpr ArbitraryModint(int64_t val) noexcept {\n        x\
    \ = (val < 0 ? val % (int64_t)(get_mod()) + get_mod()\n                     :\
    \ val % get_mod());\n    }\n    inline uint64_t _get_mod(uint64_t val) noexcept\
    \ {\n        const static uint64_t m_inv = (-1ULL) / get_mod() + 1;\n        uint64_t\
    \ ret = ((unsigned __int128)(val)*m_inv) >> 64;\n        uint64_t pro = ret *\
    \ get_mod();\n        return (val - pro + (val < pro ? get_mod() : 0));\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, ArbitraryModint &b) {\n\
    \        return os << b.x;\n    }\n    friend std::istream &operator>>(std::istream\
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
    \ name(h, std::vector<type>(w)); in(name)\n#line 5 \"Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp\"\
    \nusing mint = Modint<MOD>;\nstruct affine {\n    using T = pair<ll, mint>;\n\
    \    static T op(T x, T y) { return {x.fi + y.fi, x.se + y.se}; }\n    static\
    \ inline T e = {0, 0};\n    using F = pair<mint, mint>;\n    static T mapp(F f,\
    \ T x) { return {x.fi, f.fi * x.se + f.se * x.fi}; }\n    static F comp(F f, F\
    \ g) { return {f.fi * g.fi, g.se * f.fi + f.se}; }\n    static inline F id = {1,\
    \ 0};\n};\nvoid solve() {\n    LL(N, Q);\n    VEC(ll, A, N);\n    LazySegmentTree<affine>\
    \ a(N);\n    rep(i, N) { a.set(i, {1, A[i]}); }\n    rep(i, Q) {\n        LL(t);\n\
    \        if (t == 0) {\n            LL(l, r, b, c);\n            a.apply(l, r,\
    \ {b, c});\n        } else {\n            LL(l, r);\n            out(a.prod(l,\
    \ r).se);\n        }\n    }\n}\nint main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../DataStructure/LazySegmentTree.hpp\"\n#include \"../../Modint/Modint.hpp\"\
    \n#include \"../../Template/Template.hpp\"\nusing mint = Modint<MOD>;\nstruct\
    \ affine {\n    using T = pair<ll, mint>;\n    static T op(T x, T y) { return\
    \ {x.fi + y.fi, x.se + y.se}; }\n    static inline T e = {0, 0};\n    using F\
    \ = pair<mint, mint>;\n    static T mapp(F f, T x) { return {x.fi, f.fi * x.se\
    \ + f.se * x.fi}; }\n    static F comp(F f, F g) { return {f.fi * g.fi, g.se *\
    \ f.fi + f.se}; }\n    static inline F id = {1, 0};\n};\nvoid solve() {\n    LL(N,\
    \ Q);\n    VEC(ll, A, N);\n    LazySegmentTree<affine> a(N);\n    rep(i, N) {\
    \ a.set(i, {1, A[i]}); }\n    rep(i, Q) {\n        LL(t);\n        if (t == 0)\
    \ {\n            LL(l, r, b, c);\n            a.apply(l, r, {b, c});\n       \
    \ } else {\n            LL(l, r);\n            out(a.prod(l, r).se);\n       \
    \ }\n    }\n}\nint main() { solve(); }"
  dependsOn:
  - DataStructure/LazySegmentTree.hpp
  - Modint/Modint.hpp
  - Template/Template.hpp
  - Template/InOut.hpp
  - Template/Util.hpp
  - Template/Macro.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 20:13:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
- /verify/Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp.html
title: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
---
