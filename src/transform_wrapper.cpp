#include "transform_wrapper.h"

double complex *transform (double *vect, int size)
{
    double complex *transform_out = new double complex [size];
    fftw_complex *transform = new fftw_complex [size];

    fftw_plan p = fftw_plan_dft_r2c_1d
        (size, vect, transform, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not normalize transform
    for (int i = 0; i < size; i++ ){
        transform_out [i] = transform [i] / sqrt (size);
    }

    fftw_free (transform);

    return transform_out;
}

void full_transform (double complex *transform, int size)
{
    //fftw does not fill in latter half of transform array (hermitian symmetry)
    for (int i = 0; i < size/2; i++){
        transform [size-i-1] = conj (transform [i]);
    }

}

double *inverse_transform (double complex *transform, int size)
{
    double *inverse = new double [size];

    fftw_plan p = fftw_plan_dft_c2r_1d
        (size, transform, inverse, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not normalize transform
    for (int i = 0; i < size; i++ ){
        inverse [i] /= sqrt (size);
    }

    return inverse;
}
