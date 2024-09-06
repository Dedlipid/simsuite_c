#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>


#include "integrators.h"
#include "systems.h"

#include "init.h"
#include "simulate.h"

int main(int argc, char **argv)
{
    double time_per_loop = 0.01, total_time = 10.0;
    int opt, system_index = 1, integrator_index = 3, steps_per_loop = 100, *sys_param_index = NULL;
    double setup[SYS_PARAM_MAX + 1];
    setup[SYS_PARAM_MAX] = 0;
    char *out_name, *setup_vals;
    while ((opt = getopt(argc, argv, "s:i:t:T:l:c:o:")) != -1)
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
            time_per_loop = atof(optarg);
            break;
        case 'T':
            total_time = atof(optarg);
            break;
        case 'l':
            steps_per_loop = atoi(optarg);
            break;
        case 'c':
            setup_vals = optarg;
            parse_values(setup_vals, setup);
            break;
        case 'o':
            out_name = optarg;
            break;
        default:
            printf("Usage: sim -s [system_index] -i [integrator_index] \
-t [time_per_loop] -T [total_time] -l [steps_per_loop] -c [setup] \
-o [out_name]\n");
            exit(EXIT_FAILURE);
        }
    }
    int loops = 1 + total_time / time_per_loop;

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

    if (setup[SYS_PARAM_MAX] != system_spec_length[system_index])
        memccpy(setup, system_specs[system_index], SYS_PARAM_MAX, sizeof(double) * system_spec_length[system_index]);

    system_t *system = create_systems[system_index](setup);

    system_acc_t update_acc = system_accs[system_index];
    integrator_t integrator = integrator_list[integrator_index];
    
    double dt = time_per_loop / steps_per_loop;

    char resolved_path[PATH_MAX];

    if (argv[0][0] == '/')
    {
        realpath(argv[0], resolved_path);
    }
    else
    {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            strcat(cwd, "/");
            strcat(cwd, argv[0]);
            realpath(cwd, resolved_path);
        }
        else
        {
            perror("getcwd");
            exit(EXIT_FAILURE);
        }
    }

    char *dir = dirname(resolved_path);
    char filepath[PATH_MAX];
    printf("writing to: %s/../%s%s.out\n", dir, "data/", out_name);
    snprintf(filepath, sizeof(filepath), "%s/../%s%s.out", dir, "data/", out_name);

    simulate(system, update_acc, loops, steps_per_loop, dt, filepath, integrator);

    free_system(system);

    return 0;
}