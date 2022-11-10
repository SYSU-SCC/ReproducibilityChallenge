#!/bin/bash
# this is the shell script to run all the cases

nowpwd1=$(pwd)
nowpwd2=${nowpwd1%/*}
nowpwd3=${nowpwd2%/*}
echo $nowpwd3
export repro_root=$nowpwd3/compile
source $repro_root/spack-0.18.1/share/spack/setup-env.sh
spack unload -a
spack load gcc@10.2.0
spack load intel-oneapi-compilers
spack load mpich /avbqtm3
#spack load openmpi
spack load intel-oneapi-mkl
spack load python@3.8.5
spack load cmake /xolhqpb
#spack load cuda@11.1
export LD_PRELOAD=$MKLROOT/lib/intel64/libmkl_rt.so
source $repro_root/env-dace/bin/activate

# single node of numpy
python3 $repro_root/npbench/run_framework.py -f numpy -p paper
# single node of dace_cpu
#python3 $repro_root/npbench/run_framework.py -f dace_cpu -p paper
# single node of dace_gpu
#python3 $repro_root/npbench/run_framework.py -f dace_gpu -p paper

# # multiple nodes of cpu
#`which mpirun` -n 1 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 1 -hosts compute-permanent-node-191 -bind-to core -ppn 1 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 2 -hosts compute-permanent-node-191,compute-permanent-node-332 -bind-to core -ppn 1 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 4 -hosts compute-permanent-node-191,compute-permanent-node-332 -bind-to core -ppn 1 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 8 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 2 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 16 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 4 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 32 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 8 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 64 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 16 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 128 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 32 python3 $repro_root/dace/samples/distributed/polybench.py
#echo "------------------------------------------------------------------"
#`which mpirun` -n 256 -hosts compute-permanent-node-191,compute-permanent-node-332,compute-permanent-node-373,compute-permanent-node-682 -ppn 64 python3 $repro_root/dace/samples/distributed/polybench.py
