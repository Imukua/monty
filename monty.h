#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* data structures */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct {
    char *opcode;
    void (*func)(stack_t **, unsigned int);
} opcode_func_t;


/* function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void free_stack(stack_t **stack);



#endif 
