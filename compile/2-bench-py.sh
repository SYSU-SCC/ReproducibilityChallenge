#!/bin/bash
# this is the script to download the npbench
export repro_root=$PWD
cd $repro_root
git clone -b scc22 https://github.com/spcl/npbench.git
cd $repro_root/npbench
# python3 -m pip install -r requirements.txt
python3 -m pip install matplotlib
python3 -m pip install numpy==1.19.2
python3 -m pip install pandas==1.3.0
python3 -m pip install pygount
python3 -m pip install scipy
python3 -m pip install .
# python3 -m pip install numba==0.51.2
# python3 -m pip install pythran==0.9.9
python3 -m pip install cupy==8.3.0
cd $repro_root
