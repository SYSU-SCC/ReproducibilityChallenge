#include <cstdlib>
#include "../include/k2mm.h"

int main(int argc, char **argv) {
    k2mmHandle_t handle;
    int GK = 42;
    int GM = 42;
    int GN = 42;
    int GR = 42;
    int LKx = 42;
    int LKy = 42;
    int LMx = 42;
    int LNx = 42;
    int LNy = 42;
    int LRy = 42;
    int Px = 42;
    int Py = 42;
    double alpha = 42;
    double beta = 42;
    double * __restrict__ A = (double*) calloc((LKy * LMx), sizeof(double));
    double * __restrict__ B = (double*) calloc((LKx * LNy), sizeof(double));
    double * __restrict__ C = (double*) calloc((LNx * LRy), sizeof(double));
    double * __restrict__ D = (double*) calloc((LMx * LRy), sizeof(double));


    handle = __dace_init_k2mm(GK, GM, GN, GR, LKx, LKy, LMx, LNx, LNy, LRy, Px, Py);
    __program_k2mm(handle, A, B, C, D, GK, GM, GN, GR, LKx, LKy, LMx, LNx, LNy, LRy, Px, Py, alpha, beta);
    __dace_exit_k2mm(handle);

    free(A);
    free(B);
    free(C);
    free(D);


    return 0;
}
