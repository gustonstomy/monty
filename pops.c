#include "monty.h"
/**
 * _pop - to delete the first element
 * @head: pointer to  pointer to the stack
 * @increament: value value to print
 * Return: Nothing.
 */
void _pop(stack_t **head, unsigned int increament)
{
	stack_t *temp;

	if (!*head)
	{
		STATUS[0] = 'F';
		printf("L%d: can't pop an empty stack\n", increament);
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
