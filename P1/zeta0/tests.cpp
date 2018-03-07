//
// Created by adriasm on 2/23/18.
//

#include "../global/functions.cpp"
#include "iostream"
#include "math.h"
#include "../global/filehandler.cpp"
#include <sstream>
#include <iomanip>

using namespace std;
using namespace zeta;

void utest() {
    double test_case = 49.0/36.0;
    double res = riemann_zeta(3);
    cout << "Test = " << test_case << ". Actual = " << res << endl;
    cout << "Actual equality = " << ((res == test_case) ? "True" : "False") << endl;
}

void vtest() {
    task(test_path, true, "Exercise 3 - VTest: zeta");
    double res;
    for(int i = 1; i <= 24; i++) {
        long n = pow(2, i);
        res = riemann_zeta(n);
        ostringstream text;
        text << fabs(M_PI - fix_to_pi(res));
        write_to_file(text.str());
    }
    task(test_path, false, "Exercise 3 - VTest: zeta");
}

void etest(int iter) {
    cout << setprecision(60) << "Zeta single p error: " << fabs(M_PI - fix_to_pi(riemann_zeta(iter))) << endl;
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
