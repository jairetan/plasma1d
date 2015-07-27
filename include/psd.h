#pragma once
#include <gsl/gsl_statistics.h>
#include <complex.h>
#include <vector>
#include <stdlib.h>
#include <fftw3.h>
#include <fstream>
#include "to_string.h"
#include "parameters.h"
#include <complex>
#include <iostream>

void psd (std::vector <double> * data, int iter);
