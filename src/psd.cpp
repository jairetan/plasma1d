#include "psd.h"
#include <iostream>

void E_psd ()
{
    std::complex <double> *field_space_time_trans = NULL;
    std::vector <std::complex <double> > field_space_trans (TIME_MODES);

    std::ifstream in_file;
    std::ofstream out_file;

    for (int i = 0; i < SPATIAL_MODES; i++){
        std::string read_path = DATA_DIR + to_string (i) +
            "field_space_trans.dat";
        std::string write_path = DATA_DIR + to_string (i) +
            "field_space_time_trans.dat";
        in_file.open (read_path.c_str());

        if (in_file.fail()){
            std::cout << "In failed" << std::endl;
        }

        out_file.open (write_path.c_str(), std::ios::app);
        if (out_file.fail ()){
            std::cout << "Out failed" << std::endl;
        }

        for (int j = 0; j < TIME_MODES && !in_file.eof (); j++){
            double temp_real;
            double temp_imag;
            int time;

            in_file >> time >> temp_real >>temp_imag;
            field_space_trans [j].real (temp_real);
            field_space_trans [j].imag (temp_imag);
        }

        field_space_time_trans = complex_forward_trans
            (&field_space_trans[0], TIME_MODES);
        full_transform (field_space_time_trans, TIME_MODES);

        for (int j = 0; j < TIME_MODES; j++){
            out_file << i << " " << j << " " <<
                    square_mod (field_space_trans [j]) << std::endl;
        }

        in_file.close();
        out_file.close();
    }
}

void U_psd (std::vector <double> *potential,
        std::vector <double> *density, int iter)
{
    int size = int (ITERATIONS);
    std::ifstream in_file;
    std::ofstream out_file;
    double time = 0;
    std::vector <double> mode_ese (size);
    std::complex <double> *transform_mode_ese = NULL;

    for (int i = 0; i < SPATIAL_MODES; i++){
        std::string read_path = DATA_DIR + to_string (i) + "mode_out.dat";
        std::string write_path = DATA_DIR + to_string (i) + "U_psd_out.dat";

        in_file.open (read_path.c_str());
        out_file.open (write_path.c_str (), std::ios::app);

        for (int j = 0; !in_file.eof (); j++){
            in_file >> time >> mode_ese [j];
        }

        transform_mode_ese = transform (&mode_ese[0], size);
        full_transform (transform_mode_ese, size);

        for (int j = 0; j < size; j++){
            out_file << i << " " <<  j << " " <<
                    square_mod (transform_mode_ese [j]) << std::endl;
        }

        in_file.close();
        out_file.close();
    }

}

