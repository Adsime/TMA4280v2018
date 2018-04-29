//
// Created by adrian on 24.04.18.
//
#ifndef MAIN_FILE
#define MAIN_FILE

#include "poisson.h"
#include "unit_tests.h"
#include "verificationtests.h"

void print_stuff(real **a, char name[]) {
    printf("%s\n", name);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    check_input(argc);
    init(argc, argv);
    char marg = (char) *argv[3];
    switch(marg) {
        case 's':
            start(marg);
            break;
        case 't':
            init_from_to_unittest();
            parallel_transpose_unittest();
            start_verificationtest();
            break;
        case 'a':
            n = 4;
            m = n-1;
            init_from_to();
            init_transpose();
            real **arr = mk_2D_array(m, m, false);
            real **res = mk_2D_array(m, m, false);
            real counter = 1.0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < m; j++) {
                    arr[i][j] = counter++;
                }
            }
            parallel_transpose(res, arr);
            if(!rank) {
                print_stuff(arr, "original");
                print_stuff(res, "result");
            }
            break;
    }

    finalize();
    return 0;
}



#endif //MAIN_FILE