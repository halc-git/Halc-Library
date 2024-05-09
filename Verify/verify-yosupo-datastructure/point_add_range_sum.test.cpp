#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../DataStructure/FenwickTree.hpp"
#include "../../Template/Template.hpp"
void Halc::solve() {
    LL(N, Q);
    VEC(ll, A, N);
    FenwickTree<ll> a(A);
    rep(i, Q) {
        LL(t, x, y);
        if (t == 0) {
            a.add(x, y);
        } else {
            out(a.sum(x, y));
        }
    }
}