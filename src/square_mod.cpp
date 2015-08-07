#include "square_mod.h"
double square_mod (std::complex <double> value)
{
    return pow (value.real(),2) + pow (value.imag(), 2);
}
