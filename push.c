#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
// push.c


void push(char *arg, int line_number) {
    if (!arg || !isdigit(*arg) && *arg != '-' && *arg != '+') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);
    
    if (value == 0 && *arg != '0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (stack.top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack.stack[++stack.top] = value;
}

