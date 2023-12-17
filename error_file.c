#include "monty.h"

/**
 * handle_error - Function to handle and report errors in a Monty interpreter
 * @error_code: Integer representing the specific error code
 * @...: Variable arguments depending on the error_code
 *   1 - Missing command line argument (USAGE: monty file)
 *   2 - Unable to open the specified file
 *   3 - Unknown instruction encountered
 *   4 - Memory allocation (malloc) failure
 *   5 - Invalid usage of the "push" instruction (L%d: usage: push integer)
 */
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
	monty_free();
	exit(EXIT_FAILURE);
}
/**
 * more_handle_error - Handles and reports additional errors in a Monty.
 * @error_code: Integer error code representing the type of error.
 * @...: Variable arguments providing context based on the error code.
 */
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
	monty_free();
	exit(EXIT_FAILURE);
}

void handle_str_error(int error_code, ...)
{
	va_list argument;
	int len_numbers;

	va_start(argument, error_code);
	len_numbers = va_arg(argument, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", len_numbers);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", len_numbers);
			break;
		default:
			break;
	}
	monty_free();
	exit(EXIT_FAILURE);
}
