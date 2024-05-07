#define PROBLEM ""
#include"../../Template/Template.hpp"
#include"../../DataStructure/FenwickTree.hpp"
void solve(){
    LL(N,Q);
    VEC(ll,a,N);
    FenwickTree<ll> fw(N);
    rep(i,N){
        fw.add(i,a[i]);
    }
    rep(_,N){
        LL(t);
        if(t==0){
            LL(p,x);
            fw.add(p,x);
        }
        else{
            LL(l,r);
            out(fw.sum(l,r));
        }
    }
}
int main(){
    solve();
    return 0;
}