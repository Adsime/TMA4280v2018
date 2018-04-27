//
// Created by adrian on 24.04.18.
//

#include "global.h"

/*
 * This function is used for initializing the right-hand side of the equation.
 * Other functions can be defined to swtich between problem definitions.
 */

real rhs(real x, real y, bool ret_1) {
    return ret_1 ? 1 : 2 * (y - y * y + x - x * x);
}

/*
 * Write the transpose of b a matrix of R^(m*m) in bt.
 * In parallel the function MPI_Alltoallv is used to map directly the entries
 * stored in the array to the block structure, using displacement arrays.
 */

void transpose(real **bt, real **b, size_t m) {
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

real *mk_1D_array(size_t n, bool zero) {
    if (zero) {
        return (real *) calloc(n, sizeof(real));
    }
    return (real *) malloc(n * sizeof(real));
}

/*
 * The allocation of the two-dimensional array used for storing matrices is done
 * in the following way for a matrix in R^(n1*n2):
 * 1. an array of pointers is allocated, one pointer for each row,
 * 2. a 'flat' array of size n1*n2 is allocated to ensure that the memory space
 *   is contigusous,
 * 3. pointers are set for each row to the address of first element.
 */

real **mk_2D_array(size_t n1, size_t n2, bool zero) {
    // 1
    real **ret = (real **) malloc(n1 * sizeof(real *));

    // 2
    if (zero) {
        ret[0] = (real *) calloc(n1 * n2, sizeof(real));
    } else {
        ret[0] = (real *) malloc(n1 * n2 * sizeof(real));
    }

    // 3
    for (size_t i = 1; i < n1; i++) {
        ret[i] = ret[i - 1] + n2;
    }
    return ret;
}

void init(int argc, char **argv) {
    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /*
     *  The equation is solved on a 2D structured grid and homogeneous Dirichlet
     *  conditions are applied on the boundary:
     *  - the number of grid points in each direction is n+1,
     *  - the number of degrees of freedom in each direction is m = n-1,
     *  - the mesh size is constant h = 1/n.
     */
    if((char) *argv[3] == 't' && commsize > 1) {
        printf("Test usage: mpirun -np 1 poisson <n> 1 t\n");
        printf("Arguments:\n");
        printf("<n>: the problem size (must be a power of 2)\n");
        exit(1);
    }
    n = atoi(argv[1]);
    m = n - 1;
    h = 1.0 / n;
    numthreads = atoi(argv[2]);
}

void check_input(int argc) {
    // Check for the correct params
    if (argc < 4) {
        printf("Usage: mpirun -np <p> poisson <n> <t> <m>\n");
        printf("Arguments:\n");
        printf("<p>: process count (positive integer)\n");
        printf("<n>: the problem size (must be a power of 2)\n");
        printf("<t>: thread count (positive integer)\n");
        printf("<m>: method ('t' for tests, 's' for standard)\n");
        exit(1);
    }
}

void init_from_to() {
    from = (int *) malloc(commsize * sizeof(int));
    to = (int *) malloc(commsize * sizeof(int));
    int row_c = m / commsize;
    int rem = (m % commsize);
    for (int i = 0; i < commsize; i++) {
        from[i] = (i * row_c) + (i < rem ? i : rem);
        to[i] = from[i] + row_c + (i < rem ? 1 : 0);
    }
}

void finalize() {
    MPI_Finalize();
}

int get_row_count(int rank) {
    return to[rank] - from[rank];
}

int get_to(int rank) {
    return to[rank];
}

int get_from(int rank) {
    return from[rank];
}