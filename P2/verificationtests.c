//
// Created by adrian on 27.04.18.
//

#include "verificationtests.h"

void start_verificationtest() {
    bool passed = true;
    real current_err = 0.0;
    real current_val = 0.0;
    int test_cases = 10;
    int results[test_cases];
    for(int i = 2; i <= test_cases; i++) {
        results[i-2] = test_n(i);
    }
    for(int i = 0; i <= test_cases-2; i++) {
        current_val = results[i];
        if(current_err > current_val) {
            passed = false;
            break;
        }
        current_err = current_val;
    }

    test_n(6);
    if(!rank) {
        printf("start_verificationtest: %s\n", (passed ? "passed" : "failed"));
    }
}

real test_n(int new_n) {
    n = new_n;
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