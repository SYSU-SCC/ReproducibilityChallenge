#include <cstdlib>
#include "../include/doitgen.h"

int main(int argc, char **argv) {
    doitgenHandle_t handle;
    int GM = 42;
    int GN = 42;
    int LKx = 42;
    double * __restrict__ A = (double*) calloc(((GM * GN) * LKx), sizeof(double));
    double * __restrict__ C4 = (double*) calloc((GN * GN), sizeof(double));


    handle = __dace_init_doitgen(GM, GN, LKx);
    __program_doitgen(handle, A, C4, GM, GN, LKx);
    __dace_exit_doitgen(handle);

    free(A);
    free(C4);


    return 0;
}
