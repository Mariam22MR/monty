#include "main.h"


/**
 * add_nodes - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @i: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **node, __attribute__((unused))unsigned int i)
{
	stack_t *tmp;

	if (node == NULL || *_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	head = *node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * monty_print - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: line number of  the opcode.
 */
void monty_print(stack_t **stack, unsigned int len_number)
{
	stack_t *tmp;

	(void) len_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * monty_pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void monty_pop(stack_t **stack, unsigned int len_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_handle_error(7, len_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * monty_print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void monty_print(stack_t **stack, unsigned int len_number)
{
	if (stack == NULL || *stack == NULL)
		more_handle_error(6, len_number);
	printf("%d\n", (*stack)->n);
}
