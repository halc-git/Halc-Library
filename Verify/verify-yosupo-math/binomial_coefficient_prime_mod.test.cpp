#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../Math/ModCombination.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = ArbitraryModint<-1>;
void solve() {
    LL(T, m);
    mint::set_mod(m);
    ModCombination<mint> comb;
    comb.resize(min(m, 10000000LL));
    rep(i, T) {
        LL(n, k);
        out(comb.comb(n, k));
    }
}
int main() { solve(); }