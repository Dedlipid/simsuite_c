#include <stdlib.h>
#include <stdio.h>

#include "integrators.h"
#include "init.h"
#include "simulate.h"

int main(int argc, char **argv)
{
    double time_per_loop = 0.01,
           total_time = 10.0;
    int opt, system_index = 1,
             integrator_index = 3,
             steps_per_loop = 100;
    double setup[SYS_PARAM_MAX + 1];
    setup[SYS_PARAM_MAX] = 0;

    sim_init_t *sim_init = malloc(sizeof(sim_init_t));
    *sim_init = (sim_init_t){
        .system_index = 1,
        .integrator_index = 3,
        .time_per_loop = 0.01,
        .total_time = 10.0,
        .steps_per_loop = 100,
        .setup = setup,
        .out_name = malloc(100 * sizeof(char)),
    };
    init_systems(argc, argv, sim_init);
   
    system_t *system =
        create_systems[sim_init->system_index](sim_init->setup);

    system_acc_t update_acc = system_accs[sim_init->system_index];
    integrator_t integrator = integrator_list[sim_init->integrator_index];

    simulate(system, update_acc, sim_init->total_loops,
             sim_init->steps_per_loop, 
             sim_init->time_per_loop / sim_init->steps_per_loop, 
             sim_init->out_name, integrator);

    free_system(system);
    free(sim_init->out_name);
    free(sim_init);

    return 0;
}