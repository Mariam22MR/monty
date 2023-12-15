#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void monty_open(char *file_name);
int monty_strtok(char *buffer, int line_number, int format);
void monty_read(FILE *);
int len_chars(FILE *);
void monty_find(char *, char *, int, int);

/*Stack operations*/
stack_t *monty_create(int n);
void monty_free(void);
void monty_print_add(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void add_to_line(stack_t **, unsigned int);

void monty_call(op_func, char *, char *, int, int);

void monty_print(stack_t **, unsigned int);
void monty_pop(stack_t **, unsigned int);
void monty_nop(stack_t **, unsigned int);
void swap_tow_elements(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_tow_elements(stack_t **, unsigned int);
void sub_tow_elements(stack_t **, unsigned int);
void div_tow_elements(stack_t **, unsigned int);
void mul_tow_elements(stack_t **, unsigned int);
void mod_tow_elements(stack_t **, unsigned int);

/*Error hanlding*/
void handle_error(int error_code, ...);
void more_handle_error(int error_code, ...);

#endif
