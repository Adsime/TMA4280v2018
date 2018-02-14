#include <iostream>
#include "zeta0.h"

using namespace std;

int main() {
    zeta0 zeta = zeta0();
    long n = 100;
    cout << "For n = " << n << ": pi ~ " <<zeta.riemann_zeta(n) << endl;

    return 0;
}