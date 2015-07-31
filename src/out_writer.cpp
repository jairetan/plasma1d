#include "out_writer.h"

//Size of x_data and y_data assumed to be same
void out_writer (std::string path, std::vector <double> *x_data,
        std::vector <double> *y_data)
{
    FILE *file = NULL;
    int size = x_data->size();
    if ((file = fopen (path.c_str (), "a")) == NULL){
        printf ("Error opening file\n");
        return;
    }

    for (int i = 0 ; i < size; i++){
        fprintf (file, "%f %f\n", x_data->at (i), y_data->at (i));
    }
    fclose (file);

}
