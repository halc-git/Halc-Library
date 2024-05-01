#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../Template/Template.hpp"
#include"../../DataStructure/FenwickTree.hpp"
void solve(){
    LL(N,Q);
    FenwickTree<ll> a(N);
    rep(i,N){
        LL(a_i);
        a.add(i,a_i);
    }
    rep(i,Q){
        LL(t,x,y);
        if(t==0){
            a.add(x,y);
        }
        else{
            out(a.sum(x,y));
        }
    }
}
int main(){
    solve();
    return 0;
}