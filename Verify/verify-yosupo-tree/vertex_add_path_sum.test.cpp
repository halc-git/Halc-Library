#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../../DataStructure/FenwickTree.hpp"
#include "../../Graph/Graph.hpp"
#include "../../Tree/HLDecomposition.hpp"
#include "../../Template/Template.hpp"
void solve() {
    LL(N, Q);
    VEC(ll, a, N);
    Graph gr(N);
    rep(i, N - 1) {
        LL(u, v);
        gr.add_edge(u, v);
    }
    FenwickTree<ll> fw(N);
    HLDecomposition hld(gr);
    rep(i, N) { fw.add(hld[i], a[i]); }
    rep(i, Q) {
        LL(t);
        if (t == 0) {
            LL(p, x);
            fw.add(hld[p], x);
        }
        if (t == 1) {
            LL(u, v);
            ll ans = 0;
            for (auto &[s, t, _] : hld.path(u, v)) {
                ans += fw.sum(s, t);
            }
            out(ans);
        }
    }
}
int main() { solve(); }