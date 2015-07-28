//Return momentum vs time
#include "mom_diagnostic.h"
#include <iostream>

void mom_diagnostic (std::vector <Particle *> *particles, double t){
    double mom_total = 0;
    std::vector <double> x;
    std::vector <double> y;
    int size = particles -> size();
    std::string path = DATA_DIR + "mom_out.dat";

    for (int i = 0; i < size; i++){
        mom_total += particles->at (i)->get_mom();
    }

    x.push_back (t);
    y.push_back (mom_total);
    out_writer (path, &x, &y);
}
