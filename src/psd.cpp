#include "psd.h"
void psd (std::vector <double> * data, std::vector <double> *return_dat)
{
    std::string path = DATA_DIR + "psd_out.dat";
    std::ofstream psd_out (path.c_str(), std::ios::app);
    int size = data->size();
    double *data_array =  (double *)calloc (sizeof (double), size);
    fftw_complex *final_array =  (fftw_complex *)calloc (sizeof (double), size);
    for (int i = 0; i < size; i++){
        data_array [i] = data->at (i);
    }

    gsl_stats_lag1_autocorrelation (data_array, 1, NUM_CELLS);

    fftw_plan p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, data_array, final_array, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    //std::vector <double>::iterator it = return_dat->begin();
    for (int i = 0; i < size; i++){
        psd_out << i << " " << creal(final_array [i]) << "\n";
//        return_dat->insert (it+i, data_array[i]);
    }

}
