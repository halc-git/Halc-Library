#define PROBLEM "https://yukicoder.me/problems/no/650"
#include "DataStructure/SegmentTree.hpp"
#include "Graph/Graph.hpp"
#include "Modint/Modint.hpp"
#include "Tree/HLDecomposition.hpp"
#include "Template/Template.hpp"
using mint = Modint<MODD>;
struct mat {
    using T = array<mint, 4>;
    static T op(T x, T y) {
        return {x[0] * y[0] + x[1] * y[2], x[0] * y[1] + x[1] * y[3],
                x[2] * y[0] + x[3] * y[2], x[2] * y[1] + x[3] * y[3]};
    }
    static inline T e = {1, 0, 0, 1};
};
void solve() {
    LL(n);
    Graph gr(n);
    rep(i, n - 1) {
        LL(u, v);
        gr.add_edge(u, v);
    }
    HLDecomposition hld(gr);
    SegmentTree<mat> seg(n);
    vec(ll, change, n - 1);
    rep(i, n) {
        each(j, gr[i]) {
            if (hld.depth[i] < hld.depth[j]) {
                change[j.idx] = j;
            }
        }
    }
    LL(q);
    rep(_, q) {
        CHR(t);
        if (t == 'x') {
            LL(i);
            mat::T x;
            in(x);
            seg.set(hld[change[i]], x);
        } else {
            LL(i, j);
            ll lca = hld.lca(i, j);
            mat::T x = seg.get(hld[lca]);
            seg.set(hld[lca], mat::e);
            mat::T ans = mat::e;
            for (auto &[lf, ri, _] : hld.path(i, j)) {
                ans = mat::op(ans, seg.prod(lf, ri));
            }
            out(ans);
            seg.set(hld[lca], x);
        }
    }
}
int main() { solve(); }