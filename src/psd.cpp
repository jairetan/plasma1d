#include "psd.h"

void E_psd (std::vector <double> *field, int iter)
{
    double t = 0;
    double *field_c_array;
    std::string line;
    std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"psd_out.dat";
    std::ofstream psd_out (path.c_str(), std::ios::app);
    int size = field->size();

    fftw_complex *transformed_field = transform (&((*field)[0]), NUM_CELLS);

    for (int j = 0; j < size ; j++){
        double transformed_field_real = creal (transformed_field [j]);
        double transformed_field_imag = cimag (transformed_field [j]);

        psd_out << j << " " << pow (transformed_field_real, 2)
            + pow (transformed_field_imag, 2 )<< "\n";
    }

    psd_out.close();
    fftw_free (transformed_field);
}

void U_psd (std::vector <double> *potential,
        std::vector <double> *density, int iter)
{
    double total_ese = 0;
    double test_ese = 0;

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
        total_ese += mode_energy [i];

        test_ese += (*potential)[i] * (*density) [i]/200;
    }

    std::cout << total_ese << "::" << test_ese << "\n";
}

