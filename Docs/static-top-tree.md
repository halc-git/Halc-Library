---
title: Static Top Tree
documentation_of: ../Tree/StaticTopTree.hpp
---

## 関数の設定
```cpp
struct func{
    using point;
    using path;

    static path vertex(int v){
    }

    static path compress(path p,path c){
    }

    static path add_vertex(point t,int v){
    }

    static point rake(point x,point y){
    }

    static point add_edge(path t){
    }
};
```
* `point`: Point Clusterに載せるデータの型です。
* `path`: Path Clusterに載せるデータの型です。
* `path vertex(int v)`: 頂点 `v` のみのPath Clusterを作成する関数です。
* `path compress(path p,path c)`: Path Cluster `p` と `c` をマージする関数です。`p` が根に近い方です。
* `point add_vertex(point t,int v)`: Point Cluster `t` に頂点 `v` を追加したPath Clusterを返す関数です。
* `point rake(point x,point y)`: Point Cluster `x` と `y` をマージする関数です。
* `point add_edge(path t)`: Path Cluster `t` に辺を追加してPoint Clusterにする関数です。