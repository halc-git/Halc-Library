#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include"../../Template/Template.hpp"
#include"../../DataStructure/DisjointSparseTable.hpp"
struct rsq{
    using T=ll;
    static T op(T x,T y){
        return x+y;
    }
    static inline T e=0;
};
void solve(){
    LL(N,Q);
    VEC(ll,A,N);
    DisjointSparseTable<rsq> a(A);
    rep(i,Q){
        LL(l,r);
        out(a.prod(l,r));
    }
}
int main(){
    solve();
    return 0;
}