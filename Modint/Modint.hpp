#pragma once
#include <assert.h>

#include <cstdint>
#include <iostream>
template <uint64_t Mod>
struct Modint {
    uint64_t x;
    constexpr Modint() noexcept { x = 0; }
    constexpr Modint(int64_t val) noexcept {
        x = (val < 0 ? val % (int64_t)(Mod) + Mod : val % Mod);
    }
    inline uint64_t _get_mod(uint64_t val) noexcept {
        const static uint64_t m_inv = (-1ULL) / Mod + 1;
        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;
        uint64_t pro = ret * Mod;
        return (val - pro + (val < pro ? Mod : 0));
    }
    friend std::ostream &operator<<(std::ostream &os, Modint &b) noexcept {
        return os << b.x;
    }
    friend std::istream &operator>>(std::istream &is, Modint &b) noexcept {
        return is >> b.x;
    }
    constexpr uint64_t val() noexcept { return x; }
    constexpr Modint operator+() noexcept { return (*this); }
    constexpr Modint operator-() noexcept { return Modint() - (*this); }
    friend Modint operator+(const Modint lhs, const Modint rhs) noexcept {
        return Modint(lhs) += rhs;
    }
    friend Modint operator-(const Modint lhs, const Modint rhs) noexcept {
        return Modint(lhs) -= rhs;
    }
    friend Modint operator*(const Modint lhs, const Modint rhs) noexcept {
        return Modint(lhs) *= rhs;
    }
    friend Modint operator/(const Modint lhs, const Modint rhs) {
        return Modint(lhs) /= rhs;
    }
    constexpr Modint &operator+=(const Modint rhs) noexcept {
        x += rhs.x;
        if (x >= Mod) x -= Mod;
        return *this;
    }
    constexpr Modint &operator-=(const Modint rhs) noexcept {
        if (x < rhs.x) x += Mod;
        x -= rhs.x;
        return *this;
    }
    constexpr Modint &operator*=(const Modint rhs) noexcept {
        x = _get_mod(x * rhs.x);
        return *this;
    }
    friend bool operator==(const Modint lhs, const Modint rhs) noexcept {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const Modint lhs, const Modint rhs) noexcept {
        return rhs.x != rhs.x;
    }
    constexpr Modint &operator/=(Modint rhs) { return (*this) *= rhs.inv(); }
    constexpr Modint inv() {
        int64_t a = (*this).x, b = get_mod();
        assert(a != 0);
        int64_t s = b, t = a;
        int64_t m0 = 0, m1 = 1;
        while (t) {
            int64_t u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            int64_t tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        assert(s == 1);
        if (m0 < 0) m0 += b;
        return Modint(m0);
    }
    constexpr Modint pow(uint64_t x) noexcept {
        Modint ret = 1;
        Modint bin = (*this);
        while (x) {
            if (x & 1) ret *= bin;
            bin *= bin;
            x >>= 1;
        }
        return ret;
    }
    static uint64_t get_mod() noexcept { return Mod; }
};

template <int64_t id>
struct ArbitraryModint {
    uint64_t x;
    static uint64_t &mod() noexcept {
        static uint64_t Mod = 0;
        return Mod;
    }
    constexpr ArbitraryModint() noexcept { x = 0; }
    constexpr ArbitraryModint(int64_t val) noexcept {
        x = (val < 0 ? val % (int64_t)(get_mod()) + get_mod()
                     : val % get_mod());
    }
    inline uint64_t _get_mod(uint64_t val) noexcept {
        const static uint64_t m_inv = (-1ULL) / get_mod() + 1;
        uint64_t ret = ((unsigned __int128)(val)*m_inv) >> 64;
        uint64_t pro = ret * get_mod();
        return (val - pro + (val < pro ? get_mod() : 0));
    }
    friend std::ostream &operator<<(std::ostream &os,
                                    ArbitraryModint &b) noexcept {
        return os << b.x;
    }
    friend std::istream &operator>>(std::istream &is,
                                    ArbitraryModint &b) noexcept {
        return is >> b.x;
    }
    constexpr uint64_t val() noexcept { return x; }
    constexpr ArbitraryModint operator+() noexcept { return (*this); }
    constexpr ArbitraryModint operator-() noexcept {
        return ArbitraryModint() - (*this);
    }
    friend ArbitraryModint operator+(const ArbitraryModint lhs,
                                     const ArbitraryModint rhs) noexcept {
        return Modint(lhs) += rhs;
    }
    friend ArbitraryModint operator-(const ArbitraryModint lhs,
                                     const ArbitraryModint rhs) noexcept {
        return Modint(lhs) -= rhs;
    }
    friend ArbitraryModint operator*(const ArbitraryModint lhs,
                                     const ArbitraryModint rhs) noexcept {
        return Modint(lhs) *= rhs;
    }
    friend ArbitraryModint operator/(const ArbitraryModint lhs,
                                     const ArbitraryModint rhs) {
        return Modint(lhs) /= rhs;
    }
    constexpr ArbitraryModint &operator+=(const ArbitraryModint rhs) noexcept {
        x += rhs.x;
        if (x >= mod()) x -= mod();
        return *this;
    }
    constexpr ArbitraryModint &operator-=(const ArbitraryModint rhs) noexcept {
        if (x < rhs.x) x += mod();
        x -= rhs.x;
        return *this;
    }
    constexpr ArbitraryModint &operator*=(const ArbitraryModint rhs) noexcept {
        x = _get_mod(x * rhs.x);
        return *this;
    }
    friend bool operator==(const ArbitraryModint lhs,
                           const ArbitraryModint rhs) noexcept {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(const ArbitraryModint lhs,
                           const ArbitraryModint rhs) noexcept {
        return rhs.x != rhs.x;
    }
    constexpr ArbitraryModint &operator/=(ArbitraryModint rhs) {
        return (*this) *= rhs.inv();
    }
    constexpr ArbitraryModint inv() {
        int64_t a = (*this).x, b = get_mod();
        assert(a != 0);
        int64_t s = b, t = a;
        int64_t m0 = 0, m1 = 1;
        while (t) {
            int64_t u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            int64_t tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        assert(s == 1);
        if (m0 < 0) m0 += b;
        return ArbitraryModint(m0);
    }
    constexpr ArbitraryModint pow(uint64_t x) noexcept {
        ArbitraryModint ret = 1;
        ArbitraryModint bin = (*this);
        while (x) {
            if (x & 1) ret *= bin;
            bin *= bin;
            x >>= 1;
        }
        return ret;
    }
    static void set_mod(const uint64_t x) noexcept { mod() = x; }
    static uint64_t get_mod() noexcept { return mod(); }
};
template <uint64_t N>
inline void scan(Modint<N> &a) {
    std::cin >> a.x;
}
template <int64_t id>
inline void scan(ArbitraryModint<id> &a) {
    std::cin >> a.x;
}
template <uint64_t N>
inline void print(Modint<N> a) {
    std::cout << a.x;
}
template <int64_t id>
inline void print(ArbitraryModint<id> a) {
    std::cout << a.x;
}
