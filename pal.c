#include "monty.h"
/**
 * v_pall - to print all elements in a stack
 * @head: pointer to pointer to stack
 * @increament: value to print
 * Return: Nothing
 */
void v_pall(stack_t **head, __attribute__((unused))unsigned int increament)
{
	stack_t *aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}

}
