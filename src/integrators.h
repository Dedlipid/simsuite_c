#ifndef INTEGRATORS_H
#define INTEGRATORS_H

#include "systems.h"

void euler_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void eulerv1_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void eulerv2_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void leapfrog_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void rk4_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void verlet_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void velocity_verlet_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));
void midpoint_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *));

//Name list
char *integrator_names[] = {
    "euler",
    "eulerv1",
    "eulerv2",
    "leapfrog",
    "rk4",
    "verlet",
    "velocity_verlet",
    "midpoint"
};

//Function pointer list
void (*integrator_list[])(system_t*, double, int, void (*acc)(system_t*)) = {
    euler_step,
    eulerv1_step,
    eulerv2_step,
    leapfrog_step,
    rk4_step,
    verlet_step,
    velocity_verlet_step,
    midpoint_step
}; 

#endif
