#pragma once
#include<vector>
#include<random>
#include"../Template/Heuristic.hpp"
//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
template<typename S>
struct RollingHash{
    using u64=uint64_t;
    static const u64 MOD=(1ULL<<61)-1;
    static const u64 MASK31=(1ULL<<31)-1;
    static const u64 MASK30=(1ULL<<30)-1;
    std::vector<u64> powers;
    u64 base,fixed;
    static inline u64 add(u64 a,u64 b){
        if((a+=b)>=MOD)a-=MOD;
        return a;
    }
    static inline u64 calc_mod(u64 x){
        u64 xu=x>>61,xd=x&MOD;
        u64 ret=xu+xd;
        if(ret>=MOD)ret-=MOD;
        return ret;
    }
    static inline u64 mul(u64 a,u64 b){
        u64 au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;
        u64 mid=ad*bu+au*bd;
        u64 midu=mid>>30,midd=mid&MASK30;
        return calc_mod(((au*bu)<<1)+midu+(midd<<31)+ad*bd);
    }
    static inline u64 generate_base(){
        std::mt19937_64 mt(pcg32_fast());
        std::uniform_int_distribution<u64> rand(1ULL<<60,MOD-1);
        return rand(mt);
    }
    explicit RollingHash(u64 base_number=generate_base(),u64 fixed_number=1ULL<<31){
        base=base_number;
        fixed=fixed_number;
        powers={1};
    }
    std::vector<u64> build(const S &s){
        uint32_t sz=s.size();
        std::vector<u64> hashed(sz+1,0);
        while(powers.size()<=sz){
            powers.emplace_back(mul(powers.back(),base));
        }
        for(uint32_t i=0; i<sz; i++){
            hashed[i+1]=add(mul(hashed[i],base),s[i]+fixed);
        }
        return hashed;
    }
    u64 query(const std::vector<u64> &s,uint32_t lf,uint32_t ri){
        int64_t ret=s[ri]-mul(s[lf],powers[ri-lf]);
        if(ret<0)ret+=MOD;
        return ret;
    }
    u64 combine(u64 h1,u64 h2,uint32_t h2len){
        return add(mul(h1,powers[h2len]),h2);
    }
    uint32_t lcp(const std::vector<u64> &a,uint32_t l1,uint32_t r1,const std::vector<u64> &b,uint32_t l2,uint32_t r2){
        uint32_t ok=0,ng=std::min((r1-l1),(r2-l2))+1;
        while(ng-ok>1){
            uint32_t mid=(ok+ng)>>1;
            if(query(a,l1,l1+mid)==query(b,l2,l2+mid))ok=mid;
            else ng=mid;
        }
        return ok;
    }
};