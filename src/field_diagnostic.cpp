#include "field_diagnostic.h"

void field_diagnostic (std::vector <double> *field, int iter)
{
    std::vector <double> x;
    for (int i = NUM_CELLS-1; i >=0; i--){
        x.push_back (i);
    }
    std::string path = DATA_DIR +
        to_string (int (.5 + iter*D_T*10/T)) +"field_out.dat";

    out_writer (path, &x, field);
}

void field_space_transform (std::vector <double> *field, int iter)
{

    std::complex <double> *space_transform = transform
        (&(field->at (0)), field->size());
    std::string path = DATA_DIR +
        to_string (int (.5 + iter*D_T*10/T)) +"field_space_trans.dat";
    std::vector <std::complex <double> > writing_vector
        (space_transform, space_transform + field->size ());

    FILE *file = NULL;
    if ((file = fopen (path.c_str(), "a")) == NULL){
        return;
    }

    for (int i = 0 ; i < field->size(); i++){
        fprintf (file, "%f %f %f\n",i,
                space_transform[i].real (), space_transform[i].imag());
    }

}
