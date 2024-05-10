---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
    title: Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Misc/Compress.hpp\"\n#include <cstdint>\n#include <vector>\n\
    template <class T>\nstruct Compress {\n    std::vector<T> data;\n    void add(T\
    \ x) { data.emplace_back(x); }\n    void add(std::vector<T> x) {\n        for\
    \ (T i : x) add(i);\n    }\n    void build() {\n        sort(data.begin(), data.end());\n\
    \        data.erase(unique(data.begin(), data.end()), data.end());\n    }\n  \
    \  int32_t get(T x) {\n        return std::lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n    }\n    inline int32_t operator()(T x) { return get(x);\
    \ }\n    T operator[](int32_t i) { return data[i]; }\n    int32_t size() { return\
    \ data.size(); }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\ntemplate <class T>\n\
    struct Compress {\n    std::vector<T> data;\n    void add(T x) { data.emplace_back(x);\
    \ }\n    void add(std::vector<T> x) {\n        for (T i : x) add(i);\n    }\n\
    \    void build() {\n        sort(data.begin(), data.end());\n        data.erase(unique(data.begin(),\
    \ data.end()), data.end());\n    }\n    int32_t get(T x) {\n        return std::lower_bound(data.begin(),\
    \ data.end(), x) - data.begin();\n    }\n    inline int32_t operator()(T x) {\
    \ return get(x); }\n    T operator[](int32_t i) { return data[i]; }\n    int32_t\
    \ size() { return data.size(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Compress.hpp
  requiredBy: []
  timestamp: '2024-05-10 16:22:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/static_range_inversions_query-mo.test.cpp
documentation_of: Misc/Compress.hpp
layout: document
redirect_from:
- /library/Misc/Compress.hpp
- /library/Misc/Compress.hpp.html
title: Misc/Compress.hpp
---
