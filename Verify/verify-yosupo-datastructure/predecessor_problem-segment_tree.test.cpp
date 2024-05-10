#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../../DataStructure/SegmentTree.hpp"
#include "../../Template/Template.hpp"
struct raq {
    using T = ll;
    static T op(T x, T y) { return x + y; }
    static inline T e = 0;
};
void solve() {
    LL(N, Q);
    STR(T);
    vec(ll, t, N, 0);
    rep(i, N) {
        if (T[i] == '1') t[i] = 1;
    }
    SegmentTree<raq> seg(t);
    rep(i, Q) {
        LL(c, k);
        if (c == 0) {
            if (!seg.get(k)) {
                seg.set(k, 1);
            }
        }
        if (c == 1) {
            if (seg.get(k)) {
                seg.set(k, 0);
            }
        }
        if (c == 2) {
            out(seg.get(k));
        }
        if (c == 3) {
            ll ans = seg.max_right(k, [](ll x) { return x == 0; });
            if (ans < N) {
                out(ans);
            } else {
                out(-1);
            }
        }
        if (c == 4) {
            ll ans = seg.min_left(k + 1, [](ll x) { return x == 0; });
            out(ans - 1);
        }
    }
}
int main() { solve(); }