//
// Created by adriasm on 2/14/18.
//

#include "math.h"
#include <iostream>

using namespace std;

double arctan(long i, double x) {
    double modifier = 2.0*i - 1.0;
    double retVal = pow(-1.0, i-1) * (pow(x, modifier)/modifier);
    return retVal;
}

double machin_formula(long n, double x) {

    if(n < 1) return -1;
    double res = 0.0;
    for(long i = 1; i <= n; i++) {
        res += arctan(i, x);
    }
    return res;
}

int main(int args, char* argv[]) {
    int n = atoi(argv[1]);
    if(n < 1) exit(1);
    cout << "n = " << n << ". PI ~ " << 4 * (4*machin_formula(n, 1.0/5.0) - machin_formula(n, 1.0/239.0)) << endl;
    cout << "test = " << (4*machin_formula(n, 1.0/5.0) - machin_formula(n, 1.0/239.0));
}