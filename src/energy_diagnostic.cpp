//Return kinetic energy vs time
#include "energy_diagnostic.h"

double ke_diagnostic (std::vector <Particle *> *particles, double t){
    double ke_total = 0;
    int size = particles -> size();
    std::vector <double> x;
    std::vector <double> y;
    std::string path = DATA_DIR + "ke_out.dat";

    for (int i = 0; i < size; i++){
        ke_total += particles->at (i)->get_ke();
    }

    x.push_back (t);
    y.push_back (ke_total);

    out_writer (path, &x, &y);

    return ke_total;
}

double pe_diagnostic (std::vector <double> *potential, std::vector <double> *density, double t){
    double pe_total = 0;
    std::vector <double> x;
    std::vector <double> y;
    int size = potential -> size();

    std::string path = DATA_DIR + "pe_out.dat";

    for (int i = 0; i < size; i++){
        pe_total += potential->at (i) * density->at (i)/2;
    }
    x.push_back (t);
    y.push_back (pe_total);
    out_writer (path, &x, &y);

    return pe_total;
}

void energy_diagnostic (std::vector <Particle *> *particles, std::vector <double> *potential, std::vector <double> *density, double t){
    std::string path = DATA_DIR + "e_out.dat";
    std::ofstream e_out (path.c_str(), std::ios::app);
    std::vector <double> x;
    std::vector <double> y;
    double e_total = ke_diagnostic (particles, t) + pe_diagnostic (potential, density, t);

    x.push_back (t);
    y.push_back (e_total);
    out_writer (path, &x, &y);

}

