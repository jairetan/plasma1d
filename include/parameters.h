#pragma once
#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"
#include <string>
#include <cmath>

//Things to consider when kind of works
//1. Assymetric time steps for field and species
//Work through each module by hand
//Normalized units

static const double D_T = 1e-6;
static const double T = 1e-2;
static const int NUM_CELLS = 1e2; //size of cells < debye length
static const int PARTICLE_WIDTH = 1; //In debye lengths
static const double GRID_SIZE = .2; //Grid size must be < Debye length
static const int SYS_SIZE = 1e2; //In debye lengths
static const double FIELD_SCALE = 1;
static const int NUM_IONS = 1e4;
static const int NUM_E = 1e4;

static const int PLOT_MODES = 20;

//Boltzmann dist stuff
//static const double TOLERANCE = 1;
//static const double ELECTRON_TEMP = 1e-2; //in kelvin
//static const double NON_NORMAL_MASS = CLHEP::electron_mass_c2/
//CLHEP::c_squared/CLHEP::joule/1e12; //Mass in kg
//static const double MY_BOLTZMANN =1.3806488e-23; //in SI base units
//static const double MY_FUNDAMENTAL_CHARGE =1.6e-19; //in SI base units
//static const double MY_EPSIL0 = 8.85418782e-12;
//static const double MY_EPSIL0 = 1;

//static const double DEBYE_LENGTH = pow (MY_EPSIL0 * MY_BOLTZMANN *
//ELECTRON_TEMP/pow (MY_FUNDAMENTAL_CHARGE, 2)/NUM_E*SYS_SIZE, 1.0/3);
//static const double E_V_THERMAL = pow (2*MY_BOLTZMANN * ELECTRON_TEMP/ NON_NORMAL_MASS,.5);
//static const double I_V_THERMAL = pow (2*MY_BOLTZMANN * ELECTRON_TEMP/ NON_NORMAL_MASS/1000, .5);
//static const double PLASMA_FREQ = E_V_THERMAL/DEBYE_LENGTH;


//Normalized to electron properties
//static const double PROTON_CHARGE = 1;
//static const double ELECTRON_CHARGE = -1;
//static const double PROTON_MASS = 100;
//static const double ELECTRON_MASS = 1;

static const double ELECTRON_CHARGE = -1;
static const double ION_CHARGE = 1;
static const double ELECTRON_MASS = -ELECTRON_CHARGE;
static const double ION_MASS = 1000 * ELECTRON_MASS;
static const int BACKGROUND_DENSITY = 0;
//static const int BACKGROUND_DENSITY = -NUM_E*ELECTRON_CHARGE/NUM_CELLS;
//
static const double E_V_THERMAL = .3; //In units of grid_size/d_t
static const double I_V_THERMAL = .01;
//static const double I_V_THERMAL = .0;
static const double E_BOLTZMANN_TEMP = E_V_THERMAL* E_V_THERMAL/2; //Normalized k*T
static const double I_BOLTZMANN_TEMP = I_V_THERMAL* I_V_THERMAL/2*ION_MASS;

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
