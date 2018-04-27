//
// Created by adrian on 24.04.18.
//

#ifndef POISSON_POISSON_H
#define POISSON_POISSON_H

#include "global.h"
#include "transpose_handler.h"


// Functions
void start(real **result);
void compute(real **bt, real **b, real *grid, real *z[], int nn);

#endif //POISSON_POISSON_H
