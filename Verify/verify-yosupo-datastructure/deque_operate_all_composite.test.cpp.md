---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FoldableDeque.hpp
    title: DataStructure/FoldableDeque.hpp
  - icon: ':heavy_check_mark:'
    path: Math/MontgomeryModint.hpp
    title: Math/MontgomeryModint.hpp
  - icon: ':heavy_check_mark:'
    path: Template.hpp
    title: Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#line 2 \"Template.hpp\"\n//https://tatyam.hatenablog.com/entry/2019/12/15/003634\n\
    #include<bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\ntemplate<class\
    \ T> using pq=priority_queue<T,vector<T>,greater<T>>;\nusing pll=pair<ll,ll>;\n\
    const ll LINF=1LL<<60;\n#define _overload3(_1,_2,_3,name,...) name\n#define _overload4(_1,_2,_3,_4,name,...)\
    \ name\n#define _rep1(i,n) for(ll i=0; i<(n); i++)\n#define _rep2(i,a,b) for(ll\
    \ i=(a); i<(b); i++)\n#define _rep3(i,a,b,c) for(ll i=(a); i<(b); i+=(c))\n#define\
    \ rep(...) _overload4(__VA_ARGS__,_rep3,_rep2,_rep1)(__VA_ARGS__)\n#define _rrep1(i,n)\
    \ for(ll i=(n); i-->0;)\n#define _rrep2(i,a,b) for(ll i=(b); i-->(a);)\n#define\
    \ rrep(...) _overload3(__VA_ARGS__,_rrep2,_rrep1)(__VA_ARGS__)\n#define each(i,...)\
    \ for(auto&& i:__VA_ARGS__)\n#define all(i) begin(i),end(i)\n#define rall(i) rbegin(i),rend(i)\n\
    template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}else return\
    \ false;}\ntemplate<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}else\
    \ return false;}\ntemplate<class T> ll sum(const T &a){return accumulate(all(a),0LL);}\n\
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
    #define se second\n#line 2 \"DataStructure/FoldableDeque.hpp\"\n//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1\n\
    template<class M>\nstruct FoldableQueue{\n    using T=typename M::T;\n    stack<T>\
    \ top,bottom,topfold,bottomfold;\n    FoldableQueue(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push(T v){\n        bottom.push(v);\n\
    \        bottomfold.push(M::op(bottomfold.top(),v));\n    }\n    void pop(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        top.pop();\n        topfold.pop();\n    }\n    T front(){\n\
    \        if(top.empty()){\n            while(!bottom.empty()){\n             \
    \   top.push(bottom.top());\n                topfold.push(M::op(bottom.top(),topfold.top()));\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n        }\n        return top.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\ntemplate<class M>\nstruct FoldableDeque{\n    using T=typename M::T;\n\
    \    stack<T> top,bottom,topfold,bottomfold;\n    FoldableDeque(){\n        topfold.push(M::e);\n\
    \        bottomfold.push(M::e);\n    }\n    void push_front(T v){\n        top.push(v);\n\
    \        topfold.push(M::op(v,topfold.top()));\n    }\n    void push_back(T v){\n\
    \        bottom.push(v);\n        bottomfold.push(M::op(bottomfold.top(),v));\n\
    \    }\n    void pop_front(){\n        if(top.empty()){\n            vector<T>\
    \ change;\n            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(int32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n        }\n        top.pop();\n        topfold.pop();\n    }\n\
    \    void pop_back(){\n        if(bottom.empty()){\n            vector<T> change;\n\
    \            while(!top.empty()){\n                change.emplace_back(top.top());\n\
    \                top.pop();\n                topfold.pop();\n            }\n \
    \           size_t sz=change.size();\n            for(int32_t i=(sz>>1); i>=0;\
    \ i--){\n                bottom.push(change[sz-i-1]);\n                bottomfold.push(M::op(bottomfold.top(),change[sz-i-1]));\n\
    \            }\n            for(int32_t i=(sz>>1)+1; i<sz; i++){\n           \
    \     top.push(change[sz-i-1]);\n                topfold.push(M::op(change[sz-i-1],topfold.top()));\n\
    \            }\n        }\n        bottom.pop();\n        bottomfold.pop();\n\
    \    }\n    T front(){\n        if(top.empty()){\n            vector<T> change;\n\
    \            while(!bottom.empty()){\n                change.emplace_back(bottom.top());\n\
    \                bottom.pop();\n                bottomfold.pop();\n          \
    \  }\n            size_t sz=change.size();\n            for(uint32_t i=(sz>>1);\
    \ i>=0; i--){\n                top.push(change[i]);\n                topfold.push(M::op(change[i],topfold.top()));\n\
    \            }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n          \
    \      bottom.push(change[i]);\n                bottomfold.push(M::op(bottomfold.top(),change[i]));\n\
    \            }\n        }\n        return top.top();\n    }\n    T back(){\n \
    \       if(bottom.empty()){\n            vector<T> change;\n            while(!top.empty()){\n\
    \                change.emplace_back(top.top());\n                top.pop();\n\
    \                topfold.pop();\n            }\n            size_t sz=change.size();\n\
    \            for(uint32_t i=(sz>>1); i>=0; i--){\n                bottom.push(change[i]);\n\
    \                bottomfold.push(M::op(bottomfold.top(),change[i]));\n       \
    \     }\n            for(uint32_t i=(sz>>1)+1; i<sz; i++){\n                top.push(change[i]);\n\
    \                topfold.push(M::op(change[i],topfold.top()));\n            }\n\
    \        }\n        return bottom.top();\n    }\n    T get_all(){\n        return\
    \ M::op(topfold.top(),bottomfold.top());\n    }\n    size_t size(){\n        return\
    \ top.size()+bottom.size();\n    }\n    bool empty(){\n        return top.empty()&&bottom.empty();\n\
    \    }\n};\n#line 2 \"Math/MontgomeryModint.hpp\"\ntemplate<uint32_t N>\nstruct\
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
    \ id>\nstruct ArbitrarMontgomeryModint{\n    static uint64_t _rev(uint32_t N){\n\
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
    \        return N;\n    }\n    ArbitrarMontgomeryModint()noexcept{\n        x=0;\n\
    \    }\n    ArbitrarMontgomeryModint(int64_t val)noexcept{\n        x=(((val%N)+N)%N<<32)%N;\n\
    \    }\n    uint64_t _reduction(uint64_t val)noexcept{\n        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;\n\
    \        if(ret>=N)return ret-N;\n        return ret;\n    }\n    uint64_t val()noexcept{\n\
    \        return _reduction(x);\n    }\n    friend ostream &operator<<(ostream\
    \ &os,ArbitrarMontgomeryModint &b){\n        return os<<b.val();\n    }\n    ArbitrarMontgomeryModint\
    \ operator+()noexcept{return *this;}\n    ArbitrarMontgomeryModint operator-()noexcept{return\
    \ ArbitrarMontgomeryModint()-(*this);}\n    friend ArbitrarMontgomeryModint operator+(ArbitrarMontgomeryModint\
    \ lhs,ArbitrarMontgomeryModint rhs)noexcept{\n        return ArbitrarMontgomeryModint(lhs)+=rhs;\n\
    \    }\n    friend ArbitrarMontgomeryModint operator-(ArbitrarMontgomeryModint\
    \ lhs,ArbitrarMontgomeryModint rhs)noexcept{\n        return ArbitrarMontgomeryModint(lhs)-=rhs;\n\
    \    }\n    friend ArbitrarMontgomeryModint operator*(ArbitrarMontgomeryModint\
    \ lhs,ArbitrarMontgomeryModint rhs)noexcept{\n        return ArbitrarMontgomeryModint(lhs)*=rhs;\n\
    \    }\n    friend ArbitrarMontgomeryModint operator/(ArbitrarMontgomeryModint\
    \ lhs,ArbitrarMontgomeryModint rhs){\n        return ArbitrarMontgomeryModint(lhs)/=rhs;\n\
    \    }\n    ArbitrarMontgomeryModint operator+=(ArbitrarMontgomeryModint rhs)noexcept{\n\
    \        x+=rhs.x;\n        if(x>=N)x-=N;\n        return *this;\n    }\n    ArbitrarMontgomeryModint\
    \ operator-=(ArbitrarMontgomeryModint rhs)noexcept{\n        x-=rhs.x;\n     \
    \   if(x<0)x+=N;\n        return *this;\n    }\n    ArbitrarMontgomeryModint operator*=(ArbitrarMontgomeryModint\
    \ rhs)noexcept{\n        x=_reduction(x*rhs.x);\n        return *this;\n    }\n\
    \    ArbitrarMontgomeryModint operator/=(ArbitrarMontgomeryModint rhs){\n    \
    \    (*this)*=rhs.inv();\n        return *this;\n    }\n    ArbitrarMontgomeryModint&\
    \ operator++(){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitrarMontgomeryModint&\
    \ operator--(){\n        (*this)-=1;\n        return *this;\n    }\n    ArbitrarMontgomeryModint\
    \ operator++(int){\n        (*this)+=1;\n        return *this;\n    }\n    ArbitrarMontgomeryModint\
    \ operator--(int){\n        (*this)-=1;\n        return *this;\n    }\n    bool\
    \ operator==(ArbitrarMontgomeryModint rhs)noexcept{\n        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);\n\
    \    }\n    bool operator!=(ArbitrarMontgomeryModint rhs)noexcept{\n        return\
    \ (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);\n    }\n    ArbitrarMontgomeryModint\
    \ inv(){\n        ArbitrarMontgomeryModint ret=(*this).pow(inv_power);\n     \
    \   assert(ret*(*this)==1);\n        return ret;\n    }\n    ArbitrarMontgomeryModint\
    \ pow(uint64_t x)noexcept{\n        ArbitrarMontgomeryModint ret=1;\n        ArbitrarMontgomeryModint\
    \ bin=(*this);\n        while(x){\n            if(x&1)ret*=bin;\n            bin*=bin;\n\
    \            x>>=1;\n        }\n        return ret;\n    }\n};\ntemplate<int id>uint64_t\
    \ ArbitrarMontgomeryModint<id>::N;\ntemplate<int id>uint64_t ArbitrarMontgomeryModint<id>::R;\n\
    template<int id>uint64_t ArbitrarMontgomeryModint<id>::Nd;\ntemplate<int id>uint64_t\
    \ ArbitrarMontgomeryModint<id>::Rr;\ntemplate<int id>uint64_t ArbitrarMontgomeryModint<id>::MASK;\n\
    template<int id>uint32_t ArbitrarMontgomeryModint<id>::inv_power;\n\ntemplate<uint32_t\
    \ N> inline void print(MontgomeryModint<N> a){ cout << a; }\ntemplate<int32_t\
    \ id> inline void print(ArbitrarMontgomeryModint<id> a){ cout << a; }\n#line 5\
    \ \"Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp\"\n\
    using mint=MontgomeryModint<MOD>;\nstruct composite{\n    using T=pair<mint,mint>;\n\
    \    static T op(T lf,T ri){\n        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);\n\
    \    }\n    static inline T e=T(1,0);\n};\nvoid solve(){\n    LL(Q);\n    FoldableDeque<composite>\
    \ deq;\n    rep(i,Q){\n        LL(t);\n        if(t==0){\n            LL(a,b);\n\
    \            deq.push_front(pll(a,b));\n        }\n        if(t==1){\n       \
    \     LL(a,b);\n            deq.push_back(pll(a,b));\n        }\n        if(t==2){\n\
    \            deq.pop_front();\n        }\n        if(t==3){\n            deq.pop_back();\n\
    \        }\n        if(t==4){\n            LL(x);\n            pair<mint,mint>\
    \ ope=deq.get_all();\n            out(ope.fi*x+ope.se);\n        }\n    }\n}\n\
    int main(){\n    solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#include\"../../Template.hpp\"\n#include\"../../DataStructure/FoldableDeque.hpp\"\
    \n#include\"../../Math/MontgomeryModint.hpp\"\nusing mint=MontgomeryModint<MOD>;\n\
    struct composite{\n    using T=pair<mint,mint>;\n    static T op(T lf,T ri){\n\
    \        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);\n    }\n    static inline T\
    \ e=T(1,0);\n};\nvoid solve(){\n    LL(Q);\n    FoldableDeque<composite> deq;\n\
    \    rep(i,Q){\n        LL(t);\n        if(t==0){\n            LL(a,b);\n    \
    \        deq.push_front(pll(a,b));\n        }\n        if(t==1){\n           \
    \ LL(a,b);\n            deq.push_back(pll(a,b));\n        }\n        if(t==2){\n\
    \            deq.pop_front();\n        }\n        if(t==3){\n            deq.pop_back();\n\
    \        }\n        if(t==4){\n            LL(x);\n            pair<mint,mint>\
    \ ope=deq.get_all();\n            out(ope.fi*x+ope.se);\n        }\n    }\n}\n\
    int main(){\n    solve();\n    return 0;\n}"
  dependsOn:
  - Template.hpp
  - DataStructure/FoldableDeque.hpp
  - Math/MontgomeryModint.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-03-10 15:07:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
- /verify/Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp.html
title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
---
