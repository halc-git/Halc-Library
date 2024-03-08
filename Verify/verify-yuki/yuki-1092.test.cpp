#define PROBREM "https://yukicoder.me/problems/no/1092"
#include"../../Template.hpp"
#include"../../Modint/MontgomeryModint.hpp"
using mint=DynamicMontgomeryModint<0>;
int main(){
    LL(P,N);
    mint::set_mod(P);
    VEC(ll,A,N);
    STR(S);
    mint ans=A[0];
    rep(i,N-1){
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