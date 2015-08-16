#include "run_man.h"

static void helper (std::vector <Particle*> *particles,
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
        FILE *file = NULL;
        std::string fName = "data/"+to_string(curr_it)+"vel.dat";
        if ((file = fopen (fName.c_str(), "a")) == NULL){
            return;
        }

        for (int i=0; i < particles->size(); i++){
            Particle *particle = particles->at (i);

            if (particle->get_charge () < 0){
                fprintf (file, "%f\n", particle->get_vel());
            }
        }

        fclose (file);
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

    int end = NUM_E*.7+NUM_IONS;
 //   #pragma omp parallel for
    for (int j = NUM_IONS; j < end; j++){
        particles.insert (particles.begin() + j , new Electron
            (random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP), random_start (), 1));
    }

    int start = end;
    end = NUM_E+ NUM_IONS;
//    #pragma omp parallel for
    for (int j = start; j < end; j++){
        particles.insert (particles.begin() + j , new Electron
            (random_vel (ELECTRON_MASS, E_BOLTZMANN_TEMP)+.25, random_start (), 1));
    }

    for (int i = 0; i < ITERATIONS; i++){
        helper (&particles, &potential, &density, &field, i);

        //Progress bar
        if ((i % (ITERATIONS / 10)) == 0){
            printf ("%d ", 10 - i*10/ITERATIONS);
            fflush (stdout);
        }
        if ((i % (ITERATIONS / 50)) == 0){
            snapshot_diagnostics (&particles, &density,
                    &field, &potential, i);
        }
    }
    E_psd();

    printf ("0\nCompleted\n");
}
