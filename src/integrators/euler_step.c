#include "integrators.h"

void euler_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    for (int j = 0; j < steps; j++)
    {
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
        {
            system->q[i] += system->acc[i] * dt;
            system->p[i] += system->q[i] * dt;
        }
    }
}
