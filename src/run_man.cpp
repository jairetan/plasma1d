#include "run_man.h"

static void system_cycle (std::vector <Particle*> *particles,
        std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field, int curr_it)
{
    calc_density (particles, density);
    calc_field (field, pot, density);
    move_particles (particles, field);

    //Run diagnostics every intervals
    if (curr_it % 25 == 0){
        time_history_diagnostics (particles, curr_it, pot, density, field);
    }

    if (curr_it % (ITERATIONS/10) == 0){
        std::string fName = "data/"+to_string(curr_it)+"vel.dat";
        std::ofstream file (fName.c_str(), std::ios::app);

        for (auto particle : *particles){
            if (particle->get_charge () < 0){
                file<< particle->get_vel() << std::endl;
            }
        }
        file.close();
    }
}

int main ()
{
    std::vector <Particle *> particles;
    srand (time(NULL));
    std::vector <double> density (NUM_CELLS);
    std::vector <double> field (NUM_CELLS);
    std::vector <double> potential (NUM_CELLS);

  //  #pragma omp parallel for
    for (int j = 0; j < NUM_IONS; j++){
        particles.insert (particles.begin() + j , new Ion
            (random_vel (ION_MASS, I_BOLTZMANN_TEMP), random_start (), 1));
    }

    int end = NUM_E*.9+NUM_IONS;
 //   #pragma omp parallel for
    for (int j = NUM_IONS; j < end; j++){
        particles.insert (particles.begin() + j , new Electron
            (random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP), random_start (), 1));
    }

    int start = end;
    end = NUM_E+ NUM_IONS;
    for (int j = start; j < end; j++){
        particles.insert (particles.begin() + j , new Electron
            (random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP)+10 * E_V_THERMAL, random_start (), 1));
    }

    for (int i = 0; i < ITERATIONS; i++){
        system_cycle (&particles, &potential, &density, &field, i);

        //Progress bar
        if ((i % (ITERATIONS / 10)) == 0){
            std::cout << 10 - i*10/ITERATIONS << " " ;
            std::cout.flush();
        }

        if ((i % (ITERATIONS / 100)) == 0){
            snapshot_diagnostics (&particles, &density,
                    &field, &potential, i);
        }
    }

    E_psd();

    std::cout << "0" << std::endl << "Completed" << std::endl;
}
