#include "monty.h"

/**
 * main - interpretes Monty byte codes and executes them.
 * @argc: Number of argv
 * @argv: Argument
 * Return: Exit statu
 */

int main(int argc, char *argv[])
{
	int lines = 0, gf = 0;
	FILE *fd;
	size_t size = 0;
	char *buffer = NULL, **tokens = NULL;
	stack_t *stack = NULL;

	STATUS[0] = 'S', if_stack = 1;
	if (argc != 2)
	{	dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{	dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &size, fd)) != -1)
	{
		tokens = NULL, lines++;
		v_ts_handler(buffer);
		if (strcmp(buffer, "\n") != 0)
		{	tokens = v_strtok(tokens, buffer);
			gf = get_function_stack(tokens, &stack, lines);
			if (gf == 1)
			{	free(tokens), free(buffer), v_free_stack(&stack), fclose(fd);
				dprintf(2, "L%d: usage: push integer\n", lines), exit(EXIT_FAILURE);
			}
			if (gf == 2)
			{	dprintf(2, "L%d: unknown instruction %s\n", lines, tokens[0]);
				free(buffer), v_free_stack(&stack), fclose(fd);
				free(tokens), exit(EXIT_FAILURE);
			}
			if (gf == 3)
			{	free(buffer), v_free_stack(&stack), fclose(fd);
				free(tokens), exit(EXIT_FAILURE);
			} free(tokens);
		}
	}
	free(buffer), v_free_stack(&stack), fclose(fd);
	return (0);
}
