//
// Created by adrian on 01.03.18.
//

#ifndef functions
#define functions

#include "math.h"
#include "vector"
#include "iostream"
#include "iomanip"

using namespace std;

namespace zeta {

    double step(long i) {
        return 1.0/pow(i, 2.0);
    }

    double riemann_zeta(long n, int processCount = 1, int process = 0) {
        double res = 0.0;
        for(long i = process+1; i <= n; i += processCount) {
            res += step(i);
        }
        return res;
    }

    double fix_to_pi(double res) {
        return sqrt(6 * res);
    }

    double start(char *c) {
        int n = atoi(c);
        if(n < 1) exit(1);
        double res = riemann_zeta(n);
        res = fix_to_pi(res);
        cout << "n = " << n << ". PI ~ " << res << endl;
        return res;
    }
}

namespace mach {
    double step(long i, double x) {
        double modifier = 2.0*i - 1.0;
        return pow(-1.0, i-1.0) * (pow(x, modifier)/modifier);
    }

    double machin_formula(long n, double x, int processCount = 1, int process = 0) {
        if(n < 1) return -1;
        double res = 0.0;
        for(long i = process+1; i <= n; i += processCount) {
            res += step(i, x);
        }
        cout << setprecision(60) << res << endl;
        return res;
    }

    double fix_to_pi(double res) {
        return 4.0 * res;
    }

    double start(char *c) {
        int n = atoi(c);
        if(n < 1) exit(1);
        double res = (4*machin_formula(n, 1.0/5.0) - machin_formula(n, 1.0/239.0));
        cout << "n = " << n << ". PI ~ " << fix_to_pi(res) << endl;
        return res;
    }
}

#endif