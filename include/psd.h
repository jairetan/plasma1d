#pragma once
#include <math.h>
#include <gsl/gsl_statistics.h>
#include <complex.h>
#include <vector>
#include <stdlib.h>
#include <fftw3.h>
#include <fstream>
#include "to_string.h"
#include "parameters.h"
#include <iostream>

void psd (std::vector <double> * field, int iter);
