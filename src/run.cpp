#include "run.h"
int main ()
{
    //Note: Maybe abstract parameters into header
    double delta_t = .001; //In normalized units of plasma freq
    double run_time = 1;
    double particle_width = 1; //In normalized units of debye length
    int num_ion = 0;
    int num_e = 20000;
    int num_cells = 100; //Spaced 1 debye length apart

    run_man (random_start, random_vel, delta_t,
            run_time, particle_width, num_ion, num_e, num_cells);
}
