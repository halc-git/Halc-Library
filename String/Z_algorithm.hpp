#pragma once
#include <vector>
// https://snuke.hatenablog.com/entry/2014/12/03/214243
template <typename S>
std::vector<int32_t> z_algorithm(S s) {
    int32_t sz = s.size(), i = 1, j = 0, k;
    std::vector<int32_t> ret(sz);
    ret[0] = sz;
    while (i < sz) {
        while (i + j < sz && s[j] == s[i + j]) j++;
        ret[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        k = 1;
        while (i + k < sz && k + ret[k] < j) {
            ret[i + k] = ret[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return ret;
}