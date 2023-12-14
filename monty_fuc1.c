#include "main.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void monty_nop(stack_t **stack, unsigned int len_number)
{
	(void)stack;
	(void)len_number;
}

/**
 * swap_tow_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void swap_tow_element(stack_t **stack, unsigned int len_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_handle_error(8, len_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_tow_elements - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_handle_err(8, len_number, "add");

	(*stack) = (*stack)->next;
	i = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_tow_elements - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void sub_tow_elements(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_handle_err(8, len_number, "sub");


	(*stack) = (*stack)->next;
	i = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
