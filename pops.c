#include "monty.h"
/**
 * v_pop - to delete the first element
 * @head: pointer to  pointer to the stack
 * @increament: value value to print
 * Return: Nothing.
 */
void v_pop(stack_t **head, unsigned int increament)
{
	stack_t *temp;

	if (!*head)
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't pop an empty stack\n", increament);
		return;
	}
	temp = (*head)->next;
	free(*head);
	*head = temp;

	if (temp)
	{
		temp->next = NULL;
	}
}
