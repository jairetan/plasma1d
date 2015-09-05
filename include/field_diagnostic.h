#pragma once

#include <vector>

#include "parameters.h"
#include "to_string.h"
#include "out_writer.h"
#include "transform_wrapper.h"

void field_diagnostic (std::vector <double> *field, int iter);
void field_space_transform (std::vector <double> *field, int iter);
