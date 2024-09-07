#include "integrators.h"


void leapfrog_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    for (int j = 0; j < steps; j++)
    {
        for (int i = 0; i < system->size[0]; i++)
        {
            system->q[i] += system->p[i] * dt + 0.5 * system->acc[i] * dt * dt;
            system->p[i] += 0.5 * system->acc[i] * dt;
        }
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
            system->p[i] += 0.5 * system->acc[i] * dt;
    }
}
