#pragma once
#include <cstdint>
#include <stack>
#include <vector>

#include "../Graph/Graph.hpp"
struct HLDecomposition {
    struct Segment {
        int32_t lf, ri;
        bool rev;
    };
    int32_t sz;
    std::vector<int32_t> tree_sz;
    std::vector<int32_t> depth;
    std::vector<int32_t> order;
    std::vector<int32_t> path_roots;
    std::vector<int32_t> parent;
    std::vector<int32_t> out;
    template <class T>
    void _build(int32_t pos, Graph<T> &tree) {
        order[pos] = sz;
        sz++;
        int32_t mx = -1, mp = -1;
        for (int32_t i : tree[pos]) {
            if (i == parent[pos]) continue;
            if (mx < tree_sz[i]) {
                mx = tree_sz[i];
                mp = i;
            }
        }
        if (mx == -1) {
            out[pos] = sz;
            return;
        }
        path_roots[mp] = path_roots[pos];
        _build(mp, tree);
        for (int32_t i : tree[pos]) {
            if (i == parent[pos]) continue;
            if (i == mp) continue;
            path_roots[i] = i;
            _build(i, tree);
        }
        out[pos] = sz;
    }
    template <class T>
    int32_t _calc_sz(int32_t pos, Graph<T> &tree) {
        if (tree_sz[pos] != -1) return tree_sz[pos];
        tree_sz[pos] = 1;
        for (int32_t i : tree[pos]) {
            if (parent[pos] != i) {
                parent[i] = pos;
                depth[i] = depth[pos] + 1;
                tree_sz[pos] += _calc_sz(i, tree);
            }
        }
        return tree_sz[pos];
    }
    template <class T>
    HLDecomposition(Graph<T> &tree, int32_t root = 0) {
        sz = tree.size();
        tree_sz.resize(sz, -1);
        depth.resize(sz, -1);
        parent.resize(sz, -1);
        depth[root] = 0;
        _calc_sz(root, tree);
        order.resize(sz, -1);
        out.resize(sz, -1);
        path_roots.resize(sz, -1);
        sz = 0;
        path_roots[root] = root;
        _build(root, tree);
    }
    int32_t operator[](int32_t p) { return order[p]; }
    Segment subtree(int32_t pos) { return {order[pos], out[pos], false}; }
    std::vector<Segment> path(int32_t s, int32_t t) {
        std::vector<Segment> ret;
        std::stack<Segment> right;
        while (path_roots[s] != path_roots[t]) {
            if (depth[path_roots[s]] > depth[path_roots[t]]) {
                ret.emplace_back(
                    Segment{order[path_roots[s]], order[s] + 1, true});
                s = parent[path_roots[s]];
            } else {
                right.push({order[path_roots[t]], order[t] + 1, false});
                t = parent[path_roots[t]];
            }
        }
        if (depth[s] < depth[t]) {
            ret.emplace_back(Segment{order[s], order[t] + 1, false});
        } else {
            ret.emplace_back(Segment{order[t], order[s] + 1, true});
        }
        while (!right.empty()) {
            ret.push_back(right.top());
            right.pop();
        }
        return ret;
    }
    int32_t lca(int32_t s, int32_t t) {
        while (path_roots[s] != path_roots[t]) {
            if (depth[path_roots[s]] > depth[path_roots[t]]) {
                s = parent[path_roots[s]];
            } else {
                t = parent[path_roots[t]];
            }
        }
        if (depth[s] < depth[t]) return s;
        return t;
    }
};