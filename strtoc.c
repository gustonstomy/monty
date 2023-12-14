#include "monty.h"
/**
 * v_strtok - tokens of a string.
 * @tok: Array of token
 * @strn: input text from
 * Return: Exit statu
 */
char **v_strtok(char **tok, char *strn)
{
	char *token = NULL;
	int i = 0;

	tok = malloc(1024 * sizeof(char *));
	if (tok == NULL)
	{
		free(tok);
		return (NULL);
	}
	token = strtok(strn, "\t \n\r");
	tok[i] = token;
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, "\t \n\r"), i++;
		tok[i] = token;
	}
	if (tok[0][0] == '#')
	{
		tok[0] = "nop";
	}

	i++, tok[i] = NULL;
	return (tok);
}
