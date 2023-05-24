#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
	printf("%c", temp->n);
	temp = temp->next;
	}

	printf("\n");
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
	last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
	last = last->next;

	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}


/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing (stack is the default behavior) */
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	rotr(stack, line_number);
}