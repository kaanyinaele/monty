#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
// main.c


int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack.top = -1; // Initialize stack top

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;

        // Remove trailing newline character
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

        // Parse the command and argument
        char command[10];
        char arg[50];

        if (sscanf(line, "%s %s", command, arg) == 2) {
            if (strcmp(command, "push") == 0) {
                push(arg, line_number);
            } else if (strcmp(command, "pall") == 0) {
                pall();
            } else {
                fprintf(stderr, "L%d: Unknown command %s\n", line_number, command);
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "L%d: Invalid command format\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    // Close the file
    fclose(file);

    // Free allocated memory
    free(line);

    return 0;
}

