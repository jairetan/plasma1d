#include "field.h"

//Mutliplier for transformed density
static double trans_mult (int x)
{
    return -2*M_PI *1/(cos (2*M_PI*x/NUM_CELLS)-1);
}

static double finite_derivative (double *function, int loc)
{
    return (function [loc-1]-function [loc+1])/2;
}

//Calculate Electric field from finite differences
static void electric_field (std::vector <double> *phi,
        std::vector <double> *field)
{
    for (int i = 1 ; i < NUM_CELLS-1; i++){
        field->at (i) = -finite_derivative (&(phi->at (0)), i);
    }

    //Periodic boundary conditions
    field->at (0) = (phi->at (NUM_CELLS-1)-phi->at (1))/2;
    field->at (NUM_CELLS-1) = (phi->at(NUM_CELLS-2)-phi->at (0))/2;

}

//Calculate potential and electric field from charge density
void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector)
{
    std::vector <double> potential;
    std::vector <std::complex <double> > density_trans;

    density_trans = transform (&(density_vector->at(0)), NUM_CELLS);

    //#pragma omp parallel for
    for (int x = 1; x < NUM_CELLS/2; x++){
        density_trans [x] *= trans_mult (x);
    }

    density_trans [0] = 0; //Net charge of system = 0
    potential = inverse_transform (&density_trans[0], NUM_CELLS);

    for (int x = 0; x < NUM_CELLS; x++){
        pot_vector->at (x) = potential [x];
    }

    electric_field (pot_vector, field_vector);
}
