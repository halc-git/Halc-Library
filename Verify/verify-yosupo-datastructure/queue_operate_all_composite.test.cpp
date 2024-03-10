#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include"../../Template.hpp"
#include"../../DataStructure/FoldableDeque.hpp"
struct composite{
    using T=pll;
    static T op(T lf,T ri){
        return T((lf.fi*ri.fi)%MOD,(lf.se*ri.fi+ri.se)%MOD);
    }
    static inline T e=pll(1,0);
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
            pll ope=que.get_all();
            out((ope.fi*x+ope.se)%MOD);
        }
    }
}
int main(){
    solve();
    return 0;
}