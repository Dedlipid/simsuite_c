#include "systems.h"

// Pendulum system
void pendulum_acc(system_t *system)
{
    double length = system->prop[0];
    double g = system->prop[1];
    system->acc[0] = -(g / length) * sin(system->p[0]);
}

system_t *create_pendulum_system(double *system_spec)
{
    system_t *pendulum = (system_t *)malloc(sizeof(system_t));
    pendulum->size[0] = 1; // State size
    pendulum->size[1] = 2; // Property size
    pendulum->p = (double *)malloc(sizeof(double) * pendulum->size[0]);
    pendulum->q = (double *)malloc(sizeof(double) * pendulum->size[0]);
    pendulum->acc = (double *)malloc(sizeof(double) * pendulum->size[0]);
    pendulum->prop = (double *)malloc(sizeof(double) * pendulum->size[1]);

    pendulum->p[0] = system_spec[2];
    pendulum->q[0] = system_spec[3];
    pendulum->acc[0] = 0.0;

    pendulum->prop[0] = system_spec[0];
    pendulum->prop[1] = system_spec[1];

    return pendulum;
}
