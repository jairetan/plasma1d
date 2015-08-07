#pragma once

#include <complex>
#include <fftw3.h>
#include <math.h>

std::complex <double>*transform (double *vect, int size);

//Fill in latter half of transform
void full_transform (std::complex <double> *vect, int size);

double *inverse_transform (std::complex <double> *transform, int size);
