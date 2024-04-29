---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Heuristic.hpp
    title: Heuristic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
    title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"Heuristic.hpp\"\nusing namespace chrono;\nuint32_t pcg32_fast(){\n\
    \    static uint64_t state=(steady_clock::now().time_since_epoch().count()<<1)+1;\n\
    \    uint64_t x=state;\n    uint8_t count=x>>61;\n    state*=0xf13283ad;\n   \
    \ x^=x>>22;\n    return (uint32_t)(x>>(22+count));\n}\n\nint32_t randint(int32_t\
    \ l,int32_t r){\n    return l+(((int64_t)pcg32_fast()*(r-l+1))>>32);\n}\n\nauto\
    \ startTime=system_clock::now();\nint32_t getTime(){\n    return duration_cast<microseconds>(system_clock::now()-startTime).count();\n\
    }\n#line 3 \"String/RollingHash.hpp\"\n//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    template<typename S>\nstruct RollingHash{\n    using u64=uint64_t;\n    static\
    \ const u64 MOD=(1ULL<<61)-1;\n    static const u64 MASK31=(1ULL<<31)-1;\n   \
    \ static const u64 MASK30=(1ULL<<30)-1;\n    vector<u64> powers;\n    u64 base,fixed;\n\
    \    static inline u64 add(u64 a,u64 b){\n        if((a+=b)>=MOD)a-=MOD;\n   \
    \     return a;\n    }\n    static inline u64 calc_mod(u64 x){\n        u64 xu=x>>61,xd=x&MOD;\n\
    \        u64 ret=xu+xd;\n        if(ret>=MOD)ret-=MOD;\n        return ret;\n\
    \    }\n    static inline u64 mul(u64 a,u64 b){\n        u64 au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;\n\
    \        u64 mid=ad*bu+au*bd;\n        u64 midu=mid>>30,midd=mid&MASK30;\n   \
    \     return calc_mod(((au*bu)<<1)+midu+(midd<<31)+ad*bd);\n    }\n    static\
    \ inline u64 generate_base(){\n        mt19937_64 mt(pcg32_fast());\n        uniform_int_distribution<u64>\
    \ rand(1ULL<<60,MOD-1);\n        return rand(mt);\n    }\n    explicit RollingHash(u64\
    \ base_number=generate_base(),u64 fixed_number=1ULL<<31){\n        base=base_number;\n\
    \        fixed=fixed_number;\n        powers={1};\n    }\n    vector<u64> build(const\
    \ S &s){\n        uint32_t sz=s.size();\n        vector<u64> hashed(sz+1,0);\n\
    \        while(powers.size()<=sz){\n            powers.emplace_back(mul(powers.back(),base));\n\
    \        }\n        for(uint32_t i=0; i<sz; i++){\n            hashed[i+1]=add(mul(hashed[i],base),s[i]+fixed);\n\
    \        }\n        return hashed;\n    }\n    u64 query(const vector<u64> &s,uint32_t\
    \ lf,uint32_t ri){\n        int64_t ret=s[ri]-mul(s[lf],powers[ri-lf]);\n    \
    \    if(ret<0)ret+=MOD;\n        return ret;\n    }\n    u64 combine(u64 h1,u64\
    \ h2,uint32_t h2len){\n        return add(mul(h1,powers[h2len]),h2);\n    }\n\
    \    uint32_t lcp(const vector<u64> &a,uint32_t l1,uint32_t r1,const vector<u64>\
    \ &b,uint32_t l2,uint32_t r2){\n        uint32_t ok=0,ng=min((r1-l1),(r2-l2))+1;\n\
    \        while(ng-ok>1){\n            uint32_t mid=(ok+ng)>>1;\n            if(query(a,l1,l1+mid)==query(b,l2,l2+mid))ok=mid;\n\
    \            else ng=mid;\n        }\n        return ok;\n    }\n};\n"
  code: "#pragma once\n#include\"Heuristic.hpp\"\n//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    template<typename S>\nstruct RollingHash{\n    using u64=uint64_t;\n    static\
    \ const u64 MOD=(1ULL<<61)-1;\n    static const u64 MASK31=(1ULL<<31)-1;\n   \
    \ static const u64 MASK30=(1ULL<<30)-1;\n    vector<u64> powers;\n    u64 base,fixed;\n\
    \    static inline u64 add(u64 a,u64 b){\n        if((a+=b)>=MOD)a-=MOD;\n   \
    \     return a;\n    }\n    static inline u64 calc_mod(u64 x){\n        u64 xu=x>>61,xd=x&MOD;\n\
    \        u64 ret=xu+xd;\n        if(ret>=MOD)ret-=MOD;\n        return ret;\n\
    \    }\n    static inline u64 mul(u64 a,u64 b){\n        u64 au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;\n\
    \        u64 mid=ad*bu+au*bd;\n        u64 midu=mid>>30,midd=mid&MASK30;\n   \
    \     return calc_mod(((au*bu)<<1)+midu+(midd<<31)+ad*bd);\n    }\n    static\
    \ inline u64 generate_base(){\n        mt19937_64 mt(pcg32_fast());\n        uniform_int_distribution<u64>\
    \ rand(1ULL<<60,MOD-1);\n        return rand(mt);\n    }\n    explicit RollingHash(u64\
    \ base_number=generate_base(),u64 fixed_number=1ULL<<31){\n        base=base_number;\n\
    \        fixed=fixed_number;\n        powers={1};\n    }\n    vector<u64> build(const\
    \ S &s){\n        uint32_t sz=s.size();\n        vector<u64> hashed(sz+1,0);\n\
    \        while(powers.size()<=sz){\n            powers.emplace_back(mul(powers.back(),base));\n\
    \        }\n        for(uint32_t i=0; i<sz; i++){\n            hashed[i+1]=add(mul(hashed[i],base),s[i]+fixed);\n\
    \        }\n        return hashed;\n    }\n    u64 query(const vector<u64> &s,uint32_t\
    \ lf,uint32_t ri){\n        int64_t ret=s[ri]-mul(s[lf],powers[ri-lf]);\n    \
    \    if(ret<0)ret+=MOD;\n        return ret;\n    }\n    u64 combine(u64 h1,u64\
    \ h2,uint32_t h2len){\n        return add(mul(h1,powers[h2len]),h2);\n    }\n\
    \    uint32_t lcp(const vector<u64> &a,uint32_t l1,uint32_t r1,const vector<u64>\
    \ &b,uint32_t l2,uint32_t r2){\n        uint32_t ok=0,ng=min((r1-l1),(r2-l2))+1;\n\
    \        while(ng-ok>1){\n            uint32_t mid=(ok+ng)>>1;\n            if(query(a,l1,l1+mid)==query(b,l2,l2+mid))ok=mid;\n\
    \            else ng=mid;\n        }\n        return ok;\n    }\n};"
  dependsOn:
  - Heuristic.hpp
  isVerificationFile: false
  path: String/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-04-29 10:04:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
documentation_of: String/RollingHash.hpp
layout: document
redirect_from:
- /library/String/RollingHash.hpp
- /library/String/RollingHash.hpp.html
title: String/RollingHash.hpp
---
