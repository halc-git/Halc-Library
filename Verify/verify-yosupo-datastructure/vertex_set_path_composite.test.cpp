#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../DataStructure/SegmentTree.hpp"
#include "../../Graph/Graph.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Tree/HLDecomposition.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MOD>;
struct composite {
    using T = pair<mint, mint>;
    static T op(T lf, T ri) { return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se); }
    static inline T e = T(1, 0);
};
struct rev_composite : composite {
    static T op(T ri, T lf) { return T(lf.fi * ri.fi, lf.se * ri.fi + ri.se); }
};
void solve() {
    LL(N, Q);
    VEC(composite::T, ab, N);
    Graph gr(N);
    rep(i, N - 1) {
        LL(u, v);
        gr.add_edge(u, v);
    }
    SegmentTree<composite> rig(N);
    SegmentTree<rev_composite> rev(N);
    HLDecomposition hld(gr);
    rep(i, N) {
        rig.set(hld[i], ab[i]);
        rev.set(hld[i], ab[i]);
    }
    rep(i, Q) {
        LL(t);
        if (t == 0) {
            LL(p, c, d);
            rig.set(hld[p], {c, d});
            rev.set(hld[p], {c, d});
        }
        if (t == 1) {
            LL(u, v, x);
            pair<mint, mint> ans = {1, 0};
            for (auto &[s, t, r] : hld.path(u, v)) {
                if (!r) {
                    ans = composite::op(ans, rig.prod(s, t));
                } else {
                    ans = composite::op(ans, rev.prod(s, t));
                }
            }
            out(ans.fi * x + ans.se);
        }
    }
}
int main() { solve(); }