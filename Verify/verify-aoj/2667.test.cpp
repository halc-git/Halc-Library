#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"
#include "DataStructure/LazySegmentTree.hpp"
#include "Tree/HLDecomposition.hpp"
#include "Template/Template.hpp"
struct ops {
    using T = pll;
    using F = ll;
    static T op(T x, T y) { return {x.fi + y.fi, x.se + y.se}; }
    static inline T e = {0, 0};
    static T mapp(F f, T x) { return {x.fi, x.se + x.fi * f}; }
    static F comp(F f, F g) { return f + g; }
    static inline F id = 0;
};
void solve() {
    LL(N, Q);
    Graph gr(N);
    rep(i, N - 1) {
        LL(C, D);
        gr.add_edge(C, D);
    }
    HLDecomposition hld(gr);
    LazySegmentTree<ops> seg(N);
    rep(i, N) { seg.set(i, {1, 0}); }
    ll now = 0;
    rep(_, Q) {
        LL(t);
        if (t == 1) {
            LL(v, x);
            auto sg = hld.subtree(v);
            seg.apply(sg.lf, sg.ri, x);
            seg.set(hld[v], {1, seg.get(hld[v]).se - x});
        } else {
            LL(u, v);
            ll lca = hld.lca(u, v);
            pll wei = seg.get(hld[lca]);
            seg.set(hld[lca], ops::e);
            ll ans = 0;
            for (auto &[lf, ri, _] : hld.path(u, v)) {
                ans += seg.prod(lf, ri).se;
            }
            out(ans);
            seg.set(hld[lca], wei);
        }
    }
}
int main() { solve(); }