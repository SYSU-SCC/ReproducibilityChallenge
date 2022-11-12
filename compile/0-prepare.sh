d#!/bin/bash
# this is the shell script to prepare for the before need
export repro_root=$PWD
export TMP=/shared/home/ccuser/tmp
export tempdir=/shared/home/ccuser/tmp
cd $repro_root
# to get the spack software
wget https://github.com/spack/spack/releases/download/v0.18.1/spack-0.18.1.tar.gz
tar -zxvf spack-0.18.1.tar.gz
rm -rf spack-0.18.1.tar.gz
source spack-0.18.1/share/spack/setup-env.sh
export TMP=/shared/home/ccuser/tmp
export tempdir=/shared/home/ccuser/tmp
# sudo echo source $spack_root/spack-0.18.1/share/spack/setup-env.sh >> ~/.bashrc

# to install the software
spack compiler find
#spack install gcc@10.2.0
#spack load gcc@10.2.0
#spack compiler find
spack install python@3.8.5%gcc@9.3.0
spack install intel-oneapi-compilers%gcc@9.3.0
#spack install cuda@11.1%gcc@10.2.0
#spack install intel-oneapi-mpi%gcc@10.2.0
#spack install openmpi%gcc@10.2.0
#spack install mpich%gcc@10.2.0
spack install intel-oneapi-mkl%gcc@9.3.0
spack install cmake%gcc@9.3.0
spack install ucx~cm+cma+dc+dm+ib_hw_tm+mlx5_dv+rc+rdmacm+thread_multiple+ucg+ud+verbs


# load the software
#spack load /u7sdlqy
spack load cmake
spack load python@3.8.5

# to start the venv
mkdir download
python3 -m venv env-dace
source env-dace/bin/activate
