#include "mode_diagnostic.h"

//Time history of chosen Fourier mdoes
void mode_diagnostic (int mode, double val, double t)
{
    std::ofstream mode_out ("mode_"+std::to_string (mode)+"_out.dat", std::ios::app);
    mode_out << t << " " << val;
    mode_out.close();
}
