# Physics Systems Simulation

## Overview

This project provides a framework for simulating various physical systems using numerical methods. Each system is represented by its own model and can be simulated with different initial conditions and parameters. The library is designed to be modular, allowing for easy addition of new systems and customization.

## Available Systems

1. **Pendulum**: A simple pendulum system with gravitational acceleration.
2. **Double Pendulum**: A more complex system with two pendulums attached end-to-end.
3. **Harmonic Oscillator**: A mass-spring system with linear restoring force.
4. **Spring Coupled**: A system of two masses connected by springs.
5. **Damped Harmonic Oscillator**: A harmonic oscillator with an additional damping force.
6. **Van der Pol Oscillator**: A nonlinear oscillator with a damping term that depends on the amplitude.
7. **Mass-Spring-Damper**: A classic mass-spring-damper system for studying vibrations.
8. **Driven Pendulum**: A pendulum subject to an external periodic driving force.
9. **Inverted Pendulum**: A classic control problem involving a pendulum with its pivot point moving.

## Available Integrators

1. **Euler**: Basic Euler method for numerical integration.
2. **Euler-M1**: Improved Euler method (also known as the Heun method).
3. **Euler-M2**: Second-order Euler method.
4. **Leapfrog**: Symplectic integrator useful for Hamiltonian systems.
5. **RK4**: Fourth-order Runge-Kutta method.
6. **Verlet**: Verlet integration, commonly used in molecular dynamics.
7. **Velocity Verlet**: Modified Verlet method that updates velocities explicitly.
8. **Midpoint**: Midpoint method, a second-order accurate integration scheme.

## Usage

To run the simulation, use the following command-line options:
```
sim -s [system_index] -i [integrator_index] -t [time_per_loop] -T [total_time] -l [steps_per_loop] -c [setup] -o [out_name]
```

- `-s [system_index]`: Index of the system to simulate. Refer to the available systems list.
- `-i [integrator_index]`: Index of the integrator to use. Refer to the available integrators list.
- `-t [time_per_loop]`: Time step for each loop iteration (default: `0.01`).
- `-T [total_time]`: Total simulation time (default: `10.0`).
- `-l [steps_per_loop]`: Number of steps per loop (default: `100`).
- `-c [setup]`: Optional setup parameters specific to the system (default: see `systems.c` for defaults).
- `-o [out_name]`: Name of the output file to save the results (default: `test.csv`).

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
