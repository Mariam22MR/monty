#include "main.h"

/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_handle_error(8, len_number, "div");

	if ((*stack)->n == 0)
		more_handle_error(9, lne_number);
	(*stack) = (*stack)->next;
	i = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_handle_error(8, len_number, "mul");

	(*stack) = (*stack)->next;
	i = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_handle_error(8, len_number, "mod");


	if ((*stack)->n == 0)
		more_handle_error(9, len_number);
	(*stack) = (*stack)->next;
	i = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
