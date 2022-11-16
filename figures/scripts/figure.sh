#!/bin/bash

python3 cpu_plot.py -p paper
python3 gpu_plot.py -p paper
python3 distr_plot.py -p paper -f ../../run/output/core
python3 distr_plot_before.py -p paper -f ../../run/output/numa
rm -f tmp