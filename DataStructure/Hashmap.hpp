#pragma once
#include<ext/pb_ds/assoc_container.hpp>
#include"../Template/Heuristic.hpp"
//https://codeforces.com/blog/entry/62393?locale=en
struct custom_hash {
    //http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    uint64_t operator()(uint64_t x) const {
        mt19937_64 mt(pcg32_fast());
        uniform_int_distribution<uint64_t> rand(0,1ULL<<63);
        static const uint64_t FIXED_RANDOM=rand(mt);
        return splitmix64(x+FIXED_RANDOM);
    }
};
template<typename Key,typename Val>using Hashmap=__gnu_pbds::gp_hash_table<Key,Val,custom_hash>;
