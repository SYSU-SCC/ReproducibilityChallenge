#include <dace/dace.h>
typedef void * gemverHandle_t;
extern "C" gemverHandle_t __dace_init_gemver(int GM, int GN, int LMx, int LNy, int Px, int Py);
extern "C" void __dace_exit_gemver(gemverHandle_t handle);
extern "C" void __program_gemver(gemverHandle_t handle, double * __restrict__ A, double * __restrict__ u1, double * __restrict__ u2, double * __restrict__ v1, double * __restrict__ v2, double * __restrict__ w, double * __restrict__ x, double * __restrict__ y, double * __restrict__ z, int GM, int GN, int LMx, int LNy, int Px, int Py, double alpha, double beta);
