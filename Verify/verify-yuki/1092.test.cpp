#define PROBLEM "https://yukicoder.me/problems/no/1092"
#include"../../Template.hpp"
#include"../../Modint/Modint.hpp"
using mint=ArbitraryModint<-1>;
void solve(){
    LL(P,N);
    mint::set_mod(P);
    VEC(mint,A,N);
    STR(S);
    mint ans=A[0];
    rep(i,1,N){
        if(S[i-1]=='+')ans+=A[i];
        if(S[i-1]=='-')ans-=A[i];
        if(S[i-1]=='*')ans*=A[i];
        if(S[i-1]=='/')ans/=A[i];
    }
    out(ans);
}
int main(){
    solve();
    return 0;
}