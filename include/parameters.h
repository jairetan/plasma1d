#pragma once
#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"
#include <string>
#include <cmath>

//Things to consider when kind of works
//1. Assymetric time steps for field and species
//Work through each module by hand
//Normalized units

static const double D_T = 1e-4;
static const int ITERATIONS = 1e4;
static const int NUM_CELLS = 1e2; //size of cells < debye length
static const int PARTICLE_WIDTH = 1; //In debye lengths
static const double GRID_SIZE = .2; //Grid size must be < Debye length
static const int SYS_SIZE = 1e2; //In debye lengths
static const double FIELD_SCALE = 1;
static const int NUM_IONS = 1e3;
static const int NUM_E = 1e3;

static const int SPATIAL_MODES = 20;
static const int TIME_MODES = 100;

static const double ELECTRON_CHARGE = -1;
static const double ION_CHARGE = 1;
static const double ELECTRON_MASS = -ELECTRON_CHARGE;
static const double ION_MASS = 1000 * ELECTRON_MASS;
static const double BACKGROUND_DENSITY = 0;
//static const int BACKGROUND_DENSITY = -NUM_E*ELECTRON_CHARGE/NUM_CELLS;
//
static const double E_V_THERMAL = .01; //In units of grid_size/d_t
static const double I_V_THERMAL = .00005;
static const double E_BOLTZMANN_TEMP = E_V_THERMAL* E_V_THERMAL/2 * ELECTRON_MASS; //Normalized k*T
static const double I_BOLTZMANN_TEMP = I_V_THERMAL* I_V_THERMAL/2*ION_MASS;

//Weighing schemes
static const int CIC = 1;
static const int ZERO_ORDER = 0;

//Output Directories
static const std::string DATA_DIR ("data/");
