

#include <stdio.h>
#include <systems.h>
#include <stdlib.h>

extern void parse_values(const char *arg, double *values)
{
    puts("parse_values");
    char *token;
    char *input_copy = strdup(arg);
    int index = 0;

    token = strtok(input_copy, ",");
    while (token != NULL && index < SYS_PARAM_MAX)
    {

        values[index] = atof(token);
        printf("values[%d] = %lf\n", index, values[index]);
        index++;
        token = strtok(NULL, ",");
    }
    values[SYS_PARAM_MAX] = index;
    if (index > SYS_PARAM_MAX)
    {
        fprintf(stderr, "Invalid number of parameters\n");
        exit(EXIT_FAILURE);
    }
    free(input_copy);
}