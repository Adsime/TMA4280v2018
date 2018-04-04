//
// Created by adrian on 01.03.18.
//

#include "iostream"
#include "math.h"
#include "../common/functions.cpp"
#include <iomanip>

using namespace std;
using namespace mach;

int main(int args, char* argv[]) {
    char c = *argv[1];
    if(c == 'u') {
        utest(false);
    } else if(c == 'v') {
        vtest(false);
    } else if(c == 'e') {
        int iter = atoi(argv[2]);
        etest(iter, false);
    }
}