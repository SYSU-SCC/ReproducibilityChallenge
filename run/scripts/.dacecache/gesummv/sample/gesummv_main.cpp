#include <cstdlib>
#include "../include/gesummv.h"

int main(int argc, char **argv) {
    gesummvHandle_t handle;
    int GM = 42;
    int GN = 42;
    int LMx = 42;
    int LNy = 42;
    int Px = 42;
    int Py = 42;
    double alpha = 42;
    double beta = 42;
    double * __restrict__ A = (double*) calloc((LMx * LNy), sizeof(double));
    double * __restrict__ B = (double*) calloc((LMx * LNy), sizeof(double));
    double * __restrict__ x = (double*) calloc(GN, sizeof(double));
    double * __restrict__ y = (double*) calloc(GM, sizeof(double));


    handle = __dace_init_gesummv(GM, GN, LMx, LNy, Px, Py);
    __program_gesummv(handle, A, B, x, y, GM, GN, LMx, LNy, Px, Py, alpha, beta);
    __dace_exit_gesummv(handle);

    free(A);
    free(B);
    free(x);
    free(y);


    return 0;
}
