#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include"../../Template.hpp"
#include"../../Math/BarrettModint.hpp"
#include"../../Math/BinomialCoefficient_Primemod.hpp"
using mint=ArbitraryBarrettModint<0>;
void solve(){
    LL(T,m);
    mint::set_mod(m);
    BinomialCoefficient_Primemod<mint> comb;
    comb.resize(min(m-1,10000000LL));
    rep(i,T){
        LL(n,k);
        out(comb.comb(n,k));
    }
}
int main(){
    solve();
    return 0;
}