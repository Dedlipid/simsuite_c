#ifndef INIT_H
#define INIT_H

typedef struct
{
    char system_index;
    char integrator_index;
    unsigned int steps_per_loop;
    unsigned int total_loops;
    char *out_name;
    double total_time;
    double *setup;
    double time_per_loop;

} sim_init_t;
extern void print_init(sim_init_t *sim_init);
extern void parse_values(const char *arg, double *values);
extern void init_systems(char argc, char **argv,
                         sim_init_t *sim_init);

#endif // INIT_H