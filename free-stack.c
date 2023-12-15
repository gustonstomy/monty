#include "monty.h"

/**
 * free_stack - free stack.
 * @head: pointer
 * Return: Nothing.
 */
void free_stack(stack_t **head)
{
	stack_t *previ = NULL;

	while (*head)
	{
		previ = *head;
		*head = (*head)->next;
		free(previ);
	}
}
