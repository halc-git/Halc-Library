#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../DataStructure/SegmentTree.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MOD>;
struct composite {
    using T = pair<mint, mint>;
    static T op(T x, T y) { return T(x.fi * y.fi, x.se * y.fi + y.se); }
    static inline T e = T(1, 0);
};
void Halc::solve() {
    LL(N, Q);
    VEC(composite::T, ab, N);
    SegmentTree<composite> seg(ab);
    rep(i, Q) {
        LL(t);
        if (t == 0) {
            LL(p, c, d);
            seg.set(p, {c, d});
        } else {
            LL(l, r, x);
            pair<mint, mint> func = seg.prod(l, r);
            out(func.fi * x + func.se);
        }
    }
}