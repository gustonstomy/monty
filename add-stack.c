#include "monty.h"
/**
 * add_stack - adds new node to stack
 * @head: pointer to pointer in stack
 * @n: element
 * Return: Nothing
 */
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *current, *previ;

	previ = *head;
	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		return (NULL);
	}
	current->n = n;
	current->prev = NULL;
	if (!previ)
	{
		current->next = NULL;
	}
	else
	{
		while (previ->prev)
		{
			previ = previ->prev;
		}
		previ->prev = current;
		current->next = previ;

	}
	*head = current;
	return (*head);
}
