#include "systems.h"

// List of system names
char system_names[SYS_N][INTG_NAME_MAX] = {
    "Pendulum",
    "Double Pendulum",
    "Harmonic Oscillator",
    "Spring Coupled",
    "Damped Harmonic Oscillator",
    "Van der Pol",
    "Mass Spring Damper",
    "Driven Pendulum",
    "Inverted Pendulum"
};

// List of system-specific acceleration functions
system_acc_t system_accs[SYS_N] = {
    pendulum_acc,
    double_pendulum_acc,
    harmonic_oscillator_acc,
    spring_coupled_acc,
    damped_harmonic_oscillator_acc,
    van_der_pol_acc,
    mass_spring_damper_acc,
    driven_pendulum_acc,
    inverted_pendulum_acc
};

// List of system-specific creation functions
create_system_t create_systems[SYS_N] = {
    create_pendulum_system,
    create_double_pendulum_system,
    create_harmonic_oscillator_system,
    create_spring_coupled_system,
    create_damped_harmonic_oscillator_system,
    create_van_der_pol_system,
    create_mass_spring_damper_system,
    create_driven_pendulum_system,
    create_inverted_pendulum_system
};

// Default system spec list
double system_specs[SYS_N][SYS_PARAM_MAX] = {
    {1.0, 9.81, 0.1, 0.0}, // Pendulum: length, gravity, initial_angle, initial_velocity
    {1.0, 1.0, 1.0, 1.0, 9.81, 0.1, 0.1, 0.0, 0.0}, // Double Pendulum: m1, m2, l1, l2, g, initial_theta1, initial_theta2, initial_omega1, initial_omega2
    {1.0, 1.0, 0.0, 0.0}, // Harmonic Oscillator: mass, k, initial_position, initial_velocity
    {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0}, // Spring Coupled: m1, m2, k1, k2, initial_position1, initial_velocity1, initial_position2, initial_velocity2
    {1.0, 1.0, 0.1, 0.0}, // Damped Harmonic Oscillator: mass, k, damping coefficient, initial_position, initial_velocity
    {1.0, 0.1, 0.2, 0.0}, // Van der Pol: mass, damping coefficient, nonlinearity parameter, initial_position, initial_velocity
    {1.0, 1.0, 0.5, 0.0}, // Mass Spring Damper: mass, spring constant, damping coefficient, initial_position, initial_velocity
    {1.0, 9.81, 0.1, 0.0, 1.0, 1.0}, // Driven Pendulum: length, gravity, initial_angle, initial_angular_velocity, driving force amplitude, driving force frequency
    {1.0, 0.5, 1.0, 9.81, 0.0, 0.0, 0.1, 0.0} // Inverted Pendulum: cart_mass, pendulum_mass, pendulum_length, gravity, initial_cart_position, initial_cart_velocity, initial_pendulum_angle, initial_pendulum_angular_velocity
};

// Lengths of system_specs
unsigned char system_spec_length[SYS_N] = {
    4, // Pendulum
    9, // Double Pendulum
    4, // Harmonic Oscillator
    8, // Spring Coupled
    5, // Damped Harmonic Oscillator
    4, // Van der Pol
    4, // Mass Spring Damper
    6, // Driven Pendulum
    8  // Inverted Pendulum
};
