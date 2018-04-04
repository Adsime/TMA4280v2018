//
// Created by adrian on 12.03.18.
//

#include "omp.h"
#include "mpi.h"
#include "../common/functions.cpp"
#include "../common/mpifunctions.cpp"

using namespace zeta;

int main(int args, char* argv[]) {
    if(args < 3) {
        cout << "Usage: <iterations> <num_threads>" << endl;
        exit(1);
    }
    int nprocs, rank, intervals = atoi(argv[1]), num_t = atoi(argv[2]);
    init(args, argv, &nprocs, &rank);

    double res;
    double time;
    if(rank == 0) {
        time = MPI_Wtime();
    }
#pragma omp parallel for num_threads(num_t) schedule(guided) reduction(+:res)
    for(int i = rank + 1; i <= intervals; i += nprocs) {
        res += step(i);
    }
    finish(&res, rank, nprocs, true);
    if(rank == 0) {
        cout << "Elapsed time: " << 1000 * (MPI_Wtime() - time) << " for " << num_t << " threads." << endl;
    }
}