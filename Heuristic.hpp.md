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
  bundledCode: "#line 1 \"Heuristic.hpp\"\nusing namespace chrono;\nunsigned int randxor(){\n\
    \    static uint32_t x=42;\n    x=x^(x<<13);x=x^(x>>15);x=x^(x<<17);\n    return\
    \ x;\n}\n\nint32_t randint(int32_t l,int32_t r){\n    return l+(((long long)randxor()*(r-l+1))>>32);\n\
    }\n\nauto startTime=system_clock::now();\nint32_t getTime(){\n    return duration_cast<microseconds>(system_clock::now()-startTime).count();\n\
    }\n"
  code: "using namespace chrono;\nunsigned int randxor(){\n    static uint32_t x=42;\n\
    \    x=x^(x<<13);x=x^(x>>15);x=x^(x<<17);\n    return x;\n}\n\nint32_t randint(int32_t\
    \ l,int32_t r){\n    return l+(((long long)randxor()*(r-l+1))>>32);\n}\n\nauto\
    \ startTime=system_clock::now();\nint32_t getTime(){\n    return duration_cast<microseconds>(system_clock::now()-startTime).count();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Heuristic.hpp
  requiredBy: []
  timestamp: '2024-04-14 16:50:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heuristic.hpp
layout: document
redirect_from:
- /library/Heuristic.hpp
- /library/Heuristic.hpp.html
title: Heuristic.hpp
---
