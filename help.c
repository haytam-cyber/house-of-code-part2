#include <stdlib.h>
#include <string.h>

char *add(char *stack, char *buffer)
{
    size_t stack_len = stack ? strlen(stack) : 0;
    size_t buffer_len = strlen(buffer);
    char *new = malloc(stack_len + buffer_len + 1);

    if (!new)
        return NULL;

    if (stack)
    {
        strcpy(new, stack);
        free(stack);
    }
    else
    {
        new[0] = '\0';
    }

    strcat(new, buffer);
    return new;
}

char *extract(char *stack)
{
    if (!stack || *stack == '\0')
        return NULL;

    size_t i = 0;
    while (stack[i] && stack[i] != '\n')
        i++;

    char *line = malloc(i + 2);
    if (!line)
        return NULL;

    strncpy(line, stack, i + 1);
    line[i + 1] = '\0';

    return line;
}

char *update(char *stack)
{
    if (!stack)
        return NULL;

    char *newline = strchr(stack, '\n');
    if (!newline)
    {
        free(stack);
        return NULL;
    }

    char *new = strdup(newline + 1);
    free(stack);

    return new;
}
