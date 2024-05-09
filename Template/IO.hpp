#pragma once
#include <array>
#include <cstdio>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
inline int scan() { return getchar(); }
inline void scan(int &a) { scanf("%d", &a); }
inline void scan(unsigned &a) { scanf("%u", &a); }
inline void scan(long &a) { scanf("%ld", &a); }
inline void scan(long long &a) { scanf("%lld", &a); }
inline void scan(unsigned long long &a) { scanf("%llu", &a); }
inline void scan(char &a) { std::cin >> a; }
inline void scan(float &a) { scanf("%f", &a); }
inline void scan(double &a) { scanf("%lf", &a); }
inline void scan(long double &a) { scanf("%Lf", &a); }
inline void scan(std::vector<bool> &vec) {
    for (unsigned i = 0; i < vec.size(); i++) {
        int a;
        scan(a);
        vec[i] = a;
    }
}
inline void scan(char a[]) { scanf("%s", a); }
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
inline void print() { putchar(' '); }
inline void print(const bool &a) { printf("%d", a); }
inline void print(const int &a) { printf("%d", a); }
inline void print(const unsigned &a) { printf("%u", a); }
inline void print(const long &a) { printf("%ld", a); }
inline void print(const long long &a) { printf("%lld", a); }
inline void print(const unsigned long long &a) { printf("%llu", a); }
inline void print(const char &a) { printf("%c", a); }
inline void print(const char a[]) { printf("%s", a); }
inline void print(const float &a) { printf("%.15f", a); }
inline void print(const double &a) { printf("%.15f", a); }
inline void print(const long double &a) { printf("%.15Lf", a); }
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
        putchar(' ');
        print(*i);
    }
}
template <class T>
inline void print(const std::deque<T> &vec) {
    if (vec.empty()) return;
    print(vec[0]);
    for (auto i = vec.begin(); ++i != vec.end();) {
        putchar(' ');
        print(*i);
    }
}
template <class T, size_t size>
inline void print(const std::array<T, size> &vec) {
    print(vec[0]);
    for (auto i = vec.begin(); ++i != vec.end();) {
        putchar(' ');
        print(*i);
    }
}
template <class T, class L>
inline void print(const std::pair<T, L> &p) {
    print(p.first);
    putchar(' ');
    print(p.second);
}
template <class T, size_t size>
inline void print(const T (&vec)[size]) {
    print(vec[0]);
    for (auto i = vec; ++i != end(vec);) {
        putchar(' ');
        print(*i);
    }
}
template <class T>
inline void print(const T &a) {
    std::cout << a;
}
inline void out() { putchar('\n'); }
template <class T>
inline void out(const T &t) {
    print(t);
    putchar('\n');
}
template <class Head, class... Tail>
inline void out(const Head &head, const Tail &...tail) {
    print(head);
    putchar(' ');
    out(tail...);
}
inline void Yes(bool i = true) { out(i ? "Yes" : "No"); }
inline void No(bool i = true) { out(i ? "No" : "Yes"); }