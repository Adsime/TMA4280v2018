//
// Created by adrian on 01.03.18.
//

#include "iostream"
#include "../global/functions.cpp"
#include "../global/mpifunctions.cpp"
#include "mpi.h"

using namespace std;
using namespace zeta;

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
    double res = riemann_zeta(intervals, nprocs, rank);
    finish(&res, rank, true);
    if(rank == 0) {
        cout << "Time elapsed: " << (MPI_Wtime() - time) * 1000 << endl;
    }
}