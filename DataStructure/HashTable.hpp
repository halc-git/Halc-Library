//https://codeforces.com/blog/entry/62393
#pragma once
#include<vector>
#include<stdint.h>
#include<chrono>
#include<string>
//keyが整数型とcharにしか対応してないのをどうにかしたい
struct custom_hash{
    //http://xorshift.di.unimi.it/splitmix64.c
    uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    uint64_t operator()(uint64_t x){
        static const uint64_t FIX_RANDOM=std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIX_RANDOM);
    }
};
template<class key,class val>
struct HashMap{
    std::vector<key> keys;
    std::vector<val> values;
    std::vector<bool> flag;
    val default_value;
    uint32_t cap;
    uint32_t res;
    size_t sz=0;
    HashMap(uint32_t query_size=15){
        cap=query_size;
        cap|=cap>>1;cap|=cap>>2;cap|=cap>>4;cap|=cap>>8;cap|=cap>>16;
        cap++;
        res=cap-(cap>>2);
        keys.resize(cap);
        values.resize(cap);
        flag.resize(cap);
    }
    void resize(){
        cap<<=1;
        res<<=1;
        std::vector<key> new_keys(cap);
        std::vector<val> new_values(cap);
        std::vector<bool> new_flag(cap);
        for(int i=0; i<(cap>>1); i++){
            if(!flag[i])continue;
            uint32_t hash=custom_hash()(keys[i])&(cap-1);
            while(new_flag[hash])hash=(hash+1)&(cap-1);;
            new_keys[hash]=keys[i];
            new_values[hash]=values[i];
            new_flag[hash]=true;
        }
        keys=move(new_keys);
        values=move(new_values);
        flag=move(new_flag);
    }
    val& operator[](const key& i){
        uint32_t hash=custom_hash()(i)&(cap-1);
        while(true){
            if(!flag[hash]){
                if(res<=sz)resize();
                keys[hash]=i;
                flag[hash]=true;
                values[hash]=default_value;
                sz++;
                return values[hash];
            }
            if(keys[hash]==i)return values[hash];
            hash=(hash+1)&(cap-1);
        }
    }
    std::vector<std::pair<key,val>> enumerate(){
        std::vector<std::pair<key,val>> ret;
        for(int i=0; i<cap; i++){
            if(flag[i]){
                ret.emplace_back(keys[i],values[i]);
            }
        }
        return ret;
    }
    size_t size(){return sz;}
    void set_default(const val& new_value){default_value=new_value;}
};