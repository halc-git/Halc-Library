#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include"Template.hpp"
#include"DataStructure/Hashmap.hpp"
void solve(){
    LL(Q);
    Hashmap<ll,ll> a;
    rep(i,Q){
        LL(t,k);
        if(t==0){
            LL(v);
            a[k]=v;
        }
        else{
            out(a[k]);
        }
    }
}
int main(){
    solve();
    return 0;
}