#include "monty.h"
/**
 * _rotl - it rotates stack to top.
 * @head: pointer to pointer to stack
 * @increament: element
 * Return: Nothing.
 */
void _rotl(stack_t **head, unsigned int increament)
{
	stack_t *second_node, *last_node;
	(void)increament;

	if (*head && (*head)->next)
	{
		second_node = (*head)->next, last_node = *head;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = *head;
		(*head)->prev = last_node;
		(*head)->next = NULL;
		second_node->prev = NULL;
		*head = second_node;
	}
}
