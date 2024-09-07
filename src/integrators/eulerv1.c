#include "integrators.h"

void eulerv1_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    for (int j = 0; j < steps; j++)
    {
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
        {
            system->q[i] += system->p[i] * dt + 0.5 * system->acc[i] * dt * dt;
            system->p[i] += system->acc[i] * dt;
        }

    }
}
