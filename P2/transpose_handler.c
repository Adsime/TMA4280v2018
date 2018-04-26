//
// Created by adrian on 24.04.18.
//
#include "transpose_handler.h"

MPI_Datatype column;
MPI_Datatype matrixcolumntype;

void init_transpose() {
    // MPI_Alltoallv params
    sendcounts = (int*) malloc (commsize * sizeof (int));
    recvcounts = (int*) malloc (commsize * sizeof (int));
    senddispl = (int*) malloc (commsize * sizeof (int));
    recvdispl = (int*) malloc (commsize * sizeof (int));

    for(int i = 0; i < commsize; i++) {
        sendcounts[i] = get_row_count(rank) * m;
        senddispl[i] = get_from(rank) * m;
        recvcounts[i] = get_row_count(i);
        recvdispl[i] = get_from(i);
    }

    MPI_Type_vector(m, 1, m, MPI_DOUBLE, &column);
    MPI_Type_commit(&column);
    MPI_Type_create_resized (column, 0, sizeof(double), &matrixcolumntype);
    MPI_Type_commit (&matrixcolumntype);
}

void parallel_transpose(real **bt, real **b) {
    MPI_Alltoallv(b[0], sendcounts, senddispl, MPI_DOUBLE, bt[0], recvcounts, recvdispl, matrixcolumntype, MPI_COMM_WORLD);
}