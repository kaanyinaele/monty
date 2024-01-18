#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(int value, int line_number) {
    if (stack.top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.stack[++stack.top] = value;
}
