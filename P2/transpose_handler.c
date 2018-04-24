//
// Created by adrian on 24.04.18.
//
#include "transpose_handler.h"

void init_transpose() {
    // MPI_Alltoallv params
    sendcounts = (int*) malloc (commsize * sizeof (int));
    recvcounts = (int*) malloc (commsize * sizeof (int));
    senddispl = (int*) malloc (commsize * sizeof (int));
    recvdispl = (int*) malloc (commsize * sizeof (int));

    for(int i = 0; i < commsize; i++) {
        sendcounts[i] = get_row_count() * m;
        senddispl[i] = get_from() * m;
        recvcounts[i] = get_to() - get_from();
        recvdispl[i] = get_from();
    }
    printf("Rank: %d, To: %d, from: %d\n", rank, to, from);
    /*printasd(sendcounts, "1");
    printasd(senddispl, "2");
    printasd(recvcounts, "3");
    printasd(recvdispl, "4");*/
}

void parallel_transpose(real **bt, real **b) {

}

void printasd(int *arr, char *method) {
    printf("Method: %s. Size of arr: %d commsize: %d\n", method, sizeof(arr)/ sizeof(arr[0]), commsize);
    printf("Method: %s. rank: %d: ", method, rank);
    for(int i = 0; i < commsize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}