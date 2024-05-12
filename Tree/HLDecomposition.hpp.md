---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Graph.hpp
    title: Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/vertex_set_path_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
    title: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/HLDecomposition.hpp\"\n#include <cstdint>\n#include\
    \ <stack>\n#include <vector>\n\n#line 4 \"Graph/Graph.hpp\"\ntemplate <class T\
    \ = int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n\
    \    Edge() = default;\n    Edge(int32_t from, int32_t to, T cost = 1, int32_t\
    \ idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int32_t() { return to; }\n    void reverse() { std::swap(from, to); }\n};\n\
    template <class T = int32_t>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>>\
    \ gr;\n    int32_t eds = 0;\n    Graph() = default;\n    Graph(int32_t n) { gr.resize(n);\
    \ }\n    void add_edge(int32_t from, int32_t to, T cost = 1, bool directed = false)\
    \ {\n        gr[from].emplace_back(from, to, cost, eds);\n        if (!directed)\
    \ {\n            gr[to].emplace_back(to, from, cost, eds);\n        }\n      \
    \  eds++;\n    }\n    void add_directed_edge(int32_t from, int32_t to, T cost\
    \ = 1) {\n        gr[from].emplace_back(from, to, cost, eds);\n        eds++;\n\
    \    }\n    inline std::vector<Edge<T>> &operator[](const int32_t &p) { return\
    \ gr[p]; }\n    int32_t size() { return gr.size(); }\n};\ntemplate <class T>\n\
    Graph<T> reverse_edges(Graph<T> &gr) {\n    Graph<T> ret(gr.size());\n    for\
    \ (int32_t i = 0; i < gr.size(); i++) {\n        for (Edge<T> j : gr[i]) {\n \
    \           ret[j].emplace_back(j);\n            ret[j].back().reverse();\n  \
    \      }\n    }\n    return ret;\n}\n#line 7 \"Tree/HLDecomposition.hpp\"\nstruct\
    \ HLDecomposition {\n    struct Segment {\n        int32_t lf, ri;\n        bool\
    \ rev;\n    };\n    int32_t sz;\n    std::vector<int32_t> tree_sz;\n    std::vector<int32_t>\
    \ depth;\n    std::vector<int32_t> order;\n    std::vector<int32_t> path_roots;\n\
    \    std::vector<int32_t> parent;\n    std::vector<int32_t> out;\n    template\
    \ <class T>\n    void _build(int32_t pos, Graph<T> &tree) {\n        order[pos]\
    \ = sz;\n        sz++;\n        int32_t mx = -1, mp = -1;\n        for (int32_t\
    \ i : tree[pos]) {\n            if (i == parent[pos]) continue;\n            if\
    \ (mx < tree_sz[i]) {\n                mx = tree_sz[i];\n                mp =\
    \ i;\n            }\n        }\n        if (mx == -1) {\n            out[pos]\
    \ = sz;\n            return;\n        }\n        path_roots[mp] = path_roots[pos];\n\
    \        _build(mp, tree);\n        for (int32_t i : tree[pos]) {\n          \
    \  if (i == parent[pos]) continue;\n            if (i == mp) continue;\n     \
    \       path_roots[i] = i;\n            _build(i, tree);\n        }\n        out[pos]\
    \ = sz;\n    }\n    template <class T>\n    int32_t _calc_sz(int32_t pos, Graph<T>\
    \ &tree) {\n        if (tree_sz[pos] != -1) return tree_sz[pos];\n        tree_sz[pos]\
    \ = 1;\n        for (int32_t i : tree[pos]) {\n            if (parent[pos] !=\
    \ i) {\n                parent[i] = pos;\n                depth[i] = depth[pos]\
    \ + 1;\n                tree_sz[pos] += _calc_sz(i, tree);\n            }\n  \
    \      }\n        return tree_sz[pos];\n    }\n    template <class T>\n    HLDecomposition(Graph<T>\
    \ &tree, int32_t root = 0) {\n        sz = tree.size();\n        tree_sz.resize(sz,\
    \ -1);\n        depth.resize(sz, -1);\n        parent.resize(sz, -1);\n      \
    \  depth[root] = 0;\n        _calc_sz(root, tree);\n        order.resize(sz, -1);\n\
    \        out.resize(sz, -1);\n        path_roots.resize(sz, -1);\n        sz =\
    \ 0;\n        path_roots[root] = root;\n        _build(root, tree);\n    }\n \
    \   int32_t operator[](int32_t p) { return order[p]; }\n    Segment subtree(int32_t\
    \ pos) { return {order[pos], out[pos], false}; }\n    std::vector<Segment> path(int32_t\
    \ s, int32_t t) {\n        std::vector<Segment> ret;\n        std::stack<Segment>\
    \ right;\n        while (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]]\
    \ > depth[path_roots[t]]) {\n                ret.emplace_back(\n             \
    \       Segment{order[path_roots[s]], order[s] + 1, true});\n                s\
    \ = parent[path_roots[s]];\n            } else {\n                right.push({order[path_roots[t]],\
    \ order[t] + 1, false});\n                t = parent[path_roots[t]];\n       \
    \     }\n        }\n        if (depth[s] < depth[t]) {\n            ret.emplace_back(Segment{order[s],\
    \ order[t] + 1, false});\n        } else {\n            ret.emplace_back(Segment{order[t],\
    \ order[s] + 1, true});\n        }\n        while (!right.empty()) {\n       \
    \     ret.push_back(right.top());\n            right.pop();\n        }\n     \
    \   return ret;\n    }\n    int32_t lca(int32_t s, int32_t t) {\n        while\
    \ (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]] > depth[path_roots[t]])\
    \ {\n                s = parent[path_roots[s]];\n            } else {\n      \
    \          t = parent[path_roots[t]];\n            }\n        }\n        if (depth[s]\
    \ < depth[t]) return s;\n        return t;\n    }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <stack>\n#include <vector>\n\n\
    #include \"../Graph/Graph.hpp\"\nstruct HLDecomposition {\n    struct Segment\
    \ {\n        int32_t lf, ri;\n        bool rev;\n    };\n    int32_t sz;\n   \
    \ std::vector<int32_t> tree_sz;\n    std::vector<int32_t> depth;\n    std::vector<int32_t>\
    \ order;\n    std::vector<int32_t> path_roots;\n    std::vector<int32_t> parent;\n\
    \    std::vector<int32_t> out;\n    template <class T>\n    void _build(int32_t\
    \ pos, Graph<T> &tree) {\n        order[pos] = sz;\n        sz++;\n        int32_t\
    \ mx = -1, mp = -1;\n        for (int32_t i : tree[pos]) {\n            if (i\
    \ == parent[pos]) continue;\n            if (mx < tree_sz[i]) {\n            \
    \    mx = tree_sz[i];\n                mp = i;\n            }\n        }\n   \
    \     if (mx == -1) {\n            out[pos] = sz;\n            return;\n     \
    \   }\n        path_roots[mp] = path_roots[pos];\n        _build(mp, tree);\n\
    \        for (int32_t i : tree[pos]) {\n            if (i == parent[pos]) continue;\n\
    \            if (i == mp) continue;\n            path_roots[i] = i;\n        \
    \    _build(i, tree);\n        }\n        out[pos] = sz;\n    }\n    template\
    \ <class T>\n    int32_t _calc_sz(int32_t pos, Graph<T> &tree) {\n        if (tree_sz[pos]\
    \ != -1) return tree_sz[pos];\n        tree_sz[pos] = 1;\n        for (int32_t\
    \ i : tree[pos]) {\n            if (parent[pos] != i) {\n                parent[i]\
    \ = pos;\n                depth[i] = depth[pos] + 1;\n                tree_sz[pos]\
    \ += _calc_sz(i, tree);\n            }\n        }\n        return tree_sz[pos];\n\
    \    }\n    template <class T>\n    HLDecomposition(Graph<T> &tree, int32_t root\
    \ = 0) {\n        sz = tree.size();\n        tree_sz.resize(sz, -1);\n       \
    \ depth.resize(sz, -1);\n        parent.resize(sz, -1);\n        depth[root] =\
    \ 0;\n        _calc_sz(root, tree);\n        order.resize(sz, -1);\n        out.resize(sz,\
    \ -1);\n        path_roots.resize(sz, -1);\n        sz = 0;\n        path_roots[root]\
    \ = root;\n        _build(root, tree);\n    }\n    int32_t operator[](int32_t\
    \ p) { return order[p]; }\n    Segment subtree(int32_t pos) { return {order[pos],\
    \ out[pos], false}; }\n    std::vector<Segment> path(int32_t s, int32_t t) {\n\
    \        std::vector<Segment> ret;\n        std::stack<Segment> right;\n     \
    \   while (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]]\
    \ > depth[path_roots[t]]) {\n                ret.emplace_back(\n             \
    \       Segment{order[path_roots[s]], order[s] + 1, true});\n                s\
    \ = parent[path_roots[s]];\n            } else {\n                right.push({order[path_roots[t]],\
    \ order[t] + 1, false});\n                t = parent[path_roots[t]];\n       \
    \     }\n        }\n        if (depth[s] < depth[t]) {\n            ret.emplace_back(Segment{order[s],\
    \ order[t] + 1, false});\n        } else {\n            ret.emplace_back(Segment{order[t],\
    \ order[s] + 1, true});\n        }\n        while (!right.empty()) {\n       \
    \     ret.push_back(right.top());\n            right.pop();\n        }\n     \
    \   return ret;\n    }\n    int32_t lca(int32_t s, int32_t t) {\n        while\
    \ (path_roots[s] != path_roots[t]) {\n            if (depth[path_roots[s]] > depth[path_roots[t]])\
    \ {\n                s = parent[path_roots[s]];\n            } else {\n      \
    \          t = parent[path_roots[t]];\n            }\n        }\n        if (depth[s]\
    \ < depth[t]) return s;\n        return t;\n    }\n};"
  dependsOn:
  - Graph/Graph.hpp
  isVerificationFile: false
  path: Tree/HLDecomposition.hpp
  requiredBy: []
  timestamp: '2024-05-12 19:57:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_set_path_composite.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
documentation_of: Tree/HLDecomposition.hpp
layout: document
redirect_from:
- /library/Tree/HLDecomposition.hpp
- /library/Tree/HLDecomposition.hpp.html
title: Tree/HLDecomposition.hpp
---
