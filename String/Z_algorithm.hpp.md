---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://snuke.hatenablog.com/entry/2014/12/03/214243
  bundledCode: "#line 2 \"String/Z_algorithm.hpp\"\n#include<vector>\n//https://snuke.hatenablog.com/entry/2014/12/03/214243\n\
    template<typename S>\nstd::vector<int32_t> z_algorithm(S s){\n    int32_t sz=s.size(),i=1,j=0,k;\n\
    \    std::vector<int32_t> ret(sz);\n    ret[0]=sz;\n    while(i<sz){\n       \
    \ while(i+j<sz&&s[j]==s[i+j])j++;\n        ret[i]=j;\n        if(j==0){i++;continue;}\n\
    \        k=1;\n        while(i+k<sz&&k+ret[k]<j){\n            ret[i+k]=ret[k];\n\
    \            k++;\n        }\n        i+=k;\n        j-=k;\n    }\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n#include<vector>\n//https://snuke.hatenablog.com/entry/2014/12/03/214243\n\
    template<typename S>\nstd::vector<int32_t> z_algorithm(S s){\n    int32_t sz=s.size(),i=1,j=0,k;\n\
    \    std::vector<int32_t> ret(sz);\n    ret[0]=sz;\n    while(i<sz){\n       \
    \ while(i+j<sz&&s[j]==s[i+j])j++;\n        ret[i]=j;\n        if(j==0){i++;continue;}\n\
    \        k=1;\n        while(i+k<sz&&k+ret[k]<j){\n            ret[i+k]=ret[k];\n\
    \            k++;\n        }\n        i+=k;\n        j-=k;\n    }\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-05-01 17:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-string/zalgorithm.test.cpp
documentation_of: String/Z_algorithm.hpp
layout: document
redirect_from:
- /library/String/Z_algorithm.hpp
- /library/String/Z_algorithm.hpp.html
title: String/Z_algorithm.hpp
---
