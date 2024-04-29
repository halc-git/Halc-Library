---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FoldableDeque.hpp
    title: Foldable Deque
  - icon: ':heavy_check_mark:'
    path: Modint/Modint.hpp
    title: Modint/Modint.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
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
    \n#line 2 \"Template/Template.hpp\"\n//https://tatyam.hatenablog.com/entry/2019/12/15/003634\n\
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
    \    }\n};\n#line 2 \"Modint/Modint.hpp\"\ntemplate<uint64_t Mod>\nstruct Modint{\n\
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
    \ a;}\n#line 5 \"Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp\"\
    \nusing mint=Modint<MOD>;\nstruct composite{\n    using T=pair<mint,mint>;\n \
    \   static T op(T lf,T ri){\n        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);\n\
    \    }\n    static inline T e=T(1,0);\n};\nvoid solve(){\n    LL(Q);\n    FoldableDeque<composite>\
    \ deq;\n    rep(i,Q){\n        LL(t);\n        if(t==0){\n            LL(a,b);\n\
    \            deq.push_front(pll(a,b));\n        }\n        if(t==1){\n       \
    \     LL(a,b);\n            deq.push_back(pll(a,b));\n        }\n        if(t==2){\n\
    \            deq.pop_front();\n        }\n        if(t==3){\n            deq.pop_back();\n\
    \        }\n        if(t==4){\n            LL(x);\n            pair<mint,mint>\
    \ ope=deq.get_all();\n            out(ope.fi*x+ope.se);\n        }\n    }\n}\n\
    int main(){\n    solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n#include\"../../Template/Template.hpp\"\n#include\"../../DataStructure/FoldableDeque.hpp\"\
    \n#include\"../../Modint/Modint.hpp\"\nusing mint=Modint<MOD>;\nstruct composite{\n\
    \    using T=pair<mint,mint>;\n    static T op(T lf,T ri){\n        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);\n\
    \    }\n    static inline T e=T(1,0);\n};\nvoid solve(){\n    LL(Q);\n    FoldableDeque<composite>\
    \ deq;\n    rep(i,Q){\n        LL(t);\n        if(t==0){\n            LL(a,b);\n\
    \            deq.push_front(pll(a,b));\n        }\n        if(t==1){\n       \
    \     LL(a,b);\n            deq.push_back(pll(a,b));\n        }\n        if(t==2){\n\
    \            deq.pop_front();\n        }\n        if(t==3){\n            deq.pop_back();\n\
    \        }\n        if(t==4){\n            LL(x);\n            pair<mint,mint>\
    \ ope=deq.get_all();\n            out(ope.fi*x+ope.se);\n        }\n    }\n}\n\
    int main(){\n    solve();\n    return 0;\n}"
  dependsOn:
  - Template/Template.hpp
  - DataStructure/FoldableDeque.hpp
  - Modint/Modint.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 14:38:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
- /verify/Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp.html
title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
---