---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Heuristic.hpp
    title: Heuristic.hpp
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.hpp
    title: String/RollingHash.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
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
    #define se second\n#line 2 \"Heuristic.hpp\"\nusing namespace chrono;\nuint32_t\
    \ pcg32_fast(){\n    static uint64_t state=(steady_clock::now().time_since_epoch().count()<<1)+1;\n\
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
    \            else ng=mid;\n        }\n        return ok;\n    }\n};\n#line 4 \"\
    Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp\"\nvoid solve(){\n    STR(T);\n\
    \    STR(P);\n    RollingHash<string> roll;\n    auto tb=roll.build(T);\n    auto\
    \ pb=roll.build(P);\n    ll hash=roll.query(pb,0,len(P));\n    rep(i,len(T)-len(P)+1){\n\
    \        if(roll.query(tb,i,i+len(P))==hash)out(i);\n    }\n}\nint main(){\n \
    \   solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include\"../../Template.hpp\"\n#include\"../../String/RollingHash.hpp\"\nvoid\
    \ solve(){\n    STR(T);\n    STR(P);\n    RollingHash<string> roll;\n    auto\
    \ tb=roll.build(T);\n    auto pb=roll.build(P);\n    ll hash=roll.query(pb,0,len(P));\n\
    \    rep(i,len(T)-len(P)+1){\n        if(roll.query(tb,i,i+len(P))==hash)out(i);\n\
    \    }\n}\nint main(){\n    solve();\n    return 0;\n}"
  dependsOn:
  - Template.hpp
  - String/RollingHash.hpp
  - Heuristic.hpp
  isVerificationFile: true
  path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 10:52:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
- /verify/Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp.html
title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
---
