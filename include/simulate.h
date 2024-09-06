#include "integrators.h"

extern void simulate(system_t *system,
              system_acc_t update_acc,
              int loops, int per_loop, double dt,
              const char *output_filename,
              integrator_t integrator);