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
  bundledCode: "#line 2 \"String/Manacher.hpp\"\n#include <vector>\n// https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template <typename S>\nstd::vector<int32_t> manacher(S s, bool is_even = true)\
    \ {\n    int32_t i = 0, j = 0, k, sz = (s.size() << is_even) - is_even;\n    std::vector<int32_t>\
    \ ret(sz);\n    while (i < sz) {\n        if (is_even) {\n            while (i\
    \ - j >= -1 && i + j <= sz &&\n                   (((i - j) & 1) || s[(i - j)\
    \ >> 1] == s[(i + j) >> 1]))\n                j++;\n        } else {\n       \
    \     while (i - j >= 0 && i + j < sz && s[i - j] == s[i + j]) j++;\n        }\n\
    \        ret[i] = j;\n        k = 1;\n        while (i - k >= 0 && k + ret[i -\
    \ k] < j) {\n            ret[i + k] = ret[i - k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    for (int32_t i = 0; i < sz; i++)\
    \ {\n        if (is_even) {\n            ret[i]--;\n        } else {\n       \
    \     ret[i] = (ret[i] << 1) - 1;\n        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n// https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template <typename S>\nstd::vector<int32_t> manacher(S s, bool is_even = true)\
    \ {\n    int32_t i = 0, j = 0, k, sz = (s.size() << is_even) - is_even;\n    std::vector<int32_t>\
    \ ret(sz);\n    while (i < sz) {\n        if (is_even) {\n            while (i\
    \ - j >= -1 && i + j <= sz &&\n                   (((i - j) & 1) || s[(i - j)\
    \ >> 1] == s[(i + j) >> 1]))\n                j++;\n        } else {\n       \
    \     while (i - j >= 0 && i + j < sz && s[i - j] == s[i + j]) j++;\n        }\n\
    \        ret[i] = j;\n        k = 1;\n        while (i - k >= 0 && k + ret[i -\
    \ k] < j) {\n            ret[i + k] = ret[i - k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    for (int32_t i = 0; i < sz; i++)\
    \ {\n        if (is_even) {\n            ret[i]--;\n        } else {\n       \
    \     ret[i] = (ret[i] << 1) - 1;\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/Manacher.hpp
  requiredBy: []
  timestamp: '2024-05-08 20:46:35+09:00'
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
