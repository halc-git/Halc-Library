#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include"../../Template.hpp"
#include"../../String/RollingHash.hpp"
int main(){
    STR(S);
    vec(ll,ans,len(S));
    RollingHash<string> roll;
    auto table=roll.build(S);
    rep(i,len(S)){
        ans[i]=roll.lcp(table,i,len(S),table,0,len(S));
    }
    out(ans);
}