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
    rep(i,Q){
        LL(l,r);
        out(a.prod(l,r));
    }
}
int main(){
    solve();
    return 0;
}