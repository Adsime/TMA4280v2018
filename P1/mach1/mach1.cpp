//
// Created by adrian on 01.03.18.
//
#include "iostream"
#include "../global/functions.cpp"
#include "../global/mpifunctions.cpp"
#include "mpi.h"

using namespace std;
using namespace mach;

double a = 1.0/5.0, b = 1.0/239.0;

int main(int args, char* argv[]) {
    if(args < 2) {
        cout << "This program requires argument: number of intervals" << endl;
        return 1;
    }
    int nprocs, rank, intervals;
    init(args, argv, &nprocs, &rank, &intervals);
    double time;
    if(rank == 0) {
        time = MPI_Wtime();
    }
    double res = (4 * mod_machin(intervals, a, nprocs, rank)) - mod_machin(intervals, b, nprocs, rank);
    finish(&res, rank, false);
    cout << rank << " " << res << endl;
    if(rank == 0) {
        cout << "Time elapsed in ms: " << (MPI_Wtime() - time)*1000 << endl;
    }
}