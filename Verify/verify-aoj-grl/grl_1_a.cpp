#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../DataStructure/RadixHeap.hpp"
#include "../../Graph/Graph.hpp"
#include "../../Template/Template.hpp"

void solve() {
    LL(N, M, r);
    Graph gr(N);
    rep(i, M) {
        LL(s, t, d);
        gr.add_directed_edge(s, t, d);
    }
    vector<int64_t> dist(N, LINF);
    dist[r] = 0;
    RadixHeap<int64_t, int32_t> hq;
    hq.push(0, r);
    while (!hq.empty()) {
        ll dis, pos;
        tie(dis, pos) = hq.pop();
        if (dist[pos] != dis) continue;
        for (Edge i : gr[pos]) {
            if (dis + i.cost < dist[i]) {
                dist[i] = dis + i.cost;
                hq.push(dist[i], i);
            }
        }
    }
    each(i, dist) {
        if (i >= LINF)
            out("INF");
        else
            out(i);
    }
}
int main() { solve(); }