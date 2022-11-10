#include <dace/dace.h>
typedef void * k2mmHandle_t;
extern "C" k2mmHandle_t __dace_init_k2mm(int GK, int GM, int GN, int GR, int LKx, int LKy, int LMx, int LNx, int LNy, int LRy, int Px, int Py);
extern "C" void __dace_exit_k2mm(k2mmHandle_t handle);
extern "C" void __program_k2mm(k2mmHandle_t handle, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C, double * __restrict__ D, int GK, int GM, int GN, int GR, int LKx, int LKy, int LMx, int LNx, int LNy, int LRy, int Px, int Py, double alpha, double beta);
