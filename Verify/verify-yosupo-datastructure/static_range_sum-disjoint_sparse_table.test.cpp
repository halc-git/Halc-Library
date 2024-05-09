#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../DataStructure/DisjointSparseTable.hpp"
#include "../../Template/Template.hpp"
struct rsq {
    using T = ll;
    static T op(T x, T y) { return x + y; }
    static inline T e = 0;
};
void Halc::solve() {
    LL(N, Q);
    VEC(ll, A, N);
    DisjointSparseTable<rsq> a(A);
    rep(i, Q) {
        LL(l, r);
        out(a.prod(l, r));
    }
}