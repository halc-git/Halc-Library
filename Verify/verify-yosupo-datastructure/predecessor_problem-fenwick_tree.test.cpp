#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include"../../Template/Template.hpp"
#include"../../DataStructure/FenwickTree.hpp"
void solve(){
    LL(N,Q);
    STR(T);
    FenwickTree<ll> fw(N);
    rep(i,N){
        if(T[i]=='1')fw.add(i,1);
    }
    rep(i,Q){
        LL(c,k);
        if(c==0){
            if(fw.sum(k,k+1)==0){
                fw.add(k,1);
            }
        }
        if(c==1){
            if(fw.sum(k,k+1)==1)fw.add(k,-1);
        }
        if(c==2){
            out(fw.sum(k,k+1));
        }
        if(c==3){
            ll cnt=fw.sum(0,k)+1;
            ll ans=fw.lower_bound(cnt);
            if(fw.sum(0,ans)==cnt){
                out(ans-1);
            }
            else{
                out(-1);
            }
        }
        if(c==4){
            ll cnt=fw.sum(0,k+1);
            ll ans=fw.lower_bound(cnt);
            out(ans-1);
        }
    }
}
int main(){
    solve();
    return 0;
}
