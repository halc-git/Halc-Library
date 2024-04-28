template<uint64_t Mod>
struct Modint{
    uint64_t x;
    constexpr Modint(){
        x=0;
    }
    constexpr Modint(int64_t val){
        x=(val<0?val%(int64_t)(Mod)+Mod:val%Mod);
    }
    inline uint64_t _get_mod(uint64_t val){
        const static uint64_t m_inv=(-1ULL)/Mod+1;
        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;
        uint64_t pro=ret*Mod;
        return (val-pro+(val<pro?Mod:0));
    }
    friend ostream &operator<<(ostream &os,Modint &b){
        return os<<b.x;
    }
    friend istream &operator>>(istream &is,Modint &b){
        return is>>b.x;
    }
    constexpr uint64_t val(){
        return x;
    }
    constexpr Modint operator+(){
        return (*this);
    }
    constexpr Modint operator-(){
        return Modint()-(*this);
    }
    constexpr Modint operator+(const Modint rhs){
        return Modint(*this)+=rhs;
    }
    constexpr Modint operator-(const Modint rhs){
        return Modint(*this)-=rhs;
    }
    constexpr Modint operator*(const Modint rhs){
        return Modint(*this)*=rhs;
    }
    constexpr Modint operator/(const Modint rhs){
        return Modint(*this)/=rhs;
    }
    constexpr Modint &operator+=(const Modint rhs){
        x+=rhs.x;
        if(x>=Mod)x-=Mod;
        return *this;
    }
    constexpr Modint &operator-=(const Modint rhs){
        if(x<rhs.x)x+=Mod;
        x-=rhs.x;
        return *this;
    }
    constexpr Modint &operator*=(const Modint rhs){
        x=_get_mod(x*rhs.x);
        return *this;
    }
    constexpr bool operator==(Modint rhs){
        return x==rhs.x;
    }
    constexpr bool operator!=(Modint rhs){
        return x!=rhs.x;
    }
    constexpr Modint &operator/=(Modint rhs){
        return (*this)*=rhs.inv();
    }
    constexpr Modint inv(){
        return (*this).pow(Mod-2);
    }
    constexpr Modint pow(uint64_t x){
        Modint ret=1;
        Modint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
    static uint64_t get_mod(){
        return Mod;
    }
};

template<int64_t id>
struct ArbitraryModint{
    uint64_t x;
    static uint64_t &mod(){
        static uint64_t Mod=0;
        return Mod;
    }
    constexpr ArbitraryModint(){
        x=0;
    }
    constexpr ArbitraryModint(int64_t val){
        x=(val<0?val%(int64_t)(get_mod())+get_mod():val%get_mod());
    }
    inline uint64_t _get_mod(uint64_t val){
        const static uint64_t m_inv=(-1ULL)/get_mod()+1;
        uint64_t ret=((unsigned __int128)(val)*m_inv)>>64;
        uint64_t pro=ret*get_mod();
        return (val-pro+(val<pro?get_mod():0));
    }
    friend ostream &operator<<(ostream &os,ArbitraryModint &b){
        return os<<b.x;
    }
    friend istream &operator>>(istream &is,ArbitraryModint &b){
        return is>>b.x;
    }
    constexpr uint64_t val(){
        return x;
    }
    constexpr ArbitraryModint operator+(){
        return (*this);
    }
    constexpr ArbitraryModint operator-(){
        return ArbitraryModint()-(*this);
    }
    constexpr ArbitraryModint operator+(const ArbitraryModint rhs){
        return Modint(*this)+=rhs;
    }
    constexpr ArbitraryModint operator-(const ArbitraryModint rhs){
        return Modint(*this)-=rhs;
    }
    constexpr ArbitraryModint operator*(const ArbitraryModint rhs){
        return Modint(*this)*=rhs;
    }
    constexpr ArbitraryModint operator/(const ArbitraryModint rhs){
        return Modint(*this)/=rhs;
    }
    constexpr ArbitraryModint &operator+=(const ArbitraryModint rhs){
        x+=rhs.x;
        if(x>=get_mod())x-=get_mod();
        return *this;
    }
    constexpr ArbitraryModint &operator-=(const ArbitraryModint rhs){
        if(x<rhs.x)x+=get_mod();
        x-=rhs.x;
        return *this;
    }
    constexpr ArbitraryModint &operator*=(const ArbitraryModint rhs){
        x=_get_mod(x*rhs.x);
        return *this;
    }
    constexpr ArbitraryModint &operator/=(ArbitraryModint rhs){
        return (*this)*=rhs.inv();
    }
    constexpr bool operator==(ArbitraryModint rhs){
        return x==rhs.x;
    }
    constexpr bool operator!=(ArbitraryModint rhs){
        return x!=rhs.x;
    }
    constexpr ArbitraryModint inv(){
        return (*this).pow(get_mod()-2);
    }
    constexpr ArbitraryModint pow(uint64_t x){
        ArbitraryModint ret=1;
        ArbitraryModint bin=(*this);
        while(x){
            if(x&1)ret*=bin;
            bin*=bin;
            x>>=1;
        }
        return ret;
    }
    static void set_mod(const uint64_t x){
        mod()=x;
    }
    static uint64_t get_mod(){
        return mod();
    }
};
template<uint64_t N> inline void print(Modint<N> a){cout << a;}
template<int64_t id> inline void print(ArbitraryModint<id> a){cout << a;}
