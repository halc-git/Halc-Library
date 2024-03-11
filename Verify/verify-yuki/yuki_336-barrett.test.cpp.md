---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/BarrettModint.hpp
    title: Math/BarrettModint.hpp
  - icon: ':question:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/336
    links:
    - https://yukicoder.me/problems/no/336
  bundledCode: "#line 1 \"Verify/verify-yuki/yuki_336-barrett.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/336\"\n#line 2 \"Template.hpp\"\n\
    //https://tatyam.hatenablog.com/entry/2019/12/15/003634\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\ntemplate<class T> using pq=priority_queue<T,vector<T>,greater<T>>;\n\
    using pll=pair<ll,ll>;\nconst ll LINF=1LL<<60;\n#define _overload3(_1,_2,_3,name,...)\
    \ name\n#define _overload4(_1,_2,_3,_4,name,...) name\n#define _rep1(i,n) for(ll\
    \ i=0; i<(n); i++)\n#define _rep2(i,a,b) for(ll i=(a); i<(b); i++)\n#define _rep3(i,a,b,c)\
    \ for(ll i=(a); i<(b); i+=(c))\n#define rep(...) _overload4(__VA_ARGS__,_rep3,_rep2,_rep1)(__VA_ARGS__)\n\
    #define _rrep1(i,n) for(ll i=(n); i-->0;)\n#define _rrep2(i,a,b) for(ll i=(b);\
    \ i-->(a);)\n#define rrep(...) _overload3(__VA_ARGS__,_rrep2,_rrep1)(__VA_ARGS__)\n\
    #define each(i,...) for(auto&& i:__VA_ARGS__)\n#define all(i) begin(i),end(i)\n\
    #define rall(i) rbegin(i),rend(i)\ntemplate<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return\
    \ true;}else return false;}\ntemplate<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return\
    \ true;}else return false;}\ntemplate<class T> ll sum(const T &a){return accumulate(all(a),0LL);}\n\
    template<class T> auto min(const T &a){return *min_element(all(a));}\ntemplate<class\
    \ T> auto max(const T &a){return *max_element(all(a));}\ninline int scan(){ return\
    \ getchar(); }\ninline void scan(int &a){ scanf(\"%d\", &a); }\ninline void scan(unsigned\
    \ &a){ scanf(\"%u\", &a); }\ninline void scan(long &a){ scanf(\"%ld\", &a); }\n\
    inline void scan(long long &a){ scanf(\"%lld\", &a); }\ninline void scan(unsigned\
    \ long long &a){ scanf(\"%llu\", &a); }\ninline void scan(char &a){ cin >> a;\
    \ }\ninline void scan(float &a){ scanf(\"%f\", &a); }\ninline void scan(double\
    \ &a){ scanf(\"%lf\", &a); }\ninline void scan(long double &a){ scanf(\"%Lf\"\
    , &a); }\ninline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size();\
    \ i++) { int a; scan(a); vec[i] = a; } }\ninline void scan(char a[]){ scanf(\"\
    %s\", a); }\ninline void scan(string &a){ cin >> a; }\ntemplate<class T> inline\
    \ void scan(vector<T> &vec);\ntemplate<class T, size_t size> inline void scan(array<T,\
    \ size> &vec);\ntemplate<class T, class L> inline void scan(pair<T, L> &p);\n\
    template<class T, size_t size> inline void scan(T (&vec)[size]);\ntemplate<class\
    \ T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }\ntemplate<class\
    \ T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i); }\ntemplate<class\
    \ T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i);\
    \ }\ntemplate<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first);\
    \ scan(p.second); }\ntemplate<class T, size_t size> inline void scan(T (&vec)[size]){\
    \ for(auto &i : vec) scan(i); }\ntemplate<class T> inline void scan(T &a){ cin\
    \ >> a; }\ninline void in(){}\ntemplate <class Head, class... Tail> inline void\
    \ in(Head &head, Tail&... tail){ scan(head); in(tail...); }\ninline void print(){\
    \ putchar(' '); }\ninline void print(const bool &a){ printf(\"%d\", a); }\ninline\
    \ void print(const int &a){ printf(\"%d\", a); }\ninline void print(const unsigned\
    \ &a){ printf(\"%u\", a); }\ninline void print(const long &a){ printf(\"%ld\"\
    , a); }\ninline void print(const long long &a){ printf(\"%lld\", a); }\ninline\
    \ void print(const unsigned long long &a){ printf(\"%llu\", a); }\ninline void\
    \ print(const char &a){ printf(\"%c\", a); }\ninline void print(const char a[]){\
    \ printf(\"%s\", a); }\ninline void print(const float &a){ printf(\"%.15f\", a);\
    \ }\ninline void print(const double &a){ printf(\"%.15f\", a); }\ninline void\
    \ print(const long double &a){ printf(\"%.15Lf\", a); }\ninline void print(const\
    \ string &a){ for(auto&& i : a) print(i); }\ntemplate<class T> inline void print(const\
    \ vector<T> &vec);\ntemplate<class T, size_t size> inline void print(const array<T,\
    \ size> &vec);\ntemplate<class T, class L> inline void print(const pair<T, L>\
    \ &p);\ntemplate<class T, size_t size> inline void print(const T (&vec)[size]);\n\
    template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return;\
    \ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' ');\
    \ print(*i); } }\ntemplate<class T> inline void print(const deque<T> &vec){ if(vec.empty())\
    \ return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('\
    \ '); print(*i); } }\ntemplate<class T, size_t size> inline void print(const array<T,\
    \ size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('\
    \ '); print(*i); } }\ntemplate<class T, class L> inline void print(const pair<T,\
    \ L> &p){ print(p.first); putchar(' '); print(p.second); }\ntemplate<class T,\
    \ size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto\
    \ i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }\ntemplate<class T>\
    \ inline void print(const T &a){ cout << a; }\ninline int out(){ putchar('\\n');\
    \ return 0; }\ntemplate<class T> inline int out(const T &t){ print(t); putchar('\\\
    n'); return 0; }\ntemplate<class Head, class... Tail> inline int out(const Head\
    \ &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return\
    \ 0; }\nusing ld=long double;\nusing ull=unsigned long long;\nusing uint=unsigned\
    \ int;\nusing pii=pair<int,int>;\nusing pdd=pair<ld,ld>;\nusing tuplis=array<ll,3>;\n\
    #define vec(type,name,...) vector<type> name(__VA_ARGS__);\n#define vv(type,name,h,...)vector<vector<type>>\
    \ name(h,vector<type>(__VA_ARGS__));\n#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)\n#define ULL(...) ull __VA_ARGS__;\
    \ in(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)\n#define\
    \ CHR(...) char __VA_ARGS__; in(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;\
    \ in(__VA_ARGS__)\n#define VEC(type,name,size) vector<type> name(size); in(name)\n\
    #define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)\n\
    template<class T> ld dsum(const T &a){return accumulate(all(a),0.0L);}\nconst\
    \ int INF=INT_MAX>>1;\nconst ll MINF=1LL<<40;\nconst ld DINF=numeric_limits<ld>::infinity();\n\
    const int MODD=1000000007;\nconst int MOD=998244353;\nconst ld EPS=1e-9;\nconst\
    \ ld PI=3.1415926535897932;\nconst ll four[]={0,1,0,-1,0};\nconst ll eight[]={0,1,1,0,-1,-1,1,-1,0};\n\
    ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return ret;}\n\
    int Yes(bool i=true){return out(i?\"Yes\":\"No\");}\nint No(bool i=true){return\
    \ out(i?\"No\":\"Yes\");}\n#define len(x) ((int)(x).size())\n#define fi first\n\
    #define se second\n#line 2 \"Math/BarrettModint.hpp\"\ntemplate<uint32_t N>\n\
    struct BarrettModint{\n    static constexpr uint32_t _phi(){\n        uint32_t\
    \ prime_fact=N;\n        uint32_t ret=N;\n        for(int i=2; i*i<prime_fact;\
    \ i++){\n            if(prime_fact%i==0){\n                ret-=ret/i;\n     \
    \           while(prime_fact%i==0){\n                    prime_fact/=i;\n    \
    \            }\n            }\n        }\n        if(prime_fact!=1){\n       \
    \     ret-=ret/prime_fact;\n        }\n        return ret;\n    }\n    static\
    \ constexpr uint64_t Nr=(-1ULL)/N+1;\n    static constexpr uint32_t inv_power=_phi()-1;\n\
    \    static_assert(1<N);\n    static_assert(N<(1<<30));\n    int64_t x;\n    constexpr\
    \ uint32_t mod(){\n        return N;\n    }\n    constexpr int64_t _get_mod(int64_t\
    \ x){\n        uint64_t ret=((unsigned __int128_t)x*Nr)>>64;\n        if(x-ret*N<0){\n\
    \            return x-(ret-1)*N;\n        }\n        return x-ret*N;\n    }\n\
    \    constexpr BarrettModint()noexcept{\n        x=0;\n    }\n    constexpr BarrettModint(int64_t\
    \ val)noexcept{\n        x=((val%N)+N)%N;\n    }\n    constexpr uint64_t val()noexcept{\n\
    \        return x;\n    }\n    friend ostream &operator<<(ostream &os,BarrettModint\
    \ &b){\n        return os<<b.val();\n    }\n    constexpr BarrettModint operator+()noexcept{return\
    \ *this;}\n    constexpr BarrettModint operator-()noexcept{return BarrettModint()-(*this);}\n\
    \    constexpr friend BarrettModint operator+(BarrettModint lhs,BarrettModint\
    \ rhs)noexcept{\n        return BarrettModint(lhs)+=rhs;\n    }\n    constexpr\
    \ friend BarrettModint operator-(BarrettModint lhs,BarrettModint rhs)noexcept{\n\
    \        return BarrettModint(lhs)-=rhs;\n    }\n    constexpr friend BarrettModint\
    \ operator*(BarrettModint lhs,BarrettModint rhs)noexcept{\n        return BarrettModint(lhs)*=rhs;\n\
    \    }\n    constexpr friend BarrettModint operator/(BarrettModint lhs,BarrettModint\
    \ rhs){\n        return BarrettModint(lhs)/=rhs;\n    }\n    constexpr BarrettModint\
    \ operator+=(BarrettModint rhs)noexcept{\n        x+=rhs.x;\n        if(x>=N)x-=N;\n\
    \        return *this;\n    }\n    constexpr BarrettModint operator-=(BarrettModint\
    \ rhs)noexcept{\n        x-=rhs.x;\n        if(x<0)x+=N;\n        return *this;\n\
    \    }\n    constexpr BarrettModint operator*=(BarrettModint rhs)noexcept{\n \
    \       x=_get_mod(x*rhs.x);\n        return *this;\n    }\n    constexpr BarrettModint\
    \ operator/=(BarrettModint rhs){\n        (*this)*=rhs.inv();\n        return\
    \ *this;\n    }\n    constexpr BarrettModint& operator++(){\n        (*this)+=1;\n\
    \        return *this;\n    }\n    constexpr BarrettModint& operator--(){\n  \
    \      (*this)-=1;\n        return *this;\n    }\n    constexpr BarrettModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    constexpr\
    \ BarrettModint operator--(int){\n        (*this)-=1;\n        return *this;\n\
    \    }\n    constexpr bool operator==(BarrettModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    constexpr bool operator!=(BarrettModint\
    \ rhs)noexcept{\n        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n\
    \    constexpr BarrettModint inv(){\n        BarrettModint ret=(*this).pow(inv_power);\n\
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
    \ inline void print(ArbitraryBarrettModint<id> a){ cout << a; }\n#line 4 \"Verify/verify-yuki/yuki_336-barrett.test.cpp\"\
    \nusing mint=BarrettModint<MODD>;\nvoid solve(){\n    LL(N);\n    if(N<=2){\n\
    \        out(0);return;\n    }\n    vec(mint,dp,1,2);\n    rep(i,1,N){\n     \
    \   vec(mint,ndp,i+1,0);\n        if(i&1){\n            mint now=0;\n        \
    \    rep(j,i){\n                now+=dp[j];\n                ndp[j+1]=now;\n \
    \           }\n        }\n        else{\n            mint now=0;\n           \
    \ rrep(j,i){\n                now+=dp[j];\n                ndp[j]=now;\n     \
    \       }\n        }\n        dp=move(ndp);\n    }\n    mint ans=0;\n    each(i,dp){\n\
    \        ans+=i;\n    }\n    out(ans);\n}\nint main(){\n    solve();\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/336\"\n#include\"../../Template.hpp\"\
    \n#include\"../../Math/BarrettModint.hpp\"\nusing mint=BarrettModint<MODD>;\n\
    void solve(){\n    LL(N);\n    if(N<=2){\n        out(0);return;\n    }\n    vec(mint,dp,1,2);\n\
    \    rep(i,1,N){\n        vec(mint,ndp,i+1,0);\n        if(i&1){\n           \
    \ mint now=0;\n            rep(j,i){\n                now+=dp[j];\n          \
    \      ndp[j+1]=now;\n            }\n        }\n        else{\n            mint\
    \ now=0;\n            rrep(j,i){\n                now+=dp[j];\n              \
    \  ndp[j]=now;\n            }\n        }\n        dp=move(ndp);\n    }\n    mint\
    \ ans=0;\n    each(i,dp){\n        ans+=i;\n    }\n    out(ans);\n}\nint main(){\n\
    \    solve();\n    return 0;\n}"
  dependsOn:
  - Template.hpp
  - Math/BarrettModint.hpp
  isVerificationFile: true
  path: Verify/verify-yuki/yuki_336-barrett.test.cpp
  requiredBy: []
  timestamp: '2024-03-11 18:45:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/verify-yuki/yuki_336-barrett.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yuki/yuki_336-barrett.test.cpp
- /verify/Verify/verify-yuki/yuki_336-barrett.test.cpp.html
title: Verify/verify-yuki/yuki_336-barrett.test.cpp
---
