#include "systems.h"

void mass_spring_damper_acc(system_t *system)
{
    double m = system->prop[0]; // Mass
    double k = system->prop[1]; // Spring constant
    double c = system->prop[2]; // Damping coefficient

    system->acc[0] = (-k / m) * system->p[0] - (c / m) * system->q[0];
}

system_t *create_mass_spring_damper_system(double *system_spec)
{
    system_t *mass_spring_damper = (system_t *)malloc(sizeof(system_t));
    mass_spring_damper->size[0] = 1; // State size (position)
    mass_spring_damper->size[1] = 3; // Property size (m, k, c)
    mass_spring_damper->p = (double *)malloc(sizeof(double) * mass_spring_damper->size[0]);
    mass_spring_damper->q = (double *)malloc(sizeof(double) * mass_spring_damper->size[0]);
    mass_spring_damper->acc = (double *)malloc(sizeof(double) * mass_spring_damper->size[0]);
    mass_spring_damper->prop = (double *)malloc(sizeof(double) * mass_spring_damper->size[1]);

    mass_spring_damper->p[0] = system_spec[3]; // initial_position
    mass_spring_damper->q[0] = system_spec[4]; // initial_velocity
    mass_spring_damper->acc[0] = 0.0;

    mass_spring_damper->prop[0] = system_spec[0]; // m
    mass_spring_damper->prop[1] = system_spec[1]; // k
    mass_spring_damper->prop[2] = system_spec[2]; // c

    return mass_spring_damper;
}
