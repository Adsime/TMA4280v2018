//
// Created by adrian on 12.03.18.
//

#include "omp.h"
#include "iostream"
#include "../common/functions.cpp"

using namespace std;
using namespace mach;

double a = 1.0/5.0, b = 1.0/239.0;

int main(int args, char* argv[]) {
    if(args < 3) {
        cout << "Usage: <iterations> <num_threads>" << endl;
        exit(1);
    }
    int iter = atoi(argv[1]), num_t = atoi(argv[2]);
    double pi;

#pragma omp parallel for num_threads(num_t) schedule(guided) reduction(+:pi)
    for(long i = 1; i <= iter; i++) {
        pi += 4 * step(i, a) - step(i, b);
    }
    pi = fix_to_pi(pi);
    cout << setprecision(60) << "Approximate to pi: " << pi << endl;
    cout << "Error zeta2: " << fabs(M_PI - pi) << " for " << num_t << " threads." << endl;
}