#include "psd.h"

static fftw_complex *transform (double *vect, int size)
{
    fftw_complex *transform_out = new fftw_complex [size];
    fftw_plan p = fftw_plan_dft_r2c_1d
        (size, vect, transform_out, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //fftw does not fill in latter half of transform array (hermitian symmetry)
    for (int i = 0; i < size/2; i++){
        transform_out [size-i-1] = conj (transform_out [i]);
    }

    //fftw does not normalize transform
    for (int i = 0; i < size; i++ ){
        transform_out [i] /= size;
    }

    return transform_out;
}

void psd (std::vector <double> *field, int iter)
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
