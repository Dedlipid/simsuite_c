#include "systems.h"

void driven_pendulum_acc(system_t *system)
{
    double L = system->prop[0]; // Length
    double g = system->prop[1]; // Gravity
    double A = system->prop[2]; // Driving force amplitude
    double omega = system->prop[3]; // Driving force frequency

    double theta = system->p[0]; // Angle
    double omega_theta = system->q[0]; // Angular velocity

    double driving_force = A * sin(omega * system->prop[4]); // Time-dependent driving force
    system->acc[0] = -(g / L) * sin(theta) + driving_force;
}

system_t *create_driven_pendulum_system(double *system_spec)
{
    system_t *driven_pendulum = (system_t *)malloc(sizeof(system_t));
    driven_pendulum->size[0] = 1; // State size (angle)
    driven_pendulum->size[1] = 5; // Property size (L, g, A, omega, t)
    driven_pendulum->p = (double *)malloc(sizeof(double) * driven_pendulum->size[0]);
    driven_pendulum->q = (double *)malloc(sizeof(double) * driven_pendulum->size[0]);
    driven_pendulum->acc = (double *)malloc(sizeof(double) * driven_pendulum->size[0]);
    driven_pendulum->prop = (double *)malloc(sizeof(double) * driven_pendulum->size[1]);

    driven_pendulum->p[0] = system_spec[2]; // initial_angle
    driven_pendulum->q[0] = system_spec[3]; // initial_angular_velocity
    driven_pendulum->acc[0] = 0.0;

    driven_pendulum->prop[0] = system_spec[0]; // L
    driven_pendulum->prop[1] = system_spec[1]; // g
    driven_pendulum->prop[2] = system_spec[4]; // A
    driven_pendulum->prop[3] = system_spec[5]; // omega
    driven_pendulum->prop[4] = 0.0; // initial time, can be updated as needed

    return driven_pendulum;
}
