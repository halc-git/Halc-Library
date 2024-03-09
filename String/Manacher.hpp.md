---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://snuke.hatenablog.com/entry/2014/12/02/235837
  bundledCode: "#line 2 \"String/Manacher.hpp\"\n//https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template<typename S>\nvector<int> manacher(S s,bool is_even=true){\n    int i=0,j=0,k;\n\
    \    int sz=(s.size()<<is_even)-is_even;\n    vector<int> ret(sz);\n    while(i<sz){\n\
    \        if(is_even){\n            while(i-j>=-1&&i+j<=sz&&(((i-j)&1)||s[(i-j)>>1]==s[(i+j)>>1]))j++;\n\
    \        }\n        else{\n            while(i-j>=0&&i+j<sz&&s[i-j]==s[i+j])j++;\n\
    \        }\n        ret[i]=j;\n        k=1;\n        while(i-k>=0&&k+ret[i-k]<j){ret[i+k]=ret[i-k];k++;}\n\
    \        i+=k;\n        j-=k;\n    }\n    for(int i=0; i<sz; i++){\n        if(is_even){\n\
    \            ret[i]--;\n        }\n        else{\n            ret[i]=(ret[i]<<1)-1;\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n//https://snuke.hatenablog.com/entry/2014/12/02/235837\ntemplate<typename\
    \ S>\nvector<int> manacher(S s,bool is_even=true){\n    int i=0,j=0,k;\n    int\
    \ sz=(s.size()<<is_even)-is_even;\n    vector<int> ret(sz);\n    while(i<sz){\n\
    \        if(is_even){\n            while(i-j>=-1&&i+j<=sz&&(((i-j)&1)||s[(i-j)>>1]==s[(i+j)>>1]))j++;\n\
    \        }\n        else{\n            while(i-j>=0&&i+j<sz&&s[i-j]==s[i+j])j++;\n\
    \        }\n        ret[i]=j;\n        k=1;\n        while(i-k>=0&&k+ret[i-k]<j){ret[i+k]=ret[i-k];k++;}\n\
    \        i+=k;\n        j-=k;\n    }\n    for(int i=0; i<sz; i++){\n        if(is_even){\n\
    \            ret[i]--;\n        }\n        else{\n            ret[i]=(ret[i]<<1)-1;\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Manacher.hpp
  requiredBy: []
  timestamp: '2024-03-09 19:50:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-string/enumerate_palindromes.test.cpp
documentation_of: String/Manacher.hpp
layout: document
redirect_from:
- /library/String/Manacher.hpp
- /library/String/Manacher.hpp.html
title: String/Manacher.hpp
---
