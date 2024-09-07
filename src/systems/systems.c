#include "systems.h"
#include <math.h>
#include <stdlib.h>

// Pendulum system
void pendulum_acc(system_t *system) {
    double length = system->prop[0];
    double g = system->prop[1];
    system->acc[0] = -(g / length) * sin(system->p[0]);
}

// Double pendulum system
void double_pendulum_acc(system_t *system) {
    double m1 = system->prop[0];
    double m2 = system->prop[1];
    double l1 = system->prop[2];
    double l2 = system->prop[3];
    double g = system->prop[4];

    double theta1 = system->q[0];
    double theta2 = system->q[1];
    double omega1 = system->p[0];
    double omega2 = system->p[1];

    double delta = theta2 - theta1;

    double denominator1 = (m1 + m2) * l1 - m2 * l1 * cos(delta) * cos(delta);
    double denominator2 = (l2 / l1) * denominator1;

    system->acc[0] = (m2 * l1 * omega1 * omega1 * sin(delta) * cos(delta) +
                      m2 * g * sin(theta2) * cos(delta) +
                      m2 * l2 * omega2 * omega2 * sin(delta) -
                      (m1 + m2) * g * sin(theta1)) / denominator1;
    system->acc[1] = (-m2 * l2 * omega2 * omega2 * sin(delta) * cos(delta) +
                      (m1 + m2) * g * sin(theta1) * cos(delta) -
                      (m1 + m2) * l1 * omega1 * omega1 * sin(delta) -
                      (m1 + m2) * g * sin(theta2)) / denominator2;
}

system_t* create_pendulum_system(double* system_spec) {
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

system_t* create_double_pendulum_system(double* system_spec) {
    system_t *double_pendulum = (system_t *)malloc(sizeof(system_t));
    double_pendulum->size[0] = 2; // State size
    double_pendulum->size[1] = 5; // Property size
    double_pendulum->p = (double *)malloc(sizeof(double) * double_pendulum->size[0]);
    double_pendulum->q = (double *)malloc(sizeof(double) * double_pendulum->size[0]);
    double_pendulum->acc = (double *)malloc(sizeof(double) * double_pendulum->size[0]);
    double_pendulum->prop = (double *)malloc(sizeof(double) * double_pendulum->size[1]);

    double_pendulum->p[0] = system_spec[5];
    double_pendulum->p[1] = system_spec[6];
    double_pendulum->q[0] = system_spec[7];
    double_pendulum->q[1] = system_spec[8];
    
    double_pendulum->acc[0] = 0.0;
    double_pendulum->acc[1] = 0.0;

    double_pendulum->prop[0] = system_spec[0];
    double_pendulum->prop[1] = system_spec[1];
    double_pendulum->prop[2] = system_spec[2];
    double_pendulum->prop[3] = system_spec[3];
    double_pendulum->prop[4] = system_spec[4];

    return double_pendulum;
}

void free_system(system_t *system) {
    free(system->p);
    free(system->q);
    free(system->acc);
    free(system->prop);
    free(system);
}

char system_names[SYS_N][INTG_NAME_MAX] = {
    "pendulum",
    "dpendulum"
};

void (*system_accs[SYS_N])(system_t *system) = {
    pendulum_acc,
    double_pendulum_acc
};

system_t* (*create_systems[SYS_N])(double*) = {
    create_pendulum_system,
    create_double_pendulum_system
};

double system_specs[SYS_N][SYS_PARAM_MAX] = {
    {1.0, 9.81, 0.1, 0.0}, //pendulum_spec
    {1.0, 1.0 , 1.0, 1.0, 9.81, 1, -1, 1.0, 2.0} //double_pendulum_spec
};

int system_spec_length[SYS_N] = {
    4,
    9
};