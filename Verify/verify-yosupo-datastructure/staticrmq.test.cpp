#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../DataStructure/DisjointSparseTable.hpp"
#include "../../Template/Template.hpp"
struct rmq {
    using T = ll;
    static T op(T x, T y) { return min(x, y); }
    static inline T e = INF;
};
void Halc::solve() {
    LL(N, Q);
    VEC(ll, A, N);
    DisjointSparseTable<rmq> a(A);
    rep(i, Q) {
        LL(l, r);
        out(a.prod(l, r));
    }
}