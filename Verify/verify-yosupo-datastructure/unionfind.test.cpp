#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../DataStructure/UnionFind.hpp"
#include "../../Template/Template.hpp"
void solve() {
    LL(N, Q);
    UnionFind uni(N);
    rep(i, Q) {
        LL(t, u, v);
        if (t == 0) {
            uni.merge(u, v);
        } else {
            out(uni.same(u, v));
        }
    }
}
int main() { solve(); }