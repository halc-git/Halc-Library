---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yuki/yuki-1092.test.cpp
    title: Verify/verify-yuki/yuki-1092.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/yuki-336.test.cpp
    title: Verify/verify-yuki/yuki-336.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Modint/MontgomeryModint.hpp\"\n#include<stdint.h>\n#include<assert.h>\n\
    #include<cmath>\ntemplate<uint32_t N>\nstruct MontgomeryModint{\n    static constexpr\
    \ uint64_t _rev(){\n        uint64_t Nd=0;\n        uint64_t t=0;\n        uint64_t\
    \ r=1ULL<<32;\n        uint64_t i=1;\n        while(r){\n            if(!(t&1)){\n\
    \                t+=N;\n                Nd+=i;\n            }\n            t>>=1;\n\
    \            r>>=1;\n            i<<=1;\n        }\n        return Nd;\n    }\n\
    \    static constexpr uint32_t _phi(){\n        uint32_t prime_fact=N;\n     \
    \   uint32_t ret=N;\n        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static constexpr uint64_t R=(1ULL<<32);\n    static\
    \ constexpr uint64_t Nd=_rev();\n    static constexpr uint64_t Rr=(Nd*N+1)>>32;\n\
    \    static constexpr uint64_t MASK=R-1;\n    static constexpr uint32_t inv_power=_phi()-1;\n\
    \    static_assert(1<N);\n    static_assert(N<(1<<30));\n    static_assert(N&1);\n\
    \    uint64_t x;\n    constexpr uint32_t mod(){\n        return N;\n    }\n  \
    \  constexpr MontgomeryModint()noexcept{\n        x=0;\n    }\n    constexpr MontgomeryModint(int64_t\
    \ val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n    }\n    constexpr uint64_t\
    \ _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    constexpr uint64_t\
    \ val()noexcept{\n        return _reduction(x);\n    }\n    constexpr MontgomeryModint\
    \ operator+()noexcept{return *this;}\n    constexpr MontgomeryModint operator-()noexcept{return\
    \ MontgomeryModint()-(*this);}\n    constexpr friend MontgomeryModint operator+(MontgomeryModint\
    \ lhs,MontgomeryModint rhs)noexcept{\n        return MontgomeryModint(lhs)+=rhs;\n\
    \    }\n    constexpr friend MontgomeryModint operator-(MontgomeryModint lhs,MontgomeryModint\
    \ rhs)noexcept{\n        return MontgomeryModint(lhs)-=rhs;\n    }\n    constexpr\
    \ friend MontgomeryModint operator*(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n\
    \        return MontgomeryModint(lhs)*=rhs;\n    }\n    constexpr friend MontgomeryModint\
    \ operator/(MontgomeryModint lhs,MontgomeryModint rhs){\n        return MontgomeryModint(lhs)/=rhs;\n\
    \    }\n    constexpr MontgomeryModint operator+=(MontgomeryModint rhs)noexcept{\n\
    \        x+=rhs.x;\n        if(x>=N)x-=N;\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint operator-=(MontgomeryModint rhs)noexcept{\n        x-=rhs.x;\n\
    \        if(x<0)x+=N;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator*=(MontgomeryModint rhs)noexcept{\n        x=_reduction(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint operator/=(MontgomeryModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint& operator++(){\n        (*this)+=1;\n        return *this;\n\
    \    }\n    constexpr MontgomeryModint& operator--(){\n        (*this)-=1;\n \
    \       return *this;\n    }\n    constexpr MontgomeryModint operator++(int){\n\
    \        (*this)+=1;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    constexpr\
    \ bool operator==(MontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    constexpr bool operator!=(MontgomeryModint rhs)noexcept{\n       \
    \ return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    constexpr MontgomeryModint\
    \ inv(){\n        MontgomeryModint ret=(*this).pow(inv_power);\n        assert(ret*(*this)==1);\n\
    \        return ret;\n    }\n    constexpr MontgomeryModint pow(uint64_t x)noexcept{\n\
    \        MontgomeryModint ret=1;\n        MontgomeryModint bin=(*this);\n    \
    \    while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n        \
    \    x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>\nstruct\
    \ DynamicMontgomeryModint{\n    static uint64_t _rev(uint32_t N){\n        uint64_t\
    \ Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n        uint64_t\
    \ i=1;\n        while(r){\n            if(!(t&1)){\n                t+=N;\n  \
    \              Nd+=i;\n            }\n            t>>=1;\n            r>>=1;\n\
    \            i<<=1;\n        }\n        return Nd;\n    }\n    static uint32_t\
    \ _phi(uint32_t N){\n        uint32_t prime_fact=N;\n        uint32_t ret=N;\n\
    \        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static uint64_t N,R,Nd,Rr,MASK;\n    static uint32_t\
    \ inv_power;\n    uint64_t x;\n    static void set_mod(uint32_t mod){\n      \
    \  N=mod;\n        R=(1ULL<<32);\n        Nd=_rev(N);\n        Rr=(Nd*N+1)>>32;\n\
    \        MASK=R-1;\n        inv_power=_phi(N)-1;\n        assert(mod<(1<<30));\n\
    \        assert(mod&1);\n    }\n    uint32_t mod(){\n        return N;\n    }\n\
    \    DynamicMontgomeryModint()noexcept{\n        x=0;\n    }\n    DynamicMontgomeryModint(int64_t\
    \ val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n    }\n    uint64_t _reduction(uint64_t\
    \ val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n  \
    \      if(ret>=N)return ret-N;\n        return ret;\n    }\n    uint64_t val()noexcept{\n\
    \        return _reduction(x);\n    }\n    DynamicMontgomeryModint operator+()noexcept{return\
    \ *this;}\n    DynamicMontgomeryModint operator-()noexcept{return DynamicMontgomeryModint()-(*this);}\n\
    \    friend DynamicMontgomeryModint operator+(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)+=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator-(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)-=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator*(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)*=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator/(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs){\n        return DynamicMontgomeryModint(lhs)/=rhs;\n    }\n    DynamicMontgomeryModint\
    \ operator+=(DynamicMontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n      \
    \  if(x>=N)x-=N;\n        return *this;\n    }\n    DynamicMontgomeryModint operator-=(DynamicMontgomeryModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    DynamicMontgomeryModint operator*=(DynamicMontgomeryModint rhs)noexcept{\n\
    \        x=_reduction(x*rhs.x);\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator/=(DynamicMontgomeryModint rhs){\n        (*this)*=rhs.inv();\n    \
    \    return *this;\n    }\n    DynamicMontgomeryModint& operator++(){\n      \
    \  (*this)+=1;\n        return *this;\n    }\n    DynamicMontgomeryModint& operator--(){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(DynamicMontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(DynamicMontgomeryModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    DynamicMontgomeryModint\
    \ inv(){\n        DynamicMontgomeryModint ret=(*this).pow(inv_power);\n      \
    \  assert(ret*(*this)==1);\n        return ret;\n    }\n    DynamicMontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        DynamicMontgomeryModint ret=1;\n        DynamicMontgomeryModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>uint64_t\
    \ DynamicMontgomeryModint<id>::N;\ntemplate<int id>uint64_t DynamicMontgomeryModint<id>::R;\n\
    template<int id>uint64_t DynamicMontgomeryModint<id>::Nd;\ntemplate<int id>uint64_t\
    \ DynamicMontgomeryModint<id>::Rr;\ntemplate<int id>uint64_t DynamicMontgomeryModint<id>::MASK;\n\
    template<int id>uint32_t DynamicMontgomeryModint<id>::inv_power;\n"
  code: "#pragma once\n#include<stdint.h>\n#include<assert.h>\n#include<cmath>\ntemplate<uint32_t\
    \ N>\nstruct MontgomeryModint{\n    static constexpr uint64_t _rev(){\n      \
    \  uint64_t Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n     \
    \   uint64_t i=1;\n        while(r){\n            if(!(t&1)){\n              \
    \  t+=N;\n                Nd+=i;\n            }\n            t>>=1;\n        \
    \    r>>=1;\n            i<<=1;\n        }\n        return Nd;\n    }\n    static\
    \ constexpr uint32_t _phi(){\n        uint32_t prime_fact=N;\n        uint32_t\
    \ ret=N;\n        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static constexpr uint64_t R=(1ULL<<32);\n    static\
    \ constexpr uint64_t Nd=_rev();\n    static constexpr uint64_t Rr=(Nd*N+1)>>32;\n\
    \    static constexpr uint64_t MASK=R-1;\n    static constexpr uint32_t inv_power=_phi()-1;\n\
    \    static_assert(1<N);\n    static_assert(N<(1<<30));\n    static_assert(N&1);\n\
    \    uint64_t x;\n    constexpr uint32_t mod(){\n        return N;\n    }\n  \
    \  constexpr MontgomeryModint()noexcept{\n        x=0;\n    }\n    constexpr MontgomeryModint(int64_t\
    \ val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n    }\n    constexpr uint64_t\
    \ _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    constexpr uint64_t\
    \ val()noexcept{\n        return _reduction(x);\n    }\n    constexpr MontgomeryModint\
    \ operator+()noexcept{return *this;}\n    constexpr MontgomeryModint operator-()noexcept{return\
    \ MontgomeryModint()-(*this);}\n    constexpr friend MontgomeryModint operator+(MontgomeryModint\
    \ lhs,MontgomeryModint rhs)noexcept{\n        return MontgomeryModint(lhs)+=rhs;\n\
    \    }\n    constexpr friend MontgomeryModint operator-(MontgomeryModint lhs,MontgomeryModint\
    \ rhs)noexcept{\n        return MontgomeryModint(lhs)-=rhs;\n    }\n    constexpr\
    \ friend MontgomeryModint operator*(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{\n\
    \        return MontgomeryModint(lhs)*=rhs;\n    }\n    constexpr friend MontgomeryModint\
    \ operator/(MontgomeryModint lhs,MontgomeryModint rhs){\n        return MontgomeryModint(lhs)/=rhs;\n\
    \    }\n    constexpr MontgomeryModint operator+=(MontgomeryModint rhs)noexcept{\n\
    \        x+=rhs.x;\n        if(x>=N)x-=N;\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint operator-=(MontgomeryModint rhs)noexcept{\n        x-=rhs.x;\n\
    \        if(x<0)x+=N;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator*=(MontgomeryModint rhs)noexcept{\n        x=_reduction(x*rhs.x);\n\
    \        return *this;\n    }\n    constexpr MontgomeryModint operator/=(MontgomeryModint\
    \ rhs){\n        (*this)*=rhs.inv();\n        return *this;\n    }\n    constexpr\
    \ MontgomeryModint& operator++(){\n        (*this)+=1;\n        return *this;\n\
    \    }\n    constexpr MontgomeryModint& operator--(){\n        (*this)-=1;\n \
    \       return *this;\n    }\n    constexpr MontgomeryModint operator++(int){\n\
    \        (*this)+=1;\n        return *this;\n    }\n    constexpr MontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    constexpr\
    \ bool operator==(MontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    constexpr bool operator!=(MontgomeryModint rhs)noexcept{\n       \
    \ return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    constexpr MontgomeryModint\
    \ inv(){\n        MontgomeryModint ret=(*this).pow(inv_power);\n        assert(ret*(*this)==1);\n\
    \        return ret;\n    }\n    constexpr MontgomeryModint pow(uint64_t x)noexcept{\n\
    \        MontgomeryModint ret=1;\n        MontgomeryModint bin=(*this);\n    \
    \    while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n        \
    \    x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>\nstruct\
    \ DynamicMontgomeryModint{\n    static uint64_t _rev(uint32_t N){\n        uint64_t\
    \ Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n        uint64_t\
    \ i=1;\n        while(r){\n            if(!(t&1)){\n                t+=N;\n  \
    \              Nd+=i;\n            }\n            t>>=1;\n            r>>=1;\n\
    \            i<<=1;\n        }\n        return Nd;\n    }\n    static uint32_t\
    \ _phi(uint32_t N){\n        uint32_t prime_fact=N;\n        uint32_t ret=N;\n\
    \        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static uint64_t N,R,Nd,Rr,MASK;\n    static uint32_t\
    \ inv_power;\n    uint64_t x;\n    static void set_mod(uint32_t mod){\n      \
    \  N=mod;\n        R=(1ULL<<32);\n        Nd=_rev(N);\n        Rr=(Nd*N+1)>>32;\n\
    \        MASK=R-1;\n        inv_power=_phi(N)-1;\n        assert(mod<(1<<30));\n\
    \        assert(mod&1);\n    }\n    uint32_t mod(){\n        return N;\n    }\n\
    \    DynamicMontgomeryModint()noexcept{\n        x=0;\n    }\n    DynamicMontgomeryModint(int64_t\
    \ val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n    }\n    uint64_t _reduction(uint64_t\
    \ val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n  \
    \      if(ret>=N)return ret-N;\n        return ret;\n    }\n    uint64_t val()noexcept{\n\
    \        return _reduction(x);\n    }\n    DynamicMontgomeryModint operator+()noexcept{return\
    \ *this;}\n    DynamicMontgomeryModint operator-()noexcept{return DynamicMontgomeryModint()-(*this);}\n\
    \    friend DynamicMontgomeryModint operator+(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)+=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator-(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)-=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator*(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs)noexcept{\n        return DynamicMontgomeryModint(lhs)*=rhs;\n    }\n  \
    \  friend DynamicMontgomeryModint operator/(DynamicMontgomeryModint lhs,DynamicMontgomeryModint\
    \ rhs){\n        return DynamicMontgomeryModint(lhs)/=rhs;\n    }\n    DynamicMontgomeryModint\
    \ operator+=(DynamicMontgomeryModint rhs)noexcept{\n        x+=rhs.x;\n      \
    \  if(x>=N)x-=N;\n        return *this;\n    }\n    DynamicMontgomeryModint operator-=(DynamicMontgomeryModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    DynamicMontgomeryModint operator*=(DynamicMontgomeryModint rhs)noexcept{\n\
    \        x=_reduction(x*rhs.x);\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator/=(DynamicMontgomeryModint rhs){\n        (*this)*=rhs.inv();\n    \
    \    return *this;\n    }\n    DynamicMontgomeryModint& operator++(){\n      \
    \  (*this)+=1;\n        return *this;\n    }\n    DynamicMontgomeryModint& operator--(){\n\
    \        (*this)-=1;\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    DynamicMontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(DynamicMontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(DynamicMontgomeryModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    DynamicMontgomeryModint\
    \ inv(){\n        DynamicMontgomeryModint ret=(*this).pow(inv_power);\n      \
    \  assert(ret*(*this)==1);\n        return ret;\n    }\n    DynamicMontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        DynamicMontgomeryModint ret=1;\n        DynamicMontgomeryModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>uint64_t\
    \ DynamicMontgomeryModint<id>::N;\ntemplate<int id>uint64_t DynamicMontgomeryModint<id>::R;\n\
    template<int id>uint64_t DynamicMontgomeryModint<id>::Nd;\ntemplate<int id>uint64_t\
    \ DynamicMontgomeryModint<id>::Rr;\ntemplate<int id>uint64_t DynamicMontgomeryModint<id>::MASK;\n\
    template<int id>uint32_t DynamicMontgomeryModint<id>::inv_power;"
  dependsOn: []
  isVerificationFile: false
  path: Modint/MontgomeryModint.hpp
  requiredBy: []
  timestamp: '2024-03-08 20:45:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yuki/yuki-1092.test.cpp
  - Verify/verify-yuki/yuki-336.test.cpp
documentation_of: Modint/MontgomeryModint.hpp
layout: document
redirect_from:
- /library/Modint/MontgomeryModint.hpp
- /library/Modint/MontgomeryModint.hpp.html
title: Modint/MontgomeryModint.hpp
---
