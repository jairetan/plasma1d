//Calculate field at each grid point
#pragma once
#include <vector>
#include <math.h>
#include <complex>
#include <fftw3.h>
#include "parameters.h"
#include "transform_wrapper.h"

void calc_field (std::vector <double> *, std::vector <double> *, std::vector <double> *);
