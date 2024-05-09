---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
    title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
    title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-sample/aplusb.test.cpp
    title: Verify/verify-yosupo-sample/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/1092.test.cpp
    title: Verify/verify-yuki/1092.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/2338.test.cpp
    title: Verify/verify-yuki/2338.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://tatyam.hatenablog.com/entry/2019/12/15/003634
  bundledCode: '#line 2 "Template/Template.hpp"

    //https://tatyam.hatenablog.com/entry/2019/12/15/003634

    #include<bits/stdc++.h>

    using namespace std;

    using ll=long long;

    template<class T> using pq=priority_queue<T,vector<T>,greater<T>>;

    using pll=pair<ll,ll>;

    const ll LINF=1LL<<60;

    #define _overload3(_1,_2,_3,name,...) name

    #define _overload4(_1,_2,_3,_4,name,...) name

    #define _rep1(i,n) for(ll i=0; i<(n); i++)

    #define _rep2(i,a,b) for(ll i=(a); i<(b); i++)

    #define _rep3(i,a,b,c) for(ll i=(a); i<(b); i+=(c))

    #define rep(...) _overload4(__VA_ARGS__,_rep3,_rep2,_rep1)(__VA_ARGS__)

    #define _rrep1(i,n) for(ll i=(n); i-->0;)

    #define _rrep2(i,a,b) for(ll i=(b); i-->(a);)

    #define rrep(...) _overload3(__VA_ARGS__,_rrep2,_rrep1)(__VA_ARGS__)

    #define each(i,...) for(auto&& i:__VA_ARGS__)

    #define all(i) begin(i),end(i)

    #define rall(i) rbegin(i),rend(i)

    template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}else return
    false;}

    template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}else return
    false;}

    template<class T> ll sum(const T &a){return accumulate(all(a),0LL);}

    template<class T> auto min(const T &a){return *min_element(all(a));}

    template<class T> auto max(const T &a){return *max_element(all(a));}

    inline int scan(){ return getchar(); }

    inline void scan(int &a){ scanf("%d", &a); }

    inline void scan(unsigned &a){ scanf("%u", &a); }

    inline void scan(long &a){ scanf("%ld", &a); }

    inline void scan(long long &a){ scanf("%lld", &a); }

    inline void scan(unsigned long long &a){ scanf("%llu", &a); }

    inline void scan(char &a){ cin >> a; }

    inline void scan(float &a){ scanf("%f", &a); }

    inline void scan(double &a){ scanf("%lf", &a); }

    inline void scan(long double &a){ scanf("%Lf", &a); }

    inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++)
    { int a; scan(a); vec[i] = a; } }

    inline void scan(char a[]){ scanf("%s", a); }

    inline void scan(string &a){ cin >> a; }

    template<class T> inline void scan(vector<T> &vec);

    template<class T, size_t size> inline void scan(array<T, size> &vec);

    template<class T, class L> inline void scan(pair<T, L> &p);

    template<class T, size_t size> inline void scan(T (&vec)[size]);

    template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i);
    }

    template<class T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i);
    }

    template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto
    &i : vec) scan(i); }

    template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second);
    }

    template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i :
    vec) scan(i); }

    template<class T> inline void scan(T &a){ cin >> a; }

    inline void in(){}

    template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){
    scan(head); in(tail...); }

    inline void print(){ putchar('' ''); }

    inline void print(const bool &a){ printf("%d", a); }

    inline void print(const int &a){ printf("%d", a); }

    inline void print(const unsigned &a){ printf("%u", a); }

    inline void print(const long &a){ printf("%ld", a); }

    inline void print(const long long &a){ printf("%lld", a); }

    inline void print(const unsigned long long &a){ printf("%llu", a); }

    inline void print(const char &a){ printf("%c", a); }

    inline void print(const char a[]){ printf("%s", a); }

    inline void print(const float &a){ printf("%.15f", a); }

    inline void print(const double &a){ printf("%.15f", a); }

    inline void print(const long double &a){ printf("%.15Lf", a); }

    inline void print(const string &a){ for(auto&& i : a) print(i); }

    template<class T> inline void print(const vector<T> &vec);

    template<class T, size_t size> inline void print(const array<T, size> &vec);

    template<class T, class L> inline void print(const pair<T, L> &p);

    template<class T, size_t size> inline void print(const T (&vec)[size]);

    template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return;
    print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' '');
    print(*i); } }

    template<class T> inline void print(const deque<T> &vec){ if(vec.empty()) return;
    print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' '');
    print(*i); } }

    template<class T, size_t size> inline void print(const array<T, size> &vec){ print(vec[0]);
    for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' ''); print(*i); } }

    template<class T, class L> inline void print(const pair<T, L> &p){ print(p.first);
    putchar('' ''); print(p.second); }

    template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]);
    for(auto i = vec; ++i != end(vec); ){ putchar('' ''); print(*i); } }

    template<class T> inline void print(const T &a){ cout << a; }

    inline int out(){ putchar(''\n''); return 0; }

    template<class T> inline int out(const T &t){ print(t); putchar(''\n''); return
    0; }

    template<class Head, class... Tail> inline int out(const Head &head, const Tail&...
    tail){ print(head); putchar('' ''); out(tail...); return 0; }

    using ld=long double;

    using ull=unsigned long long;

    using uint=unsigned int;

    using pii=pair<int,int>;

    using pdd=pair<ld,ld>;

    using tuplis=array<ll,3>;

    #define vec(type,name,...) vector<type> name(__VA_ARGS__);

    #define vv(type,name,h,...)vector<vector<type>> name(h,vector<type>(__VA_ARGS__));

    #define INT(...) int __VA_ARGS__; in(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)

    #define ULL(...) ull __VA_ARGS__; in(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__; in(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)

    #define VEC(type,name,size) vector<type> name(size); in(name)

    #define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)

    template<class T> ld dsum(const T &a){return accumulate(all(a),0.0L);}

    const int INF=INT_MAX>>1;

    const ll MINF=1LL<<40;

    const ld DINF=numeric_limits<ld>::infinity();

    const int MODD=1000000007;

    const int MOD=998244353;

    const ld EPS=1e-9;

    const ld PI=3.1415926535897932;

    const ll four[]={0,1,0,-1,0};

    const ll eight[]={0,1,1,0,-1,-1,1,-1,0};

    static ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return
    ret;}

    inline int Yes(bool i=true){return out(i?"Yes":"No");}

    inline int No(bool i=true){return out(i?"No":"Yes");}

    #define len(x) ((int)(x).size())

    #define fi first

    #define se second

    '
  code: '#pragma once

    //https://tatyam.hatenablog.com/entry/2019/12/15/003634

    #include<bits/stdc++.h>

    using namespace std;

    using ll=long long;

    template<class T> using pq=priority_queue<T,vector<T>,greater<T>>;

    using pll=pair<ll,ll>;

    const ll LINF=1LL<<60;

    #define _overload3(_1,_2,_3,name,...) name

    #define _overload4(_1,_2,_3,_4,name,...) name

    #define _rep1(i,n) for(ll i=0; i<(n); i++)

    #define _rep2(i,a,b) for(ll i=(a); i<(b); i++)

    #define _rep3(i,a,b,c) for(ll i=(a); i<(b); i+=(c))

    #define rep(...) _overload4(__VA_ARGS__,_rep3,_rep2,_rep1)(__VA_ARGS__)

    #define _rrep1(i,n) for(ll i=(n); i-->0;)

    #define _rrep2(i,a,b) for(ll i=(b); i-->(a);)

    #define rrep(...) _overload3(__VA_ARGS__,_rrep2,_rrep1)(__VA_ARGS__)

    #define each(i,...) for(auto&& i:__VA_ARGS__)

    #define all(i) begin(i),end(i)

    #define rall(i) rbegin(i),rend(i)

    template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}else return
    false;}

    template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}else return
    false;}

    template<class T> ll sum(const T &a){return accumulate(all(a),0LL);}

    template<class T> auto min(const T &a){return *min_element(all(a));}

    template<class T> auto max(const T &a){return *max_element(all(a));}

    inline int scan(){ return getchar(); }

    inline void scan(int &a){ scanf("%d", &a); }

    inline void scan(unsigned &a){ scanf("%u", &a); }

    inline void scan(long &a){ scanf("%ld", &a); }

    inline void scan(long long &a){ scanf("%lld", &a); }

    inline void scan(unsigned long long &a){ scanf("%llu", &a); }

    inline void scan(char &a){ cin >> a; }

    inline void scan(float &a){ scanf("%f", &a); }

    inline void scan(double &a){ scanf("%lf", &a); }

    inline void scan(long double &a){ scanf("%Lf", &a); }

    inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++)
    { int a; scan(a); vec[i] = a; } }

    inline void scan(char a[]){ scanf("%s", a); }

    inline void scan(string &a){ cin >> a; }

    template<class T> inline void scan(vector<T> &vec);

    template<class T, size_t size> inline void scan(array<T, size> &vec);

    template<class T, class L> inline void scan(pair<T, L> &p);

    template<class T, size_t size> inline void scan(T (&vec)[size]);

    template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i);
    }

    template<class T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i);
    }

    template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto
    &i : vec) scan(i); }

    template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second);
    }

    template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i :
    vec) scan(i); }

    template<class T> inline void scan(T &a){ cin >> a; }

    inline void in(){}

    template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){
    scan(head); in(tail...); }

    inline void print(){ putchar('' ''); }

    inline void print(const bool &a){ printf("%d", a); }

    inline void print(const int &a){ printf("%d", a); }

    inline void print(const unsigned &a){ printf("%u", a); }

    inline void print(const long &a){ printf("%ld", a); }

    inline void print(const long long &a){ printf("%lld", a); }

    inline void print(const unsigned long long &a){ printf("%llu", a); }

    inline void print(const char &a){ printf("%c", a); }

    inline void print(const char a[]){ printf("%s", a); }

    inline void print(const float &a){ printf("%.15f", a); }

    inline void print(const double &a){ printf("%.15f", a); }

    inline void print(const long double &a){ printf("%.15Lf", a); }

    inline void print(const string &a){ for(auto&& i : a) print(i); }

    template<class T> inline void print(const vector<T> &vec);

    template<class T, size_t size> inline void print(const array<T, size> &vec);

    template<class T, class L> inline void print(const pair<T, L> &p);

    template<class T, size_t size> inline void print(const T (&vec)[size]);

    template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return;
    print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' '');
    print(*i); } }

    template<class T> inline void print(const deque<T> &vec){ if(vec.empty()) return;
    print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' '');
    print(*i); } }

    template<class T, size_t size> inline void print(const array<T, size> &vec){ print(vec[0]);
    for(auto i = vec.begin(); ++i != vec.end(); ){ putchar('' ''); print(*i); } }

    template<class T, class L> inline void print(const pair<T, L> &p){ print(p.first);
    putchar('' ''); print(p.second); }

    template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]);
    for(auto i = vec; ++i != end(vec); ){ putchar('' ''); print(*i); } }

    template<class T> inline void print(const T &a){ cout << a; }

    inline int out(){ putchar(''\n''); return 0; }

    template<class T> inline int out(const T &t){ print(t); putchar(''\n''); return
    0; }

    template<class Head, class... Tail> inline int out(const Head &head, const Tail&...
    tail){ print(head); putchar('' ''); out(tail...); return 0; }

    using ld=long double;

    using ull=unsigned long long;

    using uint=unsigned int;

    using pii=pair<int,int>;

    using pdd=pair<ld,ld>;

    using tuplis=array<ll,3>;

    #define vec(type,name,...) vector<type> name(__VA_ARGS__);

    #define vv(type,name,h,...)vector<vector<type>> name(h,vector<type>(__VA_ARGS__));

    #define INT(...) int __VA_ARGS__; in(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)

    #define ULL(...) ull __VA_ARGS__; in(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__; in(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)

    #define VEC(type,name,size) vector<type> name(size); in(name)

    #define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)

    template<class T> ld dsum(const T &a){return accumulate(all(a),0.0L);}

    const int INF=INT_MAX>>1;

    const ll MINF=1LL<<40;

    const ld DINF=numeric_limits<ld>::infinity();

    const int MODD=1000000007;

    const int MOD=998244353;

    const ld EPS=1e-9;

    const ld PI=3.1415926535897932;

    const ll four[]={0,1,0,-1,0};

    const ll eight[]={0,1,1,0,-1,-1,1,-1,0};

    static ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return
    ret;}

    inline int Yes(bool i=true){return out(i?"Yes":"No");}

    inline int No(bool i=true){return out(i?"No":"Yes");}

    #define len(x) ((int)(x).size())

    #define fi first

    #define se second'
  dependsOn: []
  isVerificationFile: false
  path: Template/Template.hpp
  requiredBy: []
  timestamp: '2024-05-01 17:42:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yosupo-sample/aplusb.test.cpp
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - Verify/verify-yuki/1092.test.cpp
  - Verify/verify-yuki/117.test.cpp
  - Verify/verify-yuki/2338.test.cpp
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - Verify/verify-yosupo-datastructure/unionfind.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - Verify/verify-yosupo-string/zalgorithm.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
documentation_of: Template/Template.hpp
layout: document
redirect_from:
- /library/Template/Template.hpp
- /library/Template/Template.hpp.html
title: Template/Template.hpp
---
