#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_36p_1t"
#SBATCH --output=poisson_36p_1t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

export N=$[2**13]

echo 36 process 1 threads:
mpiexec -np 36 poisson ${N} 1 s
echo