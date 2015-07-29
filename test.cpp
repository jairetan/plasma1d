#include <complex.h>
#include <fftw3.h>
#include <iostream>
int main ()
{
    double *density = new double [4];
    double *final_density = new double [4];
    density [0] = 0;
    density [1] = 1;
    density [2] = 0;
    density [3] = -1;

    fftw_complex *density_trans = new fftw_complex [4];

    fftw_plan p = fftw_plan_dft_r2c_1d
        (4, density, density_trans, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    for (int i =0 ; i <4; i++){
        std::cout <<density_trans [i][0] << " " << density_trans [i][1] << "i\n";
    }
    std::cout << "\n";
    p = fftw_plan_dft_c2r_1d
        (4, density_trans, final_density, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    for (int i =0 ; i <4; i++){
        std::cout <<creal (final_density [i]/4) << " " << cimag (final_density [i]/4) << "i\n";
    }
}
