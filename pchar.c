#include "monty.h"
/**
 * v_pchar - it printsASCII char
 * @head: pointer to pointer in stack
 * @increament: element
 * Return: Nothing
 */
void v_pchar(stack_t **head, unsigned int increament)
{
	char cha;

	if (*head)
	{
		cha = (*head)->n;
		if ((cha > 64 && cha < 91) || (cha > 96 && cha < 123))
		{
			printf("%c\n", cha);
		}
		else
		{
			STATUS[0] = 'F';
			dprintf(2, "L%d: can't pchar, value out of range\n", increament);
			return;
		}
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't pchar, stack empty\n", increament);
	}
}
