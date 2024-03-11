---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/yuki_1092-barrett.test.cpp
    title: Verify/verify-yuki/yuki_1092-barrett.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/yuki_336-barrett.test.cpp
    title: Verify/verify-yuki/yuki_336-barrett.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/BarrettModint.hpp\"\ntemplate<uint32_t N>\nstruct BarrettModint{\n\
    \    static constexpr uint32_t _phi(){\n        uint32_t prime_fact=N;\n     \
    \   uint32_t ret=N;\n        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static constexpr uint64_t Nr=(-1ULL)/N+1;\n    static\
    \ constexpr uint32_t inv_power=_phi()-1;\n    static_assert(1<N);\n    static_assert(N<(1<<30));\n\
    \    int64_t x;\n    constexpr uint32_t mod(){\n        return N;\n    }\n   \
    \ constexpr int64_t _get_mod(int64_t x){\n        uint64_t ret=((unsigned __int128_t)x*Nr)>>64;\n\
    \        if(x-ret*N<0){\n            return x-(ret-1)*N;\n        }\n        return\
    \ x-ret*N;\n    }\n    constexpr BarrettModint()noexcept{\n        x=0;\n    }\n\
    \    constexpr BarrettModint(int64_t val)noexcept{\n        x=((val%N)+N)%N;\n\
    \    }\n    constexpr uint64_t val()noexcept{\n        return x;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,BarrettModint &b){\n        return os<<b.val();\n\
    \    }\n    constexpr BarrettModint operator+()noexcept{return *this;}\n    constexpr\
    \ BarrettModint operator-()noexcept{return BarrettModint()-(*this);}\n    constexpr\
    \ friend BarrettModint operator+(BarrettModint lhs,BarrettModint rhs)noexcept{\n\
    \        return BarrettModint(lhs)+=rhs;\n    }\n    constexpr friend BarrettModint\
    \ operator-(BarrettModint lhs,BarrettModint rhs)noexcept{\n        return BarrettModint(lhs)-=rhs;\n\
    \    }\n    constexpr friend BarrettModint operator*(BarrettModint lhs,BarrettModint\
    \ rhs)noexcept{\n        return BarrettModint(lhs)*=rhs;\n    }\n    constexpr\
    \ friend BarrettModint operator/(BarrettModint lhs,BarrettModint rhs){\n     \
    \   return BarrettModint(lhs)/=rhs;\n    }\n    constexpr BarrettModint operator+=(BarrettModint\
    \ rhs)noexcept{\n        x+=rhs.x;\n        if(x>=N)x-=N;\n        return *this;\n\
    \    }\n    constexpr BarrettModint operator-=(BarrettModint rhs)noexcept{\n \
    \       x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n    }\n    constexpr\
    \ BarrettModint operator*=(BarrettModint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr BarrettModint operator/=(BarrettModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    constexpr\
    \ BarrettModint& operator++(){\n        (*this)+=1;\n        return *this;\n \
    \   }\n    constexpr BarrettModint& operator--(){\n        (*this)-=1;\n     \
    \   return *this;\n    }\n    constexpr BarrettModint operator++(int){\n     \
    \   (*this)+=1;\n        return *this;\n    }\n    constexpr BarrettModint operator--(int){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    constexpr bool operator==(BarrettModint\
    \ rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n\
    \    constexpr bool operator!=(BarrettModint rhs)noexcept{\n        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    constexpr BarrettModint inv(){\n        BarrettModint ret=(*this).pow(inv_power);\n\
    \        assert(ret*(*this)==1);\n        return ret;\n    }\n    constexpr BarrettModint\
    \ pow(uint64_t x)noexcept{\n        BarrettModint ret=1;\n        BarrettModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int32_t\
    \ id>\nstruct ArbitraryBarrettModint{\n    static uint32_t _phi(uint32_t N){\n\
    \        uint32_t prime_fact=N;\n        uint32_t ret=N;\n        for(int i=2;\
    \ i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n                ret-=ret/i;\n\
    \                while(prime_fact%i==0){\n                    prime_fact/=i;\n\
    \                }\n            }\n        }\n        if(prime_fact!=1){\n   \
    \         ret-=ret/prime_fact;\n        }\n        return ret;\n    }\n    static\
    \ uint64_t N,Nr;\n    static uint32_t inv_power;\n    int64_t x;\n    static void\
    \ set_mod(uint32_t mod){\n        N=mod;\n        Nr=(-1ULL)/N+1;\n        inv_power=_phi(N)-1;\n\
    \        assert(1<mod);\n        assert(mod<(1<<30));\n    }\n    uint32_t mod(){\n\
    \        return N;\n    }\n    int64_t _get_mod(int64_t x){\n        uint64_t\
    \ ret=((unsigned __int128_t)x*Nr)>>64;\n        if(x-ret*N<0){\n            return\
    \ x-(ret-1)*N;\n        }\n        return x-ret*N;\n    }\n    ArbitraryBarrettModint()noexcept{\n\
    \        x=0;\n    }\n    ArbitraryBarrettModint(int64_t val)noexcept{\n     \
    \   x=((val%N)+N)%N;\n    }\n    uint64_t val()noexcept{\n        return x;\n\
    \    }\n    friend ostream &operator<<(ostream &os,ArbitraryBarrettModint &b){\n\
    \        return os<<b.val();\n    }\n    ArbitraryBarrettModint operator+()noexcept{return\
    \ *this;}\n    ArbitraryBarrettModint operator-()noexcept{return ArbitraryBarrettModint()-(*this);}\n\
    \    friend ArbitraryBarrettModint operator+(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)+=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator-(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)-=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator*(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)*=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator/(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs){\n        return ArbitraryBarrettModint(lhs)/=rhs;\n    }\n    ArbitraryBarrettModint\
    \ operator+=(ArbitraryBarrettModint rhs)noexcept{\n        x+=rhs.x;\n       \
    \ if(x>=N)x-=N;\n        return *this;\n    }\n    ArbitraryBarrettModint operator-=(ArbitraryBarrettModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    ArbitraryBarrettModint operator*=(ArbitraryBarrettModint rhs)noexcept{\n\
    \        x=_get_mod(x*rhs.x);\n        return *this;\n    }\n    ArbitraryBarrettModint\
    \ operator/=(ArbitraryBarrettModint rhs){\n        (*this)*=rhs.inv();\n     \
    \   return *this;\n    }\n    ArbitraryBarrettModint& operator++(){\n        (*this)+=1;\n\
    \        return *this;\n    }\n    ArbitraryBarrettModint& operator--(){\n   \
    \     (*this)-=1;\n        return *this;\n    }\n    ArbitraryBarrettModint operator++(int){\n\
    \        (*this)+=1;\n        return *this;\n    }\n    ArbitraryBarrettModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(ArbitraryBarrettModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(ArbitraryBarrettModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    ArbitraryBarrettModint inv(){\n\
    \        ArbitraryBarrettModint ret=(*this).pow(inv_power);\n        assert(ret*(*this)==1);\n\
    \        return ret;\n    }\n    ArbitraryBarrettModint pow(uint64_t x)noexcept{\n\
    \        ArbitraryBarrettModint ret=1;\n        ArbitraryBarrettModint bin=(*this);\n\
    \        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n    \
    \        x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>uint64_t\
    \ ArbitraryBarrettModint<id>::N;\ntemplate<int id>uint64_t ArbitraryBarrettModint<id>::Nr;\n\
    template<int id>uint32_t ArbitraryBarrettModint<id>::inv_power;\n\ntemplate<uint32_t\
    \ N> inline void print(BarrettModint<N> a){ cout << a; }\ntemplate<int32_t id>\
    \ inline void print(ArbitraryBarrettModint<id> a){ cout << a; }\n"
  code: "#pragma once\ntemplate<uint32_t N>\nstruct BarrettModint{\n    static constexpr\
    \ uint32_t _phi(){\n        uint32_t prime_fact=N;\n        uint32_t ret=N;\n\
    \        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static constexpr uint64_t Nr=(-1ULL)/N+1;\n    static\
    \ constexpr uint32_t inv_power=_phi()-1;\n    static_assert(1<N);\n    static_assert(N<(1<<30));\n\
    \    int64_t x;\n    constexpr uint32_t mod(){\n        return N;\n    }\n   \
    \ constexpr int64_t _get_mod(int64_t x){\n        uint64_t ret=((unsigned __int128_t)x*Nr)>>64;\n\
    \        if(x-ret*N<0){\n            return x-(ret-1)*N;\n        }\n        return\
    \ x-ret*N;\n    }\n    constexpr BarrettModint()noexcept{\n        x=0;\n    }\n\
    \    constexpr BarrettModint(int64_t val)noexcept{\n        x=((val%N)+N)%N;\n\
    \    }\n    constexpr uint64_t val()noexcept{\n        return x;\n    }\n    friend\
    \ ostream &operator<<(ostream &os,BarrettModint &b){\n        return os<<b.val();\n\
    \    }\n    constexpr BarrettModint operator+()noexcept{return *this;}\n    constexpr\
    \ BarrettModint operator-()noexcept{return BarrettModint()-(*this);}\n    constexpr\
    \ friend BarrettModint operator+(BarrettModint lhs,BarrettModint rhs)noexcept{\n\
    \        return BarrettModint(lhs)+=rhs;\n    }\n    constexpr friend BarrettModint\
    \ operator-(BarrettModint lhs,BarrettModint rhs)noexcept{\n        return BarrettModint(lhs)-=rhs;\n\
    \    }\n    constexpr friend BarrettModint operator*(BarrettModint lhs,BarrettModint\
    \ rhs)noexcept{\n        return BarrettModint(lhs)*=rhs;\n    }\n    constexpr\
    \ friend BarrettModint operator/(BarrettModint lhs,BarrettModint rhs){\n     \
    \   return BarrettModint(lhs)/=rhs;\n    }\n    constexpr BarrettModint operator+=(BarrettModint\
    \ rhs)noexcept{\n        x+=rhs.x;\n        if(x>=N)x-=N;\n        return *this;\n\
    \    }\n    constexpr BarrettModint operator-=(BarrettModint rhs)noexcept{\n \
    \       x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n    }\n    constexpr\
    \ BarrettModint operator*=(BarrettModint rhs)noexcept{\n        x=_get_mod(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr BarrettModint operator/=(BarrettModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    constexpr\
    \ BarrettModint& operator++(){\n        (*this)+=1;\n        return *this;\n \
    \   }\n    constexpr BarrettModint& operator--(){\n        (*this)-=1;\n     \
    \   return *this;\n    }\n    constexpr BarrettModint operator++(int){\n     \
    \   (*this)+=1;\n        return *this;\n    }\n    constexpr BarrettModint operator--(int){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    constexpr bool operator==(BarrettModint\
    \ rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n\
    \    constexpr bool operator!=(BarrettModint rhs)noexcept{\n        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    constexpr BarrettModint inv(){\n        BarrettModint ret=(*this).pow(inv_power);\n\
    \        assert(ret*(*this)==1);\n        return ret;\n    }\n    constexpr BarrettModint\
    \ pow(uint64_t x)noexcept{\n        BarrettModint ret=1;\n        BarrettModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int32_t\
    \ id>\nstruct ArbitraryBarrettModint{\n    static uint32_t _phi(uint32_t N){\n\
    \        uint32_t prime_fact=N;\n        uint32_t ret=N;\n        for(int i=2;\
    \ i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n                ret-=ret/i;\n\
    \                while(prime_fact%i==0){\n                    prime_fact/=i;\n\
    \                }\n            }\n        }\n        if(prime_fact!=1){\n   \
    \         ret-=ret/prime_fact;\n        }\n        return ret;\n    }\n    static\
    \ uint64_t N,Nr;\n    static uint32_t inv_power;\n    int64_t x;\n    static void\
    \ set_mod(uint32_t mod){\n        N=mod;\n        Nr=(-1ULL)/N+1;\n        inv_power=_phi(N)-1;\n\
    \        assert(1<mod);\n        assert(mod<(1<<30));\n    }\n    uint32_t mod(){\n\
    \        return N;\n    }\n    int64_t _get_mod(int64_t x){\n        uint64_t\
    \ ret=((unsigned __int128_t)x*Nr)>>64;\n        if(x-ret*N<0){\n            return\
    \ x-(ret-1)*N;\n        }\n        return x-ret*N;\n    }\n    ArbitraryBarrettModint()noexcept{\n\
    \        x=0;\n    }\n    ArbitraryBarrettModint(int64_t val)noexcept{\n     \
    \   x=((val%N)+N)%N;\n    }\n    uint64_t val()noexcept{\n        return x;\n\
    \    }\n    friend ostream &operator<<(ostream &os,ArbitraryBarrettModint &b){\n\
    \        return os<<b.val();\n    }\n    ArbitraryBarrettModint operator+()noexcept{return\
    \ *this;}\n    ArbitraryBarrettModint operator-()noexcept{return ArbitraryBarrettModint()-(*this);}\n\
    \    friend ArbitraryBarrettModint operator+(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)+=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator-(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)-=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator*(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs)noexcept{\n        return ArbitraryBarrettModint(lhs)*=rhs;\n    }\n   \
    \ friend ArbitraryBarrettModint operator/(ArbitraryBarrettModint lhs,ArbitraryBarrettModint\
    \ rhs){\n        return ArbitraryBarrettModint(lhs)/=rhs;\n    }\n    ArbitraryBarrettModint\
    \ operator+=(ArbitraryBarrettModint rhs)noexcept{\n        x+=rhs.x;\n       \
    \ if(x>=N)x-=N;\n        return *this;\n    }\n    ArbitraryBarrettModint operator-=(ArbitraryBarrettModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    ArbitraryBarrettModint operator*=(ArbitraryBarrettModint rhs)noexcept{\n\
    \        x=_get_mod(x*rhs.x);\n        return *this;\n    }\n    ArbitraryBarrettModint\
    \ operator/=(ArbitraryBarrettModint rhs){\n        (*this)*=rhs.inv();\n     \
    \   return *this;\n    }\n    ArbitraryBarrettModint& operator++(){\n        (*this)+=1;\n\
    \        return *this;\n    }\n    ArbitraryBarrettModint& operator--(){\n   \
    \     (*this)-=1;\n        return *this;\n    }\n    ArbitraryBarrettModint operator++(int){\n\
    \        (*this)+=1;\n        return *this;\n    }\n    ArbitraryBarrettModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(ArbitraryBarrettModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(ArbitraryBarrettModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    ArbitraryBarrettModint inv(){\n\
    \        ArbitraryBarrettModint ret=(*this).pow(inv_power);\n        assert(ret*(*this)==1);\n\
    \        return ret;\n    }\n    ArbitraryBarrettModint pow(uint64_t x)noexcept{\n\
    \        ArbitraryBarrettModint ret=1;\n        ArbitraryBarrettModint bin=(*this);\n\
    \        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n    \
    \        x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>uint64_t\
    \ ArbitraryBarrettModint<id>::N;\ntemplate<int id>uint64_t ArbitraryBarrettModint<id>::Nr;\n\
    template<int id>uint32_t ArbitraryBarrettModint<id>::inv_power;\n\ntemplate<uint32_t\
    \ N> inline void print(BarrettModint<N> a){ cout << a; }\ntemplate<int32_t id>\
    \ inline void print(ArbitraryBarrettModint<id> a){ cout << a; }"
  dependsOn: []
  isVerificationFile: false
  path: Math/BarrettModint.hpp
  requiredBy: []
  timestamp: '2024-03-11 18:45:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/verify-yuki/yuki_336-barrett.test.cpp
  - Verify/verify-yuki/yuki_1092-barrett.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
documentation_of: Math/BarrettModint.hpp
layout: document
redirect_from:
- /library/Math/BarrettModint.hpp
- /library/Math/BarrettModint.hpp.html
title: Math/BarrettModint.hpp
---
