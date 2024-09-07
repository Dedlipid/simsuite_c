#ifndef SIMULATE_H
#define SIMULATE_H

#include "integrators.h"

typedef struct
{
    unsigned loops;
    unsigned steps_per_loop;
    char *filepath;
    double dt;
    system_t *system;
    system_acc_t update_acc;
    integrator_t integrator;
} sim_params_t;

extern void simulate(system_t *system,
                     system_acc_t update_acc,
                     int loops, int per_loop, double dt,
                     const char *output_filename,
                     integrator_t integrator);

#endif // SIMULATE_H