#define PROBLEM "https://yukicoder.me/problems/no/1092"
#include"../../Template.hpp"
#include"../../Math/BarrettModint.hpp"
using mint=ArbitraryBarrettModint<0>;
void solve(){
    LL(P,n);
    VEC(ll,A,n);
    STR(S);
    mint::set_mod(P);
    mint ans=A[0];
    rep(i,n-1){
        if(S[i]=='+'){
            ans+=A[i+1];
        }
        if(S[i]=='-'){
            ans-=A[i+1];
        }
        if(S[i]=='*'){
            ans*=A[i+1];
        }
        if(S[i]=='/'){
            ans/=A[i+1];
        }
    }
    out(ans);
}
int main(){
    solve();
    return 0;
}