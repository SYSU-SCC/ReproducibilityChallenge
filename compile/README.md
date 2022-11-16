# compile

## Description

You can run the compile.sh to get all the softwares needed to reproduce our results in the report.

It's worth nothing that we use spack to install and manage the softwares. For the python environment, we choose venv module in python3 and we pick pip to install the python libraries.

We install CPython 3.8.5, Intel-oneapi-compilers 2022.1.0, Intel-oneapi-mkl 2022.1.0, mpich 4.0.2 and cmake 3.23.1 by spack. The microsoft-dsvm:ubuntu-hpc:2004:latest image offers us gcc 9.3.0, g++ 9.3.0, gfortran 9.3.0 and cuda 11.1.

Also, for the python library, we use pip to mainly install NumPy 1.19.2 with Intel-MKL support, cupy 8.3.0, and mpi4py 3.1.4 for mpich.

For more information about the library installed, you can read the shell script or connect with us.

## How to run?

You can simply run the compilation.sh for the first time. However, if you meet some problem, then you may need to clear the download or installed folders and restart it. Run the seperate shell script could help sometime if you know how we construct the folder.

## Shell script

