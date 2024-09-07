#include "systems.h"

void spring_coupled_acc(system_t *system)
{
    double k1 = system->prop[0]; // Spring constant 1
    double k2 = system->prop[1]; // Spring constant 2
    double m1 = system->prop[2]; // Mass 1
    double m2 = system->prop[3]; // Mass 2

    double x1 = system->p[0];
    double x2 = system->p[1];
    double v1 = system->q[0];
    double v2 = system->q[1];

    double acc1 = (-k1 * x1 + k2 * (x2 - x1)) / m1;
    double acc2 = (-k2 * (x2 - x1)) / m2;

    system->acc[0] = acc1;
    system->acc[1] = acc2;
}

system_t *create_spring_coupled_system(double *system_spec)
{
    system_t *spring_coupled = (system_t *)malloc(sizeof(system_t));
    spring_coupled->size[0] = 2; // State size (position1, position2)
    spring_coupled->size[1] = 4; // Property size (k1, k2, m1, m2)
    spring_coupled->p = (double *)malloc(sizeof(double) * spring_coupled->size[0]);
    spring_coupled->q = (double *)malloc(sizeof(double) * spring_coupled->size[0]);
    spring_coupled->acc = (double *)malloc(sizeof(double) * spring_coupled->size[0]);
    spring_coupled->prop = (double *)malloc(sizeof(double) * spring_coupled->size[1]);

    spring_coupled->p[0] = system_spec[4]; // initial_position1
    spring_coupled->p[1] = system_spec[6]; // initial_position2
    spring_coupled->q[0] = system_spec[5]; // initial_velocity1
    spring_coupled->q[1] = system_spec[7]; // initial_velocity2
    spring_coupled->acc[0] = 0.0;
    spring_coupled->acc[1] = 0.0;

    spring_coupled->prop[0] = system_spec[2]; // k1
    spring_coupled->prop[1] = system_spec[3]; // k2
    spring_coupled->prop[2] = system_spec[0]; // m1
    spring_coupled->prop[3] = system_spec[1]; // m2

    return spring_coupled;
}
