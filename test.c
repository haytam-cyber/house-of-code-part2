#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tome_reader(FILE *fp);
// check for file name
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 1;
    }
//check if file exists
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("failed to open file %s\n", argv[1]);
        return 1;
    }

    // call function to read line by line amd free used lines
    char *line;
    while ((line = tome_reader(fp)))
    {
        printf("%s", line);
        free(line);
    }

    fclose(fp);
    return 0;
}
