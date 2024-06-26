#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "integrators.h"
#include "systems.h"

void simulate(system_t *system, void (*update_acc)(system_t *),
              int loops, double dt, const char *output_filename,
              void (*integrator)(system_t *system, double dt, int steps, void (*update_acc)(system_t *)))
{
    FILE *file = fopen(output_filename, "w");
    for (int i = 0; i < loops; i++)
    {
        int j = 0;
        integrator(system, dt, 1, update_acc);
        for (; j < system->size[0]-1; j++)
            fprintf(file, "%lf,%lf,", system->q[j], system->p[j]);
        fprintf(file, "%lf,%lf\n", system->q[j], system->p[j]);
    }
    fclose(file);
}

int main(int argc, char **argv)
{
    int opt, system_index, integrator_index;
    while ((opt = getopt(argc, argv, "s:i:")) != -1)
    {
        switch (opt)
        {
        case 's':
            system_index = atoi(optarg);
            break;
        case 'i':
            integrator_index = atoi(optarg);
            break;
        default:
            printf("sim -s [system_index] -i [integrator_index]\n");
            break;
        }
    }
    
    if (system_index < 0 || system_index >= sizeof(system_names) / sizeof(char *))
    {
        fprintf(stderr, "Invalid system index\n");
        exit(EXIT_FAILURE);
    }

    if (integrator_index < 0 || integrator_index >= sizeof(integrator_names) / sizeof(char *))
    {
        fprintf(stderr, "Invalid integrator index\n");
        exit(EXIT_FAILURE);
    }

    //system_t *system = create_systems[system_index](system_specs[system_index]);
    //void (*update_acc)(system_t*) = system_accs[system_index];
    //void (*integrator)(system_t*, double, int, void (*accler)(system_t *)) = integrators[integrator_index];
    
    
    //int loops = 1000;
    //double dt = 0.01;

    //simulate(pendulum, pendulum_acc, steps, dt, "../data/pendulum_output.txt");
    //simulate(system, double_pendulum_acc, loops, dt, "../data/double_pendulum_output.txt", integrator);

    //free_system(system);

    return 0;
}


