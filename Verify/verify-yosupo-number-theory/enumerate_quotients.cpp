#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "../../Math/EnumerateQuotients.hpp"
#include "../../Template/Template.hpp"
void solve() {
    LL(N);
    vl ans = enumerate_quotients(N);
    out(len(ans));
    out(ans);
}
int main() { solve(); }