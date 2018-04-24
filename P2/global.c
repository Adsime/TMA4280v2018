//
// Created by adrian on 24.04.18.
//

#include <stdlib.h>
#include "global.h"

/*
 * This function is used for initializing the right-hand side of the equation.
 * Other functions can be defined to swtich between problem definitions.
 */

real rhs(real x, real y) {
    return 2 * (y - y*y + x - x*x);
}

/*
 * Write the transpose of b a matrix of R^(m*m) in bt.
 * In parallel the function MPI_Alltoallv is used to map directly the entries
 * stored in the array to the block structure, using displacement arrays.
 */

void transpose(real **bt, real **b, size_t m)
{
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            bt[i][j] = b[j][i];
        }
    }
}

/*
 * The allocation of a vectore of size n is done with just allocating an array.
 * The only thing to notice here is the use of calloc to zero the array.
 */

real *mk_1D_array(size_t n, bool zero)
{
    if (zero) {
        return (real *)calloc(n, sizeof(real));
    }
    return (real *)malloc(n * sizeof(real));
}

/*
 * The allocation of the two-dimensional array used for storing matrices is done
 * in the following way for a matrix in R^(n1*n2):
 * 1. an array of pointers is allocated, one pointer for each row,
 * 2. a 'flat' array of size n1*n2 is allocated to ensure that the memory space
 *   is contigusous,
 * 3. pointers are set for each row to the address of first element.
 */

real **mk_2D_array(size_t n1, size_t n2, bool zero)
{
    // 1
    real **ret = (real **)malloc(n1 * sizeof(real *));

    // 2
    if (zero) {
        ret[0] = (real *)calloc(n1 * n2, sizeof(real));
    }
    else {
        ret[0] = (real *)malloc(n1 * n2 * sizeof(real));
    }

    // 3
    for (size_t i = 1; i < n1; i++) {
        ret[i] = ret[i-1] + n2;
    }
    return ret;
}

void time_start() {
    t = MPI_Wtime();
}

void time_stop(char method[]) {
    double res = (MPI_Wtime() - t) * 1000;
    //printf("Time elapsed method: %s - Time %f ms\n", method, res);
}

void print_asd(real **arr, int m) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void init(int argc, char **argv) {
    // Initialize MPI
    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    // Check for the correct params
    //TODO add threads
    if (argc < 3) {
        usage_err();
    }

    /*
     *  The equation is solved on a 2D structured grid and homogeneous Dirichlet
     *  conditions are applied on the boundary:
     *  - the number of grid points in each direction is n+1,
     *  - the number of degrees of freedom in each direction is m = n-1,
     *  - the mesh size is constant h = 1/n.
     */
    n = atoi(argv[1]);
    m = n - 1;
    h = 1.0 / n;
}

void usage_err() {
    printf("Usage:\n");
    printf("  poisson n\n\n");
    printf("Arguments:\n");
    printf("  n: the problem size (must be a power of 2)\n");
}

void finalize() {
    MPI_Finalize();
}

int get_row_count() {
    return to - from;
}

int get_to() {
    return to;
}

int get_from() {
    return from;
}