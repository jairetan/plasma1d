#include "psd.h"

std::complex <double> *complex_forward_trans (
        std::complex <double> *transform_in, int size)
{
    std::complex <double> *transform_out = new std::complex <double> (size);
    fftw_complex *in, *out;
    fftw_plan p = fftw_plan_dft_1d(size,
            reinterpret_cast <fftw_complex *> (transform_in),
            reinterpret_cast <fftw_complex *>(transform_out),
            FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    return transform_out;
}

void E_psd ()
{
    char *buffer = new char [1024];
    int size = ITERATIONS;
    FILE *in_file = NULL;
    FILE *out_file = NULL;
    std::complex <double> *field_space_time_trans = NULL;
    std::complex <double> *field_space_trans =
        new std::complex <double> [size];

    for (int i = 0; i < 20; i++){
        std::string read_path = DATA_DIR + to_string (i) +
            "field_space_trans.dat";
        std::string write_path = DATA_DIR + to_string (i) +
            "field_space_time_trans.dat";

        if ((in_file = fopen (read_path.c_str(), "r")) == NULL){
            printf ("File opening error");
            return;
        }

        if ((out_file = fopen (write_path.c_str(), "w+")) == NULL){
            printf ("File opening error");
            return;
        }

        for (int j = 0; fgets (buffer, 1025, in_file) != NULL; j++){
            double temp_real;
            double temp_imag;
            sscanf (buffer, "%d %lf %lf", &time, temp_real, temp_imag);
            field_space_trans [j] =
                std::complex <double> (temp_real, temp_imag);
        }

        field_space_time_trans = complex_forward_trans
            (field_space_trans, size);
        full_transform (field_space_time_trans, size);

        for (int j = 0; j < size; j++){
            fprintf (out_file, "%d %d %lf\n",i, j,
                    square_mod (field_space_time_trans [j]));
        }

        fclose (in_file);
        fclose (out_file);
    }
}

void U_psd (std::vector <double> *potential,
        std::vector <double> *density, int iter)
{
    int size = int (ITERATIONS);
    FILE *in_file = NULL;
    FILE *out_file = NULL;
    char *buffer = new char [1024];
    double time = 0;
    double *mode_ese = new double [size];
    std::complex <double> *transform_mode_ese = NULL;

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
            sscanf (buffer, "%lf %lf", &time, mode_ese+j);
        }

        transform_mode_ese = transform (mode_ese, size);
        full_transform (transform_mode_ese, size);

        for (int j = 0; j < size; j++){
            fprintf (out_file, "%d %d %lf\n", i, j,
                    square_mod (transform_mode_ese [j]));
        }

        fclose (in_file);
        fclose (out_file);
    }

    delete [] mode_ese;
    delete [] buffer;
}

