#!/bin/bash
# this is the shell script to install the Dace with development mode
export $repro_root=$PWD
cd $repro_root
git clone --recursive  -b v0.14.1 https://github.com/spcl/dace.git
cd $repro_root/dace
python3 -m pip install --editable . # 可能只需要下面那个指令
python3 -m pip install .[testing]  # this
cd $repro_root
