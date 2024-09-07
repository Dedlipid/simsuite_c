#include "integrators.h"



void velocity_verlet_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    for (int j = 0; j < steps; j++)
    {
        for (int i = 0; i < system->size[0]; i++)
        {
            system->p[i] += system->q[i] * dt + 0.5 * system->acc[i] * dt * dt;
        }
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
        {
            system->q[i] += 0.5 * (system->acc[i] + system->acc[i]) * dt;
        }
    }
}
