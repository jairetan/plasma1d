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
    double gen_val = wrap_around (rand (),100), vel = wrap_around (double (rand ())/100, 10);
    double probability = pdf (NON_NORMAL_MASS, vel)*100;

    if (gen_val - probability > TOLERANCE){
        return maxwell ();
    }

    if (wrap_around (rand () , 2)){
        return -vel;
    }

    return vel;
}

//Borrowed from elsewhere
double maxwell2 (double vb)
{
    //Initialize random number generator
    static int flag = 0;
    if (flag == 0)
    {
        int seed = time (NULL);
        srand (seed);
        flag = 1;
    }

    // Generate random v value
    double fmax = 0.5 * (1. + exp (-2. * vb * vb));
    double vmin = - 5. * vb;
    double vmax = + 5. * vb;
    double v = vmin + (vmax - vmin) * double (rand ()) / double (RAND_MAX);

    // Accept/reject value
    double f = 0.5 * (exp (-(v - vb) * (v - vb) / 2.) +
            exp (-(v + vb) * (v + vb) / 2.));
    double x = fmax * double (rand ()) / double (RAND_MAX);
    if (x > f)
        return maxwell2 (vb);
    else return v;

}

double random_vel ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    //return (double)rand () / RAND_MAX / 2;
    //return maxwell()/100; //Cold plasma
    return maxwell2 (3);
}
