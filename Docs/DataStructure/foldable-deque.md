---
title: Foldable Deque
documentation_of: ../../DataStructure/FoldableDeque.hpp
---

## 関数の設定
```cpp
struct M {
    using T;
    static T op(T x, T y) {}
    static inline T e;
};
```
* `T`: モノイドの型です。
* `T op(T x,T y)`: 演算です。モノイドであることを要求します。
* `T e`: 単位元です。