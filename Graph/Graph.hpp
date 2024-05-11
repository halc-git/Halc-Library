#pragma once
#include <cstdint>
#include <vector>
template <class T = int32_t>
struct Edge {
    int32_t from, to;
    T cost;
    int32_t idx;
    Edge() = default;
    Edge(int32_t from, int32_t to, T cost = 1, int32_t idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() { return to; }
    void reverse() { std::swap(from, to); }
};
template <class T = int32_t>
struct Graph {
    std::vector<std::vector<Edge<T>>> gr;
    int32_t eds = 0;
    Graph() = default;
    Graph(int32_t n) { gr.resize(n); }
    void add_edge(int32_t from, int32_t to, T cost = 1, bool directed = false) {
        gr[from].emplace_back(from, to, cost, eds);
        if (!directed) {
            gr[to].emplace_back(to, from, cost, eds);
        }
        eds++;
    }
    void add_directed_edge(int32_t from, int32_t to, T cost = 1) {
        gr[from].emplace_back(from, to, cost, eds);
        eds++;
    }
    inline std::vector<Edge<T>> &operator[](const int32_t &p) { return gr[p]; }
    int32_t size() { return gr.size(); }
};
template <class T>
Graph<T> reverse_edges(Graph<T> &gr) {
    Graph<T> ret(gr.size());
    for (int32_t i = 0; i < gr.size(); i++) {
        for (Edge<T> j : gr[i]) {
            ret[j].emplace_back(j);
            ret[j].back().reverse();
        }
    }
    return ret;
}