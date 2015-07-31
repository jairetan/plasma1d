#include "transform_wrapper.h"
fftw_complex *transform (double *vect, int size)
{
    fftw_complex *transform_out = new fftw_complex [size];
    fftw_plan p = fftw_plan_dft_r2c_1d
        (size, vect, transform_out, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not fill in latter half of transform array (hermitian symmetry)
    for (int i = 0; i < size/2; i++){
        transform_out [size-i-1] = conj (transform_out [i]);
    }

    //fftw does not normalize transform
    for (int i = 0; i < size; i++ ){
        transform_out [i] /= size;
    }

    return transform_out;
}

double *inverse_transform (fftw_complex *transform, int size)
{
    double *inverse = new double [size];

    fftw_plan p = fftw_plan_dft_c2r_1d
        (size, transform, inverse, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    return inverse;
}
