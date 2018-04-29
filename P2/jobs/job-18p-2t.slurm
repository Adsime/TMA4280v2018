#!/bin/sh
#SBATCH --partition=TRAINING
#SBATCH --time=00:30:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=16
#SBATCH --mem=100000
#SBATCH --job-name="poisson_18p_2t"
#SBATCH --output=poisson_18p_2t.out
#SBATCH --mail-user=tobjoh1994@gmail.com
#SBATCH --mail-type=ALL

module load GCC OpenMPI

export N=$[2**13]

echo 18 process 2 threads:
mpiexec -np 18 poisson ${N} 2 s
echo