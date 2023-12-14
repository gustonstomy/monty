#include "monty.h"
/**
 * v_swap - it pops an element in a stack
 * @head: a pointer to a pointer of stack
 * @increament: element to pop
 * Return: Nothing
 */
void v_swap(stack_t **head, unsigned int increament)
{
	stack_t *el_swap = NULL;

	if (*head)
	{
		if ((*head)->next)
		{
			el_swap = *head;
			*head = (*head)->next;
			el_swap->prev = *head, el_swap->next = (*head)->next;
			(*head)->prev = NULL, (*head)->next = el_swap;
		}
		else
		{
			STATUS[0] = 'F';
			dprintf(2, "L%d: can't swap, stack too short\n", increament);
		}
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't swap, stack too short\n", increament);
	}
}
