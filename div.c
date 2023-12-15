#include "monty.h"
/**
 * v_div - it pops the stack
 * @head: pointer to pointer to sstack
 * @increament: element in stack
 * Return: Nothing.
 */
void v_div(stack_t **head, unsigned int increament)
{
	int d = 0;

	if (*head && (*head)->next)
	{
		if ((*head)->n == 0)
		{
			STATUS[0] = 'F';
			dprintf(2, "L%d: division by zero\n", increament);
			return;
		}
		d = ((*head)->next->n / (*head)->n);
		(*head)->next->n = d;
		v_pop(head, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't div, stack too short\n", increament);
	}
}
