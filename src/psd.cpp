#include "psd.h"
#include <complex.h>
#include <fftw3.h>

//static fftw_complex *transform (std::vector <double> *vect)
//{
    //double *vect_array = new double [vect->size()];
    //fftw_complex *transform_out = new fftw_complex [vect->size()];

    //for (int i = 0; i < vect->size(); i++){
        //vect_array [i] = vect->at (i);
    //}

    //fftw_plan p;

    //p = fftw_plan_dft_r2c_1d
        //(NUM_CELLS, vect_array, transform_out, FFTW_ESTIMATE);
    //fftw_execute (p);
    //fftw_destroy_plan (p);

    //return transform_out;
//}
static fftw_complex *transform (double *vect, int size)
{
    fftw_complex *transform_out = new fftw_complex [size];

    fftw_plan p;

    p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, vect, transform_out, FFTW_ESTIMATE);
    fftw_execute (p);
    fftw_destroy_plan (p);

    for (int i = 0; i < size; i++ ){
        vect [i] /= size;
    }

    return transform_out;
}

//static double *bad_helper (std::vector <double> *potential, std::vector <double> *density)
//{
    //fftw_complex *pot_trans = transform (potential);
    //fftw_complex *density_trans = transform (density);
    //double *energy_array = new double [20];

    //for (int i = 0 ; i < 20; i++){
        //double mode_energy = 0;
        //double pot_real = creal(pot_trans[i]);
        //double pot_imag = cimag(pot_trans[i]);
        //double density_real = creal(density_trans[i]);
        //double density_imag = cimag(density_trans[i]);

        ////if (density_imag * pot_real != pot_imag * density_real)
        ////{
            ////std::cout << density_imag *pot_real << " " << pot_imag * density_real << "\n";
            //////std::cout << "darn";
        ////}

        //mode_energy = .5 * (pot_real*density_real+pot_imag*density_imag);
        //energy_array [i] = mode_energy;
    //}
    //return energy_array;

//}
void psd (std::vector <double> *data, std::vector <double> *potential, std::vector <double> *density, int iter)
{
    double t = 0;
    int i =0;
    std::string line;
    std::string path2 = DATA_DIR + to_string (2)+"mode_out.dat";
    std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"psd_out.dat";
    std::ifstream in (path2.c_str());
    std::ofstream psd_out (path.c_str(), std::ios::app);
    int size = data->size();
    double *mode_energy = new double [(int)(T/D_T)];

    while (getline (in,line)){
        sscanf (line.c_str(), "%f %f", &t, mode_energy+i);
        i++;
    }

    fftw_complex *transformed_mode = transform (mode_energy, int (T/D_T));

    for (int j = 0; j < i ; j++){
        std::cout << creal (transformed_mode [j]) << " " << cimag (transformed_mode [j]) << "i\n";
        psd_out << j << " " << pow (creal (transformed_mode [j]),2) + pow (cimag (transformed_mode [j]) ,2 )<< "\n";
    }

    psd_out.close();
    fftw_free (transformed_mode);

    //double *mode_energy = bad_helper (potential, density);

    //for (int i = 0 ; i < size; i++){
        //psd_out << 2*M_PI*i/NUM_CELLS << " " << mode_energy [i] << "\n";
    //}

}
//void psd (std::vector <double> *data, int iter)
//{
    //std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"psd_out.dat";
    //std::ofstream psd_out (path.c_str(), std::ios::app);
    //int size = data->size();
    //double *data_array =  new double [size];
    //double *out_array =  new double [size];

    //fftw_complex *final_array =  (fftw_complex *)fftw_malloc (sizeof (fftw_complex)*size);

    //for (int i = 0; i < size; i++){
        //data_array [i] = data->at (i);
    //}

    ////gsl_stats_lag1_autocorrelation (data_array, 1, NUM_CELLS);

    //fftw_plan p = fftw_plan_dft_r2c_1d
        //(NUM_CELLS, data_array, final_array, FFTW_ESTIMATE);
    //fftw_execute (p);
    //fftw_destroy_plan (p);

    ////p = fftw_plan_dft_c2r_1d
        ////(NUM_CELLS,final_array, out_array, FFTW_ESTIMATE);
    ////fftw_execute (p);
    ////fftw_destroy_plan (p);

    ////std::vector <double>::iterator it = return_dat->begin();
    //for (int i = 0; i < 20; i++){
        //double real = 0, imag = 0;
        ////std::cout << creal (final_array [i]) << " " << cimag (final_array [i]) <<"i" << "\n";
        //real = creal (final_array [i]);
        //imag = cimag (final_array [i]);
        //psd_out << 2*M_PI*i/NUM_CELLS << " " << real*real + imag * imag << "\n";
////        return_dat->insert (it+i, data_array[i]);
    //}

    //fftw_free (final_array);

//}
