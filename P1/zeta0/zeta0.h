//
// Created by adriasm on 2/14/18.
//

#ifndef P1_ZETA0_H
#define P1_ZETA0_H

#include "math.h"

class zeta0 {

public:
    static double riemann_zeta(long n) {
        double res = 0.0;
        for(long i = 1; i <= n; i++) {
            res += 1.0/pow(i, 2.0);
        }
        return sqrt(6 * res);
    }
};


#endif //P1_ZETA0_H
