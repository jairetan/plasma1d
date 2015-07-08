//Manage evolution of system over time
#include "density.h"
#include "init-pos.h"
#include "field.h"
#include "move.h"
#include "particle.h"
#include "proton.h"
#include "electron.h"
#include "diagnostics.h"
#include "field_diagnostic.h"
#include "pot_diagnostic.h"
#include <vector>

#pragma once

void run_man (int (*init_pos)(int),
        double (*init_vel)(void), double dt,
        double duration, double width, int num_ion,
        int num_e, int num_div);
