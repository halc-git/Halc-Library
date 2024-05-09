#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>
template <class M>
struct StaticTopTree {
    using point = typename M::point;
    using path = typename M::path;
    struct Node {
        bool is_path;
        point point_val;
        path path_val;
        int32_t pos;
        int32_t left;
        int32_t right;
        int32_t parent;
        Node(bool pat, int32_t po = -1, int32_t lf = -1, int32_t ri = -1) {
            is_path = pat;
            pos = po;
            left = lf;
            right = ri;
            parent = -1;
        }
    };
    size_t sz;
    std::vector<std::vector<int32_t>> tree;
    std::vector<int32_t> node_pos;
    std::vector<Node> nodes;
    int32_t rt;
    StaticTopTree(size_t size) {
        sz = size;
        tree.resize(sz);
        node_pos.resize(sz);
    }
    void add_edge(int32_t s, int32_t v) {
        tree[s].emplace_back(v);
        tree[v].emplace_back(s);
    }
    int32_t _path_cluster(int32_t pos, std::vector<int32_t> &tree_sz) {
        if (tree[pos].empty()) {
            node_pos[pos] = nodes.size();
            nodes.emplace_back(Node(1, pos));
            _calc_val(nodes.size() - 1);
            return nodes.size() - 1;
        }
        std::vector<int32_t> address;
        std::vector<int32_t> sizes;
        while (!tree[pos].empty()) {
            int32_t max_size = -1;
            int32_t next_pos = -1;
            for (int i = 0; i < tree[pos].size(); i++) {
                if (tree_sz[tree[pos][i]] > max_size) {
                    max_size = tree_sz[tree[pos][i]];
                    next_pos = i;
                }
            }
            std::swap(tree[pos][next_pos], tree[pos].back());
            next_pos = tree[pos].back();
            tree[pos].pop_back();
            tree_sz[pos] -= tree_sz[next_pos];
            sizes.emplace_back(tree_sz[pos]);
            address.emplace_back(_point_cluster(pos, tree_sz));
            pos = next_pos;
        }
        address.emplace_back(_point_cluster(pos, tree_sz));
        sizes.emplace_back(tree_sz[pos]);
        return _merge(address, sizes, 0, address.size(), 1);
    }
    int32_t _point_cluster(int32_t pos, std::vector<int32_t> &tree_sz) {
        if (tree[pos].empty()) {
            node_pos[pos] = nodes.size();
            nodes.emplace_back(Node(1, pos));
            _calc_val(nodes.size() - 1);
            return nodes.size() - 1;
        }
        std::vector<int32_t> address;
        std::vector<int32_t> sizes;
        for (int32_t i : tree[pos]) {
            sizes.emplace_back(tree_sz[i]);
            int32_t vert = _path_cluster(i, tree_sz);
            nodes.emplace_back(Node(0, -1, vert));
            nodes[vert].parent = nodes.size() - 1;
            address.emplace_back(nodes.size() - 1);
            _calc_val(nodes.size() - 1);
        }
        int32_t vert = _merge(address, sizes, 0, address.size(), 0);
        node_pos[pos] = nodes.size();
        nodes.emplace_back(Node(1, pos, vert));
        nodes[vert].parent = nodes.size() - 1;
        _calc_val(nodes.size() - 1);
        return nodes.size() - 1;
    }
    int32_t _merge(std::vector<int32_t> &address, std::vector<int32_t> &sizes,
                   int32_t lf, int32_t ri, bool pat) {
        if (lf + 1 == ri) return address[lf];
        int32_t add = 0;
        for (int32_t i = lf; i < ri; i++) {
            add += sizes[i];
        }
        int32_t now = 0;
        int32_t bef = add + 1;
        for (int32_t i = lf; i < ri; i++) {
            now += sizes[i];
            if (now > add - now) {
                if (now + now - add > bef) i--;
                int32_t left = _merge(address, sizes, lf, i + 1, pat);
                int32_t right = _merge(address, sizes, i + 1, ri, pat);
                nodes.emplace_back(Node(pat, -1, left, right));
                nodes[left].parent = nodes.size() - 1;
                nodes[right].parent = nodes.size() - 1;
                _calc_val(nodes.size() - 1);
                return nodes.size() - 1;
            }
            bef = add - now - now;
        }
        assert(false);
    }
    void _calc_val(int32_t pos) {
        if (nodes[pos].is_path) {
            if ((nodes[pos].left == -1) && (nodes[pos].right == -1)) {
                nodes[pos].path_val = M::vertex(nodes[pos].pos);
            } else if ((nodes[pos].left != -1) && (nodes[pos].right != -1)) {
                nodes[pos].path_val =
                    M::compress(nodes[nodes[pos].left].path_val,
                                nodes[nodes[pos].right].path_val);
            } else {
                nodes[pos].path_val = M::add_vertex(
                    nodes[nodes[pos].left].point_val, nodes[pos].pos);
            }
        } else {
            if ((nodes[pos].left != -1) && (nodes[pos].right != -1)) {
                nodes[pos].point_val =
                    M::rake(nodes[nodes[pos].left].point_val,
                            nodes[nodes[pos].right].point_val);
            } else {
                nodes[pos].point_val =
                    M::add_edge(nodes[nodes[pos].left].path_val);
            }
        }
    }
    void build(int32_t root) {
        std::vector<int32_t> vert(sz);
        std::vector<int32_t> tree_sz(sz, -1);
        vert[0] = root;
        tree_sz[root] = 0;
        int32_t cnt = 1;
        for (int32_t i = 0; i < sz; i++) {
            for (int32_t j : tree[vert[i]]) {
                if (tree_sz[j]) {
                    tree_sz[j] = 0;
                    vert[cnt] = j;
                    cnt++;
                }
            }
        }
        for (int32_t i = sz - 1; i >= 0; i--) {
            int32_t parent = 0;
            for (int32_t j : tree[vert[i]]) {
                if (tree_sz[j] == 0) {
                    parent = -parent - 1;
                }
                if (parent >= 0) parent++;
                tree_sz[vert[i]] += tree_sz[j];
            }
            if (parent < 0) {
                std::swap(tree[vert[i]][-parent - 1], tree[vert[i]].back());
                tree[vert[i]].pop_back();
            }
            tree_sz[vert[i]]++;
        }
        rt = _path_cluster(root, tree_sz);
    }
    path root_value() { return nodes[rt].path_val; }
    void calc(int32_t pos) {
        int32_t change = node_pos[pos];
        while (nodes[change].parent != -1) {
            _calc_val(change);
            change = nodes[change].parent;
        }
        _calc_val(change);
    }
    size_t size() { return sz; }
};