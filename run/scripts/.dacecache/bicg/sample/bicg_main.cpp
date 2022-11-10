#include <cstdlib>
#include "../include/bicg.h"

int main(int argc, char **argv) {
    bicgHandle_t handle;
    int GM = 42;
    int GN = 42;
    int LMx = 42;
    int LNy = 42;
    int Px = 42;
    int Py = 42;
    double * __restrict__ A = (double*) calloc((LMx * LNy), sizeof(double));
    double * __restrict__ o1 = (double*) calloc(GN, sizeof(double));
    double * __restrict__ o2 = (double*) calloc(GM, sizeof(double));
    double * __restrict__ p = (double*) calloc(GN, sizeof(double));
    double * __restrict__ r = (double*) calloc(GM, sizeof(double));


    handle = __dace_init_bicg(GM, GN, LMx, LNy, Px, Py);
    __program_bicg(handle, A, o1, o2, p, r, GM, GN, LMx, LNy, Px, Py);
    __dace_exit_bicg(handle);

    free(A);
    free(o1);
    free(o2);
    free(p);
    free(r);


    return 0;
}
