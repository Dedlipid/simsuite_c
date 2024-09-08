#include <stdio.h>
#include <systems.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <libgen.h>
#include <assert.h>

#include "init.h"
#include "integrators.h"

void print_init(sim_init_t *sim_init)
{
    puts("print_init");
    printf("system_index = %d\n", sim_init->system_index);
    printf("integrator_index = %d\n", sim_init->integrator_index);
    printf("time_per_loop = %lf\n", sim_init->time_per_loop);
    printf("total_time = %lf\n", sim_init->total_time);
    printf("steps_per_loop = %d\n", sim_init->steps_per_loop);
    printf("out_name = %s\n", sim_init->out_name);
    printf("total_loops = %d\n", sim_init->total_loops);
    for (int i = 0; i < SYS_PARAM_MAX; i++)
        printf("setup[%d] = %lf\n", i, sim_init->setup[i]);
}

void parse_values(const char *arg, double *values, char length)
{
    char *token,
        *input_copy = strdup(arg);
    if (input_copy == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    token = strtok(input_copy, ",");
    while (token != NULL && index < length)
    {
        values[index++] = atof(token);
        token = strtok(NULL, ",");
    }
    free(input_copy);
}

void output_path(char *name, char *out_name, char argc, char **argv)
{
    char resolved_path[PATH_MAX];
    if (argv[0][0] == '/')
        realpath(argv[0], resolved_path);

    else
    {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            strcat(cwd, "/");
            strcat(cwd, argv[0]);
            realpath(cwd, resolved_path);
            if (realpath(cwd, resolved_path) == NULL)
            {
                perror("realpath");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            perror("getcwd");
            exit(EXIT_FAILURE);
        }
    }
    char *dir = dirname(resolved_path);
    if (snprintf(out_name, 64 * sizeof(char), "%s/../%s%s.csv", dir,
                 "data/", name) >= 64)
    {
        fprintf(stderr, "Output path too long\n");
        exit(EXIT_FAILURE);
    };
    assert(strlen(out_name) > 0);
}

void init_systems(char argc, char **argv,
                  sim_init_t *sim_init)
{
    char params_set = 0;
    int opt;
    unsigned char system_index = 1,
                  integrator_index = 3;
    unsigned int steps_per_loop = 100;
    double time_per_loop = 0.01,
           total_time = 10.0;
    char *name = "test";

    // Initialize setup parameters with default values
    memset(sim_init->setup, 0, sizeof(sim_init->setup));
    memcpy(sim_init->setup, system_specs[system_index], sizeof(double) * system_spec_length[system_index]);

    while ((opt = getopt(argc, argv, "s:i:t:T:l:c:o:N:")) != -1)
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
            if (steps_per_loop <= 0)
            {
                fprintf(stderr, "Invalid steps_per_loop value\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'c':
            parse_values(optarg, sim_init->setup, system_spec_length[system_index]);
            break;
        case 'o':
            name = optarg;
            break;
        default:
            printf("Usage: sim -s [system_index] -i [integrator_index] \
-t [time_per_loop] -T [total_time] -l [steps_per_loop] -c [setup] \
-o [out_name]\n");
            exit(EXIT_FAILURE);
        }
    }

    if (system_index < 0 || system_index >= SYS_N)
    {
        fprintf(stderr, "Invalid system index\n");
        exit(EXIT_FAILURE);
    }

    if (integrator_index < 0 || integrator_index >= INTEGRATOR_N)
    {
        fprintf(stderr, "Invalid integrator index\n");
        exit(EXIT_FAILURE);
    }

    if (time_per_loop <= 0.0 || total_time <= 0.0)
    {
        fprintf(stderr, "Invalid time_per_loop or total_time values\n");
        exit(EXIT_FAILURE);
    }

    sim_init->total_loops = 1 + total_time / time_per_loop;
    sim_init->system_index = system_index;
    sim_init->integrator_index = integrator_index;
    sim_init->time_per_loop = time_per_loop;
    sim_init->total_time = total_time;
    sim_init->steps_per_loop = steps_per_loop;
    output_path(name, sim_init->out_name, argc, argv);
}