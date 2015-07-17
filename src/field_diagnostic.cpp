#include "field_diagnostic.h"
#include "parameters.h"

void field_diagnostic (std::vector <double> *field, int iter)
{
    std::string path = DATA_DIR + to_string (iter*D_T*10/T) +"field_out.dat";
    std::ofstream field_out (path.c_str(), std::ios::app);
    int size = field->size();
    for (int x = 0; x < size; x++)
    {
        field_out << x << " " << field->at (x) << "\n";
    }
    field_out.close ();
}
