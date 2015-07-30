#pragma once

#include <math.h>
#include <gsl/gsl_statistics.h>
#include <complex.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "to_string.h"
#include "parameters.h"
#include <iostream>
#include "transform_wrapper.h"

void E_psd (std::vector <double>* field, int iter);
void U_psd (std::vector <double>* potential, std::vector <double> *density,
        int iter);
