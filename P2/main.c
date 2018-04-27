//
// Created by adrian on 24.04.18.
//
#include "global.h"
#include "poisson.h"
#include "unit_tests.h"

int main(int argc, char **argv) {
    check_input(argc);
    init(argc, argv);
    char marg = (char) *argv[3];
    switch(marg) {
        case 's':
            start();
            break;
        case 't':
            init_mockdata();
            init_from_to_unittest();
            break;
    }
    finalize();
    return 0;
}