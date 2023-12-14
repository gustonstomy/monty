#include "monty.h"
/**
 * v_push - to push into the stack
 * @head: pointer to pointer to stack
 * @increament: value to include
 * Return: Nothing
 */
void v_push(stack_t **head, unsigned int increament)
{
	if (if_stack)
		v_add_stack(head, increament);
	else
		v_add_queue(head, increament);
}

