#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_9p_4t"
#SBATCH --output=poisson_9p_4t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

export N=$[2**14]

echo 9 processes 4 threads:
mpiexec -np 9 ../poisson ${N} 4 s
echo