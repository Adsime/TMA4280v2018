//
// Created by adrian on 27.04.18.
//

#include "unit_tests.h"

void init_from_to_unittest() {
    init_from_to();

    // Expected values from test
    int expected_from = 0;
    int expected_to = m;
    bool passed = expected_from == get_from(rank) && expected_to == get_to(rank);

    printf("init_from_to on process %d: %s\n", rank, (passed ? "passed" : "failed"));
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
    printf("parallel_transpose_unittest on process %d: %s\n", rank, (passed ? "passed" : "failed"));
    print_arr("expected", expected);
    print_arr("actual", bt);
}