#include "integrators.h"


void rk4_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    int n = system->size[0];
    double p_tmp[6], q_tmp[6];
    double k1_p[6], k1_q[6];
    double k2_p[6], k2_q[6];
    double k3_p[6], k3_q[6];
    double k4_p[6], k4_q[6];

    for (int j = 0; j < steps; j++)
    {
        // k1
        update_acc(system);
        for (int i = 0; i < n; i++)
        {
            k1_p[i] = dt * system->q[i];
            k1_q[i] = dt * system->acc[i];
            p_tmp[i] = system->p[i] + 0.5 * k1_p[i];
            q_tmp[i] = system->q[i] + 0.5 * k1_q[i];
        }

        // k2
        for (int i = 0; i < n; i++)
        {
            system->p[i] = p_tmp[i];
            system->q[i] = q_tmp[i];
        }
        update_acc(system);
        for (int i = 0; i < n; i++)
        {
            k2_p[i] = dt * system->q[i];
            k2_q[i] = dt * system->acc[i];
            p_tmp[i] = system->p[i] + 0.5 * k2_p[i];
            q_tmp[i] = system->q[i] + 0.5 * k2_q[i];
        }

        // k3
        for (int i = 0; i < n; i++)
        {
            system->p[i] = p_tmp[i];
            system->q[i] = q_tmp[i];
        }
        update_acc(system);
        for (int i = 0; i < n; i++)
        {
            k3_p[i] = dt * system->q[i];
            k3_q[i] = dt * system->acc[i];
            p_tmp[i] = system->p[i] + k3_p[i];
            q_tmp[i] = system->q[i] + k3_q[i];
        }

        // k4
        for (int i = 0; i < n; i++)
        {
            system->p[i] = p_tmp[i];
            system->q[i] = q_tmp[i];
        }
        update_acc(system);
        for (int i = 0; i < n; i++)
        {
            k4_p[i] = dt * system->q[i];
            k4_q[i] = dt * system->acc[i];
        }

        // Combine
        for (int i = 0; i < n; i++)
        {
            system->p[i] += (k1_p[i] + 2.0 * k2_p[i] + 2.0 * k3_p[i] + k4_p[i]) / 6.0;
            system->q[i] += (k1_q[i] + 2.0 * k2_q[i] + 2.0 * k3_q[i] + k4_q[i]) / 6.0;
        }
    }
}
