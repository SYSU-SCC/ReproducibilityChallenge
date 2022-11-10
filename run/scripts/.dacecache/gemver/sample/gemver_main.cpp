#include <cstdlib>
#include "../include/gemver.h"

int main(int argc, char **argv) {
    gemverHandle_t handle;
    int GM = 42;
    int GN = 42;
    int LMx = 42;
    int LNy = 42;
    int Px = 42;
    int Py = 42;
    double alpha = 42;
    double beta = 42;
    double * __restrict__ A = (double*) calloc((LMx * LNy), sizeof(double));
    double * __restrict__ u1 = (double*) calloc(LMx, sizeof(double));
    double * __restrict__ u2 = (double*) calloc(LMx, sizeof(double));
    double * __restrict__ v1 = (double*) calloc(LNy, sizeof(double));
    double * __restrict__ v2 = (double*) calloc(LNy, sizeof(double));
    double * __restrict__ w = (double*) calloc(GM, sizeof(double));
    double * __restrict__ x = (double*) calloc(GN, sizeof(double));
    double * __restrict__ y = (double*) calloc(GM, sizeof(double));
    double * __restrict__ z = (double*) calloc(GN, sizeof(double));


    handle = __dace_init_gemver(GM, GN, LMx, LNy, Px, Py);
    __program_gemver(handle, A, u1, u2, v1, v2, w, x, y, z, GM, GN, LMx, LNy, Px, Py, alpha, beta);
    __dace_exit_gemver(handle);

    free(A);
    free(u1);
    free(u2);
    free(v1);
    free(v2);
    free(w);
    free(x);
    free(y);
    free(z);


    return 0;
}
