#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../DataStructure/LazySegmentTree.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MOD>;
struct affine {
    using T = pair<ll, mint>;
    static T op(T x, T y) { return {x.fi + y.fi, x.se + y.se}; }
    static inline T e = {0, 0};
    using F = pair<mint, mint>;
    static T mapp(F f, T x) { return {x.fi, f.fi * x.se + f.se * x.fi}; }
    static F comp(F f, F g) { return {f.fi * g.fi, g.se * f.fi + f.se}; }
    static inline F id = {1, 0};
};
void solve() {
    LL(N, Q);
    VEC(ll, A, N);
    LazySegmentTree<affine> a(N);
    rep(i, N) { a.set(i, {1, A[i]}); }
    rep(i, Q) {
        LL(t);
        if (t == 0) {
            LL(l, r, b, c);
            a.apply(l, r, {b, c});
        } else {
            LL(l, r);
            out(a.prod(l, r).se);
        }
    }
}
int main() { solve(); }