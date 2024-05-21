#pragma once
#include <array>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
inline void scan() {}
inline void scan(int &a) { std::cin >> a; }
inline void scan(unsigned &a) { std::cin >> a; }
inline void scan(long &a) { std::cin >> a; }
inline void scan(long long &a) { std::cin >> a; }
inline void scan(unsigned long long &a) { std::cin >> a; }
inline void scan(char &a) { std::cin >> a; }
inline void scan(float &a) { std::cin >> a; }
inline void scan(double &a) { std::cin >> a; }
inline void scan(long double &a) { std::cin >> a; }
inline void scan(std::vector<bool> &vec) {
    for (int32_t i = 0; i < vec.size(); i++) {
        int a;
        scan(a);
        vec[i] = a;
    }
}
inline void scan(std::string &a) { std::cin >> a; }
template <class T>
inline void scan(std::vector<T> &vec);
template <class T, size_t size>
inline void scan(std::array<T, size> &vec);
template <class T, class L>
inline void scan(std::pair<T, L> &p);
template <class T, size_t size>
inline void scan(T (&vec)[size]);
template <class T>
inline void scan(std::vector<T> &vec) {
    for (auto &i : vec) scan(i);
}
template <class T>
inline void scan(std::deque<T> &vec) {
    for (auto &i : vec) scan(i);
}
template <class T, size_t size>
inline void scan(std::array<T, size> &vec) {
    for (auto &i : vec) scan(i);
}
template <class T, class L>
inline void scan(std::pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}
template <class T, size_t size>
inline void scan(T (&vec)[size]) {
    for (auto &i : vec) scan(i);
}
template <class T>
inline void scan(T &a) {
    std::cin >> a;
}
inline void in() {}
template <class Head, class... Tail>
inline void in(Head &head, Tail &...tail) {
    scan(head);
    in(tail...);
}
inline void print() { std::cout << ' '; }
inline void print(const bool &a) { std::cout << a; }
inline void print(const int &a) { std::cout << a; }
inline void print(const unsigned &a) { std::cout << a; }
inline void print(const long &a) { std::cout << a; }
inline void print(const long long &a) { std::cout << a; }
inline void print(const unsigned long long &a) { std::cout << a; }
inline void print(const char &a) { std::cout << a; }
inline void print(const char a[]) { std::cout << a; }
inline void print(const float &a) { std::cout << a; }
inline void print(const double &a) { std::cout << a; }
inline void print(const long double &a) { std::cout << a; }
inline void print(const std::string &a) {
    for (auto &&i : a) print(i);
}
template <class T>
inline void print(const std::vector<T> &vec);
template <class T, size_t size>
inline void print(const std::array<T, size> &vec);
template <class T, class L>
inline void print(const std::pair<T, L> &p);
template <class T, size_t size>
inline void print(const T (&vec)[size]);
template <class T>
inline void print(const std::vector<T> &vec) {
    if (vec.empty()) return;
    print(vec[0]);
    for (auto i = vec.begin(); ++i != vec.end();) {
        std::cout << ' ';
        print(*i);
    }
}
template <class T>
inline void print(const std::deque<T> &vec) {
    if (vec.empty()) return;
    print(vec[0]);
    for (auto i = vec.begin(); ++i != vec.end();) {
        std::cout << ' ';
        print(*i);
    }
}
template <class T, size_t size>
inline void print(const std::array<T, size> &vec) {
    print(vec[0]);
    for (auto i = vec.begin(); ++i != vec.end();) {
        std::cout << ' ';
        print(*i);
    }
}
template <class T, class L>
inline void print(const std::pair<T, L> &p) {
    print(p.first);
    std::cout << ' ';
    print(p.second);
}
template <class T, size_t size>
inline void print(const T (&vec)[size]) {
    print(vec[0]);
    for (auto i = vec; ++i != end(vec);) {
        std::cout << ' ';
        print(*i);
    }
}
template <class T>
inline void print(const T &a) {
    std::cout << a;
}
inline void out() { std::cout << '\n'; }
template <class T>
inline void out(const T &t) {
    print(t);
    std::cout << '\n';
}
template <class Head, class... Tail>
inline void out(const Head &head, const Tail &...tail) {
    print(head);
    std::cout << ' ';
    out(tail...);
}
inline void Yes(bool i = true) { out(i ? "Yes" : "No"); }
inline void No(bool i = true) { out(i ? "No" : "Yes"); }
inline void Takahashi(bool i = true) { out(i ? "Takahashi" : "Aoki"); }
inline void Aoki(bool i = true) { out(i ? "Aoki" : "Takahashi"); }
inline void First(bool i = true) { out(i ? "First" : "Second"); }
inline void Second(bool i = true) { out(i ? "Second" : "First"); }
inline void Possible(bool i = true) { out(i ? "Possible" : "Impossible"); }
inline void Impossible(bool i = true) { out(i ? "Impossible" : "Possible"); }
inline void fls() { std::flush(std::cout); }
struct IOsetup {
    IOsetup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(16);
    }
} iosetup;