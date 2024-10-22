#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"
#include "../../Math/MFPrefixSum.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<469762049>;
void solve() {
    LL(T);
    rep(_, T) {
        LL(N, a, b);
        mf_prefix_sum<mint> mf(N);
        vector<mint> pi = mf.pi_table();
        vector<mint> prime_sum = mf.prime_sum_table();
        vector<mint> table(pi.size());
        rep(i, pi.size()) { table[i] = pi[i] * a + prime_sum[i] * b; }
        out(mf.run(table, [a, b](ll x, ll c) -> mint {
                  return a * c + b * x;
              }).back());
    }
}
int main() { solve(); }