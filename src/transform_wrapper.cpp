#include "transform_wrapper.h"

std::complex <double> *complex_forward_trans (
        std::complex <double> *transform_in, int size)
{
    fftw_plan p;
    std::complex <double> *transform_out = new std::complex <double> [size];
    p = fftw_plan_dft_1d(size,
            reinterpret_cast <fftw_complex *>(transform_in),
            reinterpret_cast <fftw_complex *>(transform_out),
            FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    return transform_out;
}

std::complex <double> *transform (double *vect, int size)
{
    std::complex <double> *transform_out = new std::complex <double> [size];

    fftw_plan p = fftw_plan_dft_r2c_1d
        (size, vect, reinterpret_cast <fftw_complex *>(transform_out),
         FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not normalize transform
    for (int i = 0; i < size; i++){
        transform_out [i] /= sqrt (size);
    }

    return transform_out;
}

void full_transform (std::complex <double> *transform, int size)
{
    //fftw does not fill in latter half of transform array (hermitian symmetry)
    for (int i = 0; i < size/2; i++){
        transform [size-i-1] = std::conj (transform [i+1]);
    }
}

double *inverse_transform (std::complex <double> *transform, int size)
{
    double *inverse = new double [size];

    fftw_plan p = fftw_plan_dft_c2r_1d
        (size, reinterpret_cast <fftw_complex *> (transform), inverse,
         FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not normalize transform
    for (int i = 0; i < size; i++ ){
        inverse [i] /= sqrt (size);
    }

    return inverse;
}
