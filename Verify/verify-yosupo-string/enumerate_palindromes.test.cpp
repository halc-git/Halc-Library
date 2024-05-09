#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../String/Manacher.hpp"
#include "../../Template/Template.hpp"
void Halc::solve() {
    STR(S);
    out(manacher(S));
}