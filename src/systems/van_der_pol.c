#include "systems.h"

void van_der_pol_acc(system_t *system)
{
    double m = system->prop[0]; // Mass
    double mu = system->prop[1]; // Damping coefficient
    double alpha = system->prop[2]; // Nonlinearity parameter

    double x = system->p[0];
    double v = system->q[0];

    system->acc[0] = v;
    system->acc[1] = (-mu * (1 - alpha * x * x) * v - (1 / m) * x);
}

system_t *create_van_der_pol_system(double *system_spec)
{
    system_t *van_der_pol = (system_t *)malloc(sizeof(system_t));
    van_der_pol->size[0] = 2; // State size (position, velocity)
    van_der_pol->size[1] = 3; // Property size (m, mu, alpha)
    van_der_pol->p = (double *)malloc(sizeof(double) * van_der_pol->size[0]);
    van_der_pol->q = (double *)malloc(sizeof(double) * van_der_pol->size[0]);
    van_der_pol->acc = (double *)malloc(sizeof(double) * van_der_pol->size[0]);
    van_der_pol->prop = (double *)malloc(sizeof(double) * van_der_pol->size[1]);

    van_der_pol->p[0] = system_spec[3]; // initial_position
    van_der_pol->q[0] = system_spec[4]; // initial_velocity
    van_der_pol->acc[0] = 0.0;
    van_der_pol->acc[1] = 0.0;

    van_der_pol->prop[0] = system_spec[0]; // m
    van_der_pol->prop[1] = system_spec[1]; // mu
    van_der_pol->prop[2] = system_spec[2]; // alpha

    return van_der_pol;
}
