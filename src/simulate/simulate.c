
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "integrators.h"
#include "systems.h"
#include "simulate.h"

void simulate(system_t *system,
              system_acc_t update_acc,
              int loops, int per_loop, double dt,
              const char *output_filename,
              integrator_t integrator)
{
    FILE *file = fopen(output_filename, "w");
    if (!file)
        perror("fopen");

    fprintf(file, "t,");
    for (int i = 0; i < system->size[0]; i++)
        fprintf(file, "p%d,q%d,", i, i);
    fprintf(file, "\n");

    for (int i = 0; i < loops; i++)
    {
        fprintf(file, "%lf,", dt * per_loop * i);
        for (int j = 0; j < system->size[0]; j++)
            fprintf(file, "%lf,%lf,",
                    system->q[j], system->p[j]);
        fprintf(file, "\n");
        integrator(system, dt, per_loop, update_acc);
    }
    fclose(file);
}


// void simulate(system_t *system,
//               system_acc_t update_acc,
//               int loops, int per_loop, double dt,
//               const char *output_filename,
//               integrator_t integrator)
// {
//     FILE *file = fopen(output_filename, "w");
//     if (!file) {
//         perror("fopen");
//         return; // Return early on error
//     }

//     // Write headers
//     fprintf(file, "t,");
//     for (int i = 0; i < system->size[0]; i++)
//         fprintf(file, "p%d,q%d,", i, i);
//     fprintf(file, "\n");

//     // Allocate memory for storing all output data
//     char *buffer = (char *)malloc(256 * 1024); // 1 MB buffer (adjust as needed)
//     if (!buffer) {
//         perror("malloc");
//         fclose(file);
//         return; // Return early on error
//     }

//     char *current = buffer;
//     int buffer_size = 1024 * 1024; // 1 MB

//     for (int i = 0; i < loops; i++)
//     {
//         // Check if the buffer is full
//         if (current - buffer > buffer_size - 256) {
//             fwrite(buffer, 1, current - buffer, file);
//             current = buffer;
//         }

//         // Accumulate the data in the buffer
//         int written = snprintf(current, buffer_size - (current - buffer),
//                                "%lf,", dt * per_loop * i);
//         current += written;

//         for (int j = 0; j < system->size[0]; j++) {
//             written = snprintf(current, buffer_size - (current - buffer),
//                                "%lf,%lf,",
//                                system->q[j], system->p[j]);
//             current += written;
//         }

//         snprintf(current, buffer_size - (current - buffer), "\n");
//         current += strlen(current);

//         // Update the system state
//         integrator(system, dt, per_loop, update_acc);
//     }

//     // Write any remaining data in the buffer
//     fwrite(buffer, 1, current - buffer, file);

//     // Clean up
//     free(buffer);
//     fclose(file);
// }
