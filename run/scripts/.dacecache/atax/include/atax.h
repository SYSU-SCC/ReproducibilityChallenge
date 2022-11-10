#include <dace/dace.h>
typedef void * ataxHandle_t;
extern "C" ataxHandle_t __dace_init_atax(int GM, int GN, int LMx, int LNy, int Px, int Py);
extern "C" void __dace_exit_atax(ataxHandle_t handle);
extern "C" void __program_atax(ataxHandle_t handle, double * __restrict__ A, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py);
