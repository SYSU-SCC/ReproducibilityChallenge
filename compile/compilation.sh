#!/bin/bash
# this is the shell scripy to compile for all the software
export repro_root=$PWD
cd $repro_root
source 0-prepare.sh
source 1-install-dace.sh
source 2-bench-py.sh
