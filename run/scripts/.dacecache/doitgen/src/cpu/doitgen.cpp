/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"
#include "mkl.h"
#include "../include/dace_blas.h"

struct doitgen_t {

};

void __program_doitgen_internal(doitgen_t *__state, double * __restrict__ A, double * __restrict__ C4, int GM, int GN, int LKx)
{

    {

        {
            #pragma omp parallel for
            for (auto k = 0; k < LKx; k += 1) {
                double* A_0_0;
                A_0_0 = &A[((GM * GN) * k)];
                double *__tmp0;
                __tmp0 = new double DACE_ALIGN(64)[(GM * GN)];
                {
                    double* _a = &A_0_0[0];
                    double* _b = &C4[0];
                    double* _c = __tmp0;

                    ///////////////////
                    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, GN, GM, GN, double(1), _b, GN, _a, GN, double(0), _c, GN);
                    ///////////////////

                }

                dace::CopyNDDynamic<double, 1, false, 2>::Dynamic::Copy(
                __tmp0, A + ((GM * GN) * k), GM, GN, GN, GN, 1, 1);
                delete[] __tmp0;
            }
        }

    }
}

DACE_EXPORTED void __program_doitgen(doitgen_t *__state, double * __restrict__ A, double * __restrict__ C4, int GM, int GN, int LKx)
{
    __program_doitgen_internal(__state, A, C4, GM, GN, LKx);
}

DACE_EXPORTED doitgen_t *__dace_init_doitgen(int GM, int GN, int LKx)
{
    int __result = 0;
    doitgen_t *__state = new doitgen_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_doitgen(doitgen_t *__state)
{
    delete __state;
}

