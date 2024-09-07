# Create a library for the integrators
add_library(integrators 
    euler_step.c 
    eulerv2.c 
    leapfrog.c 
    rk4.c 
    verlet.c 
    eulerv1.c 
    integrators.c 
    midpoint.c 
    velocity_verlet.c
)
