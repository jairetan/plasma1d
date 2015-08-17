#pragma once
#include <fstream>
#include <math.h>
#include <vector>
#include "to_string.h"
#include "parameters.h"
#include "transform_wrapper.h"
#include "square_mod.h"

void U_psd (std::vector <double>* potential, std::vector <double> *density,
        int iter);
void E_psd ();
std::complex <double> *complex_forward_trans (
        std::complex <double> *transform_in, int size);
