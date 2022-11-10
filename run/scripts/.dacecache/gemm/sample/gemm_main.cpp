#include <cstdlib>
#include "../include/gemm.h"

int main(int argc, char **argv) {
    gemmHandle_t handle;
    int GK = 42;
    int LKx = 42;
    int LKy = 42;
    int LMx = 42;
    int LNy = 42;
    int Px = 42;
    int Py = 42;
    double alpha = 42;
    double beta = 42;
    double * __restrict__ A = (double*) calloc((LKy * LMx), sizeof(double));
    double * __restrict__ B = (double*) calloc((LKx * LNy), sizeof(double));
    double * __restrict__ C = (double*) calloc((LMx * LNy), sizeof(double));


    handle = __dace_init_gemm(GK, LKx, LKy, LMx, LNy, Px, Py);
    __program_gemm(handle, A, B, C, GK, LKx, LKy, LMx, LNy, Px, Py, alpha, beta);
    __dace_exit_gemm(handle);

    free(A);
    free(B);
    free(C);


    return 0;
}
