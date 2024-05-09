---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/StaticTopTree.hpp\"\n#include <cassert>\n#include <vector>\n\
    template <class M>\nstruct StaticTopTree {\n    using point = typename M::point;\n\
    \    using path = typename M::path;\n    struct Node {\n        bool is_path;\n\
    \        point point_val;\n        path path_val;\n        int32_t pos;\n    \
    \    int32_t left;\n        int32_t right;\n        int32_t parent;\n        Node(bool\
    \ pat, int32_t po = -1, int32_t lf = -1, int32_t ri = -1) {\n            is_path\
    \ = pat;\n            pos = po;\n            left = lf;\n            right = ri;\n\
    \            parent = -1;\n        }\n    };\n    size_t sz;\n    std::vector<std::vector<int32_t>>\
    \ tree;\n    std::vector<int32_t> node_pos;\n    std::vector<Node> nodes;\n  \
    \  int32_t rt;\n    StaticTopTree(size_t size) {\n        sz = size;\n       \
    \ tree.resize(sz);\n        node_pos.resize(sz);\n    }\n    void add_edge(int32_t\
    \ s, int32_t v) {\n        tree[s].emplace_back(v);\n        tree[v].emplace_back(s);\n\
    \    }\n    int32_t _path_cluster(int32_t pos, std::vector<int32_t> &tree_sz)\
    \ {\n        if (tree[pos].empty()) {\n            node_pos[pos] = nodes.size();\n\
    \            nodes.emplace_back(Node(1, pos));\n            _calc_val(nodes.size()\
    \ - 1);\n            return nodes.size() - 1;\n        }\n        std::vector<int32_t>\
    \ address;\n        std::vector<int32_t> sizes;\n        while (!tree[pos].empty())\
    \ {\n            int32_t max_size = -1;\n            int32_t next_pos = -1;\n\
    \            for (int i = 0; i < tree[pos].size(); i++) {\n                if\
    \ (tree_sz[tree[pos][i]] > max_size) {\n                    max_size = tree_sz[tree[pos][i]];\n\
    \                    next_pos = i;\n                }\n            }\n       \
    \     std::swap(tree[pos][next_pos], tree[pos].back());\n            next_pos\
    \ = tree[pos].back();\n            tree[pos].pop_back();\n            tree_sz[pos]\
    \ -= tree_sz[next_pos];\n            sizes.emplace_back(tree_sz[pos]);\n     \
    \       address.emplace_back(_point_cluster(pos, tree_sz));\n            pos =\
    \ next_pos;\n        }\n        address.emplace_back(_point_cluster(pos, tree_sz));\n\
    \        sizes.emplace_back(tree_sz[pos]);\n        return _merge(address, sizes,\
    \ 0, address.size(), 1);\n    }\n    int32_t _point_cluster(int32_t pos, std::vector<int32_t>\
    \ &tree_sz) {\n        if (tree[pos].empty()) {\n            node_pos[pos] = nodes.size();\n\
    \            nodes.emplace_back(Node(1, pos));\n            _calc_val(nodes.size()\
    \ - 1);\n            return nodes.size() - 1;\n        }\n        std::vector<int32_t>\
    \ address;\n        std::vector<int32_t> sizes;\n        for (int32_t i : tree[pos])\
    \ {\n            sizes.emplace_back(tree_sz[i]);\n            int32_t vert = _path_cluster(i,\
    \ tree_sz);\n            nodes.emplace_back(Node(0, -1, vert));\n            nodes[vert].parent\
    \ = nodes.size() - 1;\n            address.emplace_back(nodes.size() - 1);\n \
    \           _calc_val(nodes.size() - 1);\n        }\n        int32_t vert = _merge(address,\
    \ sizes, 0, address.size(), 0);\n        node_pos[pos] = nodes.size();\n     \
    \   nodes.emplace_back(Node(1, pos, vert));\n        nodes[vert].parent = nodes.size()\
    \ - 1;\n        _calc_val(nodes.size() - 1);\n        return nodes.size() - 1;\n\
    \    }\n    int32_t _merge(std::vector<int32_t> &address, std::vector<int32_t>\
    \ &sizes,\n                   int32_t lf, int32_t ri, bool pat) {\n        if\
    \ (lf + 1 == ri) return address[lf];\n        int32_t add = 0;\n        for (int32_t\
    \ i = lf; i < ri; i++) {\n            add += sizes[i];\n        }\n        int32_t\
    \ now = 0;\n        int32_t bef = add + 1;\n        for (int32_t i = lf; i < ri;\
    \ i++) {\n            now += sizes[i];\n            if (now > add - now) {\n \
    \               if (now + now - add > bef) i--;\n                int32_t left\
    \ = _merge(address, sizes, lf, i + 1, pat);\n                int32_t right = _merge(address,\
    \ sizes, i + 1, ri, pat);\n                nodes.emplace_back(Node(pat, -1, left,\
    \ right));\n                nodes[left].parent = nodes.size() - 1;\n         \
    \       nodes[right].parent = nodes.size() - 1;\n                _calc_val(nodes.size()\
    \ - 1);\n                return nodes.size() - 1;\n            }\n           \
    \ bef = add - now - now;\n        }\n        assert(false);\n    }\n    void _calc_val(int32_t\
    \ pos) {\n        if (nodes[pos].is_path) {\n            if ((nodes[pos].left\
    \ == -1) && (nodes[pos].right == -1)) {\n                nodes[pos].path_val =\
    \ M::vertex(nodes[pos].pos);\n            } else if ((nodes[pos].left != -1) &&\
    \ (nodes[pos].right != -1)) {\n                nodes[pos].path_val =\n       \
    \             M::compress(nodes[nodes[pos].left].path_val,\n                 \
    \               nodes[nodes[pos].right].path_val);\n            } else {\n   \
    \             nodes[pos].path_val = M::add_vertex(\n                    nodes[nodes[pos].left].point_val,\
    \ nodes[pos].pos);\n            }\n        } else {\n            if ((nodes[pos].left\
    \ != -1) && (nodes[pos].right != -1)) {\n                nodes[pos].point_val\
    \ =\n                    M::rake(nodes[nodes[pos].left].point_val,\n         \
    \                   nodes[nodes[pos].right].point_val);\n            } else {\n\
    \                nodes[pos].point_val =\n                    M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    void build(int32_t root) {\n        std::vector<int32_t>\
    \ vert(sz);\n        std::vector<int32_t> tree_sz(sz, -1);\n        vert[0] =\
    \ root;\n        tree_sz[root] = 0;\n        int32_t cnt = 1;\n        for (int32_t\
    \ i = 0; i < sz; i++) {\n            for (int32_t j : tree[vert[i]]) {\n     \
    \           if (tree_sz[j]) {\n                    tree_sz[j] = 0;\n         \
    \           vert[cnt] = j;\n                    cnt++;\n                }\n  \
    \          }\n        }\n        for (int32_t i = sz - 1; i >= 0; i--) {\n   \
    \         int32_t parent = 0;\n            for (int32_t j : tree[vert[i]]) {\n\
    \                if (tree_sz[j] == 0) {\n                    parent = -parent\
    \ - 1;\n                }\n                if (parent >= 0) parent++;\n      \
    \          tree_sz[vert[i]] += tree_sz[j];\n            }\n            if (parent\
    \ < 0) {\n                std::swap(tree[vert[i]][-parent - 1], tree[vert[i]].back());\n\
    \                tree[vert[i]].pop_back();\n            }\n            tree_sz[vert[i]]++;\n\
    \        }\n        rt = _path_cluster(root, tree_sz);\n    }\n    path root_value()\
    \ { return nodes[rt].path_val; }\n    void calc(int32_t pos) {\n        int32_t\
    \ change = node_pos[pos];\n        while (nodes[change].parent != -1) {\n    \
    \        _calc_val(change);\n            change = nodes[change].parent;\n    \
    \    }\n        _calc_val(change);\n    }\n    size_t size() { return sz; }\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <class M>\n\
    struct StaticTopTree {\n    using point = typename M::point;\n    using path =\
    \ typename M::path;\n    struct Node {\n        bool is_path;\n        point point_val;\n\
    \        path path_val;\n        int32_t pos;\n        int32_t left;\n       \
    \ int32_t right;\n        int32_t parent;\n        Node(bool pat, int32_t po =\
    \ -1, int32_t lf = -1, int32_t ri = -1) {\n            is_path = pat;\n      \
    \      pos = po;\n            left = lf;\n            right = ri;\n          \
    \  parent = -1;\n        }\n    };\n    size_t sz;\n    std::vector<std::vector<int32_t>>\
    \ tree;\n    std::vector<int32_t> node_pos;\n    std::vector<Node> nodes;\n  \
    \  int32_t rt;\n    StaticTopTree(size_t size) {\n        sz = size;\n       \
    \ tree.resize(sz);\n        node_pos.resize(sz);\n    }\n    void add_edge(int32_t\
    \ s, int32_t v) {\n        tree[s].emplace_back(v);\n        tree[v].emplace_back(s);\n\
    \    }\n    int32_t _path_cluster(int32_t pos, std::vector<int32_t> &tree_sz)\
    \ {\n        if (tree[pos].empty()) {\n            node_pos[pos] = nodes.size();\n\
    \            nodes.emplace_back(Node(1, pos));\n            _calc_val(nodes.size()\
    \ - 1);\n            return nodes.size() - 1;\n        }\n        std::vector<int32_t>\
    \ address;\n        std::vector<int32_t> sizes;\n        while (!tree[pos].empty())\
    \ {\n            int32_t max_size = -1;\n            int32_t next_pos = -1;\n\
    \            for (int i = 0; i < tree[pos].size(); i++) {\n                if\
    \ (tree_sz[tree[pos][i]] > max_size) {\n                    max_size = tree_sz[tree[pos][i]];\n\
    \                    next_pos = i;\n                }\n            }\n       \
    \     std::swap(tree[pos][next_pos], tree[pos].back());\n            next_pos\
    \ = tree[pos].back();\n            tree[pos].pop_back();\n            tree_sz[pos]\
    \ -= tree_sz[next_pos];\n            sizes.emplace_back(tree_sz[pos]);\n     \
    \       address.emplace_back(_point_cluster(pos, tree_sz));\n            pos =\
    \ next_pos;\n        }\n        address.emplace_back(_point_cluster(pos, tree_sz));\n\
    \        sizes.emplace_back(tree_sz[pos]);\n        return _merge(address, sizes,\
    \ 0, address.size(), 1);\n    }\n    int32_t _point_cluster(int32_t pos, std::vector<int32_t>\
    \ &tree_sz) {\n        if (tree[pos].empty()) {\n            node_pos[pos] = nodes.size();\n\
    \            nodes.emplace_back(Node(1, pos));\n            _calc_val(nodes.size()\
    \ - 1);\n            return nodes.size() - 1;\n        }\n        std::vector<int32_t>\
    \ address;\n        std::vector<int32_t> sizes;\n        for (int32_t i : tree[pos])\
    \ {\n            sizes.emplace_back(tree_sz[i]);\n            int32_t vert = _path_cluster(i,\
    \ tree_sz);\n            nodes.emplace_back(Node(0, -1, vert));\n            nodes[vert].parent\
    \ = nodes.size() - 1;\n            address.emplace_back(nodes.size() - 1);\n \
    \           _calc_val(nodes.size() - 1);\n        }\n        int32_t vert = _merge(address,\
    \ sizes, 0, address.size(), 0);\n        node_pos[pos] = nodes.size();\n     \
    \   nodes.emplace_back(Node(1, pos, vert));\n        nodes[vert].parent = nodes.size()\
    \ - 1;\n        _calc_val(nodes.size() - 1);\n        return nodes.size() - 1;\n\
    \    }\n    int32_t _merge(std::vector<int32_t> &address, std::vector<int32_t>\
    \ &sizes,\n                   int32_t lf, int32_t ri, bool pat) {\n        if\
    \ (lf + 1 == ri) return address[lf];\n        int32_t add = 0;\n        for (int32_t\
    \ i = lf; i < ri; i++) {\n            add += sizes[i];\n        }\n        int32_t\
    \ now = 0;\n        int32_t bef = add + 1;\n        for (int32_t i = lf; i < ri;\
    \ i++) {\n            now += sizes[i];\n            if (now > add - now) {\n \
    \               if (now + now - add > bef) i--;\n                int32_t left\
    \ = _merge(address, sizes, lf, i + 1, pat);\n                int32_t right = _merge(address,\
    \ sizes, i + 1, ri, pat);\n                nodes.emplace_back(Node(pat, -1, left,\
    \ right));\n                nodes[left].parent = nodes.size() - 1;\n         \
    \       nodes[right].parent = nodes.size() - 1;\n                _calc_val(nodes.size()\
    \ - 1);\n                return nodes.size() - 1;\n            }\n           \
    \ bef = add - now - now;\n        }\n        assert(false);\n    }\n    void _calc_val(int32_t\
    \ pos) {\n        if (nodes[pos].is_path) {\n            if ((nodes[pos].left\
    \ == -1) && (nodes[pos].right == -1)) {\n                nodes[pos].path_val =\
    \ M::vertex(nodes[pos].pos);\n            } else if ((nodes[pos].left != -1) &&\
    \ (nodes[pos].right != -1)) {\n                nodes[pos].path_val =\n       \
    \             M::compress(nodes[nodes[pos].left].path_val,\n                 \
    \               nodes[nodes[pos].right].path_val);\n            } else {\n   \
    \             nodes[pos].path_val = M::add_vertex(\n                    nodes[nodes[pos].left].point_val,\
    \ nodes[pos].pos);\n            }\n        } else {\n            if ((nodes[pos].left\
    \ != -1) && (nodes[pos].right != -1)) {\n                nodes[pos].point_val\
    \ =\n                    M::rake(nodes[nodes[pos].left].point_val,\n         \
    \                   nodes[nodes[pos].right].point_val);\n            } else {\n\
    \                nodes[pos].point_val =\n                    M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    void build(int32_t root) {\n        std::vector<int32_t>\
    \ vert(sz);\n        std::vector<int32_t> tree_sz(sz, -1);\n        vert[0] =\
    \ root;\n        tree_sz[root] = 0;\n        int32_t cnt = 1;\n        for (int32_t\
    \ i = 0; i < sz; i++) {\n            for (int32_t j : tree[vert[i]]) {\n     \
    \           if (tree_sz[j]) {\n                    tree_sz[j] = 0;\n         \
    \           vert[cnt] = j;\n                    cnt++;\n                }\n  \
    \          }\n        }\n        for (int32_t i = sz - 1; i >= 0; i--) {\n   \
    \         int32_t parent = 0;\n            for (int32_t j : tree[vert[i]]) {\n\
    \                if (tree_sz[j] == 0) {\n                    parent = -parent\
    \ - 1;\n                }\n                if (parent >= 0) parent++;\n      \
    \          tree_sz[vert[i]] += tree_sz[j];\n            }\n            if (parent\
    \ < 0) {\n                std::swap(tree[vert[i]][-parent - 1], tree[vert[i]].back());\n\
    \                tree[vert[i]].pop_back();\n            }\n            tree_sz[vert[i]]++;\n\
    \        }\n        rt = _path_cluster(root, tree_sz);\n    }\n    path root_value()\
    \ { return nodes[rt].path_val; }\n    void calc(int32_t pos) {\n        int32_t\
    \ change = node_pos[pos];\n        while (nodes[change].parent != -1) {\n    \
    \        _calc_val(change);\n            change = nodes[change].parent;\n    \
    \    }\n        _calc_val(change);\n    }\n    size_t size() { return sz; }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Tree/StaticTopTree.hpp
  requiredBy: []
  timestamp: '2024-05-08 20:46:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-new/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Tree/StaticTopTree.hpp
layout: document
title: Static Top Tree
---

## 関数の設定
```cpp
struct M{
    using point;
    using path;

    static path vertex(int v){
    }

    static path compress(path p,path c){
    }

    static path add_vertex(point t,int v){
    }

    static point rake(point x,point y){
    }

    static point add_edge(path t){
    }
};
```
* `point`: Point Clusterに載せるデータの型です。
* `path`: Path Clusterに載せるデータの型です。
* `path vertex(int v)`: 頂点 `v` のみのPath Clusterを作成する関数です。
* `path compress(path p,path c)`: Path Cluster `p` と `c` をマージする関数です。`p` が根に近い方です。
* `point add_vertex(point t,int v)`: Point Cluster `t` に頂点 `v` を追加したPath Clusterを返す関数です。
* `point rake(point x,point y)`: Point Cluster `x` と `y` をマージする関数です。
* `point add_edge(path t)`: Path Cluster `t` に辺を追加してPoint Clusterにする関数です。