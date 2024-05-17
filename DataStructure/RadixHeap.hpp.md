---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Verify/verify-aoj-grl/grl_1_a.cpp
    title: Verify/verify-aoj-grl/grl_1_a.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RadixHeap.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <bit>\n#include <cstdint>\n#include <vector>\ntemplate <class\
    \ Key, class Val>\nstruct RadixHeap {\n    static constexpr int32_t backet = sizeof(Key)\
    \ * 8 + 1;\n    std::array<std::vector<std::pair<Key, Val>>, backet> heap;\n \
    \   Key last = 0;\n    int32_t siz = 0;\n    inline int32_t bsr(uint64_t x) {\
    \ return 64 - std::countl_zero(x); }\n    void push(Key key, Val val) {\n    \
    \    siz++;\n        heap[bsr(key ^ last)].emplace_back(std::pair<Key, Val>(key,\
    \ val));\n    }\n    std::pair<Key, Val> pop() {\n        siz--;\n        if (heap[0].empty())\
    \ {\n            int32_t i = 1;\n            while (heap[i].empty()) i++;\n  \
    \          last = (*std::min_element(heap[i].begin(), heap[i].end())).first;\n\
    \            for (std::pair<Key, Val> x : heap[i]) {\n                heap[bsr(x.first\
    \ ^ last)].emplace_back(x);\n            }\n            heap[i].clear();\n   \
    \     }\n        std::pair<Key, Val> ret = heap[0].back();\n        heap[0].pop_back();\n\
    \        return ret;\n    }\n    bool empty() { return !siz; }\n    int32_t size()\
    \ { return siz; }\n};\n"
  code: "#include <algorithm>\n#include <array>\n#include <bit>\n#include <cstdint>\n\
    #include <vector>\ntemplate <class Key, class Val>\nstruct RadixHeap {\n    static\
    \ constexpr int32_t backet = sizeof(Key) * 8 + 1;\n    std::array<std::vector<std::pair<Key,\
    \ Val>>, backet> heap;\n    Key last = 0;\n    int32_t siz = 0;\n    inline int32_t\
    \ bsr(uint64_t x) { return 64 - std::countl_zero(x); }\n    void push(Key key,\
    \ Val val) {\n        siz++;\n        heap[bsr(key ^ last)].emplace_back(std::pair<Key,\
    \ Val>(key, val));\n    }\n    std::pair<Key, Val> pop() {\n        siz--;\n \
    \       if (heap[0].empty()) {\n            int32_t i = 1;\n            while\
    \ (heap[i].empty()) i++;\n            last = (*std::min_element(heap[i].begin(),\
    \ heap[i].end())).first;\n            for (std::pair<Key, Val> x : heap[i]) {\n\
    \                heap[bsr(x.first ^ last)].emplace_back(x);\n            }\n \
    \           heap[i].clear();\n        }\n        std::pair<Key, Val> ret = heap[0].back();\n\
    \        heap[0].pop_back();\n        return ret;\n    }\n    bool empty() { return\
    \ !siz; }\n    int32_t size() { return siz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RadixHeap.hpp
  requiredBy:
  - Verify/verify-aoj-grl/grl_1_a.cpp
  timestamp: '2024-05-17 17:51:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RadixHeap.hpp
layout: document
redirect_from:
- /library/DataStructure/RadixHeap.hpp
- /library/DataStructure/RadixHeap.hpp.html
title: DataStructure/RadixHeap.hpp
---
