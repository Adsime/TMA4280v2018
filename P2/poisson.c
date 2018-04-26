/**
 * C program to solve the two-dimensional Poisson equation on
 * a unit square using one-dimensional eigenvalue decompositions
 * and fast sine transforms.
 *
 * Einar M. Rønquist
 * NTNU, October 2000
 * Revised, October 2001
 * Revised by Eivind Fonn, February 2015
 */
#include "poisson.h"


void start() {
    init_list();

    init_transpose();

    /*
     * Grid points are generated with constant mesh size on both x- and y-axis.
     */
    real *grid = mk_1D_array((size_t) n+1, false);
#pragma omp parallel for num_threads(numthreads) schedule(static)
    for (size_t i = 0; i < n+1; i++) {
        grid[i] = i * h;
    }
    /*
     * The diagonal of the eigenvalue matrix of T is set with the eigenvalues
     * defined Chapter 9. page 93 of the Lecture Notes.
     * Note that the indexing starts from zero here, thus i+1.
     */
    real *diag = mk_1D_array((size_t) m, false);
#pragma omp parallel for num_threads(numthreads) schedule(static)
    for (size_t i = 0; i < m; i++) {
        diag[i] = 2.0 * (1.0 - cos((i+1) * PI / n));
    }
    /*
     * Allocate the matrices b and bt which will be used for storing value of
     * G, \tilde G^T, \tilde U^T, U as described in Chapter 9. page 101.
     */
    real **b = mk_2D_array((size_t) m, (size_t) m, false);
    real **bt = mk_2D_array((size_t) m, (size_t) m, false);
    /*
     * This vector will holds coefficients of the Discrete Sine Transform (DST)
     * but also of the Fast Fourier Transform used in the FORTRAN code.
     * The storage size is set to nn = 4 * n, look at Chapter 9. pages 98-100:
     * - Fourier coefficients are complex so storage is used for the real part
     *   and the imaginary part.
     * - Fourier coefficients are defined for j = [[ - (n-1), + (n-1) ]] while
     *   DST coefficients are defined for j [[ 0, n-1 ]].
     * As explained in the Lecture notes coefficients for positive j are stored
     * first.
     * The array is allocated once and passed as arguments to avoid doings
     * reallocations at each function call.
     */
    int nn = 4 * n;
    real *z[numthreads];
    for(int i = 0; i < numthreads; i++) {
        z[i] = mk_1D_array((size_t)nn, false);
    }

    /*
     * Step 1: Initialize the right hand side data for a given rhs function.
     * Note that the right hand-side is set at nodes corresponding to degrees
     * of freedom, so it excludes the boundary (bug fixed by petterjf 2017).
     *
     * Step 2: Compute \tilde G^T = S^-1 * (S * G)^T (Chapter 9. page 101 step 1)
     * Instead of using two matrix-matrix products the Discrete Sine Transform
     * (DST) is used.
     * The DST code is implemented in FORTRAN in fsf.f and can be called from C.
     * The array zz is used as storage for DST coefficients and internally for
     * FFT coefficients in fst_ and fstinv_.
     * In functions fst_ and fst_inv_ coefficients are written back to the input
     * array (first argument) so that the initial values are overwritten.
     */

    compute(bt, b, grid, z, nn);


    /*
     * Step 1: Solve Lambda * \tilde U = \tilde G (Chapter 9. page 101 step 2)
     *
     * Step 2: Compute U = S^-1 * (S * Utilde^T) (Chapter 9. page 101 step 3)
     *
     *
     */
    compute(b, bt, grid, z, nn);

    /*
     * Compute maximal value of solution for convergence analysis in L_\infty
     * norm.
     */
    double u_max = 0.0;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < m; j++) {
            u_max = u_max > b[i][j] ? u_max : b[i][j];
        }
    }

    printf("u_max = %e\n", u_max);
}

// Helper function to extract similar code
void compute(real **bt, real **b, real *grid, real *z[], int nn) {
    // Step 1
#pragma omp parallel for num_threads(numthreads) schedule(static)
    for (size_t i = (size_t) get_from(rank); i < get_to(rank); i++) {
        for (size_t j = 0; j < m; j++) {
            b[i][j] = h * h * rhs(grid[i+1], grid[j+1], false);
        }
    }

    // Step 2
#pragma omp parallel for num_threads(numthreads) schedule(static)
    for (size_t i = 0; i < m; i++) {
        fst_(b[i], &n, z[omp_get_thread_num()], &nn);
    }
    parallel_transpose(bt, b);

#pragma omp parallel for num_threads(numthreads) schedule(static)
    for (size_t i = 0; i < m; i++) {
        fstinv_(bt[i], &n, z[omp_get_thread_num()], &nn);
    }
}

void test() {
    real **arr = mk_2D_array(4, 4, true);
}



