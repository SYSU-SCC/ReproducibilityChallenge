#include <cstdlib>
#include "../include/atax.h"

int main(int argc, char **argv) {
    ataxHandle_t handle;
    int GM = 42;
    int GN = 42;
    int LMx = 42;
    int LNy = 42;
    int Px = 42;
    int Py = 42;
    double * __restrict__ A = (double*) calloc((LMx * LNy), sizeof(double));
    double * __restrict__ x = (double*) calloc(GN, sizeof(double));
    double * __restrict__ y = (double*) calloc(GN, sizeof(double));


    handle = __dace_init_atax(GM, GN, LMx, LNy, Px, Py);
    __program_atax(handle, A, x, y, GM, GN, LMx, LNy, Px, Py);
    __dace_exit_atax(handle);

    free(A);
    free(x);
    free(y);


    return 0;
}
