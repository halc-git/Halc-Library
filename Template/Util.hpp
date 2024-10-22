#pragma once
#include <array>
#include <climits>
#include <cstdint>
#include <functional>
#include <limits>
#include <queue>
#include <vector>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using uint = unsigned int;
using pll = std::pair<ll, ll>;
using pii = std::pair<int32_t, int32_t>;
using vl = std::vector<ll>;
using vvl = std::vector<std::vector<ll>>;
using pdd = std::pair<ld, ld>;
using tuplis = std::array<ll, 3>;
template <class T>
using pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr ll LINF = (1LL << 62) - (1LL << 31);
constexpr int32_t INF = INT_MAX >> 1;
constexpr ll MINF = 1LL << 40;
constexpr ld DINF = std::numeric_limits<ld>::infinity();
constexpr int32_t MODD = 1000000007;
constexpr int32_t MOD = 998244353;
constexpr ld EPS = 1e-9;
constexpr ld PI = 3.1415926535897932;
const ll four[] = {0, 1, 0, -1, 0};
const ll eight[] = {0, 1, 1, 0, -1, -1, 1, -1, 0};
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    } else
        return false;
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    } else
        return false;
}
template <class T>
ll sum(const T &a) {
    return accumulate(std::begin(a), std::end(a), 0LL);
}
template <class T>
ld dsum(const T &a) {
    return accumulate(std::begin(a), std::end(a), 0.0L);
}
template <class T>
auto min(const T &a) {
    return *min_element(std::begin(a), std::end(a));
}
template <class T>
auto max(const T &a) {
    return *max_element(std::begin(a), std::end(a));
}
