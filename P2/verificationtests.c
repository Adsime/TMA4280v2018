//
// Created by adrian on 27.04.18.
//

#include "verificationtests.h"

void start_verificationtest() {
    bool passed = true;
    real test_1 = test_n(2);
    real test_2 = test_n(6);
    printf("n=1: %lf\nn=10: %lf\n", test_1, test_2);

    //printf("start_verificationtest on process %d: %s\n", rank, (passed ? "passed" : "failed"));
}

real test_n(int n) {
    n = n;
    m = n - 1;
    real **result = start('t');
    real avg = 0.0;
    real ** correct = mk_2D_array(m, m, false);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            correct[i][j] = correct_val(i+1, j+1);
        }
    }
    real err = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            real inverr = fabs(result[i][j] - correct[i][j]);
            err = err < inverr ? inverr : err;
        }
    }
    return err;
}

real correct_val(real x, real y) {
    return sin(PI*x) * sin(2*PI*y);
}