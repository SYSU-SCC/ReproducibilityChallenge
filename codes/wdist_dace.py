# Original code: https://stackoverflow.com/a/19285289
# License: CC BY-SA 3.0 (https://creativecommons.org/licenses/by-sa/3.0/legalcode)
# This version: https://github.com/serge-sans-paille/numpy-benchmarks/blob/deef91c2db87b682d7670f5d4a8a6e8ae29ebdd9/numpy_benchmarks/benchmarks/wdist.py

import dace
import numpy as np

K, M, N = (dace.symbol(s) for s in ('K', 'M', 'N'))

@dace.program
def wdist(A:dace.float64[K,M], B:dace.float64[K,N], W:dace.float64[K,M]):

    k,m = A.shape
    _,n = B.shape
    D = np.zeros((m, n))

    for ii in range(m):
        for jj in range(n):
            wdiff = (A[:,ii] - B[:,jj]) / W[:,ii]
            wdiff2=wdiff**2
            tmp = wdiff2.sum()
            D[ii,jj] = np.sqrt(tmp)
    return D
