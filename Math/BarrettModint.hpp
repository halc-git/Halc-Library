#pragma once
template<uint32_t N>
struct BarrettModint{
    static constexpr uint32_t _phi(){
        uint32_t prime_fact=N;
        uint32_t ret=N;
        for(int i=2; i*i<prime_fact; i++){
            if(prime_fact%i==0){
                ret-=ret/i;
                while(prime_fact%i==0){
                    prime_fact/=i;
                }
            }
        }
        if(prime_fact!=1){
            ret-=ret/prime_fact;
        }
        return ret;
    }
    static constexpr uint64_t Nr=(-1ULL)/N+1;
    static constexpr uint32_t inv_power=_phi()-1;
    static_assert(1<N);
    static_assert(N<(1<<30));
    int64_t x;
    constexpr uint32_t mod(){
        return N;
    }
    constexpr int64_t _get_mod(int64_t x){
        uint64_t ret=((unsigned __int128)x*Nr)>>64;
        if(x-ret*N<0){
            return x-(ret-1)*N;
        }
        return x-ret*N;
    }
    constexpr BarrettModint()noexcept{
        x=0;
    }
    constexpr BarrettModint(int64_t val)noexcept{
        x=((val%N)+N)%N;
    }
    constexpr uint64_t val()noexcept{
        return x;
    }
    friend ostream &operator<<(ostream &os,BarrettModint &b){
        return os<<b.val();
    }
    constexpr BarrettModint operator+()noexcept{return *this;}
    constexpr BarrettModint operator-()noexcept{return BarrettModint()-(*this);}
    constexpr friend BarrettModint operator+(BarrettModint lhs,BarrettModint rhs)noexcept{
        return BarrettModint(lhs)+=rhs;
    }
    constexpr friend BarrettModint operator-(BarrettModint lhs,BarrettModint rhs)noexcept{
        return BarrettModint(lhs)-=rhs;
    }
    constexpr friend BarrettModint operator*(BarrettModint lhs,BarrettModint rhs)noexcept{
        return BarrettModint(lhs)*=rhs;
    }
    constexpr friend BarrettModint operator/(BarrettModint lhs,BarrettModint rhs){
        return BarrettModint(lhs)/=rhs;
    }
    constexpr BarrettModint operator+=(BarrettModint rhs)noexcept{
        x+=rhs.x;
        if(x>=N)x-=N;
        return *this;
    }
    constexpr BarrettModint operator-=(BarrettModint rhs)noexcept{
        x-=rhs.x;
        if(x<0)x+=N;
        return *this;
    }
    constexpr BarrettModint operator*=(BarrettModint rhs)noexcept{
        x=_get_mod(x*rhs.x);
        return *this;
    }
    constexpr BarrettModint operator/=(BarrettModint rhs){
        (*this)*=rhs.inv();
        return *this;
    }
    constexpr BarrettModint& operator++(){
        (*this)+=1;
        return *this;
    }
    constexpr BarrettModint& operator--(){
        (*this)-=1;
        return *this;
    }
    constexpr BarrettModint operator++(int){
        (*this)+=1;
        return *this;
    }
    constexpr BarrettModint operator--(int){
        (*this)-=1;
        return *this;
    }
    constexpr bool operator==(BarrettModint rhs)noexcept{
        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);
    }
    constexpr bool operator!=(BarrettModint rhs)noexcept{
        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);
    }
    constexpr BarrettModint inv(){
        BarrettModint ret=(*this).pow(inv_power);
        assert(ret*(*this)==1);
        return ret;
    }
    constexpr BarrettModint pow(uint64_t x)noexcept{
        BarrettModint ret=1;
        BarrettModint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
};
template<int32_t id>
struct ArbitraryBarrettModint{
    static uint32_t _phi(uint32_t N){
        uint32_t prime_fact=N;
        uint32_t ret=N;
        for(int i=2; i*i<prime_fact; i++){
            if(prime_fact%i==0){
                ret-=ret/i;
                while(prime_fact%i==0){
                    prime_fact/=i;
                }
            }
        }
        if(prime_fact!=1){
            ret-=ret/prime_fact;
        }
        return ret;
    }
    static uint64_t N,Nr;
    static uint32_t inv_power;
    int64_t x;
    static void set_mod(uint32_t mod){
        N=mod;
        Nr=(-1ULL)/N+1;
        inv_power=_phi(N)-1;
        assert(1<mod);
        assert(mod<(1<<30));
    }
    uint32_t mod(){
        return N;
    }
    int64_t _get_mod(int64_t x){
        uint64_t ret=((unsigned __int128)x*Nr)>>64;
        if(x-ret*N<0){
            return x-(ret-1)*N;
        }
        return x-ret*N;
    }
    ArbitraryBarrettModint()noexcept{
        x=0;
    }
    ArbitraryBarrettModint(int64_t val)noexcept{
        x=((val%N)+N)%N;
    }
    uint64_t val()noexcept{
        return x;
    }
    friend ostream &operator<<(ostream &os,ArbitraryBarrettModint &b){
        return os<<b.val();
    }
    ArbitraryBarrettModint operator+()noexcept{return *this;}
    ArbitraryBarrettModint operator-()noexcept{return ArbitraryBarrettModint()-(*this);}
    friend ArbitraryBarrettModint operator+(ArbitraryBarrettModint lhs,ArbitraryBarrettModint rhs)noexcept{
        return ArbitraryBarrettModint(lhs)+=rhs;
    }
    friend ArbitraryBarrettModint operator-(ArbitraryBarrettModint lhs,ArbitraryBarrettModint rhs)noexcept{
        return ArbitraryBarrettModint(lhs)-=rhs;
    }
    friend ArbitraryBarrettModint operator*(ArbitraryBarrettModint lhs,ArbitraryBarrettModint rhs)noexcept{
        return ArbitraryBarrettModint(lhs)*=rhs;
    }
    friend ArbitraryBarrettModint operator/(ArbitraryBarrettModint lhs,ArbitraryBarrettModint rhs){
        return ArbitraryBarrettModint(lhs)/=rhs;
    }
    ArbitraryBarrettModint operator+=(ArbitraryBarrettModint rhs)noexcept{
        x+=rhs.x;
        if(x>=N)x-=N;
        return *this;
    }
    ArbitraryBarrettModint operator-=(ArbitraryBarrettModint rhs)noexcept{
        x-=rhs.x;
        if(x<0)x+=N;
        return *this;
    }
    ArbitraryBarrettModint operator*=(ArbitraryBarrettModint rhs)noexcept{
        x=_get_mod(x*rhs.x);
        return *this;
    }
    ArbitraryBarrettModint operator/=(ArbitraryBarrettModint rhs){
        (*this)*=rhs.inv();
        return *this;
    }
    ArbitraryBarrettModint& operator++(){
        (*this)+=1;
        return *this;
    }
    ArbitraryBarrettModint& operator--(){
        (*this)-=1;
        return *this;
    }
    ArbitraryBarrettModint operator++(int){
        (*this)+=1;
        return *this;
    }
    ArbitraryBarrettModint operator--(int){
        (*this)-=1;
        return *this;
    }
    bool operator==(ArbitraryBarrettModint rhs)noexcept{
        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);
    }
    bool operator!=(ArbitraryBarrettModint rhs)noexcept{
        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);
    }
    ArbitraryBarrettModint inv(){
        ArbitraryBarrettModint ret=(*this).pow(inv_power);
        assert(ret*(*this)==1);
        return ret;
    }
    ArbitraryBarrettModint pow(uint64_t x)noexcept{
        ArbitraryBarrettModint ret=1;
        ArbitraryBarrettModint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
};
template<int id>uint64_t ArbitraryBarrettModint<id>::N;
template<int id>uint64_t ArbitraryBarrettModint<id>::Nr;
template<int id>uint32_t ArbitraryBarrettModint<id>::inv_power;

template<uint32_t N> inline void print(BarrettModint<N> a){ cout << a; }
template<int32_t id> inline void print(ArbitraryBarrettModint<id> a){ cout << a; }