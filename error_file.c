#include "monty.h"

void handle_error(int error_code, ...)
{
	va_list argument;
	char *opcode;
	int len_number;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argument, char *));
			break;
		case 3:
			len_number = va_arg(argument, int);
			opcode = va_arg(argument, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", len_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argument, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void more_handle_error(int error_code, ...)
{
	va_list argument;
	char *opcode;
	int len_number;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argument, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argument, int));
			break;
		case 8:
			len_number = va_arg(argument, unsigned int);
			opcode = va_arg(argument, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", len_number, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argument, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
