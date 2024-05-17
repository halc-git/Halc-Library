#pragma once
#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <vector>
template <class Key, class Val>
struct RadixHeap {
    static constexpr int32_t backet = sizeof(Key) * 8 + 1;
    std::array<std::vector<std::pair<Key, Val>>, backet> heap;
    Key last = 0;
    int32_t siz = 0;
    inline int32_t bsr(uint64_t x) { return 64 - std::countl_zero(x); }
    void push(Key key, Val val) {
        siz++;
        heap[bsr(key ^ last)].emplace_back(std::pair<Key, Val>(key, val));
    }
    std::pair<Key, Val> pop() {
        siz--;
        if (heap[0].empty()) {
            int32_t i = 1;
            while (heap[i].empty()) i++;
            last = (*std::min_element(heap[i].begin(), heap[i].end())).first;
            for (std::pair<Key, Val> x : heap[i]) {
                heap[bsr(x.first ^ last)].emplace_back(x);
            }
            heap[i].clear();
        }
        std::pair<Key, Val> ret = heap[0].back();
        heap[0].pop_back();
        return ret;
    }
    bool empty() { return !siz; }
    int32_t size() { return siz; }
};