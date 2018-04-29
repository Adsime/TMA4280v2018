#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_3p_12t"
#SBATCH --output=poisson_3p_12t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

export N=$[2**13]

echo 3 process 12 threads:
mpiexec -np 3 poisson ${N} 12 s
echo