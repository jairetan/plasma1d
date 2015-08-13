#pragma once

//Manage evolution of system over time
#include "density.h"
#include "init_pos.h"
#include "field.h"
#include "move.h"
#include "particle.h"
#include "electron.h"
#include "ion.h"
#include "time_history_diagnostics.h"
#include "density_diagnostic.h"
#include "init_v.h"
#include "init_pos.h"
#include "snapshot_diagnostics.h"
#include <vector>
#include "parameters.h"

//void run_man (int (*init_pos)(int),
        //double (*init_vel)(void), double dt,
        //double duration, double width, int num_ion,
        //int num_e, int num_div);
