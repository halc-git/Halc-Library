#pragma once
//https://snuke.hatenablog.com/entry/2014/12/03/214243
template<typename S>
vector<int> z_algorithm(S s){
    int sz=s.size();
    vector<int> ret(sz);
    ret[0]=sz;
    int i=1,j=0,k;
    while(i<sz){
        while(i+j<sz&&s[j]==s[i+j])j++;
        ret[i]=j;
        if(j==0){i++;continue;}
        k=1;
        while(i+k<sz&&k+ret[k]<j){
            ret[i+k]=ret[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    return ret;
}