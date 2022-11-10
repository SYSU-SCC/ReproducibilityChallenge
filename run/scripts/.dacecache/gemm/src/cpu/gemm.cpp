/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"
#include "mkl.h"
#include "mkl_scalapack.h"
#include "mkl_blacs.h"
#include "mkl_pblas.h"

struct gemm_t {
    int * __restrict__ __0___tmp0;
    int * __restrict__ __0___tmp1;
    double * __restrict__ __0___tmp2;
    double * __restrict__ __0___tmp5;
    MKL_INT __mkl_scalapack_context;
    MKL_INT __mkl_scalapack_rank, __mkl_scalapack_size;
    MKL_INT __mkl_scalapack_prows = 0, __mkl_scalapack_pcols = 0;
    MKL_INT __mkl_scalapack_myprow = 0, __mkl_scalapack_mypcol = 0;
    MKL_INT __mkl_int_zero = 0, __mkl_int_one = 1, __mkl_int_negone = -1;
    bool __mkl_scalapack_grid_init = false;
};

void __program_gemm_internal(gemm_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C, int GK, int LKx, int LKy, int LMx, int LNy, int Px, int Py, double alpha, double beta)
{

    {

        {
            int* __out = __state->__0___tmp0;

            ///////////////////
            // Tasklet code (_set_a_bsizes_)
            __out[0] = LMx;
            __out[1] = LKy;
            ///////////////////

        }
        {
            int* __out = __state->__0___tmp1;

            ///////////////////
            // Tasklet code (_set_b_sizes_)
            __out[0] = LKx;
            __out[1] = LNy;
            ///////////////////

        }
        {
            double* _a = &A[0];
            double* _b = &B[0];
            int* _a_block_sizes = &__state->__0___tmp0[0];
            int* _b_block_sizes = &__state->__0___tmp1[0];
            double* _c = __state->__0___tmp2;

            ///////////////////

            const double zero = 0.0E+0, one = 1.0E+0;
            const char trans = 'N';
            MKL_INT gc_rows = LNy*Py;
            MKL_INT gc_cols = LMx*Px;
            MKL_INT ga_rows = GK;
            MKL_INT ga_cols = LMx*Px;
            MKL_INT gb_rows = LNy*Py;
            MKL_INT gb_cols = GK;
            MKL_INT lc_rows = _b_block_sizes[1];
            MKL_INT lc_cols = _a_block_sizes[0];
            MKL_INT la_rows = _a_block_sizes[1];
            MKL_INT la_cols = _a_block_sizes[0];
            MKL_INT lb_rows = _b_block_sizes[1];
            MKL_INT lb_cols = _b_block_sizes[0];
            MKL_INT n_lc_rows = numroc_( &gc_rows, &lc_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_lc_cols = numroc_( &gc_cols, &lc_cols, &__state->__mkl_scalapack_mypcol, &__state->__mkl_int_zero, &__state->__mkl_scalapack_pcols);
            MKL_INT c_lld = max(n_lc_rows, 1);
            MKL_INT n_la_rows = numroc_( &ga_rows, &la_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_la_cols = numroc_( &ga_cols, &la_cols, &__state->__mkl_scalapack_mypcol, &__state->__mkl_int_zero, &__state->__mkl_scalapack_pcols);
            MKL_INT a_lld = max(n_la_rows, 1);
            MKL_INT n_lb_rows = numroc_( &gb_rows, &lb_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_lb_cols = numroc_( &gb_cols, &lb_cols, &__state->__mkl_scalapack_mypcol, &__state->__mkl_int_zero, &__state->__mkl_scalapack_pcols);
            MKL_INT b_lld = max(n_lb_rows, 1);
            MKL_INT info;
            MKL_INT _c_ldesc[9], _a_ldesc[9],  _b_ldesc[9];
            descinit_(_c_ldesc, &gc_rows, &gc_cols, &lc_rows, &lc_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &c_lld, &info);
            descinit_(_a_ldesc, &ga_rows, &ga_cols, &la_rows, &la_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &a_lld, &info);
            descinit_(_b_ldesc, &gb_rows, &gb_cols, &lb_rows, &lb_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &b_lld, &info);
            MKL_INT _m = gc_rows, _n = gc_cols, _k = ga_rows;
            pdgemm_(
            &trans, &trans, &_m, &_n, &_k, &one, _b, &__state->__mkl_int_one, &__state->__mkl_int_one, _b_ldesc,
            _a, &__state->__mkl_int_one, &__state->__mkl_int_one, _a_ldesc, &zero, _c, &__state->__mkl_int_one, &__state->__mkl_int_one, _c_ldesc);

            ///////////////////

        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < LMx; __i0 += 1) {
                for (auto __i1 = 0; __i1 < LNy; __i1 += 1) {
                    double __s0_n12__out_n13IN___tmp4;
                    {
                        double __in1 = beta;
                        double __in2 = C[((LNy * __i0) + __i1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __s0_n12__out_n13IN___tmp4 = __out;
                    }
                    double __s0_n9__out_n10IN___tmp3;
                    {
                        double __in1 = alpha;
                        double __in2 = __state->__0___tmp2[((LNy * __i0) + __i1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __s0_n9__out_n10IN___tmp3 = __out;
                    }
                    {
                        const double __in1 = __s0_n9__out_n10IN___tmp3;
                        const double __in2 = __s0_n12__out_n13IN___tmp4;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __state->__0___tmp5[((LNy * __i0) + __i1)] = __out;
                    }
                }
            }
        }

        dace::CopyNDDynamic<double, 1, false, 2>::Dynamic::Copy(
        __state->__0___tmp5, C, LMx, LNy, LNy, LNy, 1, 1);

    }
}

DACE_EXPORTED void __program_gemm(gemm_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C, int GK, int LKx, int LKy, int LMx, int LNy, int Px, int Py, double alpha, double beta)
{
    __program_gemm_internal(__state, A, B, C, GK, LKx, LKy, LMx, LNy, Px, Py, alpha, beta);
}

DACE_EXPORTED gemm_t *__dace_init_gemm(int GK, int LKx, int LKy, int LMx, int LNy, int Px, int Py)
{
    int __result = 0;
    gemm_t *__state = new gemm_t;


    {  // Environment: IntelMKLScaLAPACKMPICH
        
        blacs_pinfo(&__state->__mkl_scalapack_rank, &__state->__mkl_scalapack_size);
        blacs_get(&__state->__mkl_int_negone, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context);
        if (!__state->__mkl_scalapack_grid_init) {{
                
                __state->__mkl_scalapack_prows = Py;
                
                __state->__mkl_scalapack_pcols = Px;
                
                blacs_gridinit(&__state->__mkl_scalapack_context, "C", &__state->__mkl_scalapack_prows, &__state->__mkl_scalapack_pcols);
                
                blacs_gridinfo(&__state->__mkl_scalapack_context, &__state->__mkl_scalapack_prows, &__state->__mkl_scalapack_pcols, &__state->__mkl_scalapack_myprow, &__state->__mkl_scalapack_mypcol);
                
                __state->__mkl_scalapack_grid_init = true;
                
        }}
        
        
    }
    __state->__0___tmp0 = new int DACE_ALIGN(64)[2];
    __state->__0___tmp1 = new int DACE_ALIGN(64)[2];
    __state->__0___tmp2 = new double DACE_ALIGN(64)[(LMx * LNy)];
    __state->__0___tmp5 = new double DACE_ALIGN(64)[(LMx * LNy)];

    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_gemm(gemm_t *__state)
{
    delete[] __state->__0___tmp0;
    delete[] __state->__0___tmp1;
    delete[] __state->__0___tmp2;
    delete[] __state->__0___tmp5;
    {  // Environment: IntelMKLScaLAPACKMPICH
        
        if (__state->__mkl_scalapack_grid_init) {{
                blacs_gridexit(&__state->__mkl_scalapack_context);
        }}
        // blacs_exit(&__state->__mkl_int_zero);
        
    }
    delete __state;
}

