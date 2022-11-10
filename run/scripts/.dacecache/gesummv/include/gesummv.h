#include <dace/dace.h>
typedef void * gesummvHandle_t;
extern "C" gesummvHandle_t __dace_init_gesummv(int GM, int GN, int LMx, int LNy, int Px, int Py);
extern "C" void __dace_exit_gesummv(gesummvHandle_t handle);
extern "C" void __program_gesummv(gesummvHandle_t handle, double * __restrict__ A, double * __restrict__ B, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py, double alpha, double beta);
