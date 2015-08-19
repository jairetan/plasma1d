#pragma once
#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>
#include "to_string.h"
#include "parameters.h"
#include "transform_wrapper.h"
#include "square_mod.h"

void U_psd (std::vector <double>* potential, std::vector <double> *density,
        int iter);
void E_dispersion ();
