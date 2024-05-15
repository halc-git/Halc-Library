#define PROBLEM "https://yukicoder.me/problems/no/900"
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
    LL(N);
    Graph gr(N);
    rep(i, N - 1) {
        LL(u, v, w);
        gr.add_edge(u, v, w);
    }
    HLDecomposition hld(gr);
    LazySegmentTree<ops> seg(N);
    seg.set(0, {1, 0});
    rep(i, N) {
        each(j, gr[i]) {
            if (hld.depth[i] < hld.depth[j]) {
                seg.set(hld[j], {1, j.cost});
            }
        }
    }
    LL(Q);
    rep(_, Q) {
        LL(t);
        if (t == 1) {
            LL(a, x);
            auto sg = hld.subtree(a);
            seg.apply(sg.lf, sg.ri, x);
            seg.set(hld[a], {1, seg.get(hld[a]).se - x});
        } else {
            LL(b);
            ll ans = 0;
            for (auto &[lf, ri, _] : hld.path(0, b)) {
                ans += seg.prod(lf, ri).se;
            }
            out(ans);
        }
    }
}
int main() { solve(); }