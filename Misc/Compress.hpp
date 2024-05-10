#pragma once
#include <cstdint>
#include <vector>
template <class T>
struct Compress {
    std::vector<T> data;
    void add(T x) { data.emplace_back(x); }
    void add(std::vector<T> x) {
        for (T i : x) add(i);
    }
    void build() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    }
    int32_t get(T x) {
        return std::lower_bound(data.begin(), data.end(), x) - data.begin();
    }
    inline int32_t operator()(T x) { return get(x); }
    T operator[](int32_t i) { return data[i]; }
    int32_t size() { return data.size(); }
};