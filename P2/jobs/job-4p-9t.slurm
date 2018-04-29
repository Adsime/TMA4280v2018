#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_4p_9t"
#SBATCH --output=poisson_4p_9t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

export N=$[2**13]

echo 4 process 9 threads:
mpiexec -np 4 poisson ${N} 9 s
echo