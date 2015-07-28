#pragma once
#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"
#include <string>
//Things to consider when kind of works
//1. Assymetric time steps for field and species
//Work through each module by hand

//Guidelines for parameters (from birdsell):
//Number of particles in a debye length >> 1
//Scale length >> 1 debye length
//KE >> PE ?

static const int PLOT_MODES = 20;

//Boltzmann dist stuff
static const double TOLERANCE = 1;
static const double TEMP = 1e-6; //in kelvin
static const double NON_NORMAL_MASS = CLHEP::electron_mass_c2/CLHEP::c_squared/CLHEP::joule/1e12; //Mass in kg
static const double MY_BOLTZMANN =1.3806488e-23; //in SI base units
//static const double MY_EPSIL0 = 8.85418782e-12;
static const double MY_EPSIL0 = 1;

//Normalized units
static const double D_T = 1e-4;
static const double T = 1;
static const int NUM_CELLS = 1e2;
static const int PARTICLE_WIDTH = 1; //In debye lengths
static const int SYS_SIZE = 1e2; //In debye lengths
static const double FIELD_SCALE = 1;
static const int NUM_IONS = 0;
static const int NUM_E = 1e4;

//Normalized to electron properties
//static const double PROTON_CHARGE = 1;
//static const double ELECTRON_CHARGE = -1;
//static const double PROTON_MASS = 100;
//static const double ELECTRON_MASS = 1;

static const double ELECTRON_CHARGE = -SYS_SIZE/NUM_CELLS * MY_EPSIL0;
static const double ELECTRON_MASS = -ELECTRON_CHARGE;
static const int BACKGROUND_DENSITY = -NUM_E*ELECTRON_CHARGE/NUM_CELLS;

//Non normalized masses
/*static const double PROTON_CHARGE = CLHEP::eplus;
static const double ELECTRON_CHARGE = -CLHEP::eplus;
static const double PROTON_MASS = CLHEP::proton_mass_c2;
static const double ELECTRON_MASS = -CLHEP::electron_mass_c2;*/

//Weighing schemes
static const int CIC = 1;
static const int ZERO_ORDER = 0;

//Output Directories
static const std::string DATA_DIR ("data/");
