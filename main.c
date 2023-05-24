#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
*/
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    FILE *file;
    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
    char *opcode;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (getline(&line, &line_len, file) != -1)
    {
        line_number++;

        opcode = strtok(line, " \t\n");
        if (opcode == NULL)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(&stack);
            return EXIT_FAILURE;
        }
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    return EXIT_SUCCESS;
}
