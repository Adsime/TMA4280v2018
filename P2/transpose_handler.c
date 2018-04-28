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
    counts = (int*) malloc (commsize * sizeof (int));
    displs = (int*) malloc (commsize * sizeof (int));
    int displ = 0;
    sendcounts = (int*) malloc (commsize * sizeof (int));
    recvcounts = (int*) malloc (commsize * sizeof (int));
    senddispls = (int*) malloc (commsize * sizeof (int));
    recvdispls = (int*) malloc (commsize * sizeof (int));

//    for(int i = 0; i < commsize; i++) {
//        sendcounts[i] = get_row_count(rank) * m;
//        senddispls[i] = get_from(rank) * m;
//        recvcounts[i] = get_row_count(i);
//        recvdispls[i] = get_from(i);
//
//        printf("Rank: %d, %d, %d, %d, %d\n", rank, sendcounts[i], senddispls[i], recvcounts[i], recvdispls[i]);
//    }

    for(int i = 0; i < commsize; i++) {
        sendcounts[i] = get_row_count(rank) * m;
        senddispls[i] = 0;
        recvcounts[i] = get_row_count(i) * m;
        recvdispls[i] = 0;
    }

    /*for(int i = 0; i < commsize; i++) {
        counts[i] = get_row_count(i);
        displs[i] = displ;
        printf("rank: %d, count = %d, displ = %d\n", rank, counts[i], displs[i]);
        displ += get_row_count(i);
    }

    MPI_Type_vector(m, 1, m, MPI_DOUBLE, &column);
    MPI_Type_commit(&column);
    MPI_Type_create_resized (column, 0, sizeof(double), &matrixcolumntype);
    MPI_Type_commit (&matrixcolumntype);*/
}

void parallel_transpose(real **bt, real **b) {

    MPI_Alltoallv(b[0], sendcounts, senddispls, MPI_DOUBLE, bt[0], recvcounts, recvdispls, MPI_DOUBLE, MPI_COMM_WORLD);

    //MPI_Alltoallv(b[0], sendcounts, senddispl, MPI_DOUBLE, bt[0], recvcounts, recvdispl, matrixcolumntype, MPI_COMM_WORLD);
}

void print_arr(char name[], int* arr) {
    printf("%s\n", name);
    for(int i = 0; i < 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}