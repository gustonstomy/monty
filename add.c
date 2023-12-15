#include "monty.h"
/**
 * v_add - adds element to stack
 * @head: pointer to pointer in stack
 * @increament: element to add
 * Return: Nothing
 */
void v_add(stack_t **head, unsigned int increament)
{
	int total = 0;

	if (*head && (*head)->next)
	{
		total = ((*head)->n + (*head)->next->n);
		_pop(head, 0);
		(*head)->n = total;
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't add, stack too short\n", increament);
	}
}
