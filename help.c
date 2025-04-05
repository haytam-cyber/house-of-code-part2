#include <stdlib.h>
#include <string.h>

//the current line stack and buffer contents do a fusion dance
char *add(char *stack, char *buffer) {
    size_t len1 = stack ? strlen(stack) : 0;
    size_t len2 = strlen(buffer);

    char *combined = malloc(len1 + len2 + 1);
    if (!combined)
        return NULL;

    if (stack) {
        strcpy(combined, stack);
        free(stack);  //free the old stack after copy
    } else {
        combined[0] = '\0';
    }

    strcat(combined, buffer);  //add new buffer contents
    return combined;
}

//takes the first line from stack \n
char *extract(char *stack) {
    if (!stack || *stack == '\0')
        return NULL;

    size_t i = 0;
    while (stack[i] && stack[i] != '\n')
        i++;

    //+1 space for \n or \0
    char *line = malloc(i + 2);
    if (!line)
       return NULL;

       strncpy(line, stack, i + 1);
       line[i + 1] = '\0';

    return line;
}

//update the stack to remove extracted line 
char *update(char *stack) {
    if (!stack)
        return NULL;

    char *newline = strchr(stack, '\n');
    if (!newline) {
        free(stack);  //if no newline left, free all
        return NULL;
    }

    //move past the newline
    size_t nxt_len = strlen(newline + 1);
    char *rest = malloc(nxt_len + 1);
    if (!rest)
        return NULL;

    strcpy(rest, newline + 1);
    free(stack);
    return rest;
}
