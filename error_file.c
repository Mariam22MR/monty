#include "monty.h"
/*
 * handle_error - Function to handle and report errors in a Monty interpreter
 * @error_code: Integer representing the specific error code
 * @...: Variable arguments depending on the error_code
 *
 * This function takes an error code and variable arguments to handle and report
 * errors that may occur during the execution of a Monty interpreter. It utilizes
 * variable arguments to provide additional information based on the error type.
 *
 * Error Codes:
 *   1 - Missing command line argument (USAGE: monty file)
 *   2 - Unable to open the specified file
 *   3 - Unknown instruction encountered
 *   4 - Memory allocation (malloc) failure
 *   5 - Invalid usage of the "push" instruction (L%d: usage: push integer)
 *
 * Additional Information:
 *   - For error_code 2, the corresponding filename is passed as a variable argument.
 *   - For error_code 3, the line number and opcode are passed as variable arguments.
 *   - For error_code 5, the line number is passed as a variable argument.
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
	free_nodes();
	exit(EXIT_FAILURE);
}

/*
 * more_handle_error - Handles and reports additional errors in a Monty interpreter.
 * @error_code: Integer error code representing the type of error.
 * @...: Variable arguments providing context based on the error code.
 *
 * This function extends error handling for specific cases in a Monty interpreter.
 * Prints error messages based on the error code and additional context provided
 * as variable arguments. Calls free_nodes() to free memory and exits with EXIT_FAILURE.
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
	free_nodes();
	exit(EXIT_FAILURE);
}
