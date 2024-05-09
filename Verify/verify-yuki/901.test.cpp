#define PROBLEM "https://yukicoder.me/problems/no/901"
#include "Tree/StaticTopTree.hpp"
#include "Template/Template.hpp"
void Halc::solve() {
    LL(N);
    static vector<bool> mark(N, 0);
    static vector<ll> weight(N, -1);
    struct steiner {
        using point = array<ll, 5>;
        using path = array<ll, 6>;

        static path vertex(int v) {
            if (mark[v]) {
                return {1, 0, 0, 0, 0, weight[v]};
            }
            return {0, 0, 0, 0, 0, weight[v]};
        }

        static path compress(path p, path c) {
            if (p[0] == 0 && c[0] == 0) {
                return {0, 0, 0, p[3] + c[3] + c[5], p[3] + c[3] + c[5], p[5]};
            }
            if (p[0] == 1 && c[0] == 0) {
                return {1, p[1], p[2], p[3], p[4] + c[3] + c[5], p[5]};
            }
            if (p[0] == 0 && c[0] == 1) {
                return {1, c[1], c[2], p[3] + c[3] + c[5], c[4], p[5]};
            }
            return {1,
                    p[2] + c[2] + p[4] + c[3] + c[5],
                    p[2] + c[2] + p[4] + c[3] + c[5],
                    p[3],
                    c[4],
                    p[5]};
        }

        static path add_vertex(point t, int v) {
            if (t[0] == 0) {
                if (mark[v]) {
                    return {1, 0, 0, 0, 0, weight[v]};
                }
                return {0, 0, 0, 0, 0, weight[v]};
            }
            if (t[3] == 0) {
                if (mark[v]) {
                    return {1, t[2] + t[4], t[2] + t[4], 0, 0, weight[v]};
                }
                return {1, t[1], t[2] + t[4], 0, 0, weight[v]};
            }
            return {1, t[2] + t[4], t[2] + t[4], 0, 0, weight[v]};
        }

        static point rake(point x, point y) {
            if (x[0] < y[0]) swap(x, y);
            if (x[0] == 0 && y[0] == 0) {
                return {0, 0, 0, 0, 0};
            }
            if (x[0] == 1 && y[0] == 0) {
                return x;
            }
            return {1, x[2] + y[2], x[2] + y[2], 1, x[4] + y[4]};
        }

        static point add_edge(path t) {
            if (t[0] == 0) {
                return {0, 0, 0, 0, 0};
            }
            return {1, t[1], t[2] + t[3], 0, t[5]};
        }
    };
    StaticTopTree<steiner> tree(N);
    vv(pll, gr, N);
    rep(i, N - 1) {
        LL(u, v, w);
        tree.add_edge(u, v);
        gr[u].push_back(pll(v, w));
        gr[v].push_back(pll(u, w));
    }
    weight[0] = 0;
    stack<ll> vert;
    vert.push(0);
    while (!vert.empty()) {
        ll pos = vert.top();
        vert.pop();
        for (auto &[t, w] : gr[pos]) {
            if (weight[t] == -1) {
                weight[t] = w;
                vert.push(t);
            }
        }
    }
    tree.build(0);
    LL(Q);
    rep(i, Q) {
        LL(k);
        VEC(ll, x, k);
        each(j, x) {
            mark[j] = 1;
            tree.calc(j);
        }
        out(tree.root_value()[1]);
        each(j, x) {
            mark[j] = 0;
            tree.calc(j);
        }
    }
}