#pragma once
using namespace chrono;
uint32_t pcg32_fast(){
    static uint64_t state=(steady_clock::now().time_since_epoch().count()<<1)+1;
    uint64_t x=state;
    uint8_t count=x>>61;
    state*=0xf13283ad;
    x^=x>>22;
    return (uint32_t)(x>>(22+count));
}

int32_t randint(int32_t l,int32_t r){
    return l+(((int64_t)pcg32_fast()*(r-l+1))>>32);
}

auto startTime=system_clock::now();
int32_t getTime(){
    return duration_cast<microseconds>(system_clock::now()-startTime).count();
}