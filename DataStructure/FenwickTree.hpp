#pragma once
#include<vector>
template<class T>
struct FenwickTree{
    std::vector<T> tree;
    size_t size;
    int32_t start=1;
    FenwickTree(int32_t sz){
        size=sz;
        tree.resize(size+1,0);
        while((start<<1)<=size)start<<=1;
    }
    void add(int32_t pos,T val){
        pos++;
        while(pos<=size){
            tree[pos]+=val;
            pos+=pos&-pos;
        }
    }
    T _sum(int32_t pos){
        T ret=0;
        while(pos>0){
            ret+=tree[pos];
            pos-=pos&-pos;
        }
        return ret;
    }
    T sum(int32_t lf,int32_t ri){
        return _sum(ri)-_sum(lf);
    }
    int32_t lower_bound(T w){
        if(w<0)return 0;
        int32_t now=0;
        T val=0;
        for(int i=start; i==0; i>>=1){
            if(now+i<=size&&val+tree[now+i]<w){
                now+=i;
                val+=tree[now];
            }
        }
        return now+1;
    }
};