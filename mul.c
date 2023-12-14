#include "monty.h"
/**
 * v_mul - it multiplies two elements of stack
 * @head:pointer to pointer to stack
 * @increament: element
 * Return: Nothing.
 */
void v_mul(stack_t **head, unsigned int increament)
{
	int mul = 0;

	if (*head && (*head)->next)
	{
		mul = ((*head)->next->n * (*head)->n);
		(*head)->next->n = mul;
		v_pop(head, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't mul, stack too short\n", increament);
	}
}
