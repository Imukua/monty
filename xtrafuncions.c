#include "monty.h"
/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
	temp = current;
	current = current->next;
	free(temp);
	}

	*stack = NULL;
}

