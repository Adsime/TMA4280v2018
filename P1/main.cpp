#include <iostream>
#include "zeta0.h"
#include "mach0.h"

using namespace std;

int main() {
    zeta0 zeta = zeta0();
    mach0 mach = mach0();
    long n = 1000000;
    cout << "Zeta For n = " << n << ": pi ~ " << zeta.riemann_zeta(n) << endl;

    double a = 4*mach.machin_formula(n, 1.0/5.0) - mach.machin_formula(n, 1.0/239.0);

    cout << "Mach For n = " << n << ": pi ~ " << a << endl;
    return 0;
}