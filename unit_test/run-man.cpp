#include "run-man.h"

static void helper (std::vector <Particle*> *particles,
        std::vector <double> *pot,
        std::vector <double> *density, std::vector <double> *field, int curr_it)
{

    using namespace std;

    calc_density (density, particles);
    calc_field (field, pot, density);
    move_particles (particles, field);

}

//void run_man (int (*init_pos)(int),
        //double (*init_vel)(void), double D_T,
        //double duration, double width, int num_ion,
        //int num_e, int num_cells)
//{
int main (){

    using namespace std;
    srand (time(NULL));
    vector <Particle *> particles;
    //vector <Particle *> e (num_e);
    int iterations = T/D_T;
    vector <double> density (NUM_CELLS);
    vector <double> field (NUM_CELLS);
    vector <double> potential (NUM_CELLS);

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
//        Progress bar
        if ((i % (iterations / 10)) == 0)
        {
            std::cout << 10 - i*10/iterations << " ";
            std::cout.flush();
        }
    }

    field_diagnostic (&field);
    pot_diagnostic (&potential);
    density_diagnostic (&density);
    velocity_diagnostic (&particles);
    psd (&field, NULL);

    std::cout << "0\nCompleted\n";
}
