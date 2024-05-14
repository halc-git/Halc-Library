---
title: Lazy Segment Tree
documentation_of: ../../DataStructure/LazySegmentTree.hpp
---

## 関数の設定
```cpp
struct M {
    using T;
    using F;
    static T op(T x, T y) {}
    static inline T e;
    static T mapp(F f, T x) {}
    static F comp(F f, F g) {}
    static inline F id;
};
```
* `T`: モノイドの型です。
* `F`: 遅延の型です。
* `T op(T x,T y)`: 演算です。モノイドであることを要求します。
* `T e`: 単位元です。
* `T mapp(F f,T x)`: 要素に遅延を伝える演算です。
* `F comp(F f,F g)`: 遅延を合成する演算です。`f`が新しい方であることを意識するとよいかもしれません。
* `F id`: 遅延の単位元です。