#define PROBLEM "https://yukicoder.me/problems/no/2338"
#include "../../Misc/Mo.hpp"
#include "../../Template/Template.hpp"
void solve() {
    LL(N, M, Q);
    static vec(ll, P, N);
    static vec(bool, S, N, 0);
    rep(i, N) {
        string s;
        in(P[i], s);
        if (s == "AC") S[i] = 1;
        P[i]--;
    }
    static vec(ll, ac, M, 0);
    static vec(deque<ll>, sub, M);
    static ll ac_ans = 0;
    static ll pena_ans = 0;
    struct raq {
        using T = pll;
        static void add_left(int pos) {
            ll p = P[pos];
            if (S[pos]) {
                if (!ac[p])
                    ac_ans++;
                else
                    pena_ans -= sub[p].front();
                ac[p]++;
                sub[p].push_front(0);
            } else {
                if (sub[p].empty() || sub[p].front() == 0) {
                    sub[p].push_front(0);
                }
                sub[p].front()++;
                if (ac[p]) {
                    pena_ans++;
                }
            }
        }
        static void delete_left(int pos) {
            ll p = P[pos];
            if (S[pos]) {
                sub[p].pop_front();
                ac[p]--;
                if (!ac[p]) {
                    ac_ans--;
                } else {
                    pena_ans += sub[p].front();
                }
            } else {
                sub[p].front()--;
                if (ac[p]) {
                    pena_ans--;
                }
                if (sub[p].front() == 0) {
                    sub[p].pop_front();
                }
            }
        }
        static void add_right(int pos) {
            ll p = P[pos];
            if (S[pos]) {
                if (!ac[p]) {
                    ac_ans++;
                    if (!sub[p].empty()) {
                        pena_ans += sub[p].front();
                    }
                }
                sub[p].push_back(0);
                ac[p]++;
            } else {
                if (sub[p].empty() || sub[p].back() == 0) {
                    sub[p].push_back(0);
                }
                sub[p].back()++;
            }
        }
        static void delete_right(int pos) {
            ll p = P[pos];
            if (S[pos]) {
                sub[p].pop_back();
                ac[p]--;
                if (!ac[p]) {
                    ac_ans--;
                    if (!sub[p].empty()) pena_ans -= sub[p].front();
                }
            } else {
                sub[p].back()--;
                if (sub[p].back() == 0) sub[p].pop_back();
            }
        }
        static T rem() { return pll(ac_ans, pena_ans); }
    };
    Mo<raq> mo(N, Q);
    rep(i, Q) {
        LL(L, R);
        mo.add_query(L - 1, R);
    }
    vector<pll> fin_ans = mo.run();
    for (auto &[a, p] : fin_ans) {
        out(a, p);
    }
}
int main() { solve(); }