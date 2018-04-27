//
// Created by adrian on 27.04.18.
//

#include "timing.h"

void time_start() {
    t = MPI_Wtime();
}

void time_stop(char method[]) {
    double res = (MPI_Wtime() - t) * 1000;
    printf("Time elapsed method: %s - Time %f ms\n", method, res);
}