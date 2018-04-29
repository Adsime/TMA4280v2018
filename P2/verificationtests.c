//
// Created by adrian on 27.04.18.
//

#include "verificationtests.h"

void start_verificationtest() {
    bool passed = true;
    real current_val = 0.0;
    real res = 0.0;
    for(int i = 2; i <= 10; i++) {
        res = test_n(i);
        if(current_val > res) {
            passed = false;
            break;
        }
        current_val = res;
    }
    if(!rank) {
        printf("start_verificationtest on process %d: %s\n", rank, (passed ? "passed" : "failed"));
    }
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