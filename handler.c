#include "monty.h"

/**
 * ts_handler - handler tabs and spaces for functions.
 * @ptr_line: pointer input for char.
 * Return: Nothing.
 */

void ts_handler(char *ptr_line)
{
	char *line = malloc((strlen(ptr_line) + 1) * sizeof(char));
	int i = 0, j = 0;

	strcpy(line, ptr_line);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			if (i > 0 && (line[i - 1] != ' ' && line[i - 1] != '\t'))
				strcpy(&ptr_line[j], " "), j++;
			i++;
		}
		else
			strcpy(&ptr_line[j], &line[i]), j++, i++;
	}
	if (ptr_line[j - 2] == ' ')
		ptr_line[j - 2] = '\0';
	free(line);
}
