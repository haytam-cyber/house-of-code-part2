#include <stdlib.h> 
#include <string.h> 
#include <stdio.h> 

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif // is this a cheat? instead of a global variable

char *add(char *stack, char *buffer);
char *extract(char *stack);
char *update(char *stack);

char *tome_reader(FILE *fp)
{

    static char *stack = NULL;
    char buffer[BUFFER_SIZE + 1]; // +1 for /0

    if (!fp || BUFFER_SIZE <= 0)
        return NULL;

    while (!stack || !strchr(stack, '\n'))
    {
        if (fgets(buffer, BUFFER_SIZE + 1, fp) == NULL)
        {
            break; // EOF or error
        }
        stack = add(stack, buffer);
        if (!stack)
            return NULL;
    }
    if (!stack || *stack == '\0')
    {
        free(stack);
        stack = NULL;
        return NULL;
    }

    char *line = extract(stack);
    stack = update(stack);
    return line;
}
