#define PROBLEM "https://yukicoder.me/problems/no/1092"
#include"../../Template.hpp"
#include"../../Math/MontgomeryModint.hpp"
using mint=DynamicMontgomeryModint<0>;
void solve(){
    LL(P,n);
    VEC(ll,A,n);
    STR(S);
    if(P==2){
        ll ans=A[0];
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
        out(ans&1);return;
    }
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
    out(ans.val());
}
int main(){
    solve();
    return 0;
}