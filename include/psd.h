#pragma once
#include <gsl/gsl_statistics.h>
#include <complex.h>
#include <vector>
#include <stdlib.h>
#include <fftw3.h>
#include <fstream>
#include "parameters.h"

void psd (std::vector <double> * data, std::vector <double> *return_dat);
