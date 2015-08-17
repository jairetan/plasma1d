//Return kinetic energy vs time
#include "energy_diagnostic.h"
#include "mode_diagnostic.h"

double ke_diagnostic (std::vector <Particle *> *particles, double iter){
    auto ke_total = 0.0;
    auto size = particles -> size();
    std::vector <double> x (1);
    std::vector <double> y (1);
    std::string path = DATA_DIR + "ke_out.dat";

    for (auto particle : *particles){
        ke_total += particle->get_ke();
    }

    x[0] = iter;
    y[0] = ke_total;

    out_writer (path, &x, &y);

    return ke_total;
}

double mode_diagnostic (std::vector <double> *potential,
        std::vector <double> *density, int iter)
{
    double total_ese = 0;
    double test_ese = 0;
    int size = potential->size();
    std::vector <double> x (1);
    std::vector <double> y (1);
    std::vector <double> mode_energy (size);

    std::complex <double> *transformed_potential =
        transform (&((*potential)[0]), NUM_CELLS);
    full_transform (transformed_potential, size);
    std::complex <double> *transformed_density=
        transform (&((*density)[0]), NUM_CELLS);
    full_transform (transformed_density, size);

    for (int i = 0; i < size; i++){
        //mode_energy[i] = .5 * (trans_pot_real * trans_dens_real
                //+ trans_pot_imag * trans_dens_imag);
        mode_energy[i] = (transformed_potential [i] *
                transformed_density [i]).real();
        mode_energy [i] *= NUM_CELLS; //One too many normalizations

        total_ese += mode_energy [i];

        if (i < SPATIAL_MODES){
            x[0]= (iter);
            y[0]= mode_energy [i];
            std::string path = DATA_DIR +to_string (i)+"mode"+ "_out.dat";
            out_writer (path, &x, &y);
        }

        test_ese += (*potential)[i] * (*density) [i]/2;
    }

    return total_ese;
}

double pe_diagnostic (std::vector <double> *potential,
        std::vector <double> *density,  double iter){
    auto pe_total = 0.0;
    auto size = potential->size();
    std::vector <double> x (1);
    std::vector <double> y (1);

    std::string path = DATA_DIR + "pe_out.dat";
    mode_diagnostic (potential, density, iter);

    for (int i = 0; i < size; i++){
        pe_total += potential->at (i)* density->at(i);
    }

    x[0] = iter;
    y[0] = pe_total;
    out_writer (path, &x, &y);

    return pe_total;
}

void energy_diagnostic (std::vector <Particle *> *particles,
        std::vector <double> *potential, std::vector <double> *density,
        double iter)
{
    std::string path = DATA_DIR + "e_out.dat";
    std::vector <double> x (1);
    std::vector <double> y (1);

    auto e_total = ke_diagnostic (particles, iter) +
        pe_diagnostic (potential, density, iter);

    x [0] = iter;
    y [0] = e_total;
    out_writer (path, &x, &y);
}
