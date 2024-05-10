---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/1092.test.cpp
    title: Verify/verify-yuki/1092.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Modint/Modint.hpp\"\n#include <cstdint>\n#include <iostream>\n\
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
    \ void scan(Modint<N> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate <int64_t id>\n\
    inline void scan(ArbitraryModint<id> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate\
    \ <uint64_t N>\ninline void print(Modint<N> a) {\n    printf(\"%lu\", a.x);\n\
    }\ntemplate <int64_t id>\ninline void print(ArbitraryModint<id> a) {\n    printf(\"\
    %lu\", a.x);\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\ntemplate <uint64_t\
    \ Mod>\nstruct Modint {\n    uint64_t x;\n    constexpr Modint() noexcept { x\
    \ = 0; }\n    constexpr Modint(int64_t val) noexcept {\n        x = (val < 0 ?\
    \ val % (int64_t)(Mod) + Mod : val % Mod);\n    }\n    inline uint64_t _get_mod(uint64_t\
    \ val) noexcept {\n        const static uint64_t m_inv = (-1ULL) / Mod + 1;\n\
    \        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;\n        uint64_t\
    \ pro = ret * Mod;\n        return (val - pro + (val < pro ? Mod : 0));\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, Modint &b) {\n        return\
    \ os << b.x;\n    }\n    friend std::istream &operator>>(std::istream &is, Modint\
    \ &b) {\n        return is >> b.x;\n    }\n    constexpr uint64_t val() noexcept\
    \ { return x; }\n    constexpr Modint operator+() noexcept { return (*this); }\n\
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
    \ void scan(Modint<N> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate <int64_t id>\n\
    inline void scan(ArbitraryModint<id> &a) {\n    scanf(\"%lu\", &a.x);\n}\ntemplate\
    \ <uint64_t N>\ninline void print(Modint<N> a) {\n    printf(\"%lu\", a.x);\n\
    }\ntemplate <int64_t id>\ninline void print(ArbitraryModint<id> a) {\n    printf(\"\
    %lu\", a.x);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/Modint.hpp
  requiredBy: []
  timestamp: '2024-05-08 20:46:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-yuki/1092.test.cpp
  - Verify/verify-yuki/117.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Modint/Modint.hpp
layout: document
redirect_from:
- /library/Modint/Modint.hpp
- /library/Modint/Modint.hpp.html
title: Modint/Modint.hpp
---
