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
  bundledCode: '#line 1 "Template/Macro.hpp"

    #define _overload3(_1, _2, _3, name, ...) name

    #define _overload4(_1, _2, _3, _4, name, ...) name

    #define _rep1(i, n) for (ll i = 0; i < (n); i++)

    #define _rep2(i, a, b) for (ll i = (a); i < (b); i++)

    #define _rep3(i, a, b, c) for (ll i = (a); i < (b); i += (c))

    #define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

    #define _rrep1(i, n) for (ll i = (n); i-- > 0;)

    #define _rrep2(i, a, b) for (ll i = (b); i-- > (a);)

    #define rrep(...) _overload3(__VA_ARGS__, _rrep2, _rrep1)(__VA_ARGS__)

    #define each(i, ...) for (auto&& i : __VA_ARGS__)

    #define all(i) std::begin(i), std::end(i)

    #define rall(i) std::rbegin(i), std::rend(i)

    #define len(x) ((int)(x).size())

    #define fi first

    #define se second

    #define uniq(x) x.erase(unique(all(x)), std::end(x))

    #define vec(type, name, ...) vector<type> name(__VA_ARGS__);

    #define vv(type, name, h, ...) std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__));

    #define INT(...) int __VA_ARGS__; in(__VA_ARGS__)

    #define LL(...) long long __VA_ARGS__; in(__VA_ARGS__)

    #define ULL(...) unsigned long long __VA_ARGS__; in(__VA_ARGS__)

    #define STR(...) std::string __VA_ARGS__; in(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)

    #define LD(...) long double __VA_ARGS__; in(__VA_ARGS__)

    #define VEC(type, name, size) std::vector<type> name(size); in(name)

    #define VV(type, name, h, w) std::vector<std::vector<type>> name(h, std::vector<type>(w));
    in(name)

    '
  code: '#define _overload3(_1, _2, _3, name, ...) name

    #define _overload4(_1, _2, _3, _4, name, ...) name

    #define _rep1(i, n) for (ll i = 0; i < (n); i++)

    #define _rep2(i, a, b) for (ll i = (a); i < (b); i++)

    #define _rep3(i, a, b, c) for (ll i = (a); i < (b); i += (c))

    #define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

    #define _rrep1(i, n) for (ll i = (n); i-- > 0;)

    #define _rrep2(i, a, b) for (ll i = (b); i-- > (a);)

    #define rrep(...) _overload3(__VA_ARGS__, _rrep2, _rrep1)(__VA_ARGS__)

    #define each(i, ...) for (auto&& i : __VA_ARGS__)

    #define all(i) std::begin(i), std::end(i)

    #define rall(i) std::rbegin(i), std::rend(i)

    #define len(x) ((int)(x).size())

    #define fi first

    #define se second

    #define uniq(x) x.erase(unique(all(x)), std::end(x))

    #define vec(type, name, ...) vector<type> name(__VA_ARGS__);

    #define vv(type, name, h, ...) std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__));

    #define INT(...) int __VA_ARGS__; in(__VA_ARGS__)

    #define LL(...) long long __VA_ARGS__; in(__VA_ARGS__)

    #define ULL(...) unsigned long long __VA_ARGS__; in(__VA_ARGS__)

    #define STR(...) std::string __VA_ARGS__; in(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)

    #define LD(...) long double __VA_ARGS__; in(__VA_ARGS__)

    #define VEC(type, name, size) std::vector<type> name(size); in(name)

    #define VV(type, name, h, w) std::vector<std::vector<type>> name(h, std::vector<type>(w));
    in(name)'
  dependsOn: []
  isVerificationFile: false
  path: Template/Macro.hpp
  requiredBy:
  - Template/Template.hpp
  timestamp: '2024-05-12 20:06:10+09:00'
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
documentation_of: Template/Macro.hpp
layout: document
redirect_from:
- /library/Template/Macro.hpp
- /library/Template/Macro.hpp.html
title: Template/Macro.hpp
---
