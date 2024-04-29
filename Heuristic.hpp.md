---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Hashmap.hpp
    title: DataStructure/Hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.hpp
    title: String/RollingHash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
    title: Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
    title: Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Heuristic.hpp\"\nusing namespace chrono;\nuint32_t pcg32_fast(){\n\
    \    static uint64_t state=(steady_clock::now().time_since_epoch().count()<<1)+1;\n\
    \    uint64_t x=state;\n    uint8_t count=x>>61;\n    state*=0xf13283ad;\n   \
    \ x^=x>>22;\n    return (uint32_t)(x>>(22+count));\n}\n\nint32_t randint(int32_t\
    \ l,int32_t r){\n    return l+(((int64_t)pcg32_fast()*(r-l+1))>>32);\n}\n\nauto\
    \ startTime=system_clock::now();\nint32_t getTime(){\n    return duration_cast<microseconds>(system_clock::now()-startTime).count();\n\
    }\n"
  code: "#pragma once\nusing namespace chrono;\nuint32_t pcg32_fast(){\n    static\
    \ uint64_t state=(steady_clock::now().time_since_epoch().count()<<1)+1;\n    uint64_t\
    \ x=state;\n    uint8_t count=x>>61;\n    state*=0xf13283ad;\n    x^=x>>22;\n\
    \    return (uint32_t)(x>>(22+count));\n}\n\nint32_t randint(int32_t l,int32_t\
    \ r){\n    return l+(((int64_t)pcg32_fast()*(r-l+1))>>32);\n}\n\nauto startTime=system_clock::now();\n\
    int32_t getTime(){\n    return duration_cast<microseconds>(system_clock::now()-startTime).count();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Heuristic.hpp
  requiredBy:
  - DataStructure/Hashmap.hpp
  - String/RollingHash.hpp
  timestamp: '2024-04-21 12:08:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-aoj-alds/alds1_14_b-rollinghash.test.cpp
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
  - Verify/verify-yosupo-string/zalgorithm-rollinghash.test.cpp
  - Verify/verify-yosupo-string/enumerate_palindromes-rollinghash.test.cpp
documentation_of: Heuristic.hpp
layout: document
redirect_from:
- /library/Heuristic.hpp
- /library/Heuristic.hpp.html
title: Heuristic.hpp
---
