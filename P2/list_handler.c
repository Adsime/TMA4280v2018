//
// Created by adrian on 24.04.18.
//
#include "global.h"
#include "list_handler.h"

void init_list() {
    from = (int*) malloc(commsize * sizeof(int));
    to = (int*) malloc(commsize * sizeof(int));
    int row_c = m / commsize;
    int rem = (m % commsize);
    for(int i = 0; i < commsize; i++) {
        from[i] = (i * row_c) + (i < rem ? i : rem);
        to[i] = from[i] + row_c + (i < rem ? 1 : 0);
    }
}