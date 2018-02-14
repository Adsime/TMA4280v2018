//
// Created by adriasm on 2/14/18.
//

#include "zeta0.h"
#include <math.h>

double zeta0::riemann_zeta(long n) {
        if(n < 1) return -1;
        double res = 0;
        for(long i = 1; i <= n; i++) {
            res += 1/pow(i, 2);
        }
        return res;
    }
