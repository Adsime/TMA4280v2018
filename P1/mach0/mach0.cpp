//
// Created by adriasm on 2/14/18.
//

#include "mach0.h"
#include "math.h"

double mach0::machin_formula(long n, double x) {

    if(n < 1) return -1;
    double res = 0.0;
    for(long i = 1; i < n; i++) {
        res += arctan(i, x);
    }
    return res;
}

double mach0::arctan(long i, double x) {
    return pow(x, i-1.0) * (pow(x, 2.0*i - 1.0)/(2.0*i - 1.0));
}