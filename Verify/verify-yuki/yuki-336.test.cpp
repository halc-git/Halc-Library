#define PROBREM "https://yukicoder.me/problems/no/336"
#include"../../Template.hpp"
#include"../../Modint/MontgomeryModint.hpp"
using mint=MontgomeryModint<MODD>;
int main(){
    LL(N);
    if(N<=2){
        return out(0);
    }
    vec(mint,dp,1,1);
    rep(i,1,N){
        vec(mint,ndp,i+1,0);
        if(i&1){
            mint now=0;
            rep(j,i){
                now+=dp[j];
                ndp[j+1]+=now;
            }
        }
        else{
            mint now=0;
            rrep(j,i){
                now+=dp[j];
                ndp[j]+=now;
            }
        }
        dp=move(ndp);
    }
    mint ans=0;
    each(i,dp)ans+=i;
    out((ans*2).val());
}