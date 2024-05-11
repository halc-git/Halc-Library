#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../Misc/Random.hpp"
#include "../../Misc/Timer.hpp"
#include "../../Template/Template.hpp"
int main() {
    int stoptime = randint(0, 1000000);
    usleep(stoptime);
    assert(abs(get_time() - stoptime) <= 500);
    LL(A, B);
    out(A + B);
}
