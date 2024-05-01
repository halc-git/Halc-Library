#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include"Template/Template.hpp"
#include"DataStructure/FenwickTree.hpp"
#include"Misc/Mo.hpp"
#include"Misc/Compress.hpp"
void solve(){
    LL(N,Q);
    static VEC(ll,A,N);
    static Compress<ll> cp;
    cp.add(A);
    cp.build();
    rep(i,N){
        A[i]=cp(A[i]);
    }
    static FenwickTree<ll> fw(len(cp));
    static ll ans=0;
    struct inversions{
        using T=ll;
        static void add_left(int pos){
            ans+=fw.sum(0,A[pos]);
            fw.add(A[pos],1);
        }
        static void delete_left(int pos){
            ans-=fw.sum(0,A[pos]);
            fw.add(A[pos],-1);
        }
        static void add_right(int pos){
            ans+=fw.sum(A[pos]+1,len(cp));
            fw.add(A[pos],1);
        }
        static void delete_right(int pos){
            ans-=fw.sum(A[pos]+1,len(cp));
            fw.add(A[pos],-1);
        }
        static T rem(){
            return ans;
        }
    };
    Mo<inversions> mo(N,Q);
    rep(i,Q){
        LL(l,r);
        mo.add_query(l,r);
    }
    vector<ll> fin=mo.run();
    each(i,fin)out(i);
}
int main(){
    solve();
    return 0;
}