//
// Created by adrian on 24.04.18.
//
#include "global.h"
#include "list_handler.h"


void init_list(int n, int nprocs, int rank, real h) {

    int row_c = n / nprocs;
    int rem = (n % nprocs);
    from = (rank * row_c) + (rank < rem ? rank : rem);
    to = from + row_c + (rank < rem ? 1 : 0);
}



