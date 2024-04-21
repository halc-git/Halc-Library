---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2024-04-21 12:08:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heuristic.hpp
layout: document
redirect_from:
- /library/Heuristic.hpp
- /library/Heuristic.hpp.html
title: Heuristic.hpp
---
