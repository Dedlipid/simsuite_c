#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "integrators.h"
#include "systems.h"

void simulate(system_t *system, void (*update_acc)(system_t *),
              int loops, int per_loop, double dt, const char *output_filename,
              void (*integrator)(system_t *system, double dt, int steps, void (*update_acc)(system_t *)))
{
    FILE *file = fopen(output_filename, "w");
    fprintf(file, "time,");
    
    for (int i = 0; i < system->size[0]-1; i++)
        fprintf(file, "q%d,p%d,", i, i);
    fprintf(file, "q%d,p%d\n", system->size[0]-1, system->size[0]-1);

    for (int i = 0; i <= loops; i++)
    {
        int j = 0;
        for (; j < system->size[0]-1; j++)
            fprintf(file, "%lf,%lf,%lf,", dt * per_loop * i, system->q[j], 
            system->p[j]);
        fprintf(file, "%lf,%lf\n", system->q[system->size[0]-1], 
        system->p[system->size[0]-1]);
        integrator(system, dt, per_loop, update_acc);

    }
    fclose(file);
}

int main(int argc, char **argv)
{
    double timm_per_loop = 0.01, total_time = 10.0;
    int opt, system_index = 1, integrator_index = 3, steps_per_loop = 100;
    while ((opt = getopt(argc, argv, "s:i:t:T:l:")) != -1)
    {
        switch (opt)
        {
        case 's':
            system_index = atoi(optarg);
            break;
        case 'i':
            integrator_index = atoi(optarg);
            break;
        case 't':
            timm_per_loop = atof(optarg);
            break;
        case 'T':
            total_time = atof(optarg);
            break;
        case 'l':
            steps_per_loop = atoi(optarg);
            break;
        default:
            printf("Usage: sim -s [system_index] -i [integrator_index]\n");
            break;
        }
    }
    int loops = (int)(total_time / timm_per_loop);

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

    system_t *system = create_systems[system_index](system_specs[system_index]);
    void (*update_acc)(system_t*) = system_accs[system_index];
    void (*integrator)(system_t*, double, int, void (*accler)(system_t *)) = integrator_list[integrator_index];
    
    
    double dt = timm_per_loop/steps_per_loop;

    simulate(system, double_pendulum_acc, loops, steps_per_loop, dt, "../data/double_pendulum_output.txt", integrator);

    free_system(system);

    return 0;
}


