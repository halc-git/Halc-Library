#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include"../../Template.hpp"
#include"../../String/RollingHash.hpp"
int main(){
    STR(T);
    STR(P);
    RollingHash<string> roll;
    auto tb=roll.build(T);
    auto pb=roll.build(P);
    ll hash=roll.query(pb,0,len(P));
    rep(i,len(T)-len(P)+1){
        if(roll.query(tb,i,i+len(P))==hash)out(i);
    }
}