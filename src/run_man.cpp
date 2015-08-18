#include "run_man.h"
static std::vector <Particle> combine_vectors (std::vector <Particle> *a,
        std::vector <Particle> *b){

    std::vector <Particle> all_particles;
    all_particles.reserve (a->size() + b->size());
    all_particles.insert (end(all_particles), begin (*a), end (*a));
    all_particles.insert (end(all_particles),
            begin (*b), end (*b));

    return all_particles;
}

static void system_cycle (std::vector <Particle> *ions,
        std::vector <Particle> *electrons,std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field,
        int curr_it)
{
    std::fill (begin (*density), end (*density), BACKGROUND_DENSITY);
    calc_density (ions, density);
    calc_density (electrons, density);

    calc_field (field, pot, density);
    move_particles (ions, field);
    move_particles (electrons, field);

    //Run diagnostics every intervals
    if (curr_it % 25 == 0){
        //time_history_diagnostics (ions, curr_it, pot, density, field);
        time_history_diagnostics (electrons, curr_it, pot, density, field);
    }

    if (curr_it % (ITERATIONS/10) == 0){
        std::string fName = "data/"+to_string(curr_it)+"vel.dat";
        std::ofstream file (fName.c_str(), std::ios::app);

        for (auto particle : *electrons){
            file<< particle.get_vel() << std::endl;
        }
        file.close();
    }
}

int main ()
{
    srand (time(NULL));
    std::vector <Particle> ions (NUM_IONS);
    std::vector <Particle> electrons (NUM_E);
    std::vector <double> density (NUM_CELLS);
    std::vector <double> field (NUM_CELLS);
    std::vector <double> potential (NUM_CELLS);

    //  #pragma omp parallel for
    for (auto &ion : ions){
        ion = Particle (ION_MASS, ION_CHARGE,
                random_vel (ION_MASS, I_BOLTZMANN_TEMP), random_start (), 1);
    }

    //   #pragma omp parallel for
    for (int j = 0; j < NUM_E*.7; j++){
        electrons [j] = Particle (ELECTRON_MASS, ELECTRON_CHARGE,
                random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP),
                random_start (), 1);
    }

    for (int j = NUM_E*.7; j < NUM_E; j++){
        electrons [j] = Particle (ELECTRON_MASS, ELECTRON_CHARGE,
                random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP) + 2*E_V_THERMAL,
                random_start (), 1);
    }

    for (int i = 0; i < ITERATIONS; i++){

        //Progress bar
        if ((i % (ITERATIONS / 10)) == 0){
            std::cout << 10 - i*10/ITERATIONS << " " ;
            std::cout.flush();
        }

        system_cycle (&ions, &electrons, &potential, &density, &field, i);

        if ((i % (ITERATIONS / 100)) == 0){
            auto all_particles = combine_vectors (&ions, &electrons);
            snapshot_diagnostics (&all_particles, &density,
                    &field, &potential, i);
        }
    }

    E_psd();
    std::cout << "0" << std::endl << "Completed" << std::endl;
}
