#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Read the Monty byte code file and execute instructions */
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Parse the file and execute instructions */

    fclose(file);

    return EXIT_SUCCESS;
}

