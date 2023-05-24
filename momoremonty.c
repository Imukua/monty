#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}


/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}


/**
 * mod - Computes the rest of the division of
 * the second top element by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}


/**
 * comment - Does nothing (comment opcode)
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

