#include "run_man.h"
#include <ctime>

static void helper (std::vector <Particle*> *particles,
        std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field, int curr_it)
{
    double density_time = 0, field_time = 0, move_time = 0;
    clock_t t1 = 0, t2 = 0;
    std::ofstream times ("times.dat", std::ios::app);

    using namespace std;
    t1 = clock();
    calc_density (density, particles);
    t2 = clock();
    density_time = double(t2 - t1) / CLOCKS_PER_SEC;
    t1 = clock ();
    calc_field (field, pot, density);
    t2 = clock ();
    field_time = double(t2 - t1) / CLOCKS_PER_SEC;
    t1 = clock ();
    move_particles (particles, field);
    t2 = clock ();
    move_time = double(t2 - t1) / CLOCKS_PER_SEC;
    times << density_time << " " << field_time << " " << move_time << "\n";

    //Run diagnostics every intervals
    if (curr_it % 5 == 0)
    {
        diagnostics (particles, curr_it, pot, density);
    }
}

//void run_man (int (*init_pos)(int),
        //double (*init_vel)(void), double D_T,
        //double duration, double width, int num_ion,
        //int num_e, int num_cells)
//{
int main (){
    std::vector <Particle *> particles;
    srand (time(NULL));
    // std::vector <Particle *> e (num_e);
    int iterations = T/D_T;
    std::vector <double> density (NUM_CELLS);
    std::vector <double> field (NUM_CELLS);
    std::vector <double> potential (NUM_CELLS);

    for (int i = 0; i < NUM_IONS; i++)
    {
        particles.insert (particles.begin() + i , new Proton
            (random_vel (), random_start (), 1));
    }

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
            snapshot_diagnostics (&particles, &density,
                    &field, &potential, i);
            std::cout.flush();
        }
    }

    psd (&field);
    std::cout << "0\nCompleted\n";
}
