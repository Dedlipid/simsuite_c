#include "systems.h"

void harmonic_oscillator_acc(system_t *system)
{
    double k = system->prop[0]; // Spring constant
    double m = system->prop[1]; // Mass
    system->acc[0] = -(k / m) * system->p[0];
}

system_t *create_harmonic_oscillator_system(double *system_spec)
{
    system_t *oscillator = (system_t *)malloc(sizeof(system_t));
    oscillator->size[0] = 1; // State size (position)
    oscillator->size[1] = 2; // Property size (k, m)
    oscillator->p = (double *)malloc(sizeof(double) * oscillator->size[0]);
    oscillator->q = (double *)malloc(sizeof(double) * oscillator->size[0]);
    oscillator->acc = (double *)malloc(sizeof(double) * oscillator->size[0]);
    oscillator->prop = (double *)malloc(sizeof(double) * oscillator->size[1]);

    oscillator->p[0] = system_spec[2]; // initial_position
    oscillator->q[0] = system_spec[3]; // initial_velocity
    oscillator->acc[0] = 0.0;

    oscillator->prop[0] = system_spec[0]; // k
    oscillator->prop[1] = system_spec[1]; // m

    return oscillator;
}
