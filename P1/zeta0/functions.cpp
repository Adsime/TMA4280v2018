//
// Created by adrian on 01.03.18.
//

#include "math.h"

double riemann_zeta(long n) {
    double res = 0.0;
    for(long i = 1; i <= n; i++) {
        res += 1.0/pow(i, 2.0);
    }
    return res;
}

double fix_to_pi(double res) {
    return sqrt(6 * res);
}