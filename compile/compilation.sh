#!/bin/bash
# this is the shell scripy to compile for all the software
startTime=`date +"%Y-%m-%d %H:%M:%S"`
export repro_root=$PWD
cd $repro_root
source 0-prepare.sh
source 1-install-dace.sh
source 2-bench-py.sh
endTime=`date +"%Y-%m-%d %H:%M:%S"`
st=`date -d  "$startTime" +%s`
et=`date -d  "$endTime" +%s`
sumTime=$(($et-$st))
echo "Total time is : $sumTime second."

