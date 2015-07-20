//Calculate field at each grid point
#pragma once
#include <vector>
#include <math.h>
#include <complex.h>
#include <fftw3.h>
#include <stdlib.h>
#include "parameters.h"

void calc_field (std::vector <double> *, std::vector <double> *, std::vector <double> *);
