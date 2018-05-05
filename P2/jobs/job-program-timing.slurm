#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_1p_36t"
#SBATCH --output=poisson_1p_36t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

# 1 procs, 36 threads testing

echo 1 process 36 threads n=2^10:
mpiexec -np 1 ../poisson $[2**10] 36 s
echo

echo 1 process 36 threads n=2^11:
mpiexec -np 1 ../poisson $[2**11] 36 s
echo

echo 1 process 36 threads n=2^12:
mpiexec -np 1 ../poisson $[2**12] 36 s
echo

# 6 procs, 6 threads testing

echo 6 process 6 threads n=2^10:
mpiexec -np 6 ../poisson $[2**10] 6 s
echo

echo 6 process 6 threads n=2^11:
mpiexec -np 6 ../poisson $[2**11] 6 s
echo

echo 6 process 6 threads n=2^12:
mpiexec -np 6 ../poisson $[2**12] 6 s
echo

# 12 procs, 3 threads testing

echo 12 process 3 threads n=2^10:
mpiexec -np 12 ../poisson $[2**10] 3 s
echo

echo 12 process 3 threads n=2^11:
mpiexec -np 12 ../poisson $[2**11] 3 s
echo

echo 12 process 3 threads n=2^12:
mpiexec -np 12 ../poisson $[2**12] 3 s
echo

# 36 procs, 1 threads testing

echo 36 process 1 threads n=2^10:
mpiexec -np 36 ../poisson $[2**10] 1 s
echo

echo 36 process 1 threads n=2^11:
mpiexec -np 36 ../poisson $[2**11] 1 s
echo

echo 36 process 1 threads n=2^12:
mpiexec -np 36 ../poisson $[2**12] 1 s
echo
