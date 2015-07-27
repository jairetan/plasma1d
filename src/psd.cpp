#include "psd.h"
void psd (std::vector <double> *data, int iter)
{
    std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"psd_out.dat";
    std::ofstream psd_out (path.c_str(), std::ios::app);
    int size = data->size();
    double *data_array =  new double [size];
    double *out_array =  new double [size];

    fftw_complex *final_array =  (fftw_complex *)fftw_malloc (sizeof (fftw_complex)*size);

    for (int i = 0; i < size; i++){
        data_array [i] = data->at (i);
    }

    //gsl_stats_lag1_autocorrelation (data_array, 1, NUM_CELLS);

    fftw_plan p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, data_array, final_array, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //p = fftw_plan_dft_c2r_1d
        //(NUM_CELLS,final_array, out_array, FFTW_ESTIMATE);
    //fftw_execute (p);
    //fftw_destroy_plan (p);

    //std::vector <double>::iterator it = return_dat->begin();
    for (int i = 0; i < 20; i++){
        double real = 0, imag = 0;
        //std::cout << creal (final_array [i]) << " " << cimag (final_array [i]) <<"i" << "\n";
        real = creal (final_array [i]);
        imag = cimag (final_array [i]);
        psd_out << i << " " << real*real + imag * imag << "\n";
//        return_dat->insert (it+i, data_array[i]);
    }

    fftw_free (final_array);

}
