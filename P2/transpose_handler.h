//
// Created by adrian on 24.04.18.
//

#ifndef POISSON_TRANSPOSE_HANDLER_H
#define POISSON_TRANSPOSE_HANDLER_H

#include "global.h"

int *sendcounts;
int *recvcounts;
int *senddispls;
int *recvdispls;

int *displs;
int *counts;

void init_transpose();
void parallel_transpose(real **bt, real **b);

void print_arr(char name[], int* arr);

#endif //POISSON_TRANSPOSE_HANDLER_H
