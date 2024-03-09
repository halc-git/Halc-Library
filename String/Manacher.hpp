#pragma once
//https://snuke.hatenablog.com/entry/2014/12/02/235837
template<typename S>
vector<int32_t> manacher(S s,bool is_even=true){
    int32_t i=0,j=0,k,sz=(s.size()<<is_even)-is_even;
    vector<int32_t> ret(sz);
    while(i<sz){
        if(is_even){
            while(i-j>=-1&&i+j<=sz&&(((i-j)&1)||s[(i-j)>>1]==s[(i+j)>>1]))j++;
        }
        else{
            while(i-j>=0&&i+j<sz&&s[i-j]==s[i+j])j++;
        }
        ret[i]=j;
        k=1;
        while(i-k>=0&&k+ret[i-k]<j){ret[i+k]=ret[i-k];k++;}
        i+=k;
        j-=k;
    }
    for(int32_t i=0; i<sz; i++){
        if(is_even){
            ret[i]--;
        }
        else{
            ret[i]=(ret[i]<<1)-1;
        }
    }
    return ret;
}