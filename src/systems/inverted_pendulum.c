#include "systems.h"

void inverted_pendulum_acc(system_t *system)
{
    double Mc = system->prop[0]; // Cart mass
    double Mp = system->prop[1]; // Pendulum mass
    double L = system->prop[2]; // Pendulum length
    double g = system->prop[3]; // Gravity

    double x = system->p[0]; // Cart position
    double theta = system->p[1]; // Pendulum angle
    double vx = system->q[0]; // Cart velocity
    double omega = system->q[1]; // Pendulum angular velocity

    double sin_theta = sin(theta);
    double cos_theta = cos(theta);

    double denom = Mc + Mp * sin_theta * sin_theta;

    double acc_x = (Mp * g * sin_theta * cos_theta - Mp * L * omega * omega * sin_theta - (Mc + Mp) * g * sin_theta) / denom;
    double acc_theta = (g * sin_theta - acc_x * cos_theta) / L;

    system->acc[0] = acc_x;
    system->acc[1] = acc_theta;
}

system_t *create_inverted_pendulum_system(double *system_spec)
{
    system_t *inverted_pendulum = (system_t *)malloc(sizeof(system_t));
    inverted_pendulum->size[0] = 2; // State size (cart_position, pendulum_angle)
    inverted_pendulum->size[1] = 4; // Property size (Mc, Mp, L, g)
    inverted_pendulum->p = (double *)malloc(sizeof(double) * inverted_pendulum->size[0]);
    inverted_pendulum->q = (double *)malloc(sizeof(double) * inverted_pendulum->size[0]);
    inverted_pendulum->acc = (double *)malloc(sizeof(double) * inverted_pendulum->size[0]);
    inverted_pendulum->prop = (double *)malloc(sizeof(double) * inverted_pendulum->size[1]);

    inverted_pendulum->p[0] = system_spec[4]; // initial_cart_position
    inverted_pendulum->p[1] = system_spec[6]; // initial_pendulum_angle
    inverted_pendulum->q[0] = system_spec[5]; // initial_cart_velocity
    inverted_pendulum->q[1] = system_spec[7]; // initial_pendulum_angular_velocity
    inverted_pendulum->acc[0] = 0.0;
    inverted_pendulum->acc[1] = 0.0;

    inverted_pendulum->prop[0] = system_spec[0]; // Mc
    inverted_pendulum->prop[1] = system_spec[1]; // Mp
    inverted_pendulum->prop[2] = system_spec[2]; // L
    inverted_pendulum->prop[3] = system_spec[3]; // g

    return inverted_pendulum;
}
