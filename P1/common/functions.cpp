//
// Created by adrian on 01.03.18.
//

#ifndef functions
#define functions

#include "math.h"
#include "vector"
#include "iostream"
#include "iomanip"
#include "filehandler.cpp"
#include <sstream>

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

    double mod_machin(long n, double x, int processCount = 1, int process = 0) {
        double res = 0.0;
        int interv = n/processCount;
        for(long i = (process * interv) + 1; i <= (process + 1) * interv && i <= n; i++) {
            res += mach::step(i, x);
        }
        int rest = n % processCount;
        if(processCount < n && rest > 0 && process < rest) {
            res += mach::step(n - rest + process + 1, x);
        }
    }

    double machin_formula(long n, double x, int processCount = 1, int process = 0) {
        if(n < 1) return -1;
        double res = 0.0;
        for(long i = process+1; i <= n; i += processCount) {
            res += mach::step(i, x);
        }
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

void utest(bool isZeta) {
    double test_case;
    double res;
    if(isZeta) {
        test_case = 49.0/36.0;
        res = zeta::riemann_zeta(3);
    } else {
        res = (4*mach::machin_formula(3, 1.0/5.0) - mach::machin_formula(3, 1.0/239.0));
        test_case = 37012.0/46875.0 - 48941844013.0/11697168977985.0;
    }
    cout << "Test = " << test_case << ". Actual = " << res << endl;
    cout << "Actual equality = " << ((res == test_case) ? "True" : "False") << endl;
}

void vtest(bool isZeta) {
    string fct = (isZeta ? "Zeta" : "Mach");
    task(test_path, true, "Exercise 3 - VTest: " + fct);
    for(int i = 1; i <= 24; i++) {
        long n = pow(2, i);
        ostringstream text;
        text << "For n = " << n << " (2^" << i << ") ";
        text << fabs(M_PI - (isZeta ? zeta::fix_to_pi(zeta::riemann_zeta(n)) :
                                      mach::fix_to_pi(4*mach::machin_formula(n, 1.0/5.0)
                                                      - mach::machin_formula(n, 1.0/239.0))));
        write_to_file(text.str());
    }
    task(test_path, false, "Exercise 3 - VTest: " + fct);
}

void etest(int iter, bool isZeta) {
    double res = isZeta ? zeta::fix_to_pi(zeta::riemann_zeta(iter)) :
                 mach::fix_to_pi((4*mach::machin_formula(iter, 1.0/5.0) -
                         mach::machin_formula(iter, 1.0/239.0)));
    cout << setprecision(60) << "Mach single p error: " << fabs(M_PI - res) << endl;
}

#endif