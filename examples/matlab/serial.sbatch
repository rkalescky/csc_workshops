#!/bin/bash
#SBATCH -J matlab          # job name
#SBATCH -o matlab_%j.log   # output file name (%j expands to jobID)
#SBATCH -e matlab_%j.error # error file name  (%j expands to jobID)
#SBATCH -p htc             # queue (partition)
#SBATCH --mem=6G           # maximum memory in GB
#SBATCH -t 15              # maximum runtime in minutes

module purge               # Unload all modules
module load matlab         # Load module needed for calculation

matlab -nojvm -nodisplay -nosplash -r example

