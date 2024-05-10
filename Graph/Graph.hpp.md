---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: Tree/StaticTopTree.hpp
    title: Static Top Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':x:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Graph.hpp\"\n#include <cstdint>\n#include <vector>\n\
    template <class T = int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n\
    \    int32_t idx;\n    Edge() = default;\n    Edge(int32_t from, int32_t to, T\
    \ cost = 1, int32_t idx = -1)\n        : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n    operator int() { return to; }\n};\ntemplate <class T = int32_t>\nstruct\
    \ Graph {\n    std::vector<std::vector<Edge<T>>> gr;\n    int32_t eds = 0;\n \
    \   Graph() = default;\n    Graph(int32_t n) { gr.resize(n); }\n    void add_edge(int32_t\
    \ from, int32_t to, T cost = 1, bool directed = false) {\n        gr[from].emplace_back(from,\
    \ to, cost, eds);\n        if (!directed) {\n            eds++;\n            gr[to].emplace_back(to,\
    \ from, cost, eds);\n        }\n        eds++;\n    }\n    void add_directed_edge(int32_t\
    \ from, int32_t to, T cost = 1) {\n        gr[from].emplace_back(from, to, cost,\
    \ eds);\n        eds++;\n    }\n    inline std::vector<Edge<T>> &operator[](const\
    \ int32_t &p) { return gr[p]; }\n    int32_t size() { return gr.size(); }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\ntemplate <class T =\
    \ int32_t>\nstruct Edge {\n    int32_t from, to;\n    T cost;\n    int32_t idx;\n\
    \    Edge() = default;\n    Edge(int32_t from, int32_t to, T cost = 1, int32_t\
    \ idx = -1)\n        : from(from), to(to), cost(cost), idx(idx) {}\n    operator\
    \ int() { return to; }\n};\ntemplate <class T = int32_t>\nstruct Graph {\n   \
    \ std::vector<std::vector<Edge<T>>> gr;\n    int32_t eds = 0;\n    Graph() = default;\n\
    \    Graph(int32_t n) { gr.resize(n); }\n    void add_edge(int32_t from, int32_t\
    \ to, T cost = 1, bool directed = false) {\n        gr[from].emplace_back(from,\
    \ to, cost, eds);\n        if (!directed) {\n            eds++;\n            gr[to].emplace_back(to,\
    \ from, cost, eds);\n        }\n        eds++;\n    }\n    void add_directed_edge(int32_t\
    \ from, int32_t to, T cost = 1) {\n        gr[from].emplace_back(from, to, cost,\
    \ eds);\n        eds++;\n    }\n    inline std::vector<Edge<T>> &operator[](const\
    \ int32_t &p) { return gr[p]; }\n    int32_t size() { return gr.size(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Graph.hpp
  requiredBy:
  - Tree/StaticTopTree.hpp
  timestamp: '2024-05-10 21:48:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Graph/Graph.hpp
layout: document
redirect_from:
- /library/Graph/Graph.hpp
- /library/Graph/Graph.hpp.html
title: Graph/Graph.hpp
---
