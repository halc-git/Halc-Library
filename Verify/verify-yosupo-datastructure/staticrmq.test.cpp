#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../Template/Template.hpp"
#include"../../DataStructure/DisjointSparseTable.hpp"
struct rmq{
    using T=ll;
    static T op(T x,T y){
        return min(x,y);
    }
    static inline T e=INF;
};
void solve(){
    LL(N,Q);
    VEC(ll,A,N);
    DisjointSparseTable<rmq> a(A);
    vector<ll> ans;
    rep(i,Q){
        LL(l,r);
        ans.push_back(a.prod(l,r));
        out(a.prod(l,r));
    }
    out(a.table);
    out(ans);
}
int main(){
    solve();
    return 0;
}