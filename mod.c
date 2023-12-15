#include "monty.h"
/**
 * _mod - divide two first elements of the stack
 * @head:pointer to pointer to stack
 * @increament: value for includein the stack
 * Return: Nothing.
 */
void _mod(stack_t **head, unsigned int increament)
{

	int d = 0;

	if (*head && (*head)->next)
	{
		if ((*head)->n == 0)
		{
			STATUS[0] = 'F';
			vprintf(2, "L%d: division by zero\n", increament);
			return;
		}
		d = ((*head)->next->n % (*head)->n);
		(*head)->next->n = d;
		_pop(head, 0);
	}
	else
	{
		STATUS[0] = 'F';
		vprintf(2, "L%d: can't mod, stack too short\n", increament);
	}
}
