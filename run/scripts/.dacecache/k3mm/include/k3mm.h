#include <dace/dace.h>
typedef void * k3mmHandle_t;
extern "C" k3mmHandle_t __dace_init_k3mm(int GK, int GM, int GN, int GR, int GS, int LKx, int LKy, int LMx, int LNx, int LNy, int LRx, int LRy, int LSy, int Px, int Py);
extern "C" void __dace_exit_k3mm(k3mmHandle_t handle);
extern "C" void __program_k3mm(k3mmHandle_t handle, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C, double * __restrict__ D, double * __restrict__ E, int GK, int GM, int GN, int GR, int GS, int LKx, int LKy, int LMx, int LNx, int LNy, int LRx, int LRy, int LSy, int Px, int Py);
