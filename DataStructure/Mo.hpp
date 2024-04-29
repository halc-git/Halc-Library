#pragma once
template<class M>
struct Mo{
    using T=typename M::T;
    int32_t backet;
    vector<int32_t> left,right,order;
    Mo(int32_t N,int32_t Q){
        order.resize(Q);
        backet=max<int32_t>(1,(double)(N)/max<double>(1,sqrt(Q*2.0/3)));
        iota(order.begin(),order.end(),0);
    }
    void add_query(int32_t lf,int32_t ri){
        left.emplace_back(lf);
        right.emplace_back(ri);
    }
    vector<T> run(){
        vector<T> answer(order.size());
        sort(order.begin(),order.end(),[&](int32_t a,int32_t b){
            int32_t ab=left[a]/backet,bb=left[b]/backet;
            if(ab!=bb)return ab<bb;
            if(ab&1)return right[a]<right[b];
            return right[a]>right[b];
        });
        int32_t nl=0,nr=0;
        for(int32_t i:order){
            while(nl>left[i]){
                nl--;
                M::add_left(nl);
            }
            while(right[i]>nr){
                M::add_right(nr);
                nr++;
            }
            while(nl<left[i]){
                M::delete_left(nl);
                nl++;
            }
            while(right[i]<nr){
                nr--;
                M::delete_right(nr);
            }
            answer[i]=M::rem();
        }
        return answer;
    }
};