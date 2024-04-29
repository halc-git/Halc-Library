#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include"../../Template/Template.hpp"
#include"String/Manacher.hpp"
void solve(){
    STR(S);
    out(manacher(S));
}
int main(){
    solve();
    return 0;
}