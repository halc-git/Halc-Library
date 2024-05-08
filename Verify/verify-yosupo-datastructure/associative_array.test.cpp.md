---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Hashmap.hpp
    title: DataStructure/Hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Heuristic.hpp
    title: Template/Heuristic.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#line\
    \ 2 \"Template/Template.hpp\"\n//https://tatyam.hatenablog.com/entry/2019/12/15/003634\n\
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
    static ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return\
    \ ret;}\ninline int Yes(bool i=true){return out(i?\"Yes\":\"No\");}\ninline int\
    \ No(bool i=true){return out(i?\"No\":\"Yes\");}\n#define len(x) ((int)(x).size())\n\
    #define fi first\n#define se second\n#line 2 \"DataStructure/Hashmap.hpp\"\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#line 4 \"DataStructure/Hashmap.hpp\"\n\n#line\
    \ 4 \"Template/Heuristic.hpp\"\ninline uint32_t pcg32_fast() {\n    static uint64_t\
    \ state =\n        (std::chrono::steady_clock::now().time_since_epoch().count()\
    \ << 1) + 1;\n    uint64_t x = state;\n    uint8_t count = x >> 61;\n    state\
    \ *= 0xf13283ad;\n    x ^= x >> 22;\n    return (uint32_t)(x >> (22 + count));\n\
    }\ninline int32_t randint(int32_t l, int32_t r) {\n    return l + (((int64_t)pcg32_fast()\
    \ * (r - l + 1)) >> 32);\n}\nstatic auto startTime = std::chrono::system_clock::now();\n\
    inline int32_t getTime() {\n    return std::chrono::duration_cast<std::chrono::microseconds>(\n\
    \               std::chrono::system_clock::now() - startTime)\n        .count();\n\
    }\n#line 6 \"DataStructure/Hashmap.hpp\"\n// https://codeforces.com/blog/entry/62393?locale=en\n\
    struct custom_hash {\n    // http://xorshift.di.unimi.it/splitmix64.c\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n      \
    \  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n    uint64_t operator()(uint64_t x) const\
    \ {\n        std::mt19937_64 mt(pcg32_fast());\n        std::uniform_int_distribution<uint64_t>\
    \ rand(0, 1ULL << 63);\n        static const uint64_t FIXED_RANDOM = rand(mt);\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\ntemplate <typename Key,\
    \ typename Val>\nusing Hashmap = __gnu_pbds::gp_hash_table<Key, Val, custom_hash>;\n\
    #line 4 \"Verify/verify-yosupo-datastructure/associative_array.test.cpp\"\nvoid\
    \ solve(){\n    LL(Q);\n    Hashmap<ll,ll> a;\n    rep(i,Q){\n        LL(t,k);\n\
    \        if(t==0){\n            LL(v);\n            a[k]=v;\n        }\n     \
    \   else{\n            out(a[k]);\n        }\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\"\
    ../../Template/Template.hpp\"\n#include\"../../DataStructure/Hashmap.hpp\"\nvoid\
    \ solve(){\n    LL(Q);\n    Hashmap<ll,ll> a;\n    rep(i,Q){\n        LL(t,k);\n\
    \        if(t==0){\n            LL(v);\n            a[k]=v;\n        }\n     \
    \   else{\n            out(a[k]);\n        }\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}"
  dependsOn:
  - Template/Template.hpp
  - DataStructure/Hashmap.hpp
  - Template/Heuristic.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-05-08 20:46:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/associative_array.test.cpp
- /verify/Verify/verify-yosupo-datastructure/associative_array.test.cpp.html
title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
---
