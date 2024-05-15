#define PROBLEM "https://yukicoder.me/problems/no/235"
#include "DataStructure/LazySegmentTree.hpp"
#include "Graph/Graph.hpp"
#include "Modint/Modint.hpp"
#include "Tree/HLDecomposition.hpp"
#include "Template/Template.hpp"
using mint = Modint<MODD>;
struct ops {
    using T = pair<mint, mint>;
    using F = mint;
    static T op(T x, T y) { return {x.fi + y.fi, x.se + y.se}; }
    static inline T e = {0, 0};
    static T mapp(F f, T x) { return {x.fi, x.se + x.fi * f}; }
    static F comp(F f, F g) { return f + g; }
    static inline F id = 0;
};
void solve() {
    LL(N);
    VEC(mint, s, N);
    VEC(mint, c, N);
    Graph gr(N);
    rep(i, N - 1) {
        LL(A, B);
        gr.add_edge(A - 1, B - 1);
    }
    HLDecomposition hld(gr);
    LazySegmentTree<ops> seg(N);
    rep(i, N) { seg.set(hld[i], {c[i], s[i]}); }
    LL(Q);
    rep(i, Q) {
        LL(t);
        if (t == 0) {
            LL(X, Y, Z);
            for (auto &[lf, ri, _] : hld.path(X - 1, Y - 1)) {
                seg.apply(lf, ri, Z);
            }
        } else {
            LL(X, Y);
            mint ans = 0;
            for (auto &[lf, ri, _] : hld.path(X - 1, Y - 1)) {
                ans += seg.prod(lf, ri).se;
            }
            out(ans);
        }
    }
}
int main() { solve(); }