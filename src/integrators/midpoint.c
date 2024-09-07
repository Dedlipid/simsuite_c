#include "integrators.h"

void midpoint_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    int n = system->size[0];
    double p_mid[6], q_mid[6], acc_mid[6];

    for (int j = 0; j < steps; j++)
    {
        // Calculate midpoint values
        for (int i = 0; i < n; i++)
        {
            p_mid[i] = system->p[i] + 0.5 * system->q[i] * dt;
            q_mid[i] = system->q[i] + 0.5 * system->acc[i] * dt;
        }
        update_acc(system);

        // Update acceleration at midpoint
        for (int i = 0; i < n; i++)
        {
            acc_mid[i] = system->acc[i];
        }

        // Final update
        for (int i = 0; i < n; i++)
        {
            system->p[i] += q_mid[i] * dt;
            system->q[i] += acc_mid[i] * dt;
        }
    }
}
