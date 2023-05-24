#include "monty.h"

/**
 * execute_instruction - Execute a Monty bytecode instruction
 * @opcode: The opcode to execute
 * @stack1: Double pointer to the stack
 * @line_number: The line number of the instruction
 * Return: 0 on success, 1 on failure
 */
int execute_instruction(char *opcode, stack_t **stack1,
unsigned int line_number)
{
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

	size_t i;

	for (i = 0; i < sizeof(opcode_functions) / sizeof(opcode_func_t); i++)
	{
	if (strcmp(opcode, opcode_functions[i].opcode) == 0)
	{
	opcode_functions[i].func(stack1, line_number);
	return (0);
	}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (1);
}

/**
 * process_file - Process a Monty bytecode file
 * @filename: Name of the file to process
 * Return: 0 on success, 1 on failure
 */
int process_file(const char *filename)
{
	FILE *file;
	char line[1024], *opcode;
	unsigned int line_number = 0;
	int ret = 0;
	stack_t *stack = NULL;

	file = fopen(filename, "r");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (1);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
	line_number++;
	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
	continue;

	if (opcode[0] == '#')
	continue;

	if (execute_instruction(opcode, &stack, line_number) != 0)
	{
	ret = 1;
	break;
	}
	}

	fclose(file);
	free_stack(&stack);

	return (ret);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

	return (process_file(argv[1]));
}
