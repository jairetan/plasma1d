#pragma once
//Things to consider when kind of works
//1. Assymetric time steps for field and species

//Guidelines for parameters (from birdsell):
//Number of particles in a debye length >> 1
//Scale length >> 1 debye length
//KE >> PE ?

static const double D_T = 1e-12;
static const int NUM_CELLS = 100;
static const double T = 1e-9; //In units of plasma freq
static const int PARTICLE_WIDTH = 1; //In Units of debye length
static const int NUM_IONS = 0;
static const int NUM_E = 10000;
static const int SYS_SIZE = 1000; //In debye lengths
static const double FIELD_SCALE = 1;

