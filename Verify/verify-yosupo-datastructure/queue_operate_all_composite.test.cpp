#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include"../../Template.hpp"
#include"../../DataStructure/FoldableDeque.hpp"
#include"../../Modint/Modint.hpp"
using mint=Modint<MOD>;
struct composite{
    using T=pair<mint,mint>;
    static T op(T lf,T ri){
        return T(lf.fi*ri.fi,lf.se*ri.fi+ri.se);
    }
    static inline T e=T(1,0);
};
void solve(){
    LL(Q);
    FoldableQueue<composite> que;
    rep(i,Q){
        LL(t);
        if(t==0){
            LL(a,b);
            que.push(pll(a,b));
        }
        if(t==1){
            que.pop();
        }
        if(t==2){
            LL(x);
            pair<mint,mint> ope=que.get_all();
            out(ope.fi*x+ope.se);
        }
    }
}
int main(){
    solve();
    return 0;
}