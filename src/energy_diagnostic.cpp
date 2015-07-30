//Return kinetic energy vs time
#include "energy_diagnostic.h"
#include "mode_diagnostic.h"
#include <iostream>

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
    double total_ese = 0;
    double test_ese = 0;
    std::vector <double> x (1);
    std::vector <double> y (1);

    int size = potential->size();

    fftw_complex *transformed_potential = transform (&((*potential)[0]), NUM_CELLS);
    fftw_complex *transformed_density = transform (&((*density)[0]), NUM_CELLS);
    std::vector <double> mode_energy (size);

    for (int i = 0; i < size; i++){
        double trans_pot_real = creal (transformed_potential [i]);
        double trans_pot_imag = cimag (transformed_potential [i]);
        double trans_dens_real = creal (transformed_density [i]);
        double trans_dens_imag = cimag (transformed_density [i]);

        mode_energy[i] = .5 * (trans_pot_real * trans_dens_real
                + trans_pot_imag * trans_dens_imag);
        mode_energy [i] *= NUM_CELLS; //One too many normalizations

        total_ese += mode_energy [i];

        if (i < PLOT_MODES){
            x[0]= (t);
            y[0]= mode_energy [i];
            std::string path = DATA_DIR +to_string (i)+"mode"+ "_out.dat";
            out_writer (path, &x, &y);
        }

        test_ese += (*potential)[i] * (*density) [i]/2;
    }
    //double total_energy = 0;
    //double total_energy2 = 0;
    //int size = potential->size ();
    //fftw_complex *pot_trans = transform (&((*potential)[0]), size);
    //fftw_complex *density_trans = transform (&((*density)[0]), size);
    //std::vector <double> x;
    //std::vector <double> y;
    //x.push_back (0);
    //y.push_back (0);
    //double mode_energy = 0;
    //double pot_real = 0;
    //double pot_imag = 0;
    //double density_real = 0;
    //double density_imag = 0;
    //fftw_complex temp;


    //for (int j = 0; j < potential->size();j++){
        //total_energy += potential->at (j) * density->at (j) ;
    //}
    //for (int i = 0 ; i < NUM_CELLS; i++){
        //pot_real = creal(pot_trans[i]);
        //pot_imag = cimag(pot_trans[i]);
        //density_real = creal(density_trans[i]);
        //density_imag = cimag(density_trans[i]);
        //if (i ==0){
            //temp = pot_trans [0] * density_trans [0];
            //mode_energy = 1/NUM_CELLS * (pow (creal(temp), 2) +
                    //pow (cimag (temp), 2));
        //}
        //else {
            //temp = pot_trans [i] *density_trans [NUM_CELLS-i];
            //mode_energy = 1/NUM_CELLS *  (creal (temp) *creal (temp) +cimag (temp)*cimag (temp));
        //}
        //total_energy2 += mode_energy;

        //if (i < PLOT_MODES){
            //x[0]= (t);
            //y[0]= mode_energy;
            //std::string path = DATA_DIR +to_string (i)+"mode"+ "_out.dat";
            //out_writer (path, &x, &y);
        //}

    //}
    //total_energy2 = sqrt (total_energy2);
    //if (total_energy2 > 0){
        ////std::cout << "Energy Ratio:" << total_energy/total_energy2 << "\n";
    //}
    //else {
        ////std::cout << "Energy Ratio:" << total_energy << ":" << total_energy2 << "\n";
        ////std::cout <<"Energy error\n";
    //}

    return total_ese;
}

double pe_diagnostic (std::vector <double> *potential,
        std::vector <double> *density,  double t){
    double pe_total = 0;
    int size = potential->size();
    std::vector <double> x;
    std::vector <double> y;

    std::string path = DATA_DIR + "pe_out.dat";
    mode_diagnostic (potential, density, t);

    for (int i = 0; i < size; i++){
        pe_total += potential->at (i)* density->at(i);
    }

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

