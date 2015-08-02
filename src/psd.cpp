#include "psd.h"

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
        full_transform (transform_mode_ese, size);

        for (int j = 0; j < size; j++){
            fprintf (out_file, "%d %f\n", j,
                    square_mod (transform_mode_ese [j]));
        }

        fclose (in_file);
        fclose (out_file);
    }
}

