#pragma once

#include <complex.h>
#include <fftw3.h>
#include <math.h>

double complex *transform (double *vect, int size);

//Fill in latter half of transform
void full_transform (double complex *vect, int size);

double *inverse_transform (double complex *transform, int size);
