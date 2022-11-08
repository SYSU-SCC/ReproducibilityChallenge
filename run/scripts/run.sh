#!/bin/bash
# this is the shell script to run all the cases

nowpwd1=$(pwd)
nowpwd2=${nowpwd1%/*}
nowpwd3=${nowpwd2%/*}
echo $nowpwd3
export repro_root=$nowpwd3/compile
source $repro_root/spack-0.18.1/share/spack/setup-env.sh
spack load gcc@10.2.0
spack load intel-oneapi-compilers
spack load mpich
#spack load openmpi
spack load intel-oneapi-mkl
spack load python@3.8.5
spack load cmake
spack load cuda@11.1
export LD_PRELOAD=$MKLROOT/lib/intel64/libmkl_rt.so
source $repro_root/env-dace/bin/activate

# single node of numpy
python3 $repro_root/npbench/run_framework.py -f numpy
# single node of dace_cpu
python3 $repro_root/npbench/run_framework.py -f dace_cpu
# single node of dace_gpu
python3 $repro_root/npbench/run_framework.py -f dace_gpu

# # multiple nodes of cpu
`which mpirun` -n 1 $repro_root/dace/samples/distributed/polybench.py