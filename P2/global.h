//
// Created by adrian on 24.04.18.
//

#ifndef POISSON_GLOBAL_H
#define POISSON_GLOBAL_H

#include <stdio.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>
#include <stdlib.h>
#include "timing.h"

// Global definitions
#define true 1
#define false 0
#define PI 3.14159265358979323846

// Global type def
typedef double real;
typedef int bool;

// Global vars
int rank, commsize, n, m, numthreads;
real h;
int *from, *to;

// Project attached functions
real *mk_1D_array(size_t n, bool zero);
real **mk_2D_array(size_t n1, size_t n2, bool zero);
real rhs(real x, real y, char task);

// Functions implemented in FORTRAN in fst.f and called from C.
// The trailing underscore comes from a convention for symbol names, called name
// mangling: if can differ with compilers.
void fst_(real *v, int *n, real *w, int *nn);
void fstinv_(real *v, int *n, real *w, int *nn);

void init(int argc, char **argv);
void check_input(int argc);

void finalize();

void init_from_to();

int get_row_count(int rank);
int get_from(int rank);
int get_to(int rank);
int get_responsible_process(int j);


#endif //POISSON_GLOBAL_H
