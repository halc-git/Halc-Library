#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#include "../../Modint/Modint.hpp"
#include "../../Tree/StaticTopTree.hpp"
#include "../../Template/Template.hpp"
using mint = Modint<MOD>;
using edge_type = array<ll, 4>;
using func_type = pair<mint, mint>;
void Halc::solve() {
    LL(N, Q);
    static VEC(mint, a, N);
    VEC(edge_type, edge, N - 1);
    vv(ll, gr, N);
    rep(i, N - 1) {
        gr[edge[i][0]].emplace_back(edge[i][1]);
        gr[edge[i][1]].emplace_back(edge[i][0]);
    }
    vec(ll, dist, N, -1);
    dist[0] = 0;
    stack<ll> vert;
    vert.push(0);
    while (!vert.empty()) {
        ll pos = vert.top();
        vert.pop();
        each(i, gr[pos]) {
            if (dist[i] == -1) {
                dist[i] = dist[pos] + 1;
                vert.push(i);
            }
        }
    }
    static vec(func_type, func, N, {1, 0});
    struct ops {
        using point = array<mint, 2>;
        using path = array<mint, 4>;
        static path vertex(int v) {
            return {1, a[v] * func[v].fi + func[v].se, func[v].fi, func[v].se};
        }
        static path compress(path p, path c) {
            return {p[0] + c[0], p[1] + c[1] * p[2] + c[0] * p[3], p[2] * c[2],
                    p[2] * c[3] + p[3]};
        }
        static path add_vertex(point t, int v) {
            return {t[0] + 1,
                    (a[v] + t[1]) * func[v].fi + (t[0] + 1) * func[v].se,
                    func[v].fi, func[v].se};
        }
        static point rake(point x, point y) {
            return {x[0] + y[0], x[1] + y[1]};
        }
        static point add_edge(path t) { return {t[0], t[1]}; }
    };
    StaticTopTree<ops> tree(N);
    rep(i, N - 1) {
        if (dist[edge[i][0]] < dist[edge[i][1]]) {
            swap(edge[i][0], edge[i][1]);
        }
        func[edge[i][0]] = {edge[i][2], edge[i][3]};
        tree.add_edge(edge[i][0], edge[i][1]);
    }
    tree.build(0);
    rep(_, Q) {
        LL(t);
        if (t == 0) {
            LL(w, x);
            a[w] = x;
            tree.calc(w);
        } else {
            LL(e, y, z);
            func[edge[e][0]] = {y, z};
            tree.calc(edge[e][0]);
        }
        out(tree.root_value()[1]);
    }
}