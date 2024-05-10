---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/Graph.hpp
    title: Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/StaticTopTree.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <vector>\n\n#line 4 \"Graph/Graph.hpp\"\ntemplate <class T = int32_t>\n\
    struct Edge {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n    Edge()\
    \ = default;\n    Edge(int32_t from, int32_t to, T cost = 1, int32_t idx = -1)\n\
    \        : from(from), to(to), cost(cost), idx(idx) {}\n    operator int() { return\
    \ to; }\n};\ntemplate <class T = int32_t>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>>\
    \ gr;\n    int32_t eds = 0;\n    Graph() = default;\n    Graph(int32_t n) { gr.resize(n);\
    \ }\n    void add_edge(int32_t from, int32_t to, T cost = 1, bool directed = false)\
    \ {\n        gr[from].emplace_back(from, to, cost, eds);\n        if (!directed)\
    \ {\n            gr[to].emplace_back(to, from, cost, eds);\n        }\n      \
    \  eds++;\n    }\n    void add_directed_edge(int32_t from, int32_t to, T cost\
    \ = 1) {\n        gr[from].emplace_back(from, to, cost, eds);\n        eds++;\n\
    \    }\n    inline std::vector<Edge<T>> &operator[](const int32_t &p) { return\
    \ gr[p]; }\n    int32_t size() { return gr.size(); }\n};\n#line 7 \"Tree/StaticTopTree.hpp\"\
    \ntemplate <class M>\nstruct StaticTopTree {\n    using point = typename M::point;\n\
    \    using path = typename M::path;\n    struct Node {\n        bool is_path;\n\
    \        point point_val;\n        path path_val;\n        int32_t pos;\n    \
    \    int32_t left;\n        int32_t right;\n        int32_t parent;\n        Node(bool\
    \ pat, int32_t po = -1, int32_t lf = -1, int32_t ri = -1) {\n            is_path\
    \ = pat;\n            pos = po;\n            left = lf;\n            right = ri;\n\
    \            parent = -1;\n        }\n    };\n    int32_t sz;\n    std::vector<int32_t>\
    \ node_pos;\n    std::vector<Node> nodes;\n    int32_t rt;\n    template <class\
    \ T>\n    StaticTopTree(Graph<T> gr, int32_t root) {\n        sz = gr.size();\n\
    \        node_pos.resize(sz);\n        _build(root, gr);\n    }\n    template\
    \ <class T>\n    int32_t _path_cluster(int32_t pos, std::vector<int32_t> &tree_sz,\n\
    \                          Graph<T> &tree) {\n        if (tree[pos].empty()) {\n\
    \            node_pos[pos] = nodes.size();\n            nodes.emplace_back(Node(1,\
    \ pos));\n            _calc_val(nodes.size() - 1);\n            return nodes.size()\
    \ - 1;\n        }\n        std::vector<int32_t> address;\n        std::vector<int32_t>\
    \ sizes;\n        while (!tree[pos].empty()) {\n            int32_t max_size =\
    \ -1;\n            int32_t next_pos = -1;\n            for (int i = 0; i < tree[pos].size();\
    \ i++) {\n                if (tree_sz[tree[pos][i]] > max_size) {\n          \
    \          max_size = tree_sz[tree[pos][i]];\n                    next_pos = i;\n\
    \                }\n            }\n            std::swap(tree[pos][next_pos],\
    \ tree[pos].back());\n            next_pos = tree[pos].back();\n            tree[pos].pop_back();\n\
    \            tree_sz[pos] -= tree_sz[next_pos];\n            sizes.emplace_back(tree_sz[pos]);\n\
    \            address.emplace_back(_point_cluster(pos, tree_sz, tree));\n     \
    \       pos = next_pos;\n        }\n        address.emplace_back(_point_cluster(pos,\
    \ tree_sz, tree));\n        sizes.emplace_back(tree_sz[pos]);\n        return\
    \ _merge(address, sizes, 0, address.size(), 1);\n    }\n    template <class T>\n\
    \    int32_t _point_cluster(int32_t pos, std::vector<int32_t> &tree_sz,\n    \
    \                       Graph<T> &tree) {\n        if (tree[pos].empty()) {\n\
    \            node_pos[pos] = nodes.size();\n            nodes.emplace_back(Node(1,\
    \ pos));\n            _calc_val(nodes.size() - 1);\n            return nodes.size()\
    \ - 1;\n        }\n        std::vector<int32_t> address;\n        std::vector<int32_t>\
    \ sizes;\n        for (int32_t i : tree[pos]) {\n            sizes.emplace_back(tree_sz[i]);\n\
    \            int32_t vert = _path_cluster(i, tree_sz, tree);\n            nodes.emplace_back(Node(0,\
    \ -1, vert));\n            nodes[vert].parent = nodes.size() - 1;\n          \
    \  address.emplace_back(nodes.size() - 1);\n            _calc_val(nodes.size()\
    \ - 1);\n        }\n        int32_t vert = _merge(address, sizes, 0, address.size(),\
    \ 0);\n        node_pos[pos] = nodes.size();\n        nodes.emplace_back(Node(1,\
    \ pos, vert));\n        nodes[vert].parent = nodes.size() - 1;\n        _calc_val(nodes.size()\
    \ - 1);\n        return nodes.size() - 1;\n    }\n    int32_t _merge(std::vector<int32_t>\
    \ &address, std::vector<int32_t> &sizes,\n                   int32_t lf, int32_t\
    \ ri, bool pat) {\n        if (lf + 1 == ri) return address[lf];\n        int32_t\
    \ add = 0;\n        for (int32_t i = lf; i < ri; i++) {\n            add += sizes[i];\n\
    \        }\n        int32_t now = 0;\n        int32_t bef = add + 1;\n       \
    \ for (int32_t i = lf; i < ri; i++) {\n            now += sizes[i];\n        \
    \    if (now > add - now) {\n                if (now + now - add > bef) i--;\n\
    \                int32_t left = _merge(address, sizes, lf, i + 1, pat);\n    \
    \            int32_t right = _merge(address, sizes, i + 1, ri, pat);\n       \
    \         nodes.emplace_back(Node(pat, -1, left, right));\n                nodes[left].parent\
    \ = nodes.size() - 1;\n                nodes[right].parent = nodes.size() - 1;\n\
    \                _calc_val(nodes.size() - 1);\n                return nodes.size()\
    \ - 1;\n            }\n            bef = add - now - now;\n        }\n       \
    \ assert(false);\n    }\n    void _calc_val(int32_t pos) {\n        if (nodes[pos].is_path)\
    \ {\n            if ((nodes[pos].left == -1) && (nodes[pos].right == -1)) {\n\
    \                nodes[pos].path_val = M::vertex(nodes[pos].pos);\n          \
    \  } else if ((nodes[pos].left != -1) && (nodes[pos].right != -1)) {\n       \
    \         nodes[pos].path_val =\n                    M::compress(nodes[nodes[pos].left].path_val,\n\
    \                                nodes[nodes[pos].right].path_val);\n        \
    \    } else {\n                nodes[pos].path_val = M::add_vertex(\n        \
    \            nodes[nodes[pos].left].point_val, nodes[pos].pos);\n            }\n\
    \        } else {\n            if ((nodes[pos].left != -1) && (nodes[pos].right\
    \ != -1)) {\n                nodes[pos].point_val =\n                    M::rake(nodes[nodes[pos].left].point_val,\n\
    \                            nodes[nodes[pos].right].point_val);\n           \
    \ } else {\n                nodes[pos].point_val =\n                    M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    template <class T>\n    void _build(int32_t\
    \ root, Graph<T> &tree) {\n        std::vector<int32_t> vert(sz);\n        std::vector<int32_t>\
    \ tree_sz(sz, -1);\n        vert[0] = root;\n        tree_sz[root] = 0;\n    \
    \    int32_t cnt = 1;\n        for (int32_t i = 0; i < sz; i++) {\n          \
    \  for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j]) {\n    \
    \                tree_sz[j] = 0;\n                    vert[cnt] = j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for\
    \ (int32_t i = sz - 1; i >= 0; i--) {\n            int32_t parent = 0;\n     \
    \       for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j] == 0)\
    \ {\n                    parent = -parent - 1;\n                }\n          \
    \      if (parent >= 0) parent++;\n                tree_sz[vert[i]] += tree_sz[j];\n\
    \            }\n            if (parent < 0) {\n                std::swap(tree[vert[i]][-parent\
    \ - 1], tree[vert[i]].back());\n                tree[vert[i]].pop_back();\n  \
    \          }\n            tree_sz[vert[i]]++;\n        }\n        rt = _path_cluster(root,\
    \ tree_sz, tree);\n    }\n    path root_value() { return nodes[rt].path_val; }\n\
    \    void calc(int32_t pos) {\n        int32_t change = node_pos[pos];\n     \
    \   while (nodes[change].parent != -1) {\n            _calc_val(change);\n   \
    \         change = nodes[change].parent;\n        }\n        _calc_val(change);\n\
    \    }\n    int32_t size() { return sz; }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \n#include \"../Graph/Graph.hpp\"\ntemplate <class M>\nstruct StaticTopTree {\n\
    \    using point = typename M::point;\n    using path = typename M::path;\n  \
    \  struct Node {\n        bool is_path;\n        point point_val;\n        path\
    \ path_val;\n        int32_t pos;\n        int32_t left;\n        int32_t right;\n\
    \        int32_t parent;\n        Node(bool pat, int32_t po = -1, int32_t lf =\
    \ -1, int32_t ri = -1) {\n            is_path = pat;\n            pos = po;\n\
    \            left = lf;\n            right = ri;\n            parent = -1;\n \
    \       }\n    };\n    int32_t sz;\n    std::vector<int32_t> node_pos;\n    std::vector<Node>\
    \ nodes;\n    int32_t rt;\n    template <class T>\n    StaticTopTree(Graph<T>\
    \ gr, int32_t root) {\n        sz = gr.size();\n        node_pos.resize(sz);\n\
    \        _build(root, gr);\n    }\n    template <class T>\n    int32_t _path_cluster(int32_t\
    \ pos, std::vector<int32_t> &tree_sz,\n                          Graph<T> &tree)\
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
    \       address.emplace_back(_point_cluster(pos, tree_sz, tree));\n          \
    \  pos = next_pos;\n        }\n        address.emplace_back(_point_cluster(pos,\
    \ tree_sz, tree));\n        sizes.emplace_back(tree_sz[pos]);\n        return\
    \ _merge(address, sizes, 0, address.size(), 1);\n    }\n    template <class T>\n\
    \    int32_t _point_cluster(int32_t pos, std::vector<int32_t> &tree_sz,\n    \
    \                       Graph<T> &tree) {\n        if (tree[pos].empty()) {\n\
    \            node_pos[pos] = nodes.size();\n            nodes.emplace_back(Node(1,\
    \ pos));\n            _calc_val(nodes.size() - 1);\n            return nodes.size()\
    \ - 1;\n        }\n        std::vector<int32_t> address;\n        std::vector<int32_t>\
    \ sizes;\n        for (int32_t i : tree[pos]) {\n            sizes.emplace_back(tree_sz[i]);\n\
    \            int32_t vert = _path_cluster(i, tree_sz, tree);\n            nodes.emplace_back(Node(0,\
    \ -1, vert));\n            nodes[vert].parent = nodes.size() - 1;\n          \
    \  address.emplace_back(nodes.size() - 1);\n            _calc_val(nodes.size()\
    \ - 1);\n        }\n        int32_t vert = _merge(address, sizes, 0, address.size(),\
    \ 0);\n        node_pos[pos] = nodes.size();\n        nodes.emplace_back(Node(1,\
    \ pos, vert));\n        nodes[vert].parent = nodes.size() - 1;\n        _calc_val(nodes.size()\
    \ - 1);\n        return nodes.size() - 1;\n    }\n    int32_t _merge(std::vector<int32_t>\
    \ &address, std::vector<int32_t> &sizes,\n                   int32_t lf, int32_t\
    \ ri, bool pat) {\n        if (lf + 1 == ri) return address[lf];\n        int32_t\
    \ add = 0;\n        for (int32_t i = lf; i < ri; i++) {\n            add += sizes[i];\n\
    \        }\n        int32_t now = 0;\n        int32_t bef = add + 1;\n       \
    \ for (int32_t i = lf; i < ri; i++) {\n            now += sizes[i];\n        \
    \    if (now > add - now) {\n                if (now + now - add > bef) i--;\n\
    \                int32_t left = _merge(address, sizes, lf, i + 1, pat);\n    \
    \            int32_t right = _merge(address, sizes, i + 1, ri, pat);\n       \
    \         nodes.emplace_back(Node(pat, -1, left, right));\n                nodes[left].parent\
    \ = nodes.size() - 1;\n                nodes[right].parent = nodes.size() - 1;\n\
    \                _calc_val(nodes.size() - 1);\n                return nodes.size()\
    \ - 1;\n            }\n            bef = add - now - now;\n        }\n       \
    \ assert(false);\n    }\n    void _calc_val(int32_t pos) {\n        if (nodes[pos].is_path)\
    \ {\n            if ((nodes[pos].left == -1) && (nodes[pos].right == -1)) {\n\
    \                nodes[pos].path_val = M::vertex(nodes[pos].pos);\n          \
    \  } else if ((nodes[pos].left != -1) && (nodes[pos].right != -1)) {\n       \
    \         nodes[pos].path_val =\n                    M::compress(nodes[nodes[pos].left].path_val,\n\
    \                                nodes[nodes[pos].right].path_val);\n        \
    \    } else {\n                nodes[pos].path_val = M::add_vertex(\n        \
    \            nodes[nodes[pos].left].point_val, nodes[pos].pos);\n            }\n\
    \        } else {\n            if ((nodes[pos].left != -1) && (nodes[pos].right\
    \ != -1)) {\n                nodes[pos].point_val =\n                    M::rake(nodes[nodes[pos].left].point_val,\n\
    \                            nodes[nodes[pos].right].point_val);\n           \
    \ } else {\n                nodes[pos].point_val =\n                    M::add_edge(nodes[nodes[pos].left].path_val);\n\
    \            }\n        }\n    }\n    template <class T>\n    void _build(int32_t\
    \ root, Graph<T> &tree) {\n        std::vector<int32_t> vert(sz);\n        std::vector<int32_t>\
    \ tree_sz(sz, -1);\n        vert[0] = root;\n        tree_sz[root] = 0;\n    \
    \    int32_t cnt = 1;\n        for (int32_t i = 0; i < sz; i++) {\n          \
    \  for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j]) {\n    \
    \                tree_sz[j] = 0;\n                    vert[cnt] = j;\n       \
    \             cnt++;\n                }\n            }\n        }\n        for\
    \ (int32_t i = sz - 1; i >= 0; i--) {\n            int32_t parent = 0;\n     \
    \       for (int32_t j : tree[vert[i]]) {\n                if (tree_sz[j] == 0)\
    \ {\n                    parent = -parent - 1;\n                }\n          \
    \      if (parent >= 0) parent++;\n                tree_sz[vert[i]] += tree_sz[j];\n\
    \            }\n            if (parent < 0) {\n                std::swap(tree[vert[i]][-parent\
    \ - 1], tree[vert[i]].back());\n                tree[vert[i]].pop_back();\n  \
    \          }\n            tree_sz[vert[i]]++;\n        }\n        rt = _path_cluster(root,\
    \ tree_sz, tree);\n    }\n    path root_value() { return nodes[rt].path_val; }\n\
    \    void calc(int32_t pos) {\n        int32_t change = node_pos[pos];\n     \
    \   while (nodes[change].parent != -1) {\n            _calc_val(change);\n   \
    \         change = nodes[change].parent;\n        }\n        _calc_val(change);\n\
    \    }\n    int32_t size() { return sz; }\n};"
  dependsOn:
  - Graph/Graph.hpp
  isVerificationFile: false
  path: Tree/StaticTopTree.hpp
  requiredBy: []
  timestamp: '2024-05-10 22:25:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
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