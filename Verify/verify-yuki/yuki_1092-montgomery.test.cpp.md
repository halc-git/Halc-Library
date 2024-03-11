---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/MontgomeryModint.hpp
    title: Math/MontgomeryModint.hpp
  - icon: ':question:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1092
    links:
    - https://yukicoder.me/problems/no/1092
  bundledCode: "#line 1 \"Verify/verify-yuki/yuki_1092-montgomery.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1092\"\n#line 2 \"Template.hpp\"\n\
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
    #define se second\n#line 2 \"Math/MontgomeryModint.hpp\"\ntemplate<uint32_t N>\n\
    struct MontgomeryModint{\n    static constexpr uint64_t _rev(){\n        uint64_t\
    \ Nd=0;\n        uint64_t t=0;\n        uint64_t r=1ULL<<32;\n        uint64_t\
    \ i=1;\n        while(r){\n            if(!(t&1)){\n                t+=N;\n  \
    \              Nd+=i;\n            }\n            t>>=1;\n            r>>=1;\n\
    \            i<<=1;\n        }\n        return Nd;\n    }\n    static constexpr\
    \ uint32_t _phi(){\n        uint32_t prime_fact=N;\n        uint32_t ret=N;\n\
    \        for(int i=2; i*i<prime_fact; i++){\n            if(prime_fact%i==0){\n\
    \                ret-=ret/i;\n                while(prime_fact%i==0){\n      \
    \              prime_fact/=i;\n                }\n            }\n        }\n \
    \       if(prime_fact!=1){\n            ret-=ret/prime_fact;\n        }\n    \
    \    return ret;\n    }\n    static constexpr uint64_t R=(1ULL<<32);\n    static\
    \ constexpr uint64_t Nd=_rev();\n    static constexpr uint64_t Rr=(Nd*N+1)>>32;\n\
    \    static constexpr uint64_t MASK=R-1;\n    static constexpr uint32_t inv_power=_phi()-1;\n\
    \    static_assert(1<N);\n    static_assert(N<(1<<30));\n    static_assert(N&1);\n\
    \    int64_t x;\n    constexpr uint32_t mod(){\n        return N;\n    }\n   \
    \ constexpr MontgomeryModint()noexcept{\n        x=0;\n    }\n    constexpr MontgomeryModint(int64_t\
    \ val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n    }\n    constexpr uint64_t\
    \ _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    constexpr uint64_t\
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
    \ << a; }\n#line 4 \"Verify/verify-yuki/yuki_1092-montgomery.test.cpp\"\nusing\
    \ mint=ArbitraryMontgomeryModint<0>;\nvoid solve(){\n    LL(P,n);\n    VEC(ll,A,n);\n\
    \    STR(S);\n    if(P==2){\n        ll ans=A[0];\n        rep(i,n-1){\n     \
    \       if(S[i]=='+'){\n                ans+=A[i+1];\n            }\n        \
    \    if(S[i]=='-'){\n                ans-=A[i+1];\n            }\n           \
    \ if(S[i]=='*'){\n                ans*=A[i+1];\n            }\n            if(S[i]=='/'){\n\
    \                ans/=A[i+1];\n            }\n        }\n        out(ans&1);return;\n\
    \    }\n    mint::set_mod(P);\n    mint ans=A[0];\n    rep(i,n-1){\n        if(S[i]=='+'){\n\
    \            ans+=A[i+1];\n        }\n        if(S[i]=='-'){\n            ans-=A[i+1];\n\
    \        }\n        if(S[i]=='*'){\n            ans*=A[i+1];\n        }\n    \
    \    if(S[i]=='/'){\n            ans/=A[i+1];\n        }\n    }\n    out(ans);\n\
    }\nint main(){\n    solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1092\"\n#include\"../../Template.hpp\"\
    \n#include\"../../Math/MontgomeryModint.hpp\"\nusing mint=ArbitraryMontgomeryModint<0>;\n\
    void solve(){\n    LL(P,n);\n    VEC(ll,A,n);\n    STR(S);\n    if(P==2){\n  \
    \      ll ans=A[0];\n        rep(i,n-1){\n            if(S[i]=='+'){\n       \
    \         ans+=A[i+1];\n            }\n            if(S[i]=='-'){\n          \
    \      ans-=A[i+1];\n            }\n            if(S[i]=='*'){\n             \
    \   ans*=A[i+1];\n            }\n            if(S[i]=='/'){\n                ans/=A[i+1];\n\
    \            }\n        }\n        out(ans&1);return;\n    }\n    mint::set_mod(P);\n\
    \    mint ans=A[0];\n    rep(i,n-1){\n        if(S[i]=='+'){\n            ans+=A[i+1];\n\
    \        }\n        if(S[i]=='-'){\n            ans-=A[i+1];\n        }\n    \
    \    if(S[i]=='*'){\n            ans*=A[i+1];\n        }\n        if(S[i]=='/'){\n\
    \            ans/=A[i+1];\n        }\n    }\n    out(ans);\n}\nint main(){\n \
    \   solve();\n    return 0;\n}"
  dependsOn:
  - Template.hpp
  - Math/MontgomeryModint.hpp
  isVerificationFile: true
  path: Verify/verify-yuki/yuki_1092-montgomery.test.cpp
  requiredBy: []
  timestamp: '2024-03-11 18:45:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yuki/yuki_1092-montgomery.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yuki/yuki_1092-montgomery.test.cpp
- /verify/Verify/verify-yuki/yuki_1092-montgomery.test.cpp.html
title: Verify/verify-yuki/yuki_1092-montgomery.test.cpp
---