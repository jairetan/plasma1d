#include "mode_diagnostic.h"

static double *transform_field (std::vector <double> *field)
{
    double *field_array = new double [field->size()];
    fftw_complex *field_out = new fftw_complex [field->size()];
    double *field_return = new double [field->size()];

    for (int i = 0; i < field->size(); i++){
        field_array [i] = field->at (i);
    }

    fftw_plan p;

    p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, field_array, field_out, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    for (int i = 0; i < field->size(); i++){
        field_return [i] *= cabs (field_out[i]*conj(field_out [i]));
    }

    return field_return;
}

//Time history of chosen Fourier mdoes
void mode_diagnostic (std::vector <double> *field, int t)
{
    double *field_trans = transform_field (field);

    for (int i = 0; i < field->size()/5; i++){
        double real = creal (field_trans [i]);
        double imag = cimag (field_trans [i]);
        double real_sq = real * real;
        double imag_sq = imag * imag;

        std::string path = DATA_DIR +to_string (i)+"mode"+ "_out.dat";
        std::ofstream mode_out (path.c_str(), std::ios::app);
        mode_out << t << " " << sqrt (real_sq + imag_sq) << "\n";
        mode_out.close();
    }

    //To get power spectrum, take fourier transform again
    //Find dispersion relation plot
    //std::ofstream mode_out ("mode_"+ to_string (mode)+"_out.dat", std::ios::app);
    //mode_out << t << " " << val;
    //mode_out.close();
}
