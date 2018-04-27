//
// Created by adrian on 27.04.18.
//

#include "unit_tests.h"

void init_mockdata(int mock_n, int mock_commsize) {
    n = mock_n;
    m = n - 1;
    commsize = mock_commsize;
}

void init_from_to_unittest() {
    init_mockdata(10, 4);
    init_from_to();
    bool passed = true;

    // Expected values from test
    int *expected_from[4] = {0, 3, 5, 7};
    int *expected_to[4] = {3, 5, 7, 9};

    for(int i = 0; i < commsize; i++) {
        // Check if the expected values equal the actual values
        if(expected_from[i] != get_from(i) || expected_to[i] != get_to(i)) {
            passed = false;
            break;
        }
    }
    printf("init_from_to on process %d: %s\n", rank, (passed ? "passed" : "failed"));
}

void parallel_transpose_unittest() {
    init_mockdata(4, 2);
    init_from_to();
    init_transpose();

    double test_matrix[3][3][3] = {{{1.0,1.0,1.0},
                                     {2.0,2.0,2.0},
                                     {3.0,3.0,3.0}},

                                    {{1.0,4.0,7.0},
                                     {2.0,5.0,8.0},
                                     {3.0,6.0,9.0}},

                                    {{9.0,8.0,7.0},
                                     {6.0,5.0,4.0},
                                     {3.0,2.0,1.0}}};

    double test_matrix_expected[3][3][3] =
                                   {{{1.0,2.0,3.0},
                                     {1.0,2.0,3.0},
                                     {1.0,2.0,3.0}},

                                    {{1.0,2.0,3.0},
                                     {4.0,5.0,6.0},
                                     {7.0,8.0,9.0}},

                                    {{9.0,6.0,3.0},
                                     {8.0,5.0,2.0},
                                     {7.0,4.0,1.0}}};

    double test_matrix_target[3][3][3] =
                                    {{{0.0,0.0,0.0},
                                      {0.0,0.0,0.0},
                                      {0.0,0.0,0.0}},

                                     {{0.0,0.0,0.0},
                                      {0.0,0.0,0.0},
                                      {0.0,0.0,0.0}},

                                     {{0.0,0.0,0.0},
                                      {0.0,0.0,0.0},
                                      {0.0,0.0,0.0}}};



    real **b = mk_2D_array((size_t) m, (size_t) m, false);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            b[i][j] = 1.0/2.0;
        }
    }
    real **bt = mk_2D_array((size_t) m, (size_t) m, false);
    for(int i = 0; i < 3; i++) {
        //parallel_transpose(test_matrix_target[i], test_matrix[i]);
    }

    parallel_transpose_unittest(b, bt);

    bool passed = true;
    for(int i = 0; i < 3; i++) {
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                /*if(test_matrix_target[i][x][y] != test_matrix_expected[i][x][y]) {
                    passed = false;
                    break;
                }*/
            }
        }
    }
    printf("parallel_transpose_unittest on process %d: %s\n", rank, (passed ? "passed" : "failed"));
}