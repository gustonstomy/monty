#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char STATUS[2];
int if_stack;

stack_t *v_add_stack(stack_t **head, const int n);
stack_t *v_add_queue(stack_t **head, const int n);
int v_char_to_number(char *strn, int *number);
int _get_function_stack(char **tokens, stack_t **head, unsigned int increament);
unsigned int _isnumber(char *str);
void v_mod(stack_t **head, unsigned int increament);
void v_ts_handler(char *ptr_line);
void v_mul(stack_t **head, unsigned int increament);
void v_pstr(sstack_t **head, unsigned int increament);
char **v_strtok(char **tok, char *strn);
void v_free_stack(stack_t **head);
void v_div(stack_t **head, unsigned int increament);
void v_queue(stack_t **head, unsigned int increament);
void v_rotl(stack_t **head, unsigned int increament);
void v_rotr(stack_t **head, unsigned int increament);
void v_pall(stack_t **head, __attribute__((unused))unsigned int increament);
void v_push(stack_t **head, unsigned int increament);
void v_pint(stack_t **head, unsigned int increament);
void v_pop(stack_t **head, unsigned int increament);
void v_swap(stack_t **head, unsigned int increament);
void v_add(stack_t **head, unsigned int increament);
void v_nop(stack_t **head, unsigned int increament);
void v_pchar(stack_t **head, unsigned int increament);

#endif
