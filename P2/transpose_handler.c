//
// Created by adrian on 24.04.18.
//
#include "transpose_handler.h"
#include <stdio.h>
#include <math.h>

void init_transpose() {
    // MPI_Alltoallv params
    sendcounts = (int*) malloc (commsize * sizeof (int));
    recvcounts = (int*) malloc (commsize * sizeof (int));
    senddispls = (int*) malloc (commsize * sizeof (int));
    recvdispls = (int*) malloc (commsize * sizeof (int));

    for(int i = 0; i < commsize; i++) {
        sendcounts[i] = get_row_count(rank) * m;
        senddispls[i] = 0;
        recvcounts[i] = get_row_count(i) * m;
        recvdispls[i] = 0;
    }
}

void parallel_transpose(real **bt, real **b) {
    MPI_Alltoallv(b[get_from(rank)][0], sendcounts, senddispls, MPI_DOUBLE, bt[get_from(rank)][0], recvcounts, recvdispls, MPI_DOUBLE, MPI_COMM_WORLD);
}

void transpose_destroy() {
    realloc(sendcounts, commsize * sizeof (int));
    realloc(recvcounts, commsize * sizeof (int));
    realloc(senddispls, commsize * sizeof (int));
    realloc(recvdispls, commsize * sizeof (int));
}