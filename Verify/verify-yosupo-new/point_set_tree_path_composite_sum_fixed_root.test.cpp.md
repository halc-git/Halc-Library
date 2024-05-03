---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Modint/Modint.hpp
    title: Modint/Modint.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  - icon: ':question:'
    path: Tree/StaticTopTree.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
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
    static ll intpow(ll a,ll b){ll ret=1;while(b){if(b&1)ret*=a;a*=a;b>>=1;}return\
    \ ret;}\ninline int Yes(bool i=true){return out(i?\"Yes\":\"No\");}\ninline int\
    \ No(bool i=true){return out(i?\"No\":\"Yes\");}\n#define len(x) ((int)(x).size())\n\
    #define fi first\n#define se second\n#line 4 \"Modint/Modint.hpp\"\ntemplate<uint64_t\
    \ Mod>\nstruct Modint{\n    uint64_t x;\n    constexpr Modint()noexcept{\n   \
    \     x=0;\n    }\n    constexpr Modint(int64_t val)noexcept{\n        x=(val<0?val%(int64_t)(Mod)+Mod:val%Mod);\n\
    \    }\n    inline uint64_t _get_mod(uint64_t val)noexcept{\n        const static\
    \ uint64_t m_inv=(-1ULL)/Mod+1;\n        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;\n\
    \        uint64_t pro=ret*Mod;\n        return (val-pro+(val<pro?Mod:0));\n  \
    \  }\n    friend std::ostream &operator<<(std::ostream &os,Modint &b){\n     \
    \   return os<<b.x;\n    }\n    friend std::istream &operator>>(std::istream &is,Modint\
    \ &b){\n        return is>>b.x;\n    }\n    constexpr uint64_t val()noexcept{\n\
    \        return x;\n    }\n    constexpr Modint operator+()noexcept{\n       \
    \ return (*this);\n    }\n    constexpr Modint operator-()noexcept{\n        return\
    \ Modint()-(*this);\n    }\n    constexpr Modint operator+(const Modint rhs)noexcept{\n\
    \        return Modint(*this)+=rhs;\n    }\n    constexpr Modint operator-(const\
    \ Modint rhs)noexcept{\n        return Modint(*this)-=rhs;\n    }\n    constexpr\
    \ Modint operator*(const Modint rhs)noexcept{\n        return Modint(*this)*=rhs;\n\
    \    }\n    constexpr Modint operator/(const Modint rhs)noexcept{\n        return\
    \ Modint(*this)/=rhs;\n    }\n    constexpr Modint &operator+=(const Modint rhs)noexcept{\n\
    \        x+=rhs.x;\n        if(x>=Mod)x-=Mod;\n        return *this;\n    }\n\
    \    constexpr Modint &operator-=(const Modint rhs)noexcept{\n        if(x<rhs.x)x+=Mod;\n\
    \        x-=rhs.x;\n        return *this;\n    }\n    constexpr Modint &operator*=(const\
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
    \    }\n    friend std::ostream &operator<<(std::ostream &os,ArbitraryModint &b){\n\
    \        return os<<b.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is,ArbitraryModint &b){\n        return is>>b.x;\n    }\n    constexpr uint64_t\
    \ val()noexcept{\n        return x;\n    }\n    constexpr ArbitraryModint operator+()noexcept{\n\
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
    \ mod();\n    }\n};\ntemplate<uint64_t N> inline void print(Modint<N> a){std::cout\
    \ << a;}\ntemplate<int64_t id> inline void print(ArbitraryModint<id> a){std::cout\
    \ << a;}\n#line 4 \"Tree/StaticTopTree.hpp\"\ntemplate<class M>\nstruct StaticTopTree{\n\
    \    using point=typename M::point;\n    using path=typename M::path;\n    struct\
    \ Node{\n        bool is_path;\n        point point_val;\n        path path_val;\n\
    \        int32_t pos;\n        int32_t left;\n        int32_t right;\n       \
    \ int32_t parent;\n        Node(bool pat,int32_t po=-1,int32_t lf=-1,int32_t ri=-1){\n\
    \            is_path=pat;\n            pos=po;\n            left=lf;\n       \
    \     right=ri;\n            parent=-1;\n        }\n    };\n    size_t sz;\n \
    \   std::vector<std::vector<int32_t>> tree;\n    std::vector<int32_t> node_pos;\n\
    \    std::vector<Node> nodes;\n    int32_t rt;\n    StaticTopTree(size_t size){\n\
    \        sz=size;\n        tree.resize(sz);\n        node_pos.resize(sz);\n  \
    \  }\n    void add_edge(int32_t s,int32_t v){\n        tree[s].emplace_back(v);\n\
    \        tree[v].emplace_back(s);\n    }\n    int32_t _path_cluster(int32_t pos,std::vector<int32_t>\
    \ &tree_sz){\n        if(tree[pos].empty()){\n            node_pos[pos]=nodes.size();\n\
    \            nodes.emplace_back(Node(1,pos));\n            _calc_val(nodes.size()-1);\n\
    \            return nodes.size()-1;\n        }\n        std::vector<int32_t> address;\n\
    \        std::vector<int32_t> sizes;\n        while(!tree[pos].empty()){\n   \
    \         int32_t max_size=-1;\n            int32_t next_pos=-1;\n           \
    \ for(int i=0; i<tree[pos].size(); i++){\n                if(tree_sz[tree[pos][i]]>max_size){\n\
    \                    max_size=tree_sz[tree[pos][i]];\n                    next_pos=i;\n\
    \                }\n            }\n            std::swap(tree[pos][next_pos],tree[pos].back());\n\
    \            next_pos=tree[pos].back();\n            tree[pos].pop_back();\n \
    \           tree_sz[pos]-=tree_sz[next_pos];\n            sizes.emplace_back(tree_sz[pos]);\n\
    \            address.emplace_back(_point_cluster(pos,tree_sz));\n            pos=next_pos;\n\
    \        }\n        address.emplace_back(_point_cluster(pos,tree_sz));\n     \
    \   sizes.emplace_back(tree_sz[pos]);\n        return _merge(address,sizes,0,address.size(),1);\n\
    \    }\n    int32_t _point_cluster(int32_t pos,std::vector<int32_t> &tree_sz){\n\
    \        if(tree[pos].empty()){\n            node_pos[pos]=nodes.size();\n   \
    \         nodes.emplace_back(Node(1,pos));\n            _calc_val(nodes.size()-1);\n\
    \            return nodes.size()-1;\n        }\n        std::vector<int32_t> address;\n\
    \        std::vector<int32_t> sizes;\n        for(int32_t i:tree[pos]){\n    \
    \        sizes.emplace_back(tree_sz[i]);\n            int32_t vert=_path_cluster(i,tree_sz);\n\
    \            nodes.emplace_back(Node(0,-1,vert));\n            nodes[vert].parent=nodes.size()-1;\n\
    \            address.emplace_back(nodes.size()-1);\n            _calc_val(nodes.size()-1);\n\
    \        }\n        int32_t vert=_merge(address,sizes,0,address.size(),0);\n \
    \       node_pos[pos]=nodes.size();\n        nodes.emplace_back(Node(1,pos,vert));\n\
    \        nodes[vert].parent=nodes.size()-1;\n        _calc_val(nodes.size()-1);\n\
    \        return nodes.size()-1;\n    }\n    int32_t _merge(std::vector<int32_t>\
    \ &address,std::vector<int32_t> &sizes,int32_t lf,int32_t ri,bool pat){\n    \
    \    if(lf+1==ri)return address[lf];\n        int32_t add=0;\n        for(int32_t\
    \ i=lf; i<ri; i++){\n            add+=sizes[i];\n        }\n        int32_t now=0;\n\
    \        int32_t bef=add+1;\n        for(int32_t i=lf; i<ri; i++){\n         \
    \   now+=sizes[i];\n            if(now>add-now){\n                if(now+now-add>bef)i--;\n\
    \                int32_t left=_merge(address,sizes,lf,i+1,pat);\n            \
    \    int32_t right=_merge(address,sizes,i+1,ri,pat);\n                nodes.emplace_back(Node(pat,-1,left,right));\n\
    \                nodes[left].parent=nodes.size()-1;\n                nodes[right].parent=nodes.size()-1;\n\
    \                _calc_val(nodes.size()-1);\n                return nodes.size()-1;\n\
    \            }\n            bef=add-now-now;\n        }\n        assert(false);\n\
    \    }\n    void _calc_val(int32_t pos){\n        if(nodes[pos].is_path){\n  \
    \          if((nodes[pos].left==-1) && (nodes[pos].right==-1)){\n            \
    \    nodes[pos].path_val=M::vertex(nodes[pos].pos);\n            }\n         \
    \   else if((nodes[pos].left!=-1) && (nodes[pos].right!=-1)){\n              \
    \  nodes[pos].path_val=M::compress(nodes[nodes[pos].left].path_val,nodes[nodes[pos].right].path_val);\n\
    \            }\n            else{\n                nodes[pos].path_val=M::add_vertex(nodes[nodes[pos].left].point_val,nodes[pos].pos);\n\
    \            }\n        }\n        else{\n            if((nodes[pos].left!=-1)\
    \ && (nodes[pos].right!=-1)){\n                nodes[pos].point_val=M::rake(nodes[nodes[pos].left].point_val,nodes[nodes[pos].right].point_val);\n\
    \            }\n            else{\n                nodes[pos].point_val=M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    void build(int32_t root){\n        std::vector<int32_t>\
    \ vert(sz);\n        std::vector<int32_t> tree_sz(sz,-1);\n        vert[0]=root;\n\
    \        tree_sz[root]=0;\n        int32_t cnt=1;\n        for(int32_t i=0; i<sz;\
    \ i++){\n            for(int32_t j:tree[vert[i]]){\n                if(tree_sz[j]){\n\
    \                    tree_sz[j]=0;\n                    vert[cnt]=j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for(int32_t\
    \ i=sz-1; i>=0; i--){\n            int32_t parent=0;\n            for(int32_t\
    \ j:tree[vert[i]]){\n                if(tree_sz[j]==0){\n                    parent=-parent-1;\n\
    \                }\n                if(parent>=0)parent++;\n                tree_sz[vert[i]]+=tree_sz[j];\n\
    \            }\n            if(parent<0){\n                std::swap(tree[vert[i]][-parent-1],tree[vert[i]].back());\n\
    \                tree[vert[i]].pop_back();\n            }\n            tree_sz[vert[i]]++;\n\
    \        }\n        rt=_path_cluster(root,tree_sz);\n    }\n    path root_value(){\n\
    \        return nodes[rt].path_val;\n    }\n    void calc(int32_t pos){\n    \
    \    int32_t change=node_pos[pos];\n        while(nodes[change].parent!=-1){\n\
    \            _calc_val(change);\n            change=nodes[change].parent;\n  \
    \      }\n        _calc_val(change);\n    }\n    size_t size(){\n        return\
    \ sz;\n    }\n};\n#line 5 \"Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \nusing mint=Modint<MOD>;\nusing edge_type=array<ll,4>;\nusing func_type=pair<mint,mint>;\n\
    void solve(){\n    LL(N,Q);\n    static VEC(mint,a,N);\n    VEC(edge_type,edge,N-1);\n\
    \    vv(ll,gr,N);\n    rep(i,N-1){\n        gr[edge[i][0]].emplace_back(edge[i][1]);\n\
    \        gr[edge[i][1]].emplace_back(edge[i][0]);\n    }\n    vec(ll,dist,N,-1);\n\
    \    dist[0]=0;\n    stack<ll> vert;\n    vert.push(0);\n    while(!vert.empty()){\n\
    \        ll pos=vert.top();\n        vert.pop();\n        each(i,gr[pos]){\n \
    \           if(dist[i]==-1){\n                dist[i]=dist[pos]+1;\n         \
    \       vert.push(i);\n            }\n        }\n    }\n    static vec(func_type,func,N,{1,0});\n\
    \    struct ops{\n        using point=array<mint,2>;\n        using path=array<mint,4>;\n\
    \n        static path vertex(int v){\n            return {1,a[v]*func[v].fi+func[v].se,func[v].fi,func[v].se};\n\
    \        }\n\n        static path compress(path p,path c){\n            return\
    \ {p[0]+p[1],p[1]+c[1]*p[2]+c[0]*p[3],p[2]*c[2],p[2]*c[3]+p[3]};\n        }\n\n\
    \        static path add_vertex(point t,int v){\n            return {t[0]+1,(a[v]+t[1])*func[v].fi+(t[0]+1)*func[v].se,func[v].fi,func[v].se};\n\
    \        }\n\n        static point rake(point x,point y){\n            return\
    \ {x[0]+y[0],x[1]+y[1]};\n        }\n\n        static point add_edge(path t){\n\
    \            return {t[0],t[1]};\n        }\n    };\n    StaticTopTree<ops> tree(N);\n\
    \    rep(i,N-1){\n        if(dist[edge[i][0]]<dist[edge[i][1]]){\n           \
    \ swap(edge[i][0],edge[i][1]);\n        }\n        func[edge[i][0]]={edge[i][2],edge[i][3]};\n\
    \        tree.add_edge(edge[i][0],edge[i][1]);\n    }\n    tree.build(0);\n  \
    \  rep(_,Q){\n        LL(t);\n        if(t==0){\n            LL(w,x);\n      \
    \      a[w]=x;\n            tree.calc(w);\n        }\n        else{\n        \
    \    LL(e,y,z);\n            func[edge[e][0]]={y,z};\n            tree.calc(edge[e][0]);\n\
    \        }\n        out(tree.root_value()[1]);\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#include\"../../Template/Template.hpp\"\n#include\"../../Modint/Modint.hpp\"\
    \n#include\"../../Tree/StaticTopTree.hpp\"\nusing mint=Modint<MOD>;\nusing edge_type=array<ll,4>;\n\
    using func_type=pair<mint,mint>;\nvoid solve(){\n    LL(N,Q);\n    static VEC(mint,a,N);\n\
    \    VEC(edge_type,edge,N-1);\n    vv(ll,gr,N);\n    rep(i,N-1){\n        gr[edge[i][0]].emplace_back(edge[i][1]);\n\
    \        gr[edge[i][1]].emplace_back(edge[i][0]);\n    }\n    vec(ll,dist,N,-1);\n\
    \    dist[0]=0;\n    stack<ll> vert;\n    vert.push(0);\n    while(!vert.empty()){\n\
    \        ll pos=vert.top();\n        vert.pop();\n        each(i,gr[pos]){\n \
    \           if(dist[i]==-1){\n                dist[i]=dist[pos]+1;\n         \
    \       vert.push(i);\n            }\n        }\n    }\n    static vec(func_type,func,N,{1,0});\n\
    \    struct ops{\n        using point=array<mint,2>;\n        using path=array<mint,4>;\n\
    \n        static path vertex(int v){\n            return {1,a[v]*func[v].fi+func[v].se,func[v].fi,func[v].se};\n\
    \        }\n\n        static path compress(path p,path c){\n            return\
    \ {p[0]+p[1],p[1]+c[1]*p[2]+c[0]*p[3],p[2]*c[2],p[2]*c[3]+p[3]};\n        }\n\n\
    \        static path add_vertex(point t,int v){\n            return {t[0]+1,(a[v]+t[1])*func[v].fi+(t[0]+1)*func[v].se,func[v].fi,func[v].se};\n\
    \        }\n\n        static point rake(point x,point y){\n            return\
    \ {x[0]+y[0],x[1]+y[1]};\n        }\n\n        static point add_edge(path t){\n\
    \            return {t[0],t[1]};\n        }\n    };\n    StaticTopTree<ops> tree(N);\n\
    \    rep(i,N-1){\n        if(dist[edge[i][0]]<dist[edge[i][1]]){\n           \
    \ swap(edge[i][0],edge[i][1]);\n        }\n        func[edge[i][0]]={edge[i][2],edge[i][3]};\n\
    \        tree.add_edge(edge[i][0],edge[i][1]);\n    }\n    tree.build(0);\n  \
    \  rep(_,Q){\n        LL(t);\n        if(t==0){\n            LL(w,x);\n      \
    \      a[w]=x;\n            tree.calc(w);\n        }\n        else{\n        \
    \    LL(e,y,z);\n            func[edge[e][0]]={y,z};\n            tree.calc(edge[e][0]);\n\
    \        }\n        out(tree.root_value()[1]);\n    }\n}\nint main(){\n    solve();\n\
    \    return 0;\n}"
  dependsOn:
  - Template/Template.hpp
  - Modint/Modint.hpp
  - Tree/StaticTopTree.hpp
  isVerificationFile: true
  path: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 16:56:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
