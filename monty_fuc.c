#include "monty.h"


/*
 * add_nodes - Adds a new node at the beginning of the stack.
 * @node: Pointer to the new node to be added.
 * @l: Unused parameter (line number).
 *
 * This function adds a new node at the beginning of the stack. If the stack is
 * empty (head == NULL), the new node becomes the head. Otherwise, it updates
 * the head pointer, setting it to the new node, and adjusts the next and prev
 * pointers accordingly.
 * Exits with EXIT_FAILURE if the node or *node is NULL.
 */
void add_nodes(stack_t **node, __attribute__((unused))unsigned int l)
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


/*
 * monty_print_add - Prints the elements of the stack.
 * @stack: Pointer to the stack to be printed.
 * @len_number: Unused parameter (line number).
 *
 * This function prints the elements of the stack starting from the top.
 * Exits with EXIT_FAILURE if the stack is NULL.
 */
void monty_print_add(stack_t **stack, unsigned int len_number)
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

/*
 * monty_pop - Removes the top element from the stack.
 * @stack: Pointer to the stack from which to pop.
 * @len_number: Line number for error reporting.
 *
 * This function removes the top element from the stack. Exits with an error
 * message (case 7) if the stack is empty. Adjusts pointers accordingly and
 * frees the memory of the removed node.
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

/*
 * monty_print - Prints the top element of the stack.
 * @stack: Pointer to the stack to be printed.
 * @len_number: Line number for error reporting.
 *
 * This function prints the top element of the stack. Exits with an error
 * message (case 6) if the stack is empty.
 */
void monty_print(stack_t **stack, unsigned int len_number)
{
	if (stack == NULL || *stack == NULL)
		more_handle_error(6, len_number);
	printf("%d\n", (*stack)->n);
}
