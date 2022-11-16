# figure/output
## A brief description of the results in the output plots

Figure\_cpu shows the result we maintained from our experiment. The number over every benchmark over dace\_cpu colomn is the speedup times over NumPy. We paint it green if the speedup is positive and we deepen the color for bigger number. If the number is negative, we paint it red. Figure\_gpu shows the speedup for dace\_gpu over NumPy. Figure\_dist shows that the parallel efficiency and runtime for distributed version of dace.


## Comment on the speedups/performance on the team’s machine and compare them to the results in the Data-Centric Python paper

Figure\_cpu shows the result we maintained from our experiment. We notice that speedup results are better on a minority of benchmarks and worse on most benchmarks. For the total speedup, our result is worse than that of paper. Figure\_gpu shows that most of our results are similar with that of paper, while we found that three benchmarks are slower. Figure\_dist shows that we get worse results, that's mainly because we didn't use -bind-to NUMA parameter or set OMP_NUM_THREADS. However, we made a well-constructed experiment before the competition and also put it into this folder, named as "figure_dist_be". It seems that these parameters make DaCe optimize the code better. You can find how we run in 'run/scripts/run.sh'.