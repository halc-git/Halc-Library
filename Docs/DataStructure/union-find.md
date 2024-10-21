---
title: Union Find
documentation_of: ../../DataStructure/UnionFind.hpp
---

## 関数の設定
```cpp
struct M {
    using T;
    static T op(T x, T y) {}
    static inline T e;
};
```
* `T`: 演算の型です。
* `T op(T x,T y)`: 演算です。単位元の存在を要求します。
* `T e`: 単位元です。

`UnionFind` は `MonoidUnionFind<M>` に意味のない演算を載せたものです。