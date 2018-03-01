//
// Created by adrian on 01.03.18.
//

#include "math.h"

double arctan(long i, double x) {
    double modifier = 2.0*i - 1.0;
    return pow(-1.0, i-1) * (pow(x, modifier)/modifier);
}

double machin_formula(long n, double x) {
    if(n < 1) return -1;
    double res = 0.0;
    for(long i = 1; i <= n; i++) {
        res += arctan(i, x);
    }
    return res;
}

