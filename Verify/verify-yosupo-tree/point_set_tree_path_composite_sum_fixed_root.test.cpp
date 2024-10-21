#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#include "../../Graph/Graph.hpp"
#include "../../Modint/Modint.hpp"
#include "../../Template/Template.hpp"
#include "../../Tree/StaticTopTree.hpp"
using mint = Modint<MOD>;
using edge_type = array<ll, 4>;
using func_type = pair<mint, mint>;
void solve() {
    LL(N, Q);
    static VEC(mint, a, N);
    Graph<func_type> gr(N);
    rep(i, N - 1) {
        LL(u, v, b, c);
        gr.add_edge(v, u, {b, c});
    }
    stack<ll> vert;
    vert.push(0);
    static vec(func_type, func, N, {1, 0});
    vec(ll, change, N - 1, -1);
    while (!vert.empty()) {
        ll pos = vert.top();
        vert.pop();
        each(i, gr[pos]) {
            if (change[i.idx] == -1) {
                func[i] = i.cost;
                change[i.idx] = i;
                vert.push(i);
            }
        }
    }
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
    StaticTopTree<ops> tree(gr, 0);
    rep(_, Q) {
        LL(t);
        if (t == 0) {
            LL(w, x);
            a[w] = x;
            tree.calc(w);
        } else {
            LL(e, y, z);
            func[change[e]] = {y, z};
            tree.calc(change[e]);
        }
        out(tree.root_value()[1]);
    }
}
int main() { solve(); }