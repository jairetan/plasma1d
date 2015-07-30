#include "square_mod.h"
double square_mod (fftw_complex value)
{
    return pow (creal (value),2) + pow (cimag (value), 2);
}
