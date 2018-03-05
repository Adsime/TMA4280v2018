//
// Created by adrian on 01.03.18.
//

#include "../global/functions.cpp"
#include "iostream"
#include "math.h"
#include "../global/filehandler.cpp"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace mach;

void utest() {
    double res = (4*machin_formula(3, 1.0/5.0) - machin_formula(3, 1.0/239.0));
    double test_case = 37012.0/46875.0 - 48941844013.0/11697168977985.0;
    cout << "Test = " << test_case << ". Actual = " << res << endl;
    cout << "Actual equality = " << ((res == test_case) ? "True" : "False") << endl;
}

void vtest() {
    task(test_path, true, "Exercise 3 - VTest: mach");
    double res = 0;
    for(int i = 1; i <= 24; i++) {
        long n = pow(2, i);
        res = (4*machin_formula(n, 1.0/5.0) - machin_formula(n, 1.0/239.0));
        ostringstream text;
        text << fabs(M_PI - fix_to_pi(res));
        write_to_file(text.str());
    }
    task(test_path, false, "Exercise 3 - VTest: mach");
}

void etest(int iter) {
    double res = (4*machin_formula(iter, 1.0/5.0) - machin_formula(iter, 1.0/239.0));
    cout << "Zeta single p error: " << fabs(M_PI - fix_to_pi(res)) << endl;
}

int main(int args, char* argv[]) {
    char c = *argv[1];
    if(c == 'u') {
        utest();
    } else if(c == 'v') {
        vtest();
    } else if(c == 'e') {
        int iter = atoi(argv[2]);
        etest(iter);
    }
}