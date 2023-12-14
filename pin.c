#include "monty.h"
/**
 * v_pint - to print the first element of a stack
 * @head: pointer to pointer to stack
 * @increament: value to print
 * Return: Nothing
 */
void v_pint(stack_t **head, unsigned int increament)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		STATUS[0] = 'F',
			dprintf(2, "L%d: can't pint, stack empty\n", increament);
	}
}
