#include "monty.h"

/**
 * opcode_functions - opcode functions
 */
opcode_func_t opcode_functions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", div_op},
	{"mul", mul},
	{"mod", mod},
	{"#", comment},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stack},
	{"queue", queue},
};

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char line[1024], *opcode;
	unsigned int line_number = 0;
	int found;
	size_t i;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
	line_number++;
	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
	continue;

	found = 0;
	for (i = 0; i < sizeof(opcode_functions) / sizeof(opcode_func_t); i++)
	{
	if (strcmp(opcode, opcode_functions[i].opcode) == 0)
	{
	opcode_functions[i].func(&stack, line_number);
	found = 1;
	break;
	}
	}

	if (!found)
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free_stack(&stack);
	return (EXIT_FAILURE);
	}
	}

	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
