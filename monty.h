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
	void (*f)(stack_t **head, unsigned int increament);
} instruction_t;

char STATUS[2];
int if_stack;

stack_t *add_stack(stack_t **head, const int n);
stack_t *add_queue(stack_t **head, const int n);
int char_to_number(char *strn, int *number);
int get_function_stack(char **tokens, stack_t **head, unsigned int increament);
unsigned int _isnumber(char *str);
void _mod(stack_t **head, unsigned int increament);
void ts_handler(char *ptr_line);
void _mul(stack_t **head, unsigned int increament);
void _pstr(stack_t **head, unsigned int increament);
char **_strtok(char **tok, char *strn);
void free_stack(stack_t **head);
void _div(stack_t **head, unsigned int increament);
void _queue(stack_t **head, unsigned int increament);
void _rotl(stack_t **head, unsigned int increament);
void _rotr(stack_t **head, unsigned int increament);
void _pall(stack_t **head, __attribute__((unused))unsigned int increament);
void _push(stack_t **head, unsigned int increament);
void _pint(stack_t **head, unsigned int increament);
void _pop(stack_t **head, unsigned int increament);
void _swap(stack_t **head, unsigned int increament);
void _add(stack_t **head, unsigned int increament);
void _nop(stack_t **head, unsigned int increament);
void _pchar(stack_t **head, unsigned int increament);
void _sub(stack_t **head, unsigned int increament);

#endif
