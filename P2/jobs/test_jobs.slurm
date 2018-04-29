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

echo 1 process 36 threads:
mpiexec -np 1 ../poisson $[2**10] 36 t
echo

echo 1 process 36 threads:
mpiexec -np 1 ../poisson $[2**11] 36 t
echo

echo 1 process 36 threads:
mpiexec -np 1 ../poisson $[2**12] 36 t
echo

# 2 procs, 18 threads testing

echo 2 process 18 threads:
mpiexec -np 2 ../poisson $[2**10] 18 t
echo

echo 2 process 18 threads:
mpiexec -np 2 ../poisson $[2**11] 18 t
echo

echo 2 process 18 threads:
mpiexec -np 2 ../poisson $[2**12] 18 t
echo

# 6 procs, 6 threads testing

echo 6 process 6 threads:
mpiexec -np 6 ../poisson $[2**10] 6 t
echo

echo 6 process 6 threads:
mpiexec -np 6 ../poisson $[2**11] 6 t
echo

echo 6 process 6 threads:
mpiexec -np 6 ../poisson $[2**12] 6 t
echo

# 18 procs, 2 threads testing

echo 18 process 2 threads:
mpiexec -np 18 ../poisson $[2**10] 2 t
echo

echo 18 process 2 threads:
mpiexec -np 18 ../poisson $[2**11] 2 t
echo

echo 18 process 2 threads:
mpiexec -np 18 ../poisson $[2**12] 2 t
echo

# 36 procs, 1 threads testing

echo 36 process 1 threads:
mpiexec -np 36 ../poisson $[2**10] 1 t
echo

echo 36 process 1 threads:
mpiexec -np 36 ../poisson $[2**11] 1 t
echo

echo 36 process 1 threads:
mpiexec -np 36 ../poisson $[2**12] 1 t
echo