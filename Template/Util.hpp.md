---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
    title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
    title: Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
    title: Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
    title: Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
    title: Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/unionfind.test.cpp
    title: Verify/verify-yosupo-datastructure/unionfind.test.cpp
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
    path: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
    title: Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
    title: Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
    title: Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/1092.test.cpp
    title: Verify/verify-yuki/1092.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/117.test.cpp
    title: Verify/verify-yuki/117.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/2338.test.cpp
    title: Verify/verify-yuki/2338.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yuki/901.test.cpp
    title: Verify/verify-yuki/901.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Util.hpp\"\n#include <array>\n#include <climits>\n\
    #include <functional>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    using ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    using uint = unsigned int;\nusing pll = std::pair<ll, ll>;\nusing pii = std::pair<int,\
    \ int>;\nusing vl = std::vector<ll>;\nusing vvl = std::vector<std::vector<ll>>;\n\
    using pdd = std::pair<ld, ld>;\nusing tuplis = std::array<ll, 3>;\ntemplate <class\
    \ T>\nusing pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\nconstexpr\
    \ ll LINF = (1LL << 62) - (1LL << 31);\nconstexpr int32_t INF = INT_MAX >> 1;\n\
    constexpr ll MINF = 1LL << 40;\nconstexpr ld DINF = std::numeric_limits<ld>::infinity();\n\
    constexpr int32_t MODD = 1000000007;\nconstexpr int32_t MOD = 998244353;\nconstexpr\
    \ ld EPS = 1e-9;\nconstexpr ld PI = 3.1415926535897932;\nconst ll four[] = {0,\
    \ 1, 0, -1, 0};\nconst ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};\ntemplate\
    \ <class T>\nbool chmin(T &a, const T &b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    } else\n        return false;\n}\ntemplate <class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    } else\n        return false;\n}\ntemplate <class T>\nll sum(const\
    \ T &a) {\n    return accumulate(std::begin(a), std::end(a), 0LL);\n}\ntemplate\
    \ <class T>\nld dsum(const T &a) {\n    return accumulate(std::begin(a), std::end(a),\
    \ 0.0L);\n}\ntemplate <class T>\nauto min(const T &a) {\n    return *min_element(std::begin(a),\
    \ std::end(a));\n}\ntemplate <class T>\nauto max(const T &a) {\n    return *max_element(std::begin(a),\
    \ std::end(a));\n}\n"
  code: "#pragma once\n#include <array>\n#include <climits>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <vector>\nusing ll = long long;\n\
    using ld = long double;\nusing ull = unsigned long long;\nusing uint = unsigned\
    \ int;\nusing pll = std::pair<ll, ll>;\nusing pii = std::pair<int, int>;\nusing\
    \ vl = std::vector<ll>;\nusing vvl = std::vector<std::vector<ll>>;\nusing pdd\
    \ = std::pair<ld, ld>;\nusing tuplis = std::array<ll, 3>;\ntemplate <class T>\n\
    using pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;\nconstexpr\
    \ ll LINF = (1LL << 62) - (1LL << 31);\nconstexpr int32_t INF = INT_MAX >> 1;\n\
    constexpr ll MINF = 1LL << 40;\nconstexpr ld DINF = std::numeric_limits<ld>::infinity();\n\
    constexpr int32_t MODD = 1000000007;\nconstexpr int32_t MOD = 998244353;\nconstexpr\
    \ ld EPS = 1e-9;\nconstexpr ld PI = 3.1415926535897932;\nconst ll four[] = {0,\
    \ 1, 0, -1, 0};\nconst ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};\ntemplate\
    \ <class T>\nbool chmin(T &a, const T &b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    } else\n        return false;\n}\ntemplate <class T>\n\
    bool chmax(T &a, const T &b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    } else\n        return false;\n}\ntemplate <class T>\nll sum(const\
    \ T &a) {\n    return accumulate(std::begin(a), std::end(a), 0LL);\n}\ntemplate\
    \ <class T>\nld dsum(const T &a) {\n    return accumulate(std::begin(a), std::end(a),\
    \ 0.0L);\n}\ntemplate <class T>\nauto min(const T &a) {\n    return *min_element(std::begin(a),\
    \ std::end(a));\n}\ntemplate <class T>\nauto max(const T &a) {\n    return *max_element(std::begin(a),\
    \ std::end(a));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Template/Util.hpp
  requiredBy:
  - Template/Template.hpp
  timestamp: '2024-05-14 08:12:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-sample/aplusb-test_timer.test.cpp
  - Verify/verify-yosupo-math/binomial_coefficient_prime_mod.test.cpp
  - Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - Verify/verify-yosupo-tree/lca-hldecomposition.test.cpp
  - Verify/verify-yuki/1092.test.cpp
  - Verify/verify-yuki/117.test.cpp
  - Verify/verify-yuki/2338.test.cpp
  - Verify/verify-yuki/901.test.cpp
  - Verify/verify-yosupo-datastructure/range_affine_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_range_composite.test.cpp
  - Verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-segment_tree.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_set_path_composite.test.cpp
  - Verify/verify-yosupo-datastructure/unionfind.test.cpp
  - Verify/verify-yosupo-datastructure/predecessor_problem-fenwick_tree.test.cpp
  - Verify/verify-yosupo-datastructure/deque_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_sum-disjoint_sparse_table.test.cpp
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_subtree_sum.test.cpp
  - Verify/verify-yosupo-datastructure/vertex_add_path_sum.test.cpp
  - Verify/verify-yosupo-datastructure/staticrmq.test.cpp
  - Verify/verify-yosupo-datastructure/queue_operate_all_composite.test.cpp
  - Verify/verify-yosupo-datastructure/point_set_tree_path_composite_sum_fixed_root.test.cpp
  - Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - Verify/verify-yosupo-string/zalgorithm.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
documentation_of: Template/Util.hpp
layout: document
redirect_from:
- /library/Template/Util.hpp
- /library/Template/Util.hpp.html
title: Template/Util.hpp
---
