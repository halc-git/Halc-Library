#pragma once
//https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1
template<class M>
struct FoldableQueue{
    using T=typename M::T;
    stack<T> top,bottom,topfold,bottomfold;
    FoldableQueue(){
        topfold.push(M::e);
        bottomfold.push(M::e);
    }
    void push(T v){
        bottom.push(v);
        bottomfold.push(M::op(bottomfold.top(),v));
    }
    void pop(){
        if(top.size()==0){
            while(!bottom.empty()){
                top.push(bottom.top());
                topfold.push(M::op(bottom.top(),topfold.top()));
                bottom.pop();
                bottomfold.pop();
            }
        }
        top.pop();
        topfold.pop();
    }
    T front(){
        if(top.size()==0){
            while(!bottom.empty()){
                top.push(bottom.top());
                topfold.push(M::op(bottom.top(),topfold.top()));
                bottom.pop();
                bottomfold.pop();
            }
        }
        return top.top();
    }
    T get_all(){
        return M::op(topfold.top(),bottomfold.top());
    }
    size_t size(){
        return top.size()+bottom.size();
    }
    bool empty(){
        return top.empty()&&bottom.empty();
    }
};