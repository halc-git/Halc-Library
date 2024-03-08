---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Verify/assosiative_array.cpp
    title: Verify/assosiative_array.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
    - https://codeforces.com/blog/entry/62393
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ DataStructure/HashTable.hpp: line 2: #pragma once found in a non-first line\n"
  code: "//https://codeforces.com/blog/entry/62393\n#pragma once\n#include<vector>\n\
    #include<stdint.h>\n#include<chrono>\n#include<string>\n//key\u304C\u6574\u6570\
    \u578B\u3068char\u306B\u3057\u304B\u5BFE\u5FDC\u3057\u3066\u306A\u3044\u306E\u3092\
    \u3069\u3046\u306B\u304B\u3057\u305F\u3044\nstruct custom_hash{\n    //http://xorshift.di.unimi.it/splitmix64.c\n\
    \    uint64_t splitmix64(uint64_t x){\n        x+=0x9e3779b97f4a7c15;\n      \
    \  x=(x^(x>>30))*0xbf58476d1ce4e5b9;\n        x=(x^(x>>27))*0x94d049bb133111eb;\n\
    \        return x^(x>>31);\n    }\n    uint64_t operator()(uint64_t x){\n    \
    \    static const uint64_t FIX_RANDOM=std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x+FIX_RANDOM);\n    }\n};\ntemplate<class key,class\
    \ val>\nstruct HashMap{\n    std::vector<key> keys;\n    std::vector<val> values;\n\
    \    std::vector<bool> flag;\n    val default_value;\n    uint32_t cap;\n    uint32_t\
    \ res;\n    size_t sz=0;\n    HashMap(uint32_t query_size=15){\n        cap=query_size;\n\
    \        cap|=cap>>1;cap|=cap>>2;cap|=cap>>4;cap|=cap>>8;cap|=cap>>16;\n     \
    \   cap++;\n        res=cap-(cap>>2);\n        keys.resize(cap);\n        values.resize(cap);\n\
    \        flag.resize(cap);\n    }\n    void resize(){\n        cap<<=1;\n    \
    \    res<<=1;\n        std::vector<key> new_keys(cap);\n        std::vector<val>\
    \ new_values(cap);\n        std::vector<bool> new_flag(cap);\n        for(int\
    \ i=0; i<(cap>>1); i++){\n            if(!flag[i])continue;\n            uint32_t\
    \ hash=custom_hash()(keys[i])&(cap-1);\n            while(new_flag[hash])hash=(hash+1)&(cap-1);;\n\
    \            new_keys[hash]=keys[i];\n            new_values[hash]=values[i];\n\
    \            new_flag[hash]=true;\n        }\n        keys=move(new_keys);\n \
    \       values=move(new_values);\n        flag=move(new_flag);\n    }\n    val&\
    \ operator[](const key& i){\n        uint32_t hash=custom_hash()(i)&(cap-1);\n\
    \        while(true){\n            if(!flag[hash]){\n                if(res<=sz)resize();\n\
    \                keys[hash]=i;\n                flag[hash]=true;\n           \
    \     values[hash]=default_value;\n                sz++;\n                return\
    \ values[hash];\n            }\n            if(keys[hash]==i)return values[hash];\n\
    \            hash=(hash+1)&(cap-1);\n        }\n    }\n    std::vector<std::pair<key,val>>\
    \ enumerate(){\n        std::vector<std::pair<key,val>> ret;\n        for(int\
    \ i=0; i<cap; i++){\n            if(flag[i]){\n                ret.emplace_back(keys[i],values[i]);\n\
    \            }\n        }\n        return ret;\n    }\n    size_t size(){return\
    \ sz;}\n    void set_default(const val& new_value){default_value=new_value;}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/HashTable.hpp
  requiredBy:
  - Verify/assosiative_array.cpp
  timestamp: '2024-03-08 10:49:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/HashTable.hpp
layout: document
redirect_from:
- /library/DataStructure/HashTable.hpp
- /library/DataStructure/HashTable.hpp.html
title: DataStructure/HashTable.hpp
---
