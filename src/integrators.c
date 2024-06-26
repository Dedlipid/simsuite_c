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

void eulerv2_step(system_t *system, double dt, int steps, void (*update_acc)(system_t *))
{
    for (int j = 0; j < steps; j++)
    {
        for (int i = 0; i < system->size[0]; i++)
            system->q[i] += system->p[i] * dt + 0.5 * system->acc[i] * dt * dt;
        update_acc(system);
        for (int i = 0; i < system->size[0]; i++)
            system->p[i] += system->acc[i] * dt;
    }
}

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
