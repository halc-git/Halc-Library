#define PROBLEM "https://yukicoder.me/problems/no/336"
#include"../../Template.hpp"
#include"../../Math/MontgomeryModint.hpp"
using mint=MontgomeryModint<MODD>;
void solve(){
    LL(N);
    if(N<=2){
        out(0);return;
    }
    vec(mint,dp,1,2);
    rep(i,1,N){
        vec(mint,ndp,i+1,0);
        if(i&1){
            mint now=0;
            rep(j,i){
                now+=dp[j];
                ndp[j+1]=now;
            }
        }
        else{
            mint now=0;
            rrep(j,i){
                now+=dp[j];
                ndp[j]=now;
            }
        }
        dp=move(ndp);
    }
    mint ans=0;
    each(i,dp){
        ans+=i;
    }
    out(ans.val());
}
int main(){
    solve();
    return 0;
}