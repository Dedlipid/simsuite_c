#ifndef SYSTEMS_H
#define SYSTEMS_H

typedef struct {
    double *p;   // Position array
    double *q;   // Velocity array
    double *acc; // Acceleration array
    double *prop;  // Array of system properties
    int size[2]; // Number of elements in the system and size of properties
} system_t;

void pendulum_acc(system_t *system);
void double_pendulum_acc(system_t *system);
//length, g, initial_angle, initial_velocity
system_t* create_pendulum_system(double* system_spec);

//m1, m2, l1, l2, g, initial_theta1, initial_theta2, initial_omega1, initial_omega2
system_t* create_double_pendulum_system(double* system_spec);
void free_system(system_t *system);

//List of system names
char *system_names[] = {
    "pendulum",
    "double_pendulum"
};

//Function pointer list
void (*system_accs[])(system_t *system) = {
    pendulum_acc,
    double_pendulum_acc
};

//System pointer list
system_t* (*create_systems[])(double*) = {
    create_pendulum_system,
    create_double_pendulum_system
};


//Default list
double system_specs[2][9] = {
    {1.0, 9.81, 0.1, 0.0}, //pendulum_spec
    {1.0, 1.0 , 1.0, 1.0, 9.81, 1, -1, 0.0, 0.0} //double_pendulum_spec
};

#endif
