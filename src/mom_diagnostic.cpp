//Return momentum vs time
#include "mom_diagnostic.h"

void mom_diagnostic (std::vector <Particle *> *particles, double t){
    double mom_total = 0;
    int size = particles -> size();
    std::ofstream mom_out ("mom_out.dat", std::ios::app);

    for (int i = 0; i < size; i++){
        mom_total += particles->at (i)->get_mom();
    }

    mom_out << t << " " << mom_total << "\n";
    mom_out.close();
}
