#define PROBLEM "https://yukicoder.me/problems/no/1092"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = ArbitraryModint<-1>;
void Halc::solve() {
    LL(P, N);
    mint::set_mod(P);
    VEC(mint, A, N);
    STR(S);
    mint ans = A[0];
    rep(i, 1, N) {
        if (S[i - 1] == '+') ans += A[i];
        if (S[i - 1] == '-') ans -= A[i];
        if (S[i - 1] == '*') ans *= A[i];
        if (S[i - 1] == '/') ans /= A[i];
    }
    out(ans);
}