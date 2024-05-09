#define _overload3(_1, _2, _3, name, ...) name
#define _overload4(_1, _2, _3, _4, name, ...) name
#define _rep1(i, n) for (ll i = 0; i < (n); i++)
#define _rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define _rep3(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define _rrep1(i, n) for (ll i = (n); i-- > 0;)
#define _rrep2(i, a, b) for (ll i = (b); i-- > (a);)
#define rrep(...) _overload3(__VA_ARGS__, _rrep2, _rrep1)(__VA_ARGS__)
#define each(i, ...) for (auto&& i : __VA_ARGS__)
#define all(i) std::begin(i), std::end(i)
#define rall(i) std::rbegin(i), std::rend(i)
#define len(x) ((int)(x).size())
#define fi first
#define se second
#define uniq(x) x.erase(unique(all(x)), std::end(x))
#define vec(type, name, ...) vector<type> name(__VA_ARGS__);
#define vv(type, name, h, ...) \
    std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__));
#define INT(...)     \
    int __VA_ARGS__; \
    in(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    in(__VA_ARGS__)
#define ULL(...)     \
    ull __VA_ARGS__; \
    in(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    in(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    in(__VA_ARGS__)
#define LD(...)     \
    ld __VA_ARGS__; \
    in(__VA_ARGS__)
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    in(name)
#define VV(type, name, h, w)                                      \
    std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
    in(name)