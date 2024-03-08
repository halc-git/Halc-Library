#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include"../Template.hpp"
#include"../DataStructure/HashTable.hpp"
int main(){
    LL(Q);
    HashMap<ll,ll> table;
    rep(i,Q){
        LL(t);
        if(t==0){
            LL(k,v);
            table[k]=v;
        }
        if(t==1){
            LL(k);
            out(table[k]);
        }
    }
}