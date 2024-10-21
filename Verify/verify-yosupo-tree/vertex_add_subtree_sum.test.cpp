#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../DataStructure/FenwickTree.hpp"
#include "../../Graph/Graph.hpp"
#include "../../Tree/HLDecomposition.hpp"
#include "../../Template/Template.hpp"
void solve() {
    LL(N, Q);
    VEC(ll, a, N);
    Graph gr(N);
    VEC(ll, p, N - 1);
    rep(i, N - 1) { gr.add_edge(i + 1, p[i]); }
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
            LL(u);
            auto sg = hld.subtree(u);
            out(fw.sum(sg.lf, sg.ri));
        }
    }
}
int main() { solve(); }