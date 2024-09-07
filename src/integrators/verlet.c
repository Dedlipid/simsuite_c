#include "integrators.h"


void verlet_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    double p_prev[6];
    for (int i = 0; i < system->size[0]; i++)
    {
        p_prev[i] = system->p[i] - system->q[i] * dt + 0.5 * system->acc[i] * dt * dt;
    }

    for (int j = 0; j < steps; j++)
    {
        for (int i = 0; i < system->size[0]; i++)
        {
            double p_new = 2.0 * system->p[i] - p_prev[i] + system->acc[i] * dt * dt;
            p_prev[i] = system->p[i];
            system->p[i] = p_new;
        }
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
        {
            system->q[i] = (system->p[i] - p_prev[i]) / (2.0 * dt);
        }
    }
}
