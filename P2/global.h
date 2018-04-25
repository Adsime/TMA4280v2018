//
// Created by adrian on 24.04.18.
//

#ifndef POISSON_GLOBAL_H
#define POISSON_GLOBAL_H

#include <stdio.h>
#include <mpi.h>
#include <omp.h>

// Global definitions
#define true 1
#define false 0
#define PI 3.14159265358979323846

// Global type def
typedef double real;
typedef int bool;

int rank, commsize, n, m;
real h;

double t;
int from, to;

// Project attached functions
real *mk_1D_array(size_t n, bool zero);
real **mk_2D_array(size_t n1, size_t n2, bool zero);
void transpose(real **bt, real **b, size_t m);
real rhs(real x, real y);

// Functions implemented in FORTRAN in fst.f and called from C.
// The trailing underscore comes from a convention for symbol names, called name
// mangling: if can differ with compilers.
void fst_(real *v, int *n, real *w, int *nn);
void fstinv_(real *v, int *n, real *w, int *nn);

void time_start();
void time_stop(char method[]);

void print_asd(real **arr, int rows, int columns);

void init(int argc, char **argv);
void usage_err();
void finalize();

int get_row_count();
int get_from();
int get_to();

#endif //POISSON_GLOBAL_H
