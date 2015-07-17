//Return kinetic energy vs time
#include "ke_diagnostic.h"

void ke_diagnostic (std::vector <Particle *> *particles, double t){
    double ke_total = 0;
    int size = particles -> size();
    std::string path = DATA_DIR + "ke_out.dat";
    std::ofstream ke_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i++){
        ke_total += particles->at (i)->get_ke();
    }

    ke_out << t << " " << ke_total << "\n";
    ke_out.close();
}

void pe_diagnostic (std::vector <double> *potential, std::vector <double> *density, double t){
    double pe_total = 0;
    int size = potential -> size();
    std::string path = DATA_DIR + "pe_out.dat";
    std::ofstream pe_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i++){
        pe_total += potential->at (i) * density->at (i);
    }

    pe_out << t << " " << pe_total << "\n";
    pe_out.close();
}
