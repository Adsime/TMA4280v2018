//
// Created by adrian on 24.04.18.
//
#ifndef MAIN_FILE
#define MAIN_FILE

#include "poisson.h"
#include "unit_tests.h"

int main(int argc, char **argv) {
    check_input(argc);
    init(argc, argv);
    real **res = mk_2D_array(1, 1, false);
    char marg = (char) *argv[3];
    switch(marg) {
        case 's':
            start(res);
            break;
        case 't':
            init_from_to_unittest();
            parallel_transpose_unittest();

            for(int i = 8; i < 1025; i*=2) {

            }
            break;
    }
    finalize();
    return 0;
}

#endif //MAIN_FILE