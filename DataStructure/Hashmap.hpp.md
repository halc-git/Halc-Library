---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/Random.hpp
    title: Misc/Random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/verify-yosupo-datastructure/associative_array.test.cpp
    title: Verify/verify-yosupo-datastructure/associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393?locale=en
  bundledCode: "#line 2 \"DataStructure/Hashmap.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <random>\n\n#line 2 \"Misc/Random.hpp\"\n#include <chrono>\n#include\
    \ <cstdint>\ninline uint32_t pcg32_fast() {\n    static uint64_t state =\n   \
    \     (std::chrono::steady_clock::now().time_since_epoch().count() << 1) + 1;\n\
    \    uint64_t x = state;\n    uint8_t count = x >> 61;\n    state *= 0xf13283ad;\n\
    \    x ^= x >> 22;\n    return (uint32_t)(x >> (22 + count));\n}\ninline int32_t\
    \ randint(int32_t l, int32_t r) {\n    return l + (((int64_t)pcg32_fast() * (r\
    \ - l + 1)) >> 32);\n}\n#line 6 \"DataStructure/Hashmap.hpp\"\n// https://codeforces.com/blog/entry/62393?locale=en\n\
    struct custom_hash {\n    // http://xorshift.di.unimi.it/splitmix64.c\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n      \
    \  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n    uint64_t operator()(uint64_t x) const\
    \ {\n        std::mt19937_64 mt(pcg32_fast());\n        std::uniform_int_distribution<uint64_t>\
    \ rand(0, 1ULL << 63);\n        static const uint64_t FIXED_RANDOM = rand(mt);\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\ntemplate <typename Key,\
    \ typename Val>\nusing Hashmap = __gnu_pbds::gp_hash_table<Key, Val, custom_hash>;\n"
  code: "#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n#include <random>\n\
    \n#include \"../Misc/Random.hpp\"\n// https://codeforces.com/blog/entry/62393?locale=en\n\
    struct custom_hash {\n    // http://xorshift.di.unimi.it/splitmix64.c\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n      \
    \  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n    uint64_t operator()(uint64_t x) const\
    \ {\n        std::mt19937_64 mt(pcg32_fast());\n        std::uniform_int_distribution<uint64_t>\
    \ rand(0, 1ULL << 63);\n        static const uint64_t FIXED_RANDOM = rand(mt);\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\ntemplate <typename Key,\
    \ typename Val>\nusing Hashmap = __gnu_pbds::gp_hash_table<Key, Val, custom_hash>;\n"
  dependsOn:
  - Misc/Random.hpp
  isVerificationFile: false
  path: DataStructure/Hashmap.hpp
  requiredBy: []
  timestamp: '2024-05-09 15:56:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/verify-yosupo-datastructure/associative_array.test.cpp
documentation_of: DataStructure/Hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/Hashmap.hpp
- /library/DataStructure/Hashmap.hpp.html
title: DataStructure/Hashmap.hpp
---
