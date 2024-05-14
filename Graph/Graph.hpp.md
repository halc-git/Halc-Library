---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Tree/HLDecomposition.hpp
    title: Tree/HLDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/StaticTopTree.hpp
    title: Static Top Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj/2667.test.cpp
    title: Verify/verify-aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/399.test.cpp
    title: Verify/verify-yuki/399.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/650.test.cpp
    title: Verify/verify-yuki/650.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Graph.hpp\"\n#include <cstdint>\n#include <vector>\n\
    template <class T = int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n\
    \    int32_t idx;\n    Edge() = default;\n    Edge(int32_t from, int32_t to, T\
    \ cost = 1, int32_t idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int32_t() { return to; }\n    void reverse() { std::swap(from,\
    \ to); }\n};\ntemplate <class T = int32_t>\nstruct Graph {\n    std::vector<std::vector<Edge<T>>>\
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
    \      }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\ntemplate <class T =\
    \ int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n\
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
    \      }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Graph.hpp
  requiredBy:
  - Tree/StaticTopTree.hpp
  - Tree/HLDecomposition.hpp
  timestamp: '2024-05-12 19:57:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-aoj/2667.test.cpp
  - Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  - Verify/verify-yuki/399.test.cpp
  - Verify/verify-yuki/650.test.cpp
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_set_path_composite.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Graph/Graph.hpp
layout: document
redirect_from:
- /library/Graph/Graph.hpp
- /library/Graph/Graph.hpp.html
title: Graph/Graph.hpp
---
