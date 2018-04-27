//
// Created by adrian on 27.04.18.
//

#include "unit_tests.h"

void init_mockdata() {
    n = 10;
    m = n - 1;
    commsize = 4;
}

void init_from_to_unittest() {
    init_from_to();
    bool passed = true;
    int *expected_from[4] = {0, 3, 5, 7};
    int *expected_to[4] = {3, 5, 7, 9};

    for(int i = 0; i < commsize; i++) {
        if(expected_from[i] != get_from(i) || expected_to[i] != get_to(i)) {
            printf("expected: %d, actual: %d", expected_to[i], get_to(i));
            passed = false;
            break;
        }
    }
    printf("init_from_to on process %d: %s\n", rank, (passed ? "passed" : "failed"));
}

void parallel_transpose_unittest() {

}