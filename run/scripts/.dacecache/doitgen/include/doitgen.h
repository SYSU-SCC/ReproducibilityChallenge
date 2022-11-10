#include <dace/dace.h>
typedef void * doitgenHandle_t;
extern "C" doitgenHandle_t __dace_init_doitgen(int GM, int GN, int LKx);
extern "C" void __dace_exit_doitgen(doitgenHandle_t handle);
extern "C" void __program_doitgen(doitgenHandle_t handle, double * __restrict__ A, double * __restrict__ C4, int GM, int GN, int LKx);
