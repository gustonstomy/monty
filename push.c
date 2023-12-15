#include "monty.h"
/**
 * _push - to push into the stack
 * @head: pointer to pointer to stack
 * @increament: value to include
 * Return: Nothing
 */
void _push(stack_t **head, unsigned int increament)
{
	if (if_stack)
		add_stack(head, increament);
	else
		add_queue(head, increament);
}

