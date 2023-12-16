#include "monty.h"

/*
 * monty_nop - Does nothing.
 * @stack: Unused parameter (pointer to the stack).
 * @len_number: Unused parameter (line number).
 *
 * This function does nothing and serves as a placeholder for the "nop" opcode.
 * It takes no action and is used to maintain proper opcode handling.
 */
void monty_nop(stack_t **stack, unsigned int len_number)
{
	(void)stack;
	(void)len_number;
}

/*
 * swap_two_element - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function swaps the top two elements of the stack. Exits with an error
 * message (case 8) if the stack is too short (less than two elements).
 */
void swap_tow_elements(stack_t **stack, unsigned int len_number)
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

/*
 * add_two_elements - Adds the top two elements of the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function adds the top two elements of the stack and replaces them with
 * the result. Exits with an error message (case 8) if the stack is too short
 * (less than two elements).
 */
void add_tow_elements(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_handle_error(8, len_number, "add");

	(*stack) = (*stack)->next;
	i = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/*
 * sub_two_elements - Subtracts the top element from the second element in the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function subtracts the top element from the second element in the stack and
 * replaces them with the result. Exits with an error message (case 8) if the stack
 * is too short (less than two elements).
 */
void sub_tow_elements(stack_t **stack, unsigned int len_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_handle_error(8, len_number, "sub");

	(*stack) = (*stack)->next;
	i = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = i;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
