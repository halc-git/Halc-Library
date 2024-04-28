---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/1092.test.cpp
    title: Verify/verify-yuki/1092.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Modint/Modint.hpp\"\ntemplate<uint64_t Mod>\nstruct Modint{\n\
    \    uint64_t x;\n    constexpr Modint()noexcept{\n        x=0;\n    }\n    constexpr\
    \ Modint(int64_t val)noexcept{\n        x=(val<0?val%(int64_t)(Mod)+Mod:val%Mod);\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val)noexcept{\n        const static\
    \ uint64_t m_inv=(-1ULL)/Mod+1;\n        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;\n\
    \        uint64_t pro=ret*Mod;\n        return (val-pro+(val<pro?Mod:0));\n  \
    \  }\n    friend ostream &operator<<(ostream &os,Modint &b){\n        return os<<b.x;\n\
    \    }\n    friend istream &operator>>(istream &is,Modint &b){\n        return\
    \ is>>b.x;\n    }\n    constexpr uint64_t val()noexcept{\n        return x;\n\
    \    }\n    constexpr Modint operator+()noexcept{\n        return (*this);\n \
    \   }\n    constexpr Modint operator-()noexcept{\n        return Modint()-(*this);\n\
    \    }\n    constexpr Modint operator+(const Modint rhs)noexcept{\n        return\
    \ Modint(*this)+=rhs;\n    }\n    constexpr Modint operator-(const Modint rhs)noexcept{\n\
    \        return Modint(*this)-=rhs;\n    }\n    constexpr Modint operator*(const\
    \ Modint rhs)noexcept{\n        return Modint(*this)*=rhs;\n    }\n    constexpr\
    \ Modint operator/(const Modint rhs)noexcept{\n        return Modint(*this)/=rhs;\n\
    \    }\n    constexpr Modint &operator+=(const Modint rhs)noexcept{\n        x+=rhs.x;\n\
    \        if(x>=Mod)x-=Mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator-=(const Modint rhs)noexcept{\n        if(x<rhs.x)x+=Mod;\n       \
    \ x-=rhs.x;\n        return *this;\n    }\n    constexpr Modint &operator*=(const\
    \ Modint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n        return *this;\n\
    \    }\n    constexpr bool operator==(Modint rhs)noexcept{\n        return x==rhs.x;\n\
    \    }\n    constexpr bool operator!=(Modint rhs)noexcept{\n        return x!=rhs.x;\n\
    \    }\n    constexpr Modint &operator/=(Modint rhs)noexcept{\n        return\
    \ (*this)*=rhs.inv();\n    }\n    constexpr Modint inv()noexcept{\n        return\
    \ (*this).pow(Mod-2);\n    }\n    constexpr Modint pow(uint64_t x)noexcept{\n\
    \        Modint ret=1;\n        Modint bin=(*this);\n        while(x){\n     \
    \       if(x&1)ret*=bin;\n            bin*=bin;\n            x>>=1;\n        }\n\
    \        return ret;\n    }\n    static uint64_t get_mod()noexcept{\n        return\
    \ Mod;\n    }\n};\n\ntemplate<int64_t id>\nstruct ArbitraryModint{\n    uint64_t\
    \ x;\n    static uint64_t &mod()noexcept{\n        static uint64_t Mod=0;\n  \
    \      return Mod;\n    }\n    constexpr ArbitraryModint()noexcept{\n        x=0;\n\
    \    }\n    constexpr ArbitraryModint(int64_t val)noexcept{\n        x=(val<0?val%(int64_t)(get_mod())+get_mod():val%get_mod());\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val)noexcept{\n        const static\
    \ uint64_t m_inv=(-1ULL)/get_mod()+1;\n        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;\n\
    \        uint64_t pro=ret*get_mod();\n        return (val-pro+(val<pro?get_mod():0));\n\
    \    }\n    friend ostream &operator<<(ostream &os,ArbitraryModint &b){\n    \
    \    return os<<b.x;\n    }\n    friend istream &operator>>(istream &is,ArbitraryModint\
    \ &b){\n        return is>>b.x;\n    }\n    constexpr uint64_t val()noexcept{\n\
    \        return x;\n    }\n    constexpr ArbitraryModint operator+()noexcept{\n\
    \        return (*this);\n    }\n    constexpr ArbitraryModint operator-()noexcept{\n\
    \        return ArbitraryModint()-(*this);\n    }\n    constexpr ArbitraryModint\
    \ operator+(const ArbitraryModint rhs)noexcept{\n        return ArbitraryModint(*this)+=rhs;\n\
    \    }\n    constexpr ArbitraryModint operator-(const ArbitraryModint rhs)noexcept{\n\
    \        return ArbitraryModint(*this)-=rhs;\n    }\n    constexpr ArbitraryModint\
    \ operator*(const ArbitraryModint rhs)noexcept{\n        return ArbitraryModint(*this)*=rhs;\n\
    \    }\n    constexpr ArbitraryModint operator/(const ArbitraryModint rhs)noexcept{\n\
    \        return ArbitraryModint(*this)/=rhs;\n    }\n    constexpr ArbitraryModint\
    \ &operator+=(const ArbitraryModint rhs)noexcept{\n        x+=rhs.x;\n       \
    \ if(x>=get_mod())x-=get_mod();\n        return *this;\n    }\n    constexpr ArbitraryModint\
    \ &operator-=(const ArbitraryModint rhs)noexcept{\n        if(x<rhs.x)x+=get_mod();\n\
    \        x-=rhs.x;\n        return *this;\n    }\n    constexpr ArbitraryModint\
    \ &operator*=(const ArbitraryModint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr ArbitraryModint &operator/=(ArbitraryModint\
    \ rhs)noexcept{\n        return (*this)*=rhs.inv();\n    }\n    constexpr bool\
    \ operator==(ArbitraryModint rhs)noexcept{\n        return x==rhs.x;\n    }\n\
    \    constexpr bool operator!=(ArbitraryModint rhs)noexcept{\n        return x!=rhs.x;\n\
    \    }\n    constexpr ArbitraryModint inv()noexcept{\n        return (*this).pow(get_mod()-2);\n\
    \    }\n    constexpr ArbitraryModint pow(uint64_t x)noexcept{\n        ArbitraryModint\
    \ ret=1;\n        ArbitraryModint bin=(*this);\n        while(x){\n          \
    \  if(x&1)ret*=bin;\n            bin*=bin;\n            x>>=1;\n        }\n  \
    \      return ret;\n    }\n    static void set_mod(const uint64_t x)noexcept{\n\
    \        mod()=x;\n    }\n    static uint64_t get_mod()noexcept{\n        return\
    \ mod();\n    }\n};\ntemplate<uint64_t N> inline void print(Modint<N> a){cout\
    \ << a;}\ntemplate<int64_t id> inline void print(ArbitraryModint<id> a){cout <<\
    \ a;}\n"
  code: "template<uint64_t Mod>\nstruct Modint{\n    uint64_t x;\n    constexpr Modint()noexcept{\n\
    \        x=0;\n    }\n    constexpr Modint(int64_t val)noexcept{\n        x=(val<0?val%(int64_t)(Mod)+Mod:val%Mod);\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val)noexcept{\n        const static\
    \ uint64_t m_inv=(-1ULL)/Mod+1;\n        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;\n\
    \        uint64_t pro=ret*Mod;\n        return (val-pro+(val<pro?Mod:0));\n  \
    \  }\n    friend ostream &operator<<(ostream &os,Modint &b){\n        return os<<b.x;\n\
    \    }\n    friend istream &operator>>(istream &is,Modint &b){\n        return\
    \ is>>b.x;\n    }\n    constexpr uint64_t val()noexcept{\n        return x;\n\
    \    }\n    constexpr Modint operator+()noexcept{\n        return (*this);\n \
    \   }\n    constexpr Modint operator-()noexcept{\n        return Modint()-(*this);\n\
    \    }\n    constexpr Modint operator+(const Modint rhs)noexcept{\n        return\
    \ Modint(*this)+=rhs;\n    }\n    constexpr Modint operator-(const Modint rhs)noexcept{\n\
    \        return Modint(*this)-=rhs;\n    }\n    constexpr Modint operator*(const\
    \ Modint rhs)noexcept{\n        return Modint(*this)*=rhs;\n    }\n    constexpr\
    \ Modint operator/(const Modint rhs)noexcept{\n        return Modint(*this)/=rhs;\n\
    \    }\n    constexpr Modint &operator+=(const Modint rhs)noexcept{\n        x+=rhs.x;\n\
    \        if(x>=Mod)x-=Mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator-=(const Modint rhs)noexcept{\n        if(x<rhs.x)x+=Mod;\n       \
    \ x-=rhs.x;\n        return *this;\n    }\n    constexpr Modint &operator*=(const\
    \ Modint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n        return *this;\n\
    \    }\n    constexpr bool operator==(Modint rhs)noexcept{\n        return x==rhs.x;\n\
    \    }\n    constexpr bool operator!=(Modint rhs)noexcept{\n        return x!=rhs.x;\n\
    \    }\n    constexpr Modint &operator/=(Modint rhs)noexcept{\n        return\
    \ (*this)*=rhs.inv();\n    }\n    constexpr Modint inv()noexcept{\n        return\
    \ (*this).pow(Mod-2);\n    }\n    constexpr Modint pow(uint64_t x)noexcept{\n\
    \        Modint ret=1;\n        Modint bin=(*this);\n        while(x){\n     \
    \       if(x&1)ret*=bin;\n            bin*=bin;\n            x>>=1;\n        }\n\
    \        return ret;\n    }\n    static uint64_t get_mod()noexcept{\n        return\
    \ Mod;\n    }\n};\n\ntemplate<int64_t id>\nstruct ArbitraryModint{\n    uint64_t\
    \ x;\n    static uint64_t &mod()noexcept{\n        static uint64_t Mod=0;\n  \
    \      return Mod;\n    }\n    constexpr ArbitraryModint()noexcept{\n        x=0;\n\
    \    }\n    constexpr ArbitraryModint(int64_t val)noexcept{\n        x=(val<0?val%(int64_t)(get_mod())+get_mod():val%get_mod());\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val)noexcept{\n        const static\
    \ uint64_t m_inv=(-1ULL)/get_mod()+1;\n        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;\n\
    \        uint64_t pro=ret*get_mod();\n        return (val-pro+(val<pro?get_mod():0));\n\
    \    }\n    friend ostream &operator<<(ostream &os,ArbitraryModint &b){\n    \
    \    return os<<b.x;\n    }\n    friend istream &operator>>(istream &is,ArbitraryModint\
    \ &b){\n        return is>>b.x;\n    }\n    constexpr uint64_t val()noexcept{\n\
    \        return x;\n    }\n    constexpr ArbitraryModint operator+()noexcept{\n\
    \        return (*this);\n    }\n    constexpr ArbitraryModint operator-()noexcept{\n\
    \        return ArbitraryModint()-(*this);\n    }\n    constexpr ArbitraryModint\
    \ operator+(const ArbitraryModint rhs)noexcept{\n        return ArbitraryModint(*this)+=rhs;\n\
    \    }\n    constexpr ArbitraryModint operator-(const ArbitraryModint rhs)noexcept{\n\
    \        return ArbitraryModint(*this)-=rhs;\n    }\n    constexpr ArbitraryModint\
    \ operator*(const ArbitraryModint rhs)noexcept{\n        return ArbitraryModint(*this)*=rhs;\n\
    \    }\n    constexpr ArbitraryModint operator/(const ArbitraryModint rhs)noexcept{\n\
    \        return ArbitraryModint(*this)/=rhs;\n    }\n    constexpr ArbitraryModint\
    \ &operator+=(const ArbitraryModint rhs)noexcept{\n        x+=rhs.x;\n       \
    \ if(x>=get_mod())x-=get_mod();\n        return *this;\n    }\n    constexpr ArbitraryModint\
    \ &operator-=(const ArbitraryModint rhs)noexcept{\n        if(x<rhs.x)x+=get_mod();\n\
    \        x-=rhs.x;\n        return *this;\n    }\n    constexpr ArbitraryModint\
    \ &operator*=(const ArbitraryModint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr ArbitraryModint &operator/=(ArbitraryModint\
    \ rhs)noexcept{\n        return (*this)*=rhs.inv();\n    }\n    constexpr bool\
    \ operator==(ArbitraryModint rhs)noexcept{\n        return x==rhs.x;\n    }\n\
    \    constexpr bool operator!=(ArbitraryModint rhs)noexcept{\n        return x!=rhs.x;\n\
    \    }\n    constexpr ArbitraryModint inv()noexcept{\n        return (*this).pow(get_mod()-2);\n\
    \    }\n    constexpr ArbitraryModint pow(uint64_t x)noexcept{\n        ArbitraryModint\
    \ ret=1;\n        ArbitraryModint bin=(*this);\n        while(x){\n          \
    \  if(x&1)ret*=bin;\n            bin*=bin;\n            x>>=1;\n        }\n  \
    \      return ret;\n    }\n    static void set_mod(const uint64_t x)noexcept{\n\
    \        mod()=x;\n    }\n    static uint64_t get_mod()noexcept{\n        return\
    \ mod();\n    }\n};\ntemplate<uint64_t N> inline void print(Modint<N> a){cout\
    \ << a;}\ntemplate<int64_t id> inline void print(ArbitraryModint<id> a){cout <<\
    \ a;}\n"
  dependsOn: []
  isVerificationFile: false
  path: Modint/Modint.hpp
  requiredBy: []
  timestamp: '2024-04-28 12:56:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-yuki/1092.test.cpp
  - Verify/verify-yuki/117.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
documentation_of: Modint/Modint.hpp
layout: document
redirect_from:
- /library/Modint/Modint.hpp
- /library/Modint/Modint.hpp.html
title: Modint/Modint.hpp
---