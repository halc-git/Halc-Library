---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FenwickTree.hpp
    title: DataStructure/FenwickTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#line\
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
    #define fi first\n#define se second\n#line 3 \"DataStructure/FenwickTree.hpp\"\
    \ntemplate <class T>\nstruct FenwickTree {\n    std::vector<T> tree;\n    int32_t\
    \ start = 1;\n    size_t siz;\n    FenwickTree(int32_t sz) {\n        siz = sz;\n\
    \        tree.resize(sz + 1, 0);\n        while ((start << 1) <= siz) start <<=\
    \ 1;\n    }\n    FenwickTree(std::vector<T> def) {\n        siz = def.size();\n\
    \        tree.resize(siz + 1, 0);\n        while ((start << 1) <= siz) start <<=\
    \ 1;\n        for (int32_t i = 0; i < siz; i++) {\n            tree[i + 1] +=\
    \ def[i];\n            if (i + (i & -i) <= siz) {\n                tree[i + (i\
    \ & -i)] += tree[i];\n            }\n        }\n    }\n    void add(int32_t pos,\
    \ T val) {\n        pos++;\n        while (pos <= siz) {\n            tree[pos]\
    \ += val;\n            pos += pos & -pos;\n        }\n    }\n    T _sum(int32_t\
    \ pos) {\n        T ret = 0;\n        while (pos > 0) {\n            ret += tree[pos];\n\
    \            pos -= pos & -pos;\n        }\n        return ret;\n    }\n    T\
    \ sum(int32_t lf, int32_t ri) { return _sum(ri) - _sum(lf); }\n    int32_t lower_bound(T\
    \ w) {\n        if (w <= 0) return 0;\n        int32_t now = 0;\n        T val\
    \ = 0;\n        for (int32_t i = start; i > 0; i >>= 1) {\n            if (now\
    \ + i <= siz && val + tree[now + i] < w) {\n                now += i;\n      \
    \          val += tree[now];\n            }\n        }\n        return now + 1;\n\
    \    }\n    size_t size() { return siz; }\n};\n#line 4 \"Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp\"\
    \nvoid solve(){\n    LL(N,Q);\n    STR(T);\n    vec(ll,t,N,0);\n    rep(i,N){\n\
    \        if(T[i]=='1')t[i]=1;\n    }\n    FenwickTree<ll> fw(t);\n    rep(i,Q){\n\
    \        LL(c,k);\n        if(c==0){\n            if(!fw.sum(k,k+1)){\n      \
    \          fw.add(k,1);\n            }\n        }\n        if(c==1){\n       \
    \     if(fw.sum(k,k+1)){\n                fw.add(k,-1);\n            }\n     \
    \   }\n        if(c==2){\n            out(fw.sum(k,k+1));\n        }\n       \
    \ if(c==3){\n            ll cnt=fw.sum(0,k)+1;\n            ll ans=fw.lower_bound(cnt);\n\
    \            if(fw.sum(0,ans)==cnt){\n                out(ans-1);\n          \
    \  }\n            else{\n                out(-1);\n            }\n        }\n\
    \        if(c==4){\n            ll cnt=fw.sum(0,k+1);\n            ll ans=fw.lower_bound(cnt);\n\
    \            out(ans-1);\n        }\n    }\n}\nint main(){\n    solve();\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include\"../../Template/Template.hpp\"\n#include\"../../DataStructure/FenwickTree.hpp\"\
    \nvoid solve(){\n    LL(N,Q);\n    STR(T);\n    vec(ll,t,N,0);\n    rep(i,N){\n\
    \        if(T[i]=='1')t[i]=1;\n    }\n    FenwickTree<ll> fw(t);\n    rep(i,Q){\n\
    \        LL(c,k);\n        if(c==0){\n            if(!fw.sum(k,k+1)){\n      \
    \          fw.add(k,1);\n            }\n        }\n        if(c==1){\n       \
    \     if(fw.sum(k,k+1)){\n                fw.add(k,-1);\n            }\n     \
    \   }\n        if(c==2){\n            out(fw.sum(k,k+1));\n        }\n       \
    \ if(c==3){\n            ll cnt=fw.sum(0,k)+1;\n            ll ans=fw.lower_bound(cnt);\n\
    \            if(fw.sum(0,ans)==cnt){\n                out(ans-1);\n          \
    \  }\n            else{\n                out(-1);\n            }\n        }\n\
    \        if(c==4){\n            ll cnt=fw.sum(0,k+1);\n            ll ans=fw.lower_bound(cnt);\n\
    \            out(ans-1);\n        }\n    }\n}\nint main(){\n    solve();\n   \
    \ return 0;\n}\n"
  dependsOn:
  - Template/Template.hpp
  - DataStructure/FenwickTree.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2024-05-09 08:35:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
- /verify/Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp.html
title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
---
