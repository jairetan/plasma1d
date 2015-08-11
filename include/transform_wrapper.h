#pragma once
#include <complex>
#include <fftw3.h>
#include <cmath>

std::complex <double> *transform (double *vect, int size);

void full_transform (std::complex <double> *transform, int size);

double *inverse_transform (std::complex <double> *transform, int size);
