#include <random>
#include "init_v.h"
#include <cstdio>
#include <chrono>

static double pdf (double mass, double vel, double boltzmann_temp)
{
    double coeff1 = 4 * M_PI;
    double coeff2 = mass/(2*M_PI*boltzmann_temp);

    //printf ("%d\n", isnan (coeff2));
    //fflush (stdout);
    coeff2 = pow (coeff2, 1.5);
    double vterm1 = vel * vel;
    double exponential = -mass * vel * vel/(2 *boltzmann_temp);
    exponential = exp (exponential);

    return coeff1 * coeff2 * vterm1 *exponential;
}

//static double normalize_vel (double non_normalized_v)
//{
    //return non_normalized_v * PLASMA_FREQ/DEBYE_LENGTH;
//}

static double maxwell (double max_vel, double mass, double boltzmann_temp)
{
    double gen_val = double (rand())/RAND_MAX,
           vel = max_vel*rand ()/RAND_MAX;
    double probability = pdf (mass, vel, boltzmann_temp);

    if (gen_val > probability){
        return maxwell (max_vel,mass, boltzmann_temp);
    }

    printf ("%f %f %f\n", probability, gen_val, vel);

    if (rand () % 2){
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

static double maxwell_3 (double boltzmann_temp, double mass)
{
    static std::default_random_engine generator (std::chrono::system_clock::now().time_since_epoch().count());

    double std_dev = sqrt (boltzmann_temp/mass);
    double mean = 0;
    std::normal_distribution <double> distribution (mean, std_dev);

    return distribution (generator);
}

double random_vel (double mass, double boltzmann_temp)
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    //return (double)rand () / RAND_MAX / 2;
    //return maxwell(10000, mass, boltzmann_temp);
    //return maxwell2 (1);
    double vel = maxwell_3 (boltzmann_temp, mass);
    return vel;
}
