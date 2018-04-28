//
// Created by adrian on 24.04.18.
//
#include "transpose_handler.h"
#include <stdio.h>
#include <math.h>

MPI_Datatype column;
MPI_Datatype matrixcolumntype;

void init_transpose() {
    // MPI_Alltoallv params
    sendcounts = (int*) malloc (commsize * sizeof (int));
    recvcounts = (int*) malloc (commsize * sizeof (int));
    senddispls = (int*) malloc (commsize * sizeof (int));
    recvdispls = (int*) malloc (commsize * sizeof (int));

    for(int i = 0; i < commsize; i++) {
        sendcounts[i] = get_row_count(rank) * m;
        senddispls[i] = get_from(rank) * m;
        recvcounts[i] = get_row_count(i);
        recvdispls[i] = get_from(i);
   }

    MPI_Type_vector(m, 1, m, MPI_DOUBLE, &column);
    MPI_Type_commit(&column);
    MPI_Type_create_resized (column, 0, sizeof(double), &matrixcolumntype);
    MPI_Type_commit (&matrixcolumntype);
}

void parallel_transpose(real **bt, real **b) {
    MPI_Alltoallv(b[0], sendcounts, senddispls, MPI_DOUBLE, bt[0], recvcounts, recvdispls, matrixcolumntype, MPI_COMM_WORLD);
}

void print_arr(int rank, real** arr, bool up) {
    printf("rank %d\n", rank);
    for(int i = 0; i < (up ? m : 2); i++) {
        for(int j = 0; j < (up ? 2 : m); j++) {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}