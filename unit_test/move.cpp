//Move particles
#include "move.h"
#include <iostream>
#include "electron.h"

//Return normalized acceleration
static double find_accel (double field, Particle *particle)
{
    double accel = field * particle->get_charge ();
    return accel;
}

void move_particles_run ()
{
    std::vector <Particle *> particles;
    std::vector <double> field;

    field.push_back (-.125);
    field.push_back (-.375);
    field.push_back (.125);
    field.push_back (.375);

    Electron e1 (0, 2, 1);
    Electron e2 (0, 1, 1);
    Electron e3 (.1, 1.5, 1);
    Electron e4 (-.1, 0, 1);

    particles.push_back (&e4);
    particles.push_back (&e3);
    particles.push_back (&e2);
    particles.push_back (&e1);

    move_particles (&particles, &field);

    for (std::vector <Particle *>::iterator it = particles.begin(); it != particles.end(); it++){

        std::cout << "Particle: " << (*it)->get_pos () << " " << (*it)->get_vel () << "\n";
    }

}

void move_particles (std::vector <Particle *> * particles, std::vector <double> *field)
{
    using namespace std;

    int num_particles = particles->size();
    vector <double> weights;
    vector <int> points;

    for (int i = 0; i < num_particles; i++)
    {
        weighing (particles->at (i), &weights);
        //zero_order_weighing (particles->at (i), &weights); //Birdsell says to conserve energy
        adjacent_points (particles->at (i), &points);

        particles->at (i)->inc_vel (find_accel(field->at (points.at (0))*weights.at (0)+field->at (points.at (1))*weights.at (1), particles->at(i)));
        particles->at (i)->inc_pos ();

        weights.clear();
        points.clear ();
    }
}
