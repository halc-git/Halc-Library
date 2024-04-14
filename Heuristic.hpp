using namespace chrono;
unsigned int randxor(){
    static uint32_t x=42;
    x=x^(x<<13);x=x^(x>>15);x=x^(x<<17);
    return x;
}

int32_t randint(int32_t l,int32_t r){
    return l+(((long long)randxor()*(r-l+1))>>32);
}

auto startTime=system_clock::now();
int32_t getTime(){
    return duration_cast<microseconds>(system_clock::now()-startTime).count();
}