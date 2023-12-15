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
	{	printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{	printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(&buffer, &size, fd)) != -1)
	{
		tokens = NULL, lines++;
		ts_handler(buffer);
		if (strcmp(buffer, "\n") != 0)
		{	tokens = _strtok(tokens, buffer);
			gf = get_function_stack(tokens, &stack, lines);
			if (gf == 1)
			{	free(tokens), free(buffer), free_stack(&stack), fclose(fd);
				printf("L%d: usage: push integer\n", lines), exit(EXIT_FAILURE);
			}
			if (gf == 2)
			{	printf("L%d: unknown instruction %s\n", lines, tokens[0]);
				free(buffer), free_stack(&stack), fclose(fd);
				free(tokens), exit(EXIT_FAILURE);
			}
			if (gf == 3)
			{	free(buffer), free_stack(&stack), fclose(fd);
				free(tokens), exit(EXIT_FAILURE);
			} free(tokens);
		}
	}
	free(buffer), free_stack(&stack), fclose(fd);
	return (0);
}
