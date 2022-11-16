# Original code: https://github.com/rasbt/One-Python-benchmark-per-day/blob/9511f6539223843172259f3fe64cc2968404b147/ipython_nbs/day10_fortran_lstsqr.ipynb
# This version: https://github.com/serge-sans-paille/numpy-benchmarks/blob/deef91c2db87b682d7670f5d4a8a6e8ae29ebdd9/numpy_benchmarks/benchmarks/lstsqr.py

import dace
import numpy as np

N = dace.symbol('N',dtype=dace.int64)
@dace.program
def lstsqr(x:dace.float64[N], y:dace.float64[N]):
    """ Computes the least-squares solution to a linear matrix equation. """
    x_avg = dace.define_local_scalar(dace.float64)
    y_avg = dace.define_local_scalar(dace.float64)
    x_sum = x.sum()
    y_sum = y.sum()
    # for i in range(N):
    #     x_sum += x[i]
    #     y_sum += y[i]
    x_avg =x_sum / N
    y_avg =y_sum / N
    # dx,dy
    # for i in range(N):
    #     dx[i] = x[i] - x_avg
    #     dy[i] = y[i] - y_avg
    dx = x - x_avg
    dy = y - y_avg
    
    var_x = np.sum(dx**2)
    cov_xy = np.sum(dx * dy)
    slope = cov_xy / var_x
    y_interc = y_avg - slope*x_avg
    return (slope, y_interc)
