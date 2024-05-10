#pragma once
#include <cstdint>
#include <stack>
#include <vector>
// https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1
template <class M>
struct FoldableQueue {
    using T = typename M::T;
    std::stack<T> top, bottom, topfold, bottomfold;
    FoldableQueue() {
        topfold.push(M::e);
        bottomfold.push(M::e);
    }
    void push(T v) {
        bottom.push(v);
        bottomfold.push(M::op(bottomfold.top(), v));
    }
    void pop() {
        if (top.empty()) {
            while (!bottom.empty()) {
                top.push(bottom.top());
                topfold.push(M::op(bottom.top(), topfold.top()));
                bottom.pop();
                bottomfold.pop();
            }
        }
        top.pop();
        topfold.pop();
    }
    T front() {
        if (top.empty()) {
            while (!bottom.empty()) {
                top.push(bottom.top());
                topfold.push(M::op(bottom.top(), topfold.top()));
                bottom.pop();
                bottomfold.pop();
            }
        }
        return top.top();
    }
    T get_all() { return M::op(topfold.top(), bottomfold.top()); }
    int32_t size() { return top.size() + bottom.size(); }
    bool empty() { return top.empty() && bottom.empty(); }
};
template <class M>
struct FoldableDeque {
    using T = typename M::T;
    std::stack<T> top, bottom, topfold, bottomfold;
    FoldableDeque() {
        topfold.push(M::e);
        bottomfold.push(M::e);
    }
    void push_front(T v) {
        top.push(v);
        topfold.push(M::op(v, topfold.top()));
    }
    void push_back(T v) {
        bottom.push(v);
        bottomfold.push(M::op(bottomfold.top(), v));
    }
    void pop_front() {
        if (top.empty()) {
            std::vector<T> change;
            while (!bottom.empty()) {
                change.emplace_back(bottom.top());
                bottom.pop();
                bottomfold.pop();
            }
            int32_t sz = change.size();
            for (int32_t i = (sz >> 1); i >= 0; i--) {
                top.push(change[sz - i - 1]);
                topfold.push(M::op(change[sz - i - 1], topfold.top()));
            }
            for (int32_t i = (sz >> 1) + 1; i < sz; i++) {
                bottom.push(change[sz - i - 1]);
                bottomfold.push(M::op(bottomfold.top(), change[sz - i - 1]));
            }
        }
        top.pop();
        topfold.pop();
    }
    void pop_back() {
        if (bottom.empty()) {
            std::vector<T> change;
            while (!top.empty()) {
                change.emplace_back(top.top());
                top.pop();
                topfold.pop();
            }
            int32_t sz = change.size();
            for (int32_t i = (sz >> 1); i >= 0; i--) {
                bottom.push(change[sz - i - 1]);
                bottomfold.push(M::op(bottomfold.top(), change[sz - i - 1]));
            }
            for (int32_t i = (sz >> 1) + 1; i < sz; i++) {
                top.push(change[sz - i - 1]);
                topfold.push(M::op(change[sz - i - 1], topfold.top()));
            }
        }
        bottom.pop();
        bottomfold.pop();
    }
    T front() {
        if (top.empty()) {
            std::vector<T> change;
            while (!bottom.empty()) {
                change.emplace_back(bottom.top());
                bottom.pop();
                bottomfold.pop();
            }
            int32_t sz = change.size();
            for (uint32_t i = (sz >> 1); i >= 0; i--) {
                top.push(change[i]);
                topfold.push(M::op(change[i], topfold.top()));
            }
            for (uint32_t i = (sz >> 1) + 1; i < sz; i++) {
                bottom.push(change[i]);
                bottomfold.push(M::op(bottomfold.top(), change[i]));
            }
        }
        return top.top();
    }
    T back() {
        if (bottom.empty()) {
            std::vector<T> change;
            while (!top.empty()) {
                change.emplace_back(top.top());
                top.pop();
                topfold.pop();
            }
            int32_t sz = change.size();
            for (uint32_t i = (sz >> 1); i >= 0; i--) {
                bottom.push(change[i]);
                bottomfold.push(M::op(bottomfold.top(), change[i]));
            }
            for (uint32_t i = (sz >> 1) + 1; i < sz; i++) {
                top.push(change[i]);
                topfold.push(M::op(change[i], topfold.top()));
            }
        }
        return bottom.top();
    }
    T get_all() { return M::op(topfold.top(), bottomfold.top()); }
    int32_t size() { return top.size() + bottom.size(); }
    bool empty() { return top.empty() && bottom.empty(); }
};