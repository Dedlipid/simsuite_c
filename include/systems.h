#ifndef SYSTEMS_H
#define SYSTEMS_H

#define SYS_N 4
#define INTG_NAME_MAX 30
#define SYS_PARAM_MAX 12

typedef struct
{
    double *p;    // Position array
    double *q;    // Velocity array
    double *acc;  // Acceleration array
    double *prop; // Array of system properties
    int size[2];  // Number of elements in the system and size of properties
} system_t;

void pendulum_acc(system_t *system);
void double_pendulum_acc(system_t *system);
void harmonic_oscillator_acc(system_t *system);
void spring_coupled_acc(system_t *system);

// length, g, initial_angle, initial_velocity
system_t *create_pendulum_system(double *system_spec);

// m1, m2, l1, l2, g, initial_theta1, initial_theta2, initial_omega1, initial_omega2
system_t *create_double_pendulum_system(double *system_spec);

// mass, k, initial_position, initial_velocity
system_t *create_harmonic_oscillator_system(double *system_spec);

// m1, m2, k1, k2, initial_position1, initial_velocity1, initial_position2, initial_velocity2
system_t *create_spring_coupled_system(double *system_spec);

void free_system(system_t *system);

// List of system names
extern char system_names[SYS_N][INTG_NAME_MAX];

// Function pointer list of size SYS_N
extern void (*system_accs[SYS_N])(system_t *system);

// System pointer list
extern system_t *(*create_systems[SYS_N])(double *);

// Default list
extern double system_specs[SYS_N][SYS_PARAM_MAX];

// Length of system_specs lengths
extern int system_spec_length[SYS_N];

#endif
