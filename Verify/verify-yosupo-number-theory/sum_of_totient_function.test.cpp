#define PROBLEM ""
#include "../../Math/MFPrefixSum.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MOD>;
void solve() {
    LL(N);
    MFPrefixSum<mint> mf(N);
    auto pi = mf.pi_table(), prime_sum = mf.prime_sum_table();
    rep(i, len(pi)) prime_sum[i] -= pi[i];
    out(mf.min25_sieve(prime_sum, [](ll x, ll c) {
              mint ret = 1;
              rep(i, c) ret *= x;
              return ret - ret / x;
          }).back());
}
int main() { solve(); }