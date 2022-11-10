#include <dace/dace.h>
typedef void * bicgHandle_t;
extern "C" bicgHandle_t __dace_init_bicg(int GM, int GN, int LMx, int LNy, int Px, int Py);
extern "C" void __dace_exit_bicg(bicgHandle_t handle);
extern "C" void __program_bicg(bicgHandle_t handle, double * __restrict__ A, double * __restrict__ o1, double * __restrict__ o2, double * __restrict__ p, double * __restrict__ r, int GM, int GN, int LMx, int LNy, int Px, int Py);
