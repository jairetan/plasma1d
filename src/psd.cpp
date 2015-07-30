#include "psd.h"

void E_psd (std::vector <double> *field, int iter)
{
    double t = 0;
    double *field_c_array;
    std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"E_psd_out.dat";
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
    int size = int (T/D_T);
    FILE *in_file = NULL;
    FILE *out_file = NULL;
    char *buffer = new char [1024];
    double time = 0;
    double *mode_ese = new double [size];
    fftw_complex *transform_mode_ese = NULL;


    for (int i = 0; i < PLOT_MODES; i++){
        std::string read_path = DATA_DIR + to_string (i) + "mode_out.dat";
        std::string write_path = DATA_DIR + to_string (i) + "U_psd_out.dat";

        if ((in_file = fopen (read_path.c_str(), "r")) == NULL){
            printf ("File opening error");
            return;
        }

        if ((out_file = fopen (write_path.c_str(), "w+")) == NULL){
            printf ("File opening error");
            return;
        }

        for (int j = 0; fgets (buffer, 1025, in_file) != NULL; j++){
            sscanf (buffer, "%f %f", &time, mode_ese+j);
        }

        transform_mode_ese = transform (mode_ese, size);
        for (int j = 0; j < size; j++){
            fprintf (out_file, "%d %f\n",j,
                    square_mod (transform_mode_ese [j]));
        }

        fclose (in_file);
        fclose (out_file);
    }
    //std::string path = DATA_DIR + to_string (10*iter*D_T/T)+"U_psd_out.dat";
    //std::ofstream psd_out (path.c_str(), std::ios::app);

    //double total_ese = 0;
    //double test_ese = 0;

    //int size = potential->size();

    //fftw_complex *transformed_potential = transform (&((*potential)[0]), NUM_CELLS);
    //fftw_complex *transformed_density = transform (&((*density)[0]), NUM_CELLS);
    //std::vector <double> mode_energy (size);

    //for (int i = 0; i < size; i++){
        //double trans_pot_real = creal (transformed_potential [i]);
        //double trans_pot_imag = cimag (transformed_potential [i]);
        //double trans_dens_real = creal (transformed_density [i]);
        //double trans_dens_imag = cimag (transformed_density [i]);

        //mode_energy[i] = .5 * (trans_pot_real * trans_dens_real
                //+ trans_pot_imag * trans_dens_imag);
        //mode_energy [i] *= NUM_CELLS; //One too many normalizations

        //psd_out << i << " " << mode_energy [i] << "\n";
        //total_ese += mode_energy [i];

        //test_ese += (*potential)[i] * (*density) [i]/2;
    //}
}

