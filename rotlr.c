#include "monty.h"
/**
 * v_rotr - it rotates stack to bottom.
 * @head: pointer to pointer to stack
 * @increament:element
 * Return: Nothing.
 */
void v_rotr(stack_t **head, unsigned int increament)
{
	stack_t *last_node, *prev_last_node;
	(void)increament;

	if (*head && (*head)->next)
	{
		last_node = *head, prev_last_node = *head;
		while (prev_last_node->next->next)
			prev_last_node = prev_last_node->next;
		while (last_node->next)
			last_node = last_node->next;
		prev_last_node->next = NULL;
		last_node->prev = NULL;
		last_node->next = *head;
		(*head)->prev = last_node;
		*head = last_node;
	}
}
