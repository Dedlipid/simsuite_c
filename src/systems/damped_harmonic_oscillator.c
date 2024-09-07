#include "systems.h"

void damped_harmonic_oscillator_acc(system_t *system)
{
    double m = system->prop[0]; // Mass
    double k = system->prop[1]; // Spring constant
    double c = system->prop[2]; // Damping coefficient

    system->acc[0] = (-k / m) * system->p[0] - (c / m) * system->q[0];
}

system_t *create_damped_harmonic_oscillator_system(double *system_spec)
{
    system_t *damped_oscillator = (system_t *)malloc(sizeof(system_t));
    damped_oscillator->size[0] = 1; // State size (position)
    damped_oscillator->size[1] = 3; // Property size (m, k, c)
    damped_oscillator->p = (double *)malloc(sizeof(double) * damped_oscillator->size[0]);
    damped_oscillator->q = (double *)malloc(sizeof(double) * damped_oscillator->size[0]);
    damped_oscillator->acc = (double *)malloc(sizeof(double) * damped_oscillator->size[0]);
    damped_oscillator->prop = (double *)malloc(sizeof(double) * damped_oscillator->size[1]);

    damped_oscillator->p[0] = system_spec[2]; // initial_position
    damped_oscillator->q[0] = system_spec[3]; // initial_velocity
    damped_oscillator->acc[0] = 0.0;

    damped_oscillator->prop[0] = system_spec[0]; // m
    damped_oscillator->prop[1] = system_spec[1]; // k
    damped_oscillator->prop[2] = system_spec[4]; // c

    return damped_oscillator;
}
