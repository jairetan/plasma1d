//Return kinetic energy vs time
#include "energy_diagnostic.h"
#include "mode_diagnostic.h"
#include <iostream>

static fftw_complex *transform (std::vector <double> *vect)
{
    int size = vect->size();
    double *vect_array = new double [size];
    fftw_complex *transform_out = new fftw_complex [vect->size()];

    for (int i = 0; i < size; i++){
        vect_array [i] = vect->at (i);
    }

    fftw_plan p;

    p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, vect_array, transform_out, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    return transform_out;
}

double ke_diagnostic (std::vector <Particle *> *particles,  double t){
    double ke_total = 0;
    int size = particles -> size();
    std::vector <double> x;
    std::vector <double> y;
    std::string path = DATA_DIR + "ke_out.dat";

    for (int i = 0; i < size; i++){
        ke_total += particles->at (i)->get_ke();
    }

    x.push_back (t);
    y.push_back (ke_total);

    out_writer (path, &x, &y);

    return ke_total;
}

double mode_diagnostic ( std::vector <double> *potential,
        std::vector <double> *density, int t)
{
    double total_energy = 0;
    double total_energy2 = 0;
    fftw_complex *pot_trans = transform (potential);
    fftw_complex *density_trans = transform (density);
    std::vector <double> x;
    std::vector <double> y;
    x.push_back (0);
    y.push_back (0);
    double mode_energy = 0;
    double pot_real = 0;
    double pot_imag = 0;
    double density_real = 0;
    double density_imag = 0;
    fftw_complex temp;


    for (int j = 0; j < potential->size();j++){
        total_energy += potential->at (j) * density->at (j) ;
    }
    for (int i = 0 ; i < NUM_CELLS; i++){
        pot_real = creal(pot_trans[i]);
        pot_imag = cimag(pot_trans[i]);
        density_real = creal(density_trans[i]);
        density_imag = cimag(density_trans[i]);
        if (i ==0){
            temp = pot_trans [0] * density_trans [0];
            mode_energy = 1/NUM_CELLS * (creal (temp) *creal (temp) +cimag (temp)*cimag (temp));
        }
        else {
            temp = pot_trans [i] *density_trans [NUM_CELLS-i];
            mode_energy = 1/NUM_CELLS *  (creal (temp) *creal (temp) +cimag (temp)*cimag (temp));
        }
        total_energy2 += mode_energy;

        if (i < PLOT_MODES){
            x[0]= (t);
            y[0]= mode_energy;
            std::string path = DATA_DIR +to_string (i)+"mode"+ "_out.dat";
            out_writer (path, &x, &y);
        }

    }
    total_energy2 = sqrt (total_energy2);
    if (total_energy2 > 0){
        std::cout << "Energy Ratio:" << total_energy/total_energy2 << "\n";
    }
    else {
        std::cout <<"Energy error\n";
    }

    return total_energy;
}

double pe_diagnostic (std::vector <double> *potential,
        std::vector <double> *density,  double t){
    double pe_total = 0;
    std::vector <double> x;
    std::vector <double> y;

    std::string path = DATA_DIR + "pe_out.dat";
    pe_total = mode_diagnostic (potential, density, t);

    x.push_back (t);
    y.push_back (pe_total);
    out_writer (path, &x, &y);

    return pe_total;
}

void energy_diagnostic (std::vector <Particle *> *particles,
        std::vector <double> *potential, std::vector <double> *density,
        double t)
{
    std::string path = DATA_DIR + "e_out.dat";
    std::ofstream e_out (path.c_str(), std::ios::app);
    std::vector <double> x;
    std::vector <double> y;

    double e_total = ke_diagnostic (particles, t) +
        pe_diagnostic (potential, density, t);

    x.push_back (t);
    y.push_back (e_total);
    out_writer (path, &x, &y);
}

