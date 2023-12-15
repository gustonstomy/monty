#include "monty.h"
/**
 * add_queue - adds node to stack
 * @head: pointer to pointer in stack
 * @n: element
 * Return: Nothing
 */
stack_t *add_queue(stack_t **head, const int n)
{
	stack_t *current, *previ;

	previ = *head;

	current = malloc(sizeof(stack_t));

	if (current == NULL)
	{
		return (NULL);
	}
	current->n = n;
	current->next = NULL;
	while (previ && previ->next)
	{
		previ = previ->next;
	}
	if (previ)
	{
		previ->next = current, current->prev = previ;
	}
	else
	{
		*head = current, current->prev = NULL;
	}
	return (current);

}
