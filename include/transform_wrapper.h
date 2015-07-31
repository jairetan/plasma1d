#pragma once

#include <complex.h>
#include <fftw3.h>

fftw_complex *transform (double *vect, int size);
double *inverse_transform (fftw_complex *transform, int size);
