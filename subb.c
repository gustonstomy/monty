#include "monty.h"
/**
 * _sub - subtracts the top element
 * @head: pointer to pointer of stack
 * @increament: element
 * Return: Nothing.
 */
void _sub(stack_t **head, unsigned int increament)
{
	int sub = 0;

	if (*head && (*head)->next)
	{
		sub = ((*head)->next->n - (*head)->n);
		(*head)->next->n = sub;
		_pop(head, 0);
	}
	else
	{
		STATUS[0] = 'F';
		printf("L%d: can't sub, stack too short\n", increament);
	}
}
