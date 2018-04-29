//
// Created by adrian on 27.04.18.
//

#include "unit_tests.h"

void init_from_to_unittest() {
    if(!rank) {
        int holder_n = n;
        int holder_m = m;
        n = 10;
        m = n - 1;
        init_from_to();
        int expected_from = 0;
        int expected_to = m/commsize + (m % commsize > 0 ? 1 : 0);
        bool passed = expected_from == get_from(rank) && expected_to == get_to(rank);

        printf("init_from_to on: %s\n", (passed ? "passed" : "failed"));
        n = holder_n;
        m = holder_m;
    }
    // Expected values from test

}

void parallel_transpose_unittest() {
    init_from_to();
    init_transpose();
    // Test matrix
    real **b = mk_2D_array(m, m, false);
    // Transpose target test matrix
    real **bt = mk_2D_array(m, m, false);

    // Populate test matrix with test values
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = 1.0/(1+i+j);
        }
    }

    parallel_transpose(bt, b);
    if(!rank) {
        bool passed = true;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                // test actual to manual transpose
                if(bt[i][j] != b[j][i]) {
                    passed = false;
                    break;
                }

            }
        }
        real **expected = mk_2D_array(m, m, false);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                // test actual to manual transpose
                expected[i][j] = b[j][i];
            }
        }
        printf("parallel_transpose_unittest: %s\n", (passed ? "passed" : "failed"));
    }
}