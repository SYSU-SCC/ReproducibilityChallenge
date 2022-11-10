#include <dace/dace.h>
typedef void * gemmHandle_t;
extern "C" gemmHandle_t __dace_init_gemm(int GK, int LKx, int LKy, int LMx, int LNy, int Px, int Py);
extern "C" void __dace_exit_gemm(gemmHandle_t handle);
extern "C" void __program_gemm(gemmHandle_t handle, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C, int GK, int LKx, int LKy, int LMx, int LNy, int Px, int Py, double alpha, double beta);
