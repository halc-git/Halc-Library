#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../Template/Template.hpp"
#include"../../Graph/Graph.hpp"
#include"../../Tree/HLDecomposition.hpp"
void solve(){
    LL(N, Q);
    Graph gr(N);
    VEC(ll, p, N - 1);
    rep(i, N - 1) { gr.add_edge(i + 1, p[i]); }
    HLDecomposition hld(gr);
    rep(i,Q){
        LL(u,v);
        out(hld.lca(u,v));
    }
}
int main(){ solve(); }