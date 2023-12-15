#include "monty.h"

#define INITIAL_BUFFER_SIZE 128

/**
 * custom_getline - interpretes Monty byte codes and executes them.
 * @file: Number of argv
 * Return: Exit statu
 */
char *custom_getline(FILE *file) {
    char *buffer = malloc(INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int position = 0, bufferSize = INITIAL_BUFFER_SIZE, c;

    if (!buffer) {
        fprintf(stderr, "Unable to allocate buffer\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = fgetc(file);

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }

        position++;

        if (position >= bufferSize) {
            bufferSize += INITIAL_BUFFER_SIZE;
            buffer = realloc(buffer, bufferSize);
            if (!buffer) {
                fprintf(stderr, "Unable to reallocate buffer\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
 * main - interpretes Monty byte codes and executes them.
 * @argc: Number of argv
 * @argv: Argument
 * Return: Exit statu
 */
int main(int argc, char *argv[]) {
    int lines = 0, gf = 0;
    FILE *fd;
    char *buffer;
    char **tokens = NULL;
    stack_t *stack = NULL;

    if (argc != 2) {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");
    if (fd == NULL) {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((buffer = custom_getline(fd)) != NULL)
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

    fclose(fd);
    return 0;
}
