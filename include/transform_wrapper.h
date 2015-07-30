#pragma once

#include <complex.h>
#include <fftw3.h>

fftw_complex *transform (double *vect, int size);
