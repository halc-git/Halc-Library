#pragma once
template<uint32_t N>
struct MontgomeryModint{
    static constexpr uint64_t _rev(){
        uint64_t Nd=0;
        uint64_t t=0;
        uint64_t r=1ULL<<32;
        uint64_t i=1;
        while(r){
            if(!(t&1)){
                t+=N;
                Nd+=i;
            }
            t>>=1;
            r>>=1;
            i<<=1;
        }
        return Nd;
    }
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
    static constexpr uint64_t R=(1ULL<<32);
    static constexpr uint64_t Nd=_rev();
    static constexpr uint64_t Rr=(Nd*N+1)>>32;
    static constexpr uint64_t MASK=R-1;
    static constexpr uint32_t inv_power=_phi()-1;
    static_assert(1<N);
    static_assert(N<(1<<30));
    static_assert(N&1);
    int64_t x;
    constexpr uint32_t mod(){
        return N;
    }
    constexpr MontgomeryModint()noexcept{
        x=0;
    }
    constexpr MontgomeryModint(int64_t val)noexcept{
        x=(((val%N)+N)%N<<32)%N;
    }
    constexpr uint64_t _reduction(uint64_t val)noexcept{
        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;
        if(ret>=N)return ret-N;
        return ret;
    }
    constexpr uint64_t val()noexcept{
        return _reduction(x);
    }
    friend ostream &operator<<(ostream &os,MontgomeryModint &b){
        return os<<b.val();
    }
    constexpr MontgomeryModint operator+()noexcept{return *this;}
    constexpr MontgomeryModint operator-()noexcept{return MontgomeryModint()-(*this);}
    constexpr friend MontgomeryModint operator+(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{
        return MontgomeryModint(lhs)+=rhs;
    }
    constexpr friend MontgomeryModint operator-(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{
        return MontgomeryModint(lhs)-=rhs;
    }
    constexpr friend MontgomeryModint operator*(MontgomeryModint lhs,MontgomeryModint rhs)noexcept{
        return MontgomeryModint(lhs)*=rhs;
    }
    constexpr friend MontgomeryModint operator/(MontgomeryModint lhs,MontgomeryModint rhs){
        return MontgomeryModint(lhs)/=rhs;
    }
    constexpr MontgomeryModint operator+=(MontgomeryModint rhs)noexcept{
        x+=rhs.x;
        if(x>=N)x-=N;
        return *this;
    }
    constexpr MontgomeryModint operator-=(MontgomeryModint rhs)noexcept{
        x-=rhs.x;
        if(x<0)x+=N;
        return *this;
    }
    constexpr MontgomeryModint operator*=(MontgomeryModint rhs)noexcept{
        x=_reduction(x*rhs.x);
        return *this;
    }
    constexpr MontgomeryModint operator/=(MontgomeryModint rhs){
        (*this)*=rhs.inv();
        return *this;
    }
    constexpr MontgomeryModint& operator++(){
        (*this)+=1;
        return *this;
    }
    constexpr MontgomeryModint& operator--(){
        (*this)-=1;
        return *this;
    }
    constexpr MontgomeryModint operator++(int){
        (*this)+=1;
        return *this;
    }
    constexpr MontgomeryModint operator--(int){
        (*this)-=1;
        return *this;
    }
    constexpr bool operator==(MontgomeryModint rhs)noexcept{
        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);
    }
    constexpr bool operator!=(MontgomeryModint rhs)noexcept{
        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);
    }
    constexpr MontgomeryModint inv(){
        MontgomeryModint ret=(*this).pow(inv_power);
        assert(ret*(*this)==1);
        return ret;
    }
    constexpr MontgomeryModint pow(uint64_t x)noexcept{
        MontgomeryModint ret=1;
        MontgomeryModint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
};
template<int32_t id>
struct ArbitrarMontgomeryModint{
    static uint64_t _rev(uint32_t N){
        uint64_t Nd=0;
        uint64_t t=0;
        uint64_t r=1ULL<<32;
        uint64_t i=1;
        while(r){
            if(!(t&1)){
                t+=N;
                Nd+=i;
            }
            t>>=1;
            r>>=1;
            i<<=1;
        }
        return Nd;
    }
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
    static uint64_t N,R,Nd,Rr,MASK;
    static uint32_t inv_power;
    int64_t x;
    static void set_mod(uint32_t mod){
        N=mod;
        R=(1ULL<<32);
        Nd=_rev(N);
        Rr=(Nd*N+1)>>32;
        MASK=R-1;
        inv_power=_phi(N)-1;
        assert(1<mod);
        assert(mod<(1<<30));
        assert(mod&1);
    }
    uint32_t mod(){
        return N;
    }
    ArbitrarMontgomeryModint()noexcept{
        x=0;
    }
    ArbitrarMontgomeryModint(int64_t val)noexcept{
        x=(((val%N)+N)%N<<32)%N;
    }
    uint64_t _reduction(uint64_t val)noexcept{
        uint64_t ret=(val+(((val&MASK)*Nd)&MASK)*N)>>32;
        if(ret>=N)return ret-N;
        return ret;
    }
    uint64_t val()noexcept{
        return _reduction(x);
    }
    friend ostream &operator<<(ostream &os,ArbitrarMontgomeryModint &b){
        return os<<b.val();
    }
    ArbitrarMontgomeryModint operator+()noexcept{return *this;}
    ArbitrarMontgomeryModint operator-()noexcept{return ArbitrarMontgomeryModint()-(*this);}
    friend ArbitrarMontgomeryModint operator+(ArbitrarMontgomeryModint lhs,ArbitrarMontgomeryModint rhs)noexcept{
        return ArbitrarMontgomeryModint(lhs)+=rhs;
    }
    friend ArbitrarMontgomeryModint operator-(ArbitrarMontgomeryModint lhs,ArbitrarMontgomeryModint rhs)noexcept{
        return ArbitrarMontgomeryModint(lhs)-=rhs;
    }
    friend ArbitrarMontgomeryModint operator*(ArbitrarMontgomeryModint lhs,ArbitrarMontgomeryModint rhs)noexcept{
        return ArbitrarMontgomeryModint(lhs)*=rhs;
    }
    friend ArbitrarMontgomeryModint operator/(ArbitrarMontgomeryModint lhs,ArbitrarMontgomeryModint rhs){
        return ArbitrarMontgomeryModint(lhs)/=rhs;
    }
    ArbitrarMontgomeryModint operator+=(ArbitrarMontgomeryModint rhs)noexcept{
        x+=rhs.x;
        if(x>=N)x-=N;
        return *this;
    }
    ArbitrarMontgomeryModint operator-=(ArbitrarMontgomeryModint rhs)noexcept{
        x-=rhs.x;
        if(x<0)x+=N;
        return *this;
    }
    ArbitrarMontgomeryModint operator*=(ArbitrarMontgomeryModint rhs)noexcept{
        x=_reduction(x*rhs.x);
        return *this;
    }
    ArbitrarMontgomeryModint operator/=(ArbitrarMontgomeryModint rhs){
        (*this)*=rhs.inv();
        return *this;
    }
    ArbitrarMontgomeryModint& operator++(){
        (*this)+=1;
        return *this;
    }
    ArbitrarMontgomeryModint& operator--(){
        (*this)-=1;
        return *this;
    }
    ArbitrarMontgomeryModint operator++(int){
        (*this)+=1;
        return *this;
    }
    ArbitrarMontgomeryModint operator--(int){
        (*this)-=1;
        return *this;
    }
    bool operator==(ArbitrarMontgomeryModint rhs)noexcept{
        return (x>=N?x-N:x)==(rhs.x>=N?rhs.x-N:rhs.x);
    }
    bool operator!=(ArbitrarMontgomeryModint rhs)noexcept{
        return (x>=N?x-N:x)!=(rhs.x>=N?rhs.x-N:rhs.x);
    }
    ArbitrarMontgomeryModint inv(){
        ArbitrarMontgomeryModint ret=(*this).pow(inv_power);
        assert(ret*(*this)==1);
        return ret;
    }
    ArbitrarMontgomeryModint pow(uint64_t x)noexcept{
        ArbitrarMontgomeryModint ret=1;
        ArbitrarMontgomeryModint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
};
template<int id>uint64_t ArbitrarMontgomeryModint<id>::N;
template<int id>uint64_t ArbitrarMontgomeryModint<id>::R;
template<int id>uint64_t ArbitrarMontgomeryModint<id>::Nd;
template<int id>uint64_t ArbitrarMontgomeryModint<id>::Rr;
template<int id>uint64_t ArbitrarMontgomeryModint<id>::MASK;
template<int id>uint32_t ArbitrarMontgomeryModint<id>::inv_power;

template<uint32_t N> inline void print(MontgomeryModint<N> a){ cout << a; }
template<int32_t id> inline void print(ArbitrarMontgomeryModint<id> a){ cout << a; }