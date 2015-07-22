#include "init_v.h"
#include <iostream>

static double pdf (double mass, double vel)
{
    double coeff1 = 4 * M_PI;
    double coeff2 = mass/(2*M_PI*MY_BOLTZMANN*TEMP);
    coeff2 = pow (coeff2, 1.5);
    double vterm1 = vel * vel;
    double exponential = -mass * vel * vel/(2 *MY_BOLTZMANN * TEMP);
    exponential = exp (exponential);

    return coeff1 * coeff2 * vterm1 *exponential;
}

static double maxwell ()
{
    double gen_val = jmod (rand (),100), vel = jmod (double (rand ())/100, 10);
    double probability = pdf (NON_NORMAL_MASS, vel)*100;

    //std::cout << NON_NORMAL_MASS << "\n";
    //std::cout << gen_val << " " << vel << " " << probability <<"\n";
    if (gen_val - probability > TOLERANCE){
        return maxwell ();
    }

    if (rand () % 2){
        return -vel;
    }

    return vel;
}

double random_vel ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    //return (double)rand () / RAND_MAX / 2;
    return maxwell()/20; //Cold plasma
}
