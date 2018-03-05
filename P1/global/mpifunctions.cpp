//
// Created by adrian on 02.03.18.
//
#ifndef mpifunctions
#define mpifunctions

#include "mpi.h"
#include "iostream"
#include "functions.cpp"
#include "math.h"
#include "iomanip"

using namespace std;

void init(int args, char *argv[], int *nprocs, int *rank, int *intervals) {
    MPI_Init(&args, &argv); // Init MPI
    MPI_Comm_size(MPI_COMM_WORLD, nprocs); // Get number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, rank); // Get current process rank
    *intervals = atoi(argv[1]); // Assign number of intervals specified at launch
    // Exit program if is not power of 2
    if((*nprocs == 0 || (*nprocs & (*nprocs - 1))) && *rank == 0) {
        MPI_Finalize();
        cout << "You have entered " << *nprocs << " number of processes.\n"
                << "It should be a power of 2 (2^n)." << endl;
        exit(1);
    }
}

double finish(double *res, int rank, bool isZeta) {
    // Store the value of pi
    double pi;

    // Sum the values from all the processes and store the result in 'pi'
    MPI_Reduce(res, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Ensures only process 0 prints
    if(rank == 0) {
        // Depending on which method is used, calculate accordingly.
        pi = (isZeta ? zeta::fix_to_pi(pi) : mach::fix_to_pi(pi));
        string fct = (isZeta ? "Zeta" : "Mach");
        cout << setprecision(60) << "PI approximate for " << fct << " - " << pi << endl;
        cout << "Error for " << fct << " - " << fabs(M_PI - pi) << endl;
    }
    // Finalize
    MPI_Finalize();
}

#endif