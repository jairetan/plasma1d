//Return kinetic energy vs time
#include "energy_diagnostic.h"

double ke_diagnostic (std::vector <Particle *> *particles, double t){
    double ke_total = 0;
    int size = particles -> size();
    std::string path = DATA_DIR + "ke_out.dat";
    std::ofstream ke_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i++){
        ke_total += particles->at (i)->get_ke();
    }

    ke_out << t << " " << ke_total << "\n";
    ke_out.close();
    return ke_total;
}

double pe_diagnostic (std::vector <double> *potential, std::vector <double> *density, double t){
    double pe_total = 0;
    int size = potential -> size();
    std::string path = DATA_DIR + "pe_out.dat";
    std::ofstream pe_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i++){
        pe_total += potential->at (i) * density->at (i)/2;
    }

    pe_out << t << " " << pe_total << "\n";
    pe_out.close();
    return pe_total;
}

void energy_diagnostic (std::vector <Particle *> *particles, std::vector <double> *potential, std::vector <double> *density, double t){
    std::string path = DATA_DIR + "e_out.dat";
    std::ofstream e_out (path.c_str(), std::ios::app);
    double e_total = ke_diagnostic (particles, t) + pe_diagnostic (potential, density, t);

    e_out << t << " " << e_total << "\n";
    e_out.close();
}

