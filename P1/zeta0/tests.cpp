//
// Created by adriasm on 2/23/18.
//

#include <iostream>
#include "zeta0.h"

using namespace std;

double test_zeta(double test) {
    double a = zeta0::riemann_zeta(3);
    return test - a;
}

int main(int args, char* argv[]) {
    double test_case = 2.85774;
    cout << "test case = " << test_case << ". Difference in test case vs zeta is: " << test_zeta(test_case) << endl;
    return 1;
}
