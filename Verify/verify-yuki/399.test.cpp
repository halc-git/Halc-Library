#define PROBLEM "https://yukicoder.me/problems/no/399"
#include "DataStructure/FenwickTree.hpp"
#include "Graph/Graph.hpp"
#include "Tree/HLDecomposition.hpp"
#include "Template/Template.hpp"
void solve() {
    LL(N);
    Graph gr(N);
    rep(i, N - 1) {
        LL(u, v);
        gr.add_edge(u - 1, v - 1);
    }
    FenwickTree<ll> fw(N + 1);
    HLDecomposition hld(gr);
    LL(Q);
    rep(i, Q) {
        LL(A, B);
        for (auto &[lf, ri, _] : hld.path(A - 1, B - 1)) {
            fw.add(lf, 1);
            fw.add(ri, -1);
        }
    }
    ll ans = 0;
    rep(i, N) {
        ll now = fw.sum(0, i + 1);
        ans += now * (now + 1) / 2;
    }
    out(ans);
}
int main() { solve(); }