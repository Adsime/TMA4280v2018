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

int ALL_REDUC = 0, REC_SUM = 1, REDUC = 2;

void init(int args, char *argv[], int *nprocs, int *rank) {
    MPI_Init(&args, &argv); // Init MPI
    MPI_Comm_size(MPI_COMM_WORLD, nprocs); // Get number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, rank); // Get current process rank
    // Exit program if is not power of 2
    if((*nprocs == 0 || (*nprocs & (*nprocs - 1))) && *rank == 0) {
        MPI_Finalize();
        cout << "You have entered " << *nprocs << " number of processes.\n"
                << "It should be a power of 2 (2^n)." << endl;
        exit(1);
    }
}

double rec_sum(double pi, int nprocs, int rank) {
    int stop = log2(nprocs);
    double sum = pi;
    for(int i = 0; i < stop; i++) {
        int q = rank xor int(pow(2, i));
        MPI_Send(&sum, 1, MPI_DOUBLE, q, 0, MPI_COMM_WORLD);
        double r = 0;
        MPI_Recv(&r, 1, MPI_DOUBLE, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        sum += r;
    }
    return sum;
}

double finish(double *res, int rank, int nprocs, bool isZeta, int method=REDUC) {
    // Store the value of pi
    double pi;

    if(method == ALL_REDUC) {
        MPI_Allreduce(res, &pi, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    } else if(method == REC_SUM) {
        pi = rec_sum(*res, nprocs, rank);
    } else {
        // Sum the values from all the processes and store the result in 'pi'
        MPI_Reduce(res, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    }
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