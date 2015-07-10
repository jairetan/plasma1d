#include "run.h"
int main ()
{
    //Note: Maybe abstract parameters into header
    double delta_t = 1e-9; //In normalized units of plasma freq
    double run_time = 1e-6;
    double particle_width = 1; //In normalized units of debye length
    int num_ion = 0;
    int num_e = 1000;
    int num_cells = 10;
    int size = 100; //In Debye lengths

    run_man (random_start, random_vel, delta_t,
            run_time, particle_width, num_ion, num_e, num_cells);
}
