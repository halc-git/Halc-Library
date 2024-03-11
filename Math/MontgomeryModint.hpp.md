---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/yuki_1092-montgomery.test.cpp
    title: Verify/verify-yuki/yuki_1092-montgomery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/yuki_336-montgomery.test.cpp
    title: Verify/verify-yuki/yuki_336-montgomery.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/MontgomeryModint.hpp\"\ntemplate<uint32_t N>\nstruct\
    \ MontgomeryModint{\n    static constexpr uint64_t _rev(){\n        uint64_t Nd=0;\n\
    \        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n        uint64_t i=1;\n\
    \        while(r){\n            if(!(t&1)){\n                t+=N;\n         \
    \       Nd+=i;\n            }\n            t>>=1;\n            r>>=1;\n      \
    \      i<<=1;\n        }\n        return Nd;\n    }\n    static constexpr uint32_t\
    \ _phi(){\n        uint32_t prime_fact=N;\n        uint32_t ret=N;\n        for(int\
    \ i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n             \
    \   ret-=ret/i;\n                while(prime_fact%i==0){\n                   \
    \ prime_fact/=i;\n                }\n            }\n        }\n        if(prime_fact!=1){\n\
    \            ret-=ret/prime_fact;\n        }\n        return ret;\n    }\n   \
    \ static constexpr uint64_t R=(1ULL<<32);\n    static constexpr uint64_t Nd=_rev();\n\
    \    static constexpr uint64_t Rr=(Nd*N+1)>>32;\n    static constexpr uint64_t\
    \ MASK=R-1;\n    static constexpr uint32_t inv_power=_phi()-1;\n    static_assert(1<N);\n\
    \    static_assert(N<(1<<30));\n    static_assert(N&1);\n    int64_t x;\n    constexpr\
    \ uint32_t mod(){\n        return N;\n    }\n    constexpr MontgomeryModint()noexcept{\n\
    \        x=0;\n    }\n    constexpr MontgomeryModint(int64_t val)noexcept{\n \
    \       x=(((val%N)+N)%N<<32)%N;\n    }\n    constexpr uint64_t _reduction(uint64_t\
    \ val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n  \
    \      if(ret>=N)return ret-N;\n        return ret;\n    }\n    constexpr uint64_t\
    \ val()noexcept{\n        return _reduction(x);\n    }\n    friend ostream &operator<<(ostream\
    \ &os,MontgomeryModint &b){\n        return os<<b.val();\n    }\n    constexpr\
    \ MontgomeryModint operator+()noexcept{return *this;}\n    constexpr MontgomeryModint\
    \ operator-()noexcept{return MontgomeryModint()-(*this);}\n    constexpr friend\
    \ MontgomeryModint operator+(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n\
    \        return MontgomeryModint(lhs)+=rhs;\n    }\n    constexpr friend MontgomeryModint\
    \ operator-(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n        return\
    \ MontgomeryModint(lhs)-=rhs;\n    }\n    constexpr friend MontgomeryModint operator*(MontgomeryModint\
    \ lhs,MontgomeryModint rhs)noexcept{\n        return MontgomeryModint(lhs)*=rhs;\n\
    \    }\n    constexpr friend MontgomeryModint operator/(MontgomeryModint lhs,MontgomeryModint\
    \ rhs){\n        return MontgomeryModint(lhs)/=rhs;\n    }\n    constexpr MontgomeryModint\
    \ operator+=(MontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n        if(x>=N)x-=N;\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint operator-=(MontgomeryModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    constexpr MontgomeryModint operator*=(MontgomeryModint rhs)noexcept{\n\
    \        x=_reduction(x*rhs.x);\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator/=(MontgomeryModint rhs){\n        (*this)*=rhs.inv();\n        return\
    \ *this;\n    }\n    constexpr MontgomeryModint& operator++(){\n        (*this)+=1;\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint& operator--(){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint operator--(int){\n        (*this)-=1;\n        return *this;\n\
    \    }\n    constexpr bool operator==(MontgomeryModint rhs)noexcept{\n       \
    \ return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    constexpr bool operator!=(MontgomeryModint\
    \ rhs)noexcept{\n        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n\
    \    constexpr MontgomeryModint inv(){\n        MontgomeryModint ret=(*this).pow(inv_power);\n\
    \        assert(ret*(*this)==1);\n        return ret;\n    }\n    constexpr MontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        MontgomeryModint ret=1;\n        MontgomeryModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int32_t\
    \ id>\nstruct ArbitraryMontgomeryModint{\n    static uint64_t _rev(uint32_t N){\n\
    \        uint64_t Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n\
    \        uint64_t i=1;\n        while(r){\n            if(!(t&1)){\n         \
    \       t+=N;\n                Nd+=i;\n            }\n            t>>=1;\n   \
    \         r>>=1;\n            i<<=1;\n        }\n        return Nd;\n    }\n \
    \   static uint32_t _phi(uint32_t N){\n        uint32_t prime_fact=N;\n      \
    \  uint32_t ret=N;\n        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static uint64_t N,R,Nd,Rr,MASK;\n    static uint32_t\
    \ inv_power;\n    int64_t x;\n    static void set_mod(uint32_t mod){\n       \
    \ N=mod;\n        R=(1ULL<<32);\n        Nd=_rev(N);\n        Rr=(Nd*N+1)>>32;\n\
    \        MASK=R-1;\n        inv_power=_phi(N)-1;\n        assert(1<mod);\n   \
    \     assert(mod<(1<<30));\n        assert(mod&1);\n    }\n    uint32_t mod(){\n\
    \        return N;\n    }\n    ArbitraryMontgomeryModint()noexcept{\n        x=0;\n\
    \    }\n    ArbitraryMontgomeryModint(int64_t val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n\
    \    }\n    uint64_t _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    uint64_t val()noexcept{\n\
    \        return _reduction(x);\n    }\n    friend ostream &operator<<(ostream\
    \ &os,ArbitraryMontgomeryModint &b){\n        return os<<b.val();\n    }\n   \
    \ ArbitraryMontgomeryModint operator+()noexcept{return *this;}\n    ArbitraryMontgomeryModint\
    \ operator-()noexcept{return ArbitraryMontgomeryModint()-(*this);}\n    friend\
    \ ArbitraryMontgomeryModint operator+(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)+=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator-(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)-=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator*(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)*=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator/(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs){\n        return ArbitraryMontgomeryModint(lhs)/=rhs;\n    }\n    ArbitraryMontgomeryModint\
    \ operator+=(ArbitraryMontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n    \
    \    if(x>=N)x-=N;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator-=(ArbitraryMontgomeryModint rhs)noexcept{\n        x-=rhs.x;\n    \
    \    if(x<0)x+=N;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator*=(ArbitraryMontgomeryModint rhs)noexcept{\n        x=_reduction(x*rhs.x);\n\
    \        return *this;\n    }\n    ArbitraryMontgomeryModint operator/=(ArbitraryMontgomeryModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    ArbitraryMontgomeryModint&\
    \ operator++(){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint&\
    \ operator--(){\n        (*this)-=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(ArbitraryMontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(ArbitraryMontgomeryModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    ArbitraryMontgomeryModint\
    \ inv(){\n        ArbitraryMontgomeryModint ret=(*this).pow(inv_power);\n    \
    \    assert(ret*(*this)==1);\n        return ret;\n    }\n    ArbitraryMontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        ArbitraryMontgomeryModint ret=1;\n       \
    \ ArbitraryMontgomeryModint bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n\
    \            bin*=bin;\n            x>>=1;\n        }\n        return ret;\n \
    \   }\n};\ntemplate<int id>uint64_t ArbitraryMontgomeryModint<id>::N;\ntemplate<int\
    \ id>uint64_t ArbitraryMontgomeryModint<id>::R;\ntemplate<int id>uint64_t ArbitraryMontgomeryModint<id>::Nd;\n\
    template<int id>uint64_t ArbitraryMontgomeryModint<id>::Rr;\ntemplate<int id>uint64_t\
    \ ArbitraryMontgomeryModint<id>::MASK;\ntemplate<int id>uint32_t ArbitraryMontgomeryModint<id>::inv_power;\n\
    \ntemplate<uint32_t N> inline void print(MontgomeryModint<N> a){ cout << a; }\n\
    template<int32_t id> inline void print(ArbitraryMontgomeryModint<id> a){ cout\
    \ << a; }\n"
  code: "#pragma once\ntemplate<uint32_t N>\nstruct MontgomeryModint{\n    static\
    \ constexpr uint64_t _rev(){\n        uint64_t Nd=0;\n        uint64_t t=0;\n\
    \        uint64_t r=1ULL<<32;\n        uint64_t i=1;\n        while(r){\n    \
    \        if(!(t&1)){\n                t+=N;\n                Nd+=i;\n        \
    \    }\n            t>>=1;\n            r>>=1;\n            i<<=1;\n        }\n\
    \        return Nd;\n    }\n    static constexpr uint32_t _phi(){\n        uint32_t\
    \ prime_fact=N;\n        uint32_t ret=N;\n        for(int i=2; i*i<prime_fact;\
    \ i++){\n            if(prime_fact%i==0){\n                ret-=ret/i;\n     \
    \           while(prime_fact%i==0){\n                    prime_fact/=i;\n    \
    \            }\n            }\n        }\n        if(prime_fact!=1){\n       \
    \     ret-=ret/prime_fact;\n        }\n        return ret;\n    }\n    static\
    \ constexpr uint64_t R=(1ULL<<32);\n    static constexpr uint64_t Nd=_rev();\n\
    \    static constexpr uint64_t Rr=(Nd*N+1)>>32;\n    static constexpr uint64_t\
    \ MASK=R-1;\n    static constexpr uint32_t inv_power=_phi()-1;\n    static_assert(1<N);\n\
    \    static_assert(N<(1<<30));\n    static_assert(N&1);\n    int64_t x;\n    constexpr\
    \ uint32_t mod(){\n        return N;\n    }\n    constexpr MontgomeryModint()noexcept{\n\
    \        x=0;\n    }\n    constexpr MontgomeryModint(int64_t val)noexcept{\n \
    \       x=(((val%N)+N)%N<<32)%N;\n    }\n    constexpr uint64_t _reduction(uint64_t\
    \ val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n  \
    \      if(ret>=N)return ret-N;\n        return ret;\n    }\n    constexpr uint64_t\
    \ val()noexcept{\n        return _reduction(x);\n    }\n    friend ostream &operator<<(ostream\
    \ &os,MontgomeryModint &b){\n        return os<<b.val();\n    }\n    constexpr\
    \ MontgomeryModint operator+()noexcept{return *this;}\n    constexpr MontgomeryModint\
    \ operator-()noexcept{return MontgomeryModint()-(*this);}\n    constexpr friend\
    \ MontgomeryModint operator+(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n\
    \        return MontgomeryModint(lhs)+=rhs;\n    }\n    constexpr friend MontgomeryModint\
    \ operator-(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n        return\
    \ MontgomeryModint(lhs)-=rhs;\n    }\n    constexpr friend MontgomeryModint operator*(MontgomeryModint\
    \ lhs,MontgomeryModint rhs)noexcept{\n        return MontgomeryModint(lhs)*=rhs;\n\
    \    }\n    constexpr friend MontgomeryModint operator/(MontgomeryModint lhs,MontgomeryModint\
    \ rhs){\n        return MontgomeryModint(lhs)/=rhs;\n    }\n    constexpr MontgomeryModint\
    \ operator+=(MontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n        if(x>=N)x-=N;\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint operator-=(MontgomeryModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    constexpr MontgomeryModint operator*=(MontgomeryModint rhs)noexcept{\n\
    \        x=_reduction(x*rhs.x);\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator/=(MontgomeryModint rhs){\n        (*this)*=rhs.inv();\n        return\
    \ *this;\n    }\n    constexpr MontgomeryModint& operator++(){\n        (*this)+=1;\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint& operator--(){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint operator--(int){\n        (*this)-=1;\n        return *this;\n\
    \    }\n    constexpr bool operator==(MontgomeryModint rhs)noexcept{\n       \
    \ return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    constexpr bool operator!=(MontgomeryModint\
    \ rhs)noexcept{\n        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n\
    \    constexpr MontgomeryModint inv(){\n        MontgomeryModint ret=(*this).pow(inv_power);\n\
    \        assert(ret*(*this)==1);\n        return ret;\n    }\n    constexpr MontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        MontgomeryModint ret=1;\n        MontgomeryModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int32_t\
    \ id>\nstruct ArbitraryMontgomeryModint{\n    static uint64_t _rev(uint32_t N){\n\
    \        uint64_t Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n\
    \        uint64_t i=1;\n        while(r){\n            if(!(t&1)){\n         \
    \       t+=N;\n                Nd+=i;\n            }\n            t>>=1;\n   \
    \         r>>=1;\n            i<<=1;\n        }\n        return Nd;\n    }\n \
    \   static uint32_t _phi(uint32_t N){\n        uint32_t prime_fact=N;\n      \
    \  uint32_t ret=N;\n        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static uint64_t N,R,Nd,Rr,MASK;\n    static uint32_t\
    \ inv_power;\n    int64_t x;\n    static void set_mod(uint32_t mod){\n       \
    \ N=mod;\n        R=(1ULL<<32);\n        Nd=_rev(N);\n        Rr=(Nd*N+1)>>32;\n\
    \        MASK=R-1;\n        inv_power=_phi(N)-1;\n        assert(1<mod);\n   \
    \     assert(mod<(1<<30));\n        assert(mod&1);\n    }\n    uint32_t mod(){\n\
    \        return N;\n    }\n    ArbitraryMontgomeryModint()noexcept{\n        x=0;\n\
    \    }\n    ArbitraryMontgomeryModint(int64_t val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n\
    \    }\n    uint64_t _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    uint64_t val()noexcept{\n\
    \        return _reduction(x);\n    }\n    friend ostream &operator<<(ostream\
    \ &os,ArbitraryMontgomeryModint &b){\n        return os<<b.val();\n    }\n   \
    \ ArbitraryMontgomeryModint operator+()noexcept{return *this;}\n    ArbitraryMontgomeryModint\
    \ operator-()noexcept{return ArbitraryMontgomeryModint()-(*this);}\n    friend\
    \ ArbitraryMontgomeryModint operator+(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)+=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator-(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)-=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator*(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs)noexcept{\n        return ArbitraryMontgomeryModint(lhs)*=rhs;\n    }\n\
    \    friend ArbitraryMontgomeryModint operator/(ArbitraryMontgomeryModint lhs,ArbitraryMontgomeryModint\
    \ rhs){\n        return ArbitraryMontgomeryModint(lhs)/=rhs;\n    }\n    ArbitraryMontgomeryModint\
    \ operator+=(ArbitraryMontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n    \
    \    if(x>=N)x-=N;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator-=(ArbitraryMontgomeryModint rhs)noexcept{\n        x-=rhs.x;\n    \
    \    if(x<0)x+=N;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator*=(ArbitraryMontgomeryModint rhs)noexcept{\n        x=_reduction(x*rhs.x);\n\
    \        return *this;\n    }\n    ArbitraryMontgomeryModint operator/=(ArbitraryMontgomeryModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    ArbitraryMontgomeryModint&\
    \ operator++(){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint&\
    \ operator--(){\n        (*this)-=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitraryMontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(ArbitraryMontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(ArbitraryMontgomeryModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    ArbitraryMontgomeryModint\
    \ inv(){\n        ArbitraryMontgomeryModint ret=(*this).pow(inv_power);\n    \
    \    assert(ret*(*this)==1);\n        return ret;\n    }\n    ArbitraryMontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        ArbitraryMontgomeryModint ret=1;\n       \
    \ ArbitraryMontgomeryModint bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n\
    \            bin*=bin;\n            x>>=1;\n        }\n        return ret;\n \
    \   }\n};\ntemplate<int id>uint64_t ArbitraryMontgomeryModint<id>::N;\ntemplate<int\
    \ id>uint64_t ArbitraryMontgomeryModint<id>::R;\ntemplate<int id>uint64_t ArbitraryMontgomeryModint<id>::Nd;\n\
    template<int id>uint64_t ArbitraryMontgomeryModint<id>::Rr;\ntemplate<int id>uint64_t\
    \ ArbitraryMontgomeryModint<id>::MASK;\ntemplate<int id>uint32_t ArbitraryMontgomeryModint<id>::inv_power;\n\
    \ntemplate<uint32_t N> inline void print(MontgomeryModint<N> a){ cout << a; }\n\
    template<int32_t id> inline void print(ArbitraryMontgomeryModint<id> a){ cout\
    \ << a; }"
  dependsOn: []
  isVerificationFile: false
  path: Math/MontgomeryModint.hpp
  requiredBy: []
  timestamp: '2024-03-11 18:45:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yuki/yuki_1092-montgomery.test.cpp
  - Verify/verify-yuki/yuki_336-montgomery.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
documentation_of: Math/MontgomeryModint.hpp
layout: document
redirect_from:
- /library/Math/MontgomeryModint.hpp
- /library/Math/MontgomeryModint.hpp.html
title: Math/MontgomeryModint.hpp
---
