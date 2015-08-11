#include <gtest/gtest.h>
#include "density.h"
#include "ion.h"
#include "electron.h"

TEST (density_test, density_test)
{
    std::vector <double> density (100);
    std::vector <Particle *> particles;
    Ion i1 (0,0,1);
    Ion i2 (0,1.25,1);
    Ion i3 (0,2,1);
    Ion i4 (0,2.5,1);
    Electron e1 (0,5,1);
    Electron e2 (0,3,1);
    particles.push_back (&i1);
    particles.push_back (&i2);
    particles.push_back (&i3);
    particles.push_back (&i4);
    particles.push_back (&e1);
    particles.push_back (&e2);

    calc_density (&particles, &density);

    ASSERT_EQ (density[0], 1);
    ASSERT_EQ (density[1], .75);
    ASSERT_EQ (density[2], 1.75);
    ASSERT_EQ (density[3], -.5);
    ASSERT_EQ (density[4], 0);
    ASSERT_EQ (density[5], -1);
}
