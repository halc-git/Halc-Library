#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../../Math/EnumeratePrimes.hpp"
#include "../../Template/Template.hpp"

void solve() {
    LL(N, A, B);
    vector<int32_t> primes = enumerate_primes(N);
    ll phi = primes.size();
    vl ans;
    while (B < phi) {
        ans.emplace_back(primes[B]);
        B += A;
    }
    out(phi, ans.size());
    out(ans);
}
int main() { solve(); }