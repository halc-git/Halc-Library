#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
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
    FoldableDeque<composite> deq;
    rep(i,Q){
        LL(t);
        if(t==0){
            LL(a,b);
            deq.push_front(pll(a,b));
        }
        if(t==1){
            LL(a,b);
            deq.push_back(pll(a,b));
        }
        if(t==2){
            deq.pop_front();
        }
        if(t==3){
            deq.pop_back();
        }
        if(t==4){
            LL(x);
            pll ope=deq.get_all();
            out((ope.fi*x+ope.se)%MOD);
        }
    }
}
int main(){
    solve();
    return 0;
}