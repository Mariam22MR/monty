#include "monty.h"


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
