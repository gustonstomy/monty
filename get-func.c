#include "monty.h"
/**
 * _get_function_stack - Gets a function to use.
 * @tokens: An Array of tokens.
 * @head: The stack.
 * @increament: numbers of line in the file
 * Return: Nothing.
 */

int _get_function_stack(char **tokens, stack_t **head, unsigned int increament)
{
	instruction_t ops[] = { {"push", v_push}, {"pall", v_pall}, {"pint", v_pint},
		{"pop", v_pop}, {"swap", v_swap},	{"add", v_add}, {"sub", v_sub},
		{"div", v_div}, {"mul", v_mul}, {"mod", v_mod}, {"pchar", v_pchar},
		{"pstr", v_pstr}, {"rotl", v_rotl}, {"rotr", v_rotr}, {"head", v_head},
		{"queue", v_queue}, {"nop", v_nop}, {"\n", v_nop}, {NULL, NULL} };
	int i = 0, j = 0, find_func = 0, number = 0, out = 0;

	for (j = 0; tokens[j]; j++)
	{
		for (i = 0; ops[i].opcode; i++)
		{
			if (strcmp(ops[i].opcode, tokens[j]) == 0)
			{	find_func = 1;
				if (strcmp(tokens[j], "push") == 0)
				{
					if (!tokens[j + 1])
						return (1);
					out = v_char_to_number(tokens[j + 1], &number);
					if (out)
						return (1);
					if (!number || atoi(tokens[j + 1]) != 0)
					{	number = atoi(tokens[j + 1]), ops[i].f(head, number);
						return (0);
					} else
						return (1);
				} else
				{
					ops[i].f(head, increament);
					if (!strcmp(&STATUS[0], "F"))
						return (3);
					return (0);
				}
			} else
				find_func = 0;
		}
		if (find_func == 0)
			return (2);
	}
	return (0);
}
