/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"
#include "mkl.h"
#include "mkl_scalapack.h"
#include "mkl_blacs.h"
#include "mkl_pblas.h"

struct atax_t {
    int * __restrict__ __0___tmp0;
    int * __restrict__ __0___tmp1;
    int * __restrict__ __0___tmp3;
    int * __restrict__ __0___tmp4;
    double * __restrict__ __0___tmp5;
    double * __restrict__ __0_tmp;
    MKL_INT __mkl_scalapack_context;
    MKL_INT __mkl_scalapack_rank, __mkl_scalapack_size;
    MKL_INT __mkl_scalapack_prows = 0, __mkl_scalapack_pcols = 0;
    MKL_INT __mkl_scalapack_myprow = 0, __mkl_scalapack_mypcol = 0;
    MKL_INT __mkl_int_zero = 0, __mkl_int_one = 1, __mkl_int_negone = -1;
    bool __mkl_scalapack_grid_init = false;
};

void __program_atax_internal(atax_t *__state, double * __restrict__ A, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py)
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
            double* _c = __state->__0_tmp;

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
            __out[0] = GM;
            __out[1] = 1;
            ///////////////////

        }
        {
            int* _a_block_sizes = &__state->__0___tmp3[0];
            int* _b_block_sizes = &__state->__0___tmp4[0];
            double* _a = &A[0];
            double* _b = &__state->__0_tmp[0];
            double* _c = __state->__0___tmp5;

            ///////////////////

            const double zero = 0.0E+0, one = 1.0E+0;
            const char trans = 'N';
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

        dace::CopyNDDynamic<double, 1, false, 1>::template ConstDst<1>::Copy(
        __state->__0___tmp5, y, GN, 1);

    }
}

DACE_EXPORTED void __program_atax(atax_t *__state, double * __restrict__ A, double * __restrict__ x, double * __restrict__ y, int GM, int GN, int LMx, int LNy, int Px, int Py)
{
    __program_atax_internal(__state, A, x, y, GM, GN, LMx, LNy, Px, Py);
}

DACE_EXPORTED atax_t *__dace_init_atax(int GM, int GN, int LMx, int LNy, int Px, int Py)
{
    int __result = 0;
    atax_t *__state = new atax_t;


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
    __state->__0___tmp5 = new double DACE_ALIGN(64)[GN];
    __state->__0_tmp = new double DACE_ALIGN(64)[GM];

    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_atax(atax_t *__state)
{
    delete[] __state->__0___tmp0;
    delete[] __state->__0___tmp1;
    delete[] __state->__0___tmp3;
    delete[] __state->__0___tmp4;
    delete[] __state->__0___tmp5;
    delete[] __state->__0_tmp;
    {  // Environment: IntelMKLScaLAPACKMPICH
        
        if (__state->__mkl_scalapack_grid_init) {{
                blacs_gridexit(&__state->__mkl_scalapack_context);
        }}
        // blacs_exit(&__state->__mkl_int_zero);
        
    }
    delete __state;
}

