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
  bundledCode: "#line 2 \"Misc/Compress.hpp\"\n#include<vector>\ntemplate<class T>\n\
    struct Compress{\n    std::vector<T> data;\n    void add(T x){\n        data.emplace_back(x);\n\
    \    }\n    void add(std::vector<T> x){\n        for(T i:x)add(i);\n    }\n  \
    \  void build(){\n        sort(data.begin(),data.end());\n        data.erase(unique(data.begin(),data.end()),data.end());\n\
    \    }\n    int32_t get(T x){\n        return std::lower_bound(data.begin(),data.end(),x)-data.begin();\n\
    \    }\n    inline int32_t operator()(T x){\n        return get(x);\n    }\n \
    \   T operator[](int32_t i){\n        return data[i];\n    }\n    size_t size(){\n\
    \        return data.size();\n    }\n};\n"
  code: "#pragma once\n#include<vector>\ntemplate<class T>\nstruct Compress{\n   \
    \ std::vector<T> data;\n    void add(T x){\n        data.emplace_back(x);\n  \
    \  }\n    void add(std::vector<T> x){\n        for(T i:x)add(i);\n    }\n    void\
    \ build(){\n        sort(data.begin(),data.end());\n        data.erase(unique(data.begin(),data.end()),data.end());\n\
    \    }\n    int32_t get(T x){\n        return std::lower_bound(data.begin(),data.end(),x)-data.begin();\n\
    \    }\n    inline int32_t operator()(T x){\n        return get(x);\n    }\n \
    \   T operator[](int32_t i){\n        return data[i];\n    }\n    size_t size(){\n\
    \        return data.size();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Compress.hpp
  requiredBy: []
  timestamp: '2024-05-01 20:27:09+09:00'
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
