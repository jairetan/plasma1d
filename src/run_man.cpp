#include "run_man.h"
#include <ctime>

static void helper (std::vector <Particle*> *particles,
        std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field, int curr_it)
{
    calc_density (particles,density);
    calc_field (field, pot, density);
    move_particles (particles, field);

    //Run diagnostics every intervals
    if (curr_it % 25 == 0)
    {
        time_history_diagnostics (particles, curr_it, pot, density, field);
    }
}

int main (){
    std::vector <Particle *> particles;
    srand (time(NULL));
    int iterations = T/D_T;
    std::vector <double> density (NUM_CELLS);
    std::vector <double> field (NUM_CELLS);
    std::vector <double> potential (NUM_CELLS);

    for (int j = NUM_IONS; j < NUM_E + NUM_IONS; j++)
    {
        particles.insert (particles.begin() + j , new Electron
            (random_vel (), random_start (), 1));
    }

    for (int i = 0; i < iterations; i++){

        helper (&particles, &potential, &density, &field, i);
        //Progress bar
        if ((i % (iterations / 10)) == 0)
        {
            std::cout << 10 - i*10/iterations << " ";
            std::cout.flush();
            snapshot_diagnostics (&particles, &density,
                    &field, &potential, i);
        }
    }

    std::cout << "0\nCompleted\n";
}
