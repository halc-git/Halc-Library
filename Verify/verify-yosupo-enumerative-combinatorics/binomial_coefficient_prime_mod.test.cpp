#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../Math/ModCombination.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = ArbitraryModint<0>;
void solve() {
    LL(T, m);
    mint::set_mod(m);
    ModCombination<mint> comb(10000000);
    rep(i, T) {
        LL(n, k);
        out(comb.comb(n, k));
    }
}
int main() { solve(); }