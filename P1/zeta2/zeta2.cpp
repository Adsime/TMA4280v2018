//
// Created by adrian on 12.03.18.
//

#include "omp.h"
#include "iostream"
#include "../common/functions.cpp"

using namespace std;
using namespace zeta;

int main(int args, char* argv[]) {
    if(args < 3) {
        cout << "Usage: <iterations> <num_threads>" << endl;
        exit(1);
    }
    int iter = atoi(argv[1]), num_t = atoi(argv[2]);
    double pi;

#pragma omp parallel for num_threads(num_t) schedule(guided) reduction(+:pi)
    for(long i = 1; i <= iter; i++) {
        pi += step(i);
    }
    pi = fix_to_pi(pi);
    cout << setprecision(60) << "Approximate to pi: " << pi << endl;
    cout << "Error zeta2: " << fabs(M_PI - pi) << " for " << num_t << " threads." << endl;
}