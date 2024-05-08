#pragma once
#include <cstdint>
#include <vector>
template <class M>
struct MonoidUnionFind {
    using T = typename M::T;
    std::vector<std::pair<int32_t, T>> tree;
    MonoidUnionFind(int32_t sz) { tree.resize(sz, {-1, M::e}); }
    int32_t root(int32_t pos) {
        int32_t ret = pos;
        while (tree[ret].first >= 0) {
            ret = tree[ret].first;
        }
        while (tree[pos].first >= 0) {
            int32_t now = pos;
            pos = tree[pos].first;
            tree[now].first = ret;
        }
        return ret;
    }
    void set(int32_t pos, T val) { tree[root(pos)].second = val; }
    T get(int32_t pos) { return tree[root(pos)].second; }
    bool same(int32_t a, int32_t b) { return root(a) == root(b); }
    bool merge(int32_t a, int32_t b) {
        a = root(a);
        b = root(b);
        if (a == b) return false;
        if (tree[a].first > tree[b].first) std::swap(a, b);
        tree[a] = {tree[a].first + tree[b].first,
                   M::op(tree[a].second, tree[b].second)};
        tree[b].first = a;
        return true;
    }
    size_t size(int32_t pos) { return -tree[root(pos)].first; }
    std::vector<std::vector<int32_t>> groups() {
        std::vector<std::vector<int32_t>> members(tree.size());
        for (int32_t i = 0; i < tree.size(); i++) {
            members[root(i)].emplace_back(i);
        }
        std::vector<std::vector<int32_t>> ret;
        for (int32_t i = 0; i < tree.size(); i++) {
            if (!members[i].empty()) ret.emplace_back(members[i]);
        }
        return ret;
    }
};
namespace union_find_void {
struct void_monoid {
    using T = bool;
    constexpr static inline T op(T a, T b) { return 0; }
    constexpr static inline T e = 0;
};
}  // namespace union_find_void
using UnionFind = MonoidUnionFind<union_find_void::void_monoid>;