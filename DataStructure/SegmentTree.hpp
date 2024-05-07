#pragma once
#include<cstdint>
#include<vector>
template<class M>
struct SegmentTree{
    using T=typename M::T;
    int32_t size;
    std::vector<T> tree;
    SegmentTree(int32_t sz){
        size=sz;
        tree=vector<T>(size*2,M::e);
    }
    void set(int32_t p,T v){
        p+=size;
        tree[p]=v;
        p>>=1;
        while(p>0){
            tree[p]=op(tree[p<<1],tree[(p<<1)+1]);
            p>>=1;
        }
    }
    T prod(int32_t lf,int32_t ri){
        lf+=size;
        ri+=size;
        T rel=M::e;
        T rer=M::e;
        while(lf<ri){
            if(lf%2==1){
                rel=M::op(rel,tree[lf]);
                lf++;
            }
            if(ri%2==1){
                ri--;
                rer=M::op(tree[ri],rer);
            }
            lf>>=1;
            ri>>=1;
        }
        return op(rel,rer);
    }
};