#include "main.h"

/*
 * div_two_elements - Divides the second element by the top element in the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function divides the second element by the top element in the stack and
 * replaces them with the result. Exits with an error message (case 8) if the stack
 * is too short (less than two elements) or (case 9) if the top element is zero.
 */
void div_tow_elements(stack_t **stack, unsigned int len_number)
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

/*
 * mul_two_elements - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function multiplies the top two elements of the stack and replaces them
 * with the result. Exits with an error message (case 8) if the stack is too short
 * (less than two elements).
 */
void mul_tow_elements(stack_t **stack, unsigned int len_number)
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

/*
 * mod_two_elements - Computes the remainder of the division of the second element
 *                    by the top element in the stack.
 * @stack: Pointer to the stack to be modified.
 * @len_number: Line number for error reporting.
 *
 * This function computes the remainder of the division of the second element by
 * the top element in the stack and replaces them with the result. Exits with an
 * error message (case 8) if the stack is too short (less than two elements) or
 * (case 9) if the top element is zero.
 */
void mod_tow_elements(stack_t **stack, unsigned int len_number)
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
