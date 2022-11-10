#include <cstdlib>
#include "../include/k3mm.h"

int main(int argc, char **argv) {
    k3mmHandle_t handle;
    int GK = 42;
    int GM = 42;
    int GN = 42;
    int GR = 42;
    int GS = 42;
    int LKx = 42;
    int LKy = 42;
    int LMx = 42;
    int LNx = 42;
    int LNy = 42;
    int LRx = 42;
    int LRy = 42;
    int LSy = 42;
    int Px = 42;
    int Py = 42;
    double * __restrict__ A = (double*) calloc((LKy * LMx), sizeof(double));
    double * __restrict__ B = (double*) calloc((LKx * LNy), sizeof(double));
    double * __restrict__ C = (double*) calloc((LNx * LRy), sizeof(double));
    double * __restrict__ D = (double*) calloc((LRx * LSy), sizeof(double));
    double * __restrict__ E = (double*) calloc((LMx * LSy), sizeof(double));


    handle = __dace_init_k3mm(GK, GM, GN, GR, GS, LKx, LKy, LMx, LNx, LNy, LRx, LRy, LSy, Px, Py);
    __program_k3mm(handle, A, B, C, D, E, GK, GM, GN, GR, GS, LKx, LKy, LMx, LNx, LNy, LRx, LRy, LSy, Px, Py);
    __dace_exit_k3mm(handle);

    free(A);
    free(B);
    free(C);
    free(D);
    free(E);


    return 0;
}
