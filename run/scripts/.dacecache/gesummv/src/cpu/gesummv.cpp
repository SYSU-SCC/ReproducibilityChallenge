/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"
#include "mkl.h"
#include "mkl_scalapack.h"
#include "mkl_blacs.h"
#include "mkl_pblas.h"

struct gesummv_t {
    int * __restrict__ __0___tmp0;
    int * __restrict__ __0___tmp1;
    int * __restrict__ __0___tmp3;
    int * __restrict__ __0___tmp4;
    double * __restrict__ __0___tmp8;
    double * __restrict__ __0_tmp1;
    double * __restrict__ __0_tmp2;
    MKL_INT __mkl_scalapack_context;
    MKL_INT __mkl_scalapack_rank, __mkl_scalapack_size;
    MKL_INT __mkl_scalapack_prows = 0, __mkl_scalapack_pcols = 0;
    MKL_INT __mkl_scalapack_myprow = 0, __mkl_scalapack_mypcol = 0;
    MKL_INT __mkl_int_zero = 0, __mkl_int_one = 1, __mkl_int_negone = -1;
    bool __mkl_scalapack_grid_init = false;
};

void __program_gesummv_internal(gesummv_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py, double alpha, double beta)
{

    {

        {
            int* __out = __state->__0___tmp0;

            ///////////////////
            // Tasklet code (_set_a_bsizes_)
            __out[0] = LMx;
            __out[1] = LNy;
            ///////////////////

        }
        {
            int* __out = __state->__0___tmp1;

            ///////////////////
            // Tasklet code (_set_b_sizes_)
            __out[0] = GN;
            __out[1] = 1;
            ///////////////////

        }
        {
            double* _a = &A[0];
            double* _b = &x[0];
            int* _a_block_sizes = &__state->__0___tmp0[0];
            int* _b_block_sizes = &__state->__0___tmp1[0];
            double* _c = __state->__0_tmp1;

            ///////////////////

            const double zero = 0.0E+0, one = 1.0E+0;
            const char trans = 'T';
            MKL_INT ga_rows = (trans == 'N' ? LNy*Py : LNy*Py);
            MKL_INT ga_cols = (trans == 'N' ? LMx*Px : LMx*Px);
            MKL_INT gy_rows = (trans == 'N' ? LNy*Py : LMx*Px);
            MKL_INT gy_cols = 1;
            MKL_INT gx_rows = (trans == 'N' ? LMx*Px : LNy*Py);
            MKL_INT gx_cols = 1;
            MKL_INT la_rows = (trans == 'N' ? _a_block_sizes[1] : _a_block_sizes[1]);
            MKL_INT la_cols = (trans == 'N' ? _a_block_sizes[0] : _a_block_sizes[0]);
            MKL_INT ly_rows = gy_rows;
            MKL_INT ly_cols = 1;
            MKL_INT lx_rows = gx_rows;
            MKL_INT lx_cols = 1;
            MKL_INT n_ly_rows = numroc_( &gy_rows, &ly_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_ly_cols = numroc_( &gy_cols, &ly_cols, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            MKL_INT y_lld = max(n_ly_rows, 1);
            MKL_INT n_la_rows = numroc_( &ga_rows, &la_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_la_cols = numroc_( &ga_cols, &la_cols, &__state->__mkl_scalapack_mypcol, &__state->__mkl_int_zero, &__state->__mkl_scalapack_pcols);
            MKL_INT a_lld = max(la_rows, 1);
            MKL_INT n_lx_rows = numroc_( &gx_rows, &lx_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_lx_cols = numroc_( &gx_cols, &lx_cols, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            MKL_INT x_lld = max(n_lx_rows, 1);
            MKL_INT info;
            MKL_INT _y_ldesc[9], _a_ldesc[9],  _x_ldesc[9];
            descinit_(_y_ldesc, &gy_rows, &gy_cols, &ly_rows, &ly_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &y_lld, &info);
            descinit_(_a_ldesc, &ga_rows, &ga_cols, &la_rows, &la_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &a_lld, &info);
            descinit_(_x_ldesc, &gx_rows, &gx_cols, &lx_rows, &lx_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &x_lld, &info);
            MKL_INT _m = ga_rows, _n = ga_cols;
            pdgemv_(
            &trans, &_m, &_n, &one, _a, &__state->__mkl_int_one, &__state->__mkl_int_one, _a_ldesc,
            _b, &__state->__mkl_int_one, &__state->__mkl_int_one, _x_ldesc, &__state->__mkl_int_one,
            &zero, _c, &__state->__mkl_int_one, &__state->__mkl_int_one, _y_ldesc, &__state->__mkl_int_one);

            ///////////////////

        }
        {
            int* __out = __state->__0___tmp3;

            ///////////////////
            // Tasklet code (_set_a_bsizes_)
            __out[0] = LMx;
            __out[1] = LNy;
            ///////////////////

        }
        {
            int* __out = __state->__0___tmp4;

            ///////////////////
            // Tasklet code (_set_b_sizes_)
            __out[0] = GN;
            __out[1] = 1;
            ///////////////////

        }
        {
            double* _a = &B[0];
            int* _a_block_sizes = &__state->__0___tmp3[0];
            int* _b_block_sizes = &__state->__0___tmp4[0];
            double* _b = &x[0];
            double* _c = __state->__0_tmp2;

            ///////////////////

            const double zero = 0.0E+0, one = 1.0E+0;
            const char trans = 'T';
            MKL_INT ga_rows = (trans == 'N' ? GN : GN);
            MKL_INT ga_cols = (trans == 'N' ? GM : GM);
            MKL_INT gy_rows = (trans == 'N' ? GN : GM);
            MKL_INT gy_cols = 1;
            MKL_INT gx_rows = (trans == 'N' ? GM : GN);
            MKL_INT gx_cols = 1;
            MKL_INT la_rows = (trans == 'N' ? _a_block_sizes[1] : _a_block_sizes[1]);
            MKL_INT la_cols = (trans == 'N' ? _a_block_sizes[0] : _a_block_sizes[0]);
            MKL_INT ly_rows = gy_rows;
            MKL_INT ly_cols = 1;
            MKL_INT lx_rows = gx_rows;
            MKL_INT lx_cols = 1;
            MKL_INT n_ly_rows = numroc_( &gy_rows, &ly_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_ly_cols = numroc_( &gy_cols, &ly_cols, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            MKL_INT y_lld = max(n_ly_rows, 1);
            MKL_INT n_la_rows = numroc_( &ga_rows, &la_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_la_cols = numroc_( &ga_cols, &la_cols, &__state->__mkl_scalapack_mypcol, &__state->__mkl_int_zero, &__state->__mkl_scalapack_pcols);
            MKL_INT a_lld = max(la_rows, 1);
            MKL_INT n_lx_rows = numroc_( &gx_rows, &lx_rows, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            // MKL_INT n_lx_cols = numroc_( &gx_cols, &lx_cols, &__state->__mkl_scalapack_myprow, &__state->__mkl_int_zero, &__state->__mkl_scalapack_prows);
            MKL_INT x_lld = max(n_lx_rows, 1);
            MKL_INT info;
            MKL_INT _y_ldesc[9], _a_ldesc[9],  _x_ldesc[9];
            descinit_(_y_ldesc, &gy_rows, &gy_cols, &ly_rows, &ly_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &y_lld, &info);
            descinit_(_a_ldesc, &ga_rows, &ga_cols, &la_rows, &la_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &a_lld, &info);
            descinit_(_x_ldesc, &gx_rows, &gx_cols, &lx_rows, &lx_cols, &__state->__mkl_int_zero, &__state->__mkl_int_zero, &__state->__mkl_scalapack_context, &x_lld, &info);
            MKL_INT _m = ga_rows, _n = ga_cols;
            pdgemv_(
            &trans, &_m, &_n, &one, _a, &__state->__mkl_int_one, &__state->__mkl_int_one, _a_ldesc,
            _b, &__state->__mkl_int_one, &__state->__mkl_int_one, _x_ldesc, &__state->__mkl_int_one,
            &zero, _c, &__state->__mkl_int_one, &__state->__mkl_int_one, _y_ldesc, &__state->__mkl_int_one);

            ///////////////////

        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < GM; __i0 += 1) {
                double __s0_n19__out_n20IN___tmp7;
                {
                    double __in1 = beta;
                    double __in2 = __state->__0_tmp2[__i0];
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (__in1 * __in2);
                    ///////////////////

                    __s0_n19__out_n20IN___tmp7 = __out;
                }
                double __s0_n16__out_n17IN___tmp6;
                {
                    double __in1 = alpha;
                    double __in2 = __state->__0_tmp1[__i0];
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (__in1 * __in2);
                    ///////////////////

                    __s0_n16__out_n17IN___tmp6 = __out;
                }
                {
                    const double __in1 = __s0_n16__out_n17IN___tmp6;
                    const double __in2 = __s0_n19__out_n20IN___tmp7;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __state->__0___tmp8[__i0] = __out;
                }
            }
        }

        dace::CopyNDDynamic<double, 1, false, 1>::template ConstDst<1>::Copy(
        __state->__0___tmp8, y, GM, 1);

    }
}

DACE_EXPORTED void __program_gesummv(gesummv_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py, double alpha, double beta)
{
    __program_gesummv_internal(__state, A, B, x, y, GM, GN, LMx, LNy, Px, Py, alpha, beta);
}

DACE_EXPORTED gesummv_t *__dace_init_gesummv(int GM, int GN, int LMx, int LNy, int Px, int Py)
{
    int __result = 0;
    gesummv_t *__state = new gesummv_t;


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
    __state->__0___tmp3 = new int DACE_ALIGN(64)[2];
    __state->__0___tmp4 = new int DACE_ALIGN(64)[2];
    __state->__0___tmp8 = new double DACE_ALIGN(64)[GM];
    __state->__0_tmp1 = new double DACE_ALIGN(64)[GM];
    __state->__0_tmp2 = new double DACE_ALIGN(64)[GM];

    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_gesummv(gesummv_t *__state)
{
    delete[] __state->__0___tmp0;
    delete[] __state->__0___tmp1;
    delete[] __state->__0___tmp3;
    delete[] __state->__0___tmp4;
    delete[] __state->__0___tmp8;
    delete[] __state->__0_tmp1;
    delete[] __state->__0_tmp2;
    {  // Environment: IntelMKLScaLAPACKMPICH
        
        if (__state->__mkl_scalapack_grid_init) {{
                blacs_gridexit(&__state->__mkl_scalapack_context);
        }}
        // blacs_exit(&__state->__mkl_int_zero);
        
    }
    delete __state;
}

