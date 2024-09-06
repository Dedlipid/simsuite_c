#ifndef INTEGRATORS_H
#define INTEGRATORS_H

#define INTEGRATOR_N 8
#define INTEGRATOR_INTG_NAME_MAX 10

#include "systems.h"
typedef void (*integrator_t)(system_t *, double, int, void (*acc)(system_t *));

void euler_step(system_t *system, double dt, int steps,
                void (*update_acc)(system_t *));
void eulerv1_step(system_t *system, double dt, int steps,
                  void (*update_acc)(system_t *));
void eulerv2_step(system_t *system, double dt, int steps,
                  void (*update_acc)(system_t *));
void leapfrog_step(system_t *system, double dt, int steps,
                   void (*update_acc)(system_t *));
void rk4_step(system_t *system, double dt, int steps,
              void (*update_acc)(system_t *));
void verlet_step(system_t *system, double dt, int steps,
                 void (*update_acc)(system_t *));
void velocity_verlet_step(system_t *system, double dt, int steps,
                          void (*update_acc)(system_t *));
void midpoint_step(system_t *system, double dt, int steps,
                   void (*update_acc)(system_t *));


// Name list
extern char integrator_names[INTEGRATOR_N][INTEGRATOR_INTG_NAME_MAX];

// Function pointer list
extern integrator_t integrator_list[INTEGRATOR_N];

#endif
