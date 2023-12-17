#include "monty.h"

/**
 * monty_pchar - Prints the ASCII character of the top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @len_number: Line number in the Monty byte code file where the
 *		instruction appears.
 */
void monty_pchar(stack_t **stack, unsigned int len_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		handle_str_error(11, len_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		handle_str_error(10, len_number);
	printf("%c\n", ascii);
}

/**
 * monty_pstr - Prints the string starting at the top of the stack
 * @stack: A pointer to the top of the stack
 * @l: Line number (unused in this function)
 */
void monty_pstr(stack_t **stack, __attribute__((unused))unsigned int l)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
