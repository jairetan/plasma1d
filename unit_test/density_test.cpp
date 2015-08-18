#include <gtest/gtest.h>
#include "density.h"
#include "ion.h"
#include "electron.h"

TEST (density_test, density_test)
{
    std::vector <double> density (100);
    std::fill (begin (density), end (density), BACKGROUND_DENSITY);
    std::vector <Particle> particles;
    Particle i1 (ION_MASS, ION_CHARGE,0,0,1);
    Particle i2 (ION_MASS, ION_CHARGE,0,1.25,1);
    Particle i3 (ION_MASS, ION_CHARGE,0,2,1);
    Particle i4 (ION_MASS, ION_CHARGE,0,2.5,1);
    Particle e1 (ELECTRON_MASS, ELECTRON_CHARGE,0,5,1);
    Particle e2 (ELECTRON_MASS, ELECTRON_CHARGE,0,3,1);
    particles.push_back (i1);
    particles.push_back (i2);
    particles.push_back (i3);
    particles.push_back (i4);
    particles.push_back (e1);
    particles.push_back (e2);

    calc_density (&particles, &density);

    ASSERT_FLOAT_EQ (density[0], 1+BACKGROUND_DENSITY);
    ASSERT_FLOAT_EQ (density[1], .75+BACKGROUND_DENSITY);
    ASSERT_FLOAT_EQ (density[2], 1.75+BACKGROUND_DENSITY);
    ASSERT_FLOAT_EQ (density[3], -.5+BACKGROUND_DENSITY);
    ASSERT_FLOAT_EQ (density[4], 0+BACKGROUND_DENSITY);
    ASSERT_FLOAT_EQ (density[5], -1+BACKGROUND_DENSITY);
}
