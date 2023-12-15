#include "monty.h"
/**
 * _mul - it multiplies two elements of stack
 * @head:pointer to pointer to stack
 * @increament: element
 * Return: Nothing.
 */
void _mul(stack_t **head, unsigned int increament)
{
	int mul = 0;

	if (*head && (*head)->next)
	{
		mul = ((*head)->next->n * (*head)->n);
		(*head)->next->n = mul;
		_pop(head, 0);
	}
	else
	{
		STATUS[0] = 'F';
		printf("L%d: can't mul, stack too short\n", increament);
	}
}
