#include "out_writer.h"

//Size of x_data and y_data assumed to be same
void out_writer (std::string path, std::vector <double> *x_data,
        std::vector <double> *y_data)
{
    std::ofstream file (path.c_str(), std::ios::app);
    int size = x_data->size();

    for (int i = 0 ; i < size; i++){
        file << x_data->at (i) << " " <<  y_data->at (i) << std::endl;
    }

}
