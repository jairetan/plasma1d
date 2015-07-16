#include "field.h"
#include <iostream>

static double trans_mult (int x, double kappa)
{
    //double delta_x = SYS_SIZE/4;
    //double k = kappa * x;
    //double inner_term = k * delta_x / 2;

    //double multiplier =  inner_term*inner_term/sin (inner_term) / sin (inner_term)/k/k;
    double multiplier = .5 * 1/(cos (2*M_PI*x/4)-1);

    return multiplier;
}

static void electric_field (std::vector <double> *phi, std::vector <double> *field)
{
    for (int i = 1 ; i < 4-1; i++)
    {
        field->at (i) = (phi->at (i-1)-phi->at (i+1))/2;
    }

    //Periodic boundary conditions
    field->at (0) = (phi->at (4-1)-phi->at (1))/2;
    field->at (4-1) = (phi->at(4-2)-phi->at (0))/2;
}

void calc_field_run()
{
    std::vector <double> field_vector (4);
    std::vector <double> pot_vector (4);
    std::vector <double> density_vector (4);

    //density_vector.push_back (0);
    //density_vector.push_back (1.5);
    //density_vector.push_back (1.5);
    //density_vector.push_back (1);
    density_vector.insert (density_vector.begin (), 1);
    density_vector.insert (density_vector.begin ()+1, 1.5);
    density_vector.insert (density_vector.begin ()+2, 1.5);
    density_vector.insert (density_vector.begin ()+3, 0);

    calc_field (&field_vector, &pot_vector, &density_vector);
    std::cout << field_vector.at (0) << " " << field_vector.at (1) << " " << field_vector.at (2) << " " << field_vector.at (3) << "\n";
    std::cout << pot_vector.at (0) << " " << pot_vector.at (1) << " " << pot_vector.at (2) << " " << pot_vector.at (3) << "\n";
}

void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector)
{
    double *potential = (double *)calloc (4,
            sizeof (double)),
           *density = (double *)calloc (4,
                   sizeof (double));

    std::cout.precision (15);
    double kappa = 2*M_PI/4;
    fftw_complex *pot_trans = NULL;
    fftw_plan p;

    for (int i = 0; i < 4; i++){
        density [i] = density_vector->at(i);
        std::cout << "Density: " << density [i] << " ";
    }
    std::cout << "\n";

    pot_trans = (fftw_complex*) fftw_malloc
        (sizeof (fftw_complex)*(3));

    /*Transform density*/
    p = fftw_plan_dft_r2c_1d
        (4, density, pot_trans, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    for (int x = 1; x < 3; x++)
    {
        //pot_trans [x] *= -1/ (x*x)/.1 / kappa /kappa;
        std::cout << "Density Transform " << pot_trans[x] << "\n";
        pot_trans [x] *= trans_mult (x, kappa);
        std::cout << "Density Transform Mult " << trans_mult (x, kappa) << "\n";
    }

    //pot_trans [0] = 0;

    p = fftw_plan_dft_c2r_1d (4, pot_trans,
            potential, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*divide by 4 in array (inverse transform not normalized)*/
    for (int x = 0; x < 4; x++)
    {
        potential [x] /= 4;
        pot_vector->at (x) = potential [x];
    }

    electric_field (pot_vector, field_vector);
    free (potential);
    free (density);

    fftw_free (pot_trans);
}
