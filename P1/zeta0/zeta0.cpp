//
// Created by adriasm on 2/14/18.
//

#include "zeta0.h"
#include <math.h>
#include <iostream>
#include <omp.h>

double zeta0::riemann_zeta(long n) {
    double res = 0.0;
    for(long i = 1; i <= n; i++) {
        res += 1.0/pow(i, 2.0);
    }
    return res;
}
