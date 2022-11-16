# figures/scripts
## Description

This is the folder to hold scripts to paint the figures for our report. **cpu_plot.py** could plots the figure_cpu to figures/output folder. **gpu_plot.py** is used to produce the figure_gpu. For the distributed verison, we have distr_plot.py to paint figure_distr using results during competition, while the distr_plot_be.py is useful for repainting the figure_distr_be using results we got before competition. 

## How to run

We can run the python script using cmd. The cpu_plot.py and gpu_plot.py have the arg for data size, using '-p paper' to select data with the same size in paper. The distr_plot.py has the arg '-f .' to set the folder including '*.csv' and it can produce the figure_distr. Also, the distr_plot_be.py is the same as the distr_plot.py and it can produce the figure_distr_be. You can find the example to paint the figure in figure.sh.

## What tools and software were utilized
The script just needs python and some dependent libraries. They are listed below:

- glob
- pandas
- seaborn
- matplotlib
- numpy
- argparse

You can use pip or conda to install and manage them.