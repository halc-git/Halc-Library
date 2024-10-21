#define PROBLEM "https://yukicoder.me/problems/no/117"
#include "../../Math/ModCombination.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MODD>;
void solve() {
    LL(T);
    ModCombination<mint> comb;
    rep(i, T) {
        STR(S);
        ll N = 0, K = 0;
        bool flg = false;
        each(j, S) {
            if (0 <= j - '0' && j - '0' <= 9) {
                if (flg) {
                    K *= 10;
                    K += j - '0';
                } else {
                    N *= 10;
                    N += j - '0';
                }
            } else if (j == ',') {
                flg = true;
            }
        }
        if (S[0] == 'C')
            out(comb.comb(N, K));
        else if (S[0] == 'P')
            out(comb.perm(N, K));
        else if (S[0] == 'H')
            out(comb.multi_comb(N, K));
    }
}
int main() { solve(); }