#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include"../../Template.hpp"
#include"../../String/Manacher.hpp"
int main(){
    STR(S);
    out(manacher(S));
}