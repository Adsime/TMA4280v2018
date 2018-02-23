//
// Created by adriasm on 2/14/18.
//

#include "zeta0.h"
#include <math.h>
#include <iostream>

using namespace std;

int main(int args, char* argv[]) {
    int n = atoi(argv[1]);
    if(n < 1) exit(1);
    cout << "n = " << n << ". PI ~ " << zeta0::riemann_zeta(n) << endl;
}