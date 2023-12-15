#include "monty.h"
/**
 * v_pstr - print first word from stack
 * @head: pointer to pointer to stack
 * @increament: element
 * Return: Nothing.
 */
void v_pstr(stack_t **head, unsigned int increament)
{
	char c;
	shead_t *tmp = *head;

	(void) increament;
	if (*head)
	{
		while (tmp)
		{
			c = tmp->n;
			if ((c > 64 && c < 91) || (c > 96 && c < 123))
				printf("%c", c);
			else
			{
				printf("\n");
				return;
			}
			if (!tmp->next || tmp->n == 0)
			{
				printf("\n");
				return;
			}
			else
			{
				tmp = tmp->next;
				c = tmp->n;
			}
		}
	}
	else
		printf("\n");
}
