#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../String/Manacher.hpp"
#include "../../Template/Template.hpp"
void solve() {
    STR(S);
    out(manacher(S));
}
int main() { solve(); }