//
// Created by adrian on 12.03.18.
//

#include "iostream"
#include "../common/functions.cpp"
#include "../common/mpifunctions.cpp"
#include "mpi.h"

using namespace std;
using namespace mach;

double a = 1.0/5.0, b = 1.0/239.0;

int main(int args, char* argv[]) {
    if(args < 2) {
        cout << "This program requires argument: number of intervals" << endl;
        return 1;
    }
    int nprocs, rank, intervals = atoi(argv[1]);
    init(args, argv, &nprocs, &rank);
    double time;
    if(rank == 0) {
        time = MPI_Wtime();
    }
    double res = (4 * mod_machin(intervals, a, nprocs, rank)) - mod_machin(intervals, b, nprocs, rank);
    // Three different methods can be used in this function. Use ALL_REDUC, REC_SUM or REDUC.
    finish(&res, rank, nprocs, false, REC_SUM);
    if(rank == 0) {
        cout << "Time elapsed in ms: " << (MPI_Wtime() - time)*1000 << endl;
    }
}