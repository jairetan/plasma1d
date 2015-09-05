#pragma once
#include <complex>
#include <fftw3.h>
#include <cmath>
#include <vector>

std::vector <std::complex <double> > transform (double *vect, int size);

void full_transform (std::complex <double> *transform, int size);

std::vector <double> inverse_transform (std::complex <double> *transform, int size);

std::vector <std::complex <double> > complex_forward_trans (std::complex <double> *transform_in, int size);
