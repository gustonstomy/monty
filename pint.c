#include "monty.h"
/**
 * _pint - to print the first element of a stack
 * @head: pointer to pointer to stack
 * @increament: value to print
 * Return: Nothing
 */
void _pint(stack_t **head, unsigned int increament)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		STATUS[0] = 'F',
			printf("L%d: can't pint, stack empty\n", increament);
	}
}
