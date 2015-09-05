#include "ion.h"

Ion::Ion ()
{
    Ion (0,0,0);
}

Ion::Ion (double v, double p, double w)
    :Particle (ION_MASS,ION_CHARGE, v, p, w)
{
}
