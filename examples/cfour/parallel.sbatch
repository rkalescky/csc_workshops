#!/bin/bash
#SBATCH -J cfour
#SBATCH -o cfour_%j.out
#SBATCH -p standard-mem-s
#sbatch --mem=250G
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2
#SBATCH --cpus-per-task=18

module purge
module load cfour

scratch="${SLURM_JOB_NAME}_${SLURM_JOB_ID}"
mkdir ${scratch}
lfs setstripe -c 2 ${scratch}
cp ZMAT GENBAS ${scratch}/
cd ${scratch}

xcfour

