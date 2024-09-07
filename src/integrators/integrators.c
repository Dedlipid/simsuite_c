#include "integrators.h"

char integrator_names[INTEGRATOR_N][INTEGRATOR_INTG_NAME_MAX] = {
    "euler",
    "eulerm1",
    "eulerm2",
    "lpfrog",
    "rk4",
    "verlet",
    "velver",
    "midp"
};

void (*integrator_list[INTEGRATOR_N])(system_t*, double, int, void (*acc)(system_t*)) = {
    euler_step,
    eulerv1_step,
    eulerv2_step,
    leapfrog_step,
    rk4_step,
    verlet_step,
    velocity_verlet_step,
    midpoint_step
}; 


