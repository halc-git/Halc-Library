#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../String/RollingHash.hpp"
#include "../../Template/Template.hpp"
void Halc::solve() {
    STR(S);
    RollingHash<string> roll;
    auto st = roll.build(S);
    reverse(all(S));
    auto rev = roll.build(S);
    vec(ll, ans, len(S) * 2 - 1);
    rep(i, len(S)) {
        ll ok = 1, ng = min(i + 1, len(S) - i) + 1;
        while (ng - ok > 1) {
            ll mid = (ok + ng) >> 1;
            if (roll.query(st, i - mid + 1, i + mid) ==
                roll.query(rev, len(S) - i - mid, len(S) - i + mid - 1)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans[i << 1] = (ok << 1) - 1;
    }
    rep(i, len(S) - 1) {
        ll ok = 0, ng = min(i + 1, len(S) - i - 1) + 1;
        while (ng - ok > 1) {
            ll mid = (ok + ng) >> 1;
            if (roll.query(st, i - mid + 1, i + mid + 1) ==
                roll.query(rev, len(S) - i - mid - 1, len(S) - i + mid - 1)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans[(i << 1) + 1] = ok << 1;
    }
    out(ans);
}