
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "integrators.h"
#include "systems.h"
#include "simulate.h"

void simulate(system_t *system,
              system_acc_t update_acc,
              int loops, int per_loop, double dt,
              const char *output_filename,
              integrator_t integrator)
{
    FILE *file = fopen(output_filename, "w");
    if (!file)
        perror("fopen");

    fprintf(file, "t,");
    for (int i = 0; i < system->size[0]; i++)
        fprintf(file, "p%d,q%d,", i, i);
    fprintf(file, "\n");

    for (int i = 0; i < loops; i++)
    {
        fprintf(file, "%lf,", dt * per_loop * i);
        for (int j = 0; j < system->size[0]; j++)
            fprintf(file, "%lf,%lf,",
                    system->q[j], system->p[j]);
        fprintf(file, "\n");
        integrator(system, dt, per_loop, update_acc);
    }
    fclose(file);
}
