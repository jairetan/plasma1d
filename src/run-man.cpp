#include "run-man.h"
static void helper (std::vector <Particle*> *particles,
        std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field,
        int num_cells, double dt, double t){
    using namespace std;

    calc_density (density, particles, num_cells);
    calc_field (field, pot, density, num_cells);
    move_particles (particles, field, dt, num_cells);

    //Run diagnostics every 10 intervals
    //if (((int)(t/dt) % 5) == 0)
    //{
        diagnostics (particles, t, pot, density);
    //}

}

void run_man (int (*init_pos)(int),
        double (*init_vel)(void), double dt,
        double duration, double width, int num_ion,
        int num_e, int num_cells)
{

    using namespace std;
    vector <Particle *> particles;
    //vector <Particle *> e (num_e);
    int iterations = duration/dt;
    vector <double> density (num_cells);
    vector <double> field (num_cells);
    vector <double> potential (num_cells);

    for (int i = 0; i < num_ion; i++)
    {
        particles.insert (particles.begin() + i , new Proton
            (init_vel (), init_pos (num_cells), 1));
    }

    for (int j = num_ion; j < num_e+num_ion; j++)
    {
        particles.insert (particles.begin() + j , new Electron
            (init_vel (), init_pos (num_cells), 1));
    }

    for (int i = 0; i < iterations; i++){
        helper (&particles, &potential, &density, &field, num_cells, dt, dt*i);
        //Progress bar
        if ((i % (iterations / 10)) == 0)
        {
            std::cout << 10 - i*10/iterations << " ";
            std::cout.flush();
        }
    }

    field_diagnostic (&field);
    pot_diagnostic (&potential);

    std::cout << "0\nCompleted\n";

}
