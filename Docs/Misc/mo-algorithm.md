---
title: Mo's Algorithm
documentation_of: ../../Misc/Mo.hpp
---

## 関数の設定
```cpp
struct M{
    using T;
    static void add_left(int pos) {}
    static void delete_left(int pos) {}
    static void add_right(int pos) {}
    static void delete_right(int pos) {}
    static T rem() {}
};
```
* `T`: 答えの型です。
* `void add_left(int pos)`: `pos` 番目の要素を左に追加するときの処理です。
* `void delete_left(int pos)`: `pos` 番目の要素を左から削除するときの処理です。
* `void add_right(int pos)`: `pos` 番目の要素を右に追加するときの処理です。
* `void delete_right(int pos)`: `pos` 番目の要素を右から削除するときの処理です。
* `T rem()`: 現時点でのクエリに対する答えを返す処理です。