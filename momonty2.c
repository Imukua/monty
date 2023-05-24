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
