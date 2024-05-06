---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.hpp
    title: Union Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"Template/Template.hpp\"\
    \n//https://tatyam.hatenablog.com/entry/2019/12/15/003634\n#include<bits/stdc++.h>\n\
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
    static ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return\
    \ ret;}\ninline int Yes(bool i=true){return out(i?\"Yes\":\"No\");}\ninline int\
    \ No(bool i=true){return out(i?\"No\":\"Yes\");}\n#define len(x) ((int)(x).size())\n\
    #define fi first\n#define se second\n#line 4 \"DataStructure/UnionFind.hpp\"\n\
    template<class M>\nstruct MonoidUnionFind{\n    using T=typename M::T;\n    std::vector<std::pair<int32_t,T>>\
    \ tree;\n    MonoidUnionFind(int32_t sz){\n        tree.resize(sz,{-1,M::e});\n\
    \    }\n    int32_t root(int32_t pos){\n        int32_t ret=pos;\n        while(tree[ret].first>=0){\n\
    \            ret=tree[ret].first;\n        }\n        while(tree[pos].first>=0){\n\
    \            int32_t now=pos;\n            pos=tree[pos].first;\n            tree[now].first=ret;\n\
    \        }\n        return ret;\n    }\n    void set(int32_t pos,T val){\n   \
    \     tree[root(pos)].second=val;\n    }\n    T get(int32_t pos){\n        return\
    \ tree[root(pos)].second;\n    }\n    bool same(int32_t a,int32_t b){\n      \
    \  return root(a)==root(b);\n    }\n    bool merge(int32_t a,int32_t b){\n   \
    \     a=root(a);\n        b=root(b);\n        if(a==b)return false;\n        if(tree[a].first>tree[b].first)std::swap(a,b);\n\
    \        tree[a]={tree[a].first+tree[b].first,M::op(tree[a].second,tree[b].second)};\n\
    \        tree[b].first=a;\n        return true;\n    }\n    size_t size(int32_t\
    \ pos){\n        return -tree[root(pos)].first;\n    }\n    std::vector<std::vector<int32_t>>\
    \ groups(){\n        std::vector<std::vector<int32_t>> members(tree.size());\n\
    \        for(int32_t i=0; i<tree.size(); i++){\n            members[root(i)].emplace_back(i);\n\
    \        }\n        std::vector<std::vector<int32_t>> ret;\n        for(int32_t\
    \ i=0; i<tree.size(); i++){\n            if(!members[i].empty())ret.emplace_back(members[i]);\n\
    \        }\n        return ret;\n    }\n};\nstruct void_monoid{\n    using T=bool;\n\
    \    constexpr static inline T op(T a,T b){return 0;}\n    constexpr static inline\
    \ T e=0;\n};\nusing UnionFind=MonoidUnionFind<void_monoid>;\n#line 4 \"Verify/verify-yosupo-datastructure/unionfind.test.cpp\"\
    \nvoid solve(){\n    LL(N,Q);\n    UnionFind uni(N);\n    rep(i,Q){\n        LL(t,u,v);\n\
    \        if(t==0){\n            uni.merge(u,v);\n        }\n        else{\n  \
    \          out(uni.same(u,v));\n        }\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include\"\
    ../../Template/Template.hpp\"\n#include\"../../DataStructure/UnionFind.hpp\"\n\
    void solve(){\n    LL(N,Q);\n    UnionFind uni(N);\n    rep(i,Q){\n        LL(t,u,v);\n\
    \        if(t==0){\n            uni.merge(u,v);\n        }\n        else{\n  \
    \          out(uni.same(u,v));\n        }\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}\n"
  dependsOn:
  - Template/Template.hpp
  - DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 21:09:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/unionfind.test.cpp
- /verify/Verify/verify-yosupo-datastructure/unionfind.test.cpp.html
title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
---
