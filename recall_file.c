#include "monty.h"

/**
 * monty_open - Opens and reads a Monty script file.
 * @name_file: Name of the Monty script file to be opened.
 *
 * This function opens the specified Monty script file in read-only mode.
 * Exits with an error message (case 2) if the file cannot be opened.
 * Reads the content of the file using monty_read() and then closes the file.
 */
void monty_open(char *name_file)
{
	FILE *file_desc = fopen(name_file, "r");

	if (name_file == NULL || file_desc == NULL)
		handle_error(2, name_file);

	monty_read(file_desc);
	fclose(file_desc);
}


/**
 * monty_read - Reads and processes Monty script file lines.
 * @file_desc: Pointer to the opened Monty script file.
 *
 * This function reads each line from the provided Monty script file
 * and processes the commands using monty_strtok(). It increments the
 * line number for error reporting.
 */
void monty_read(FILE *file_desc)
{
	int len_number, format = 0;
	char *buf = NULL;
	size_t l = 0;

	for (len_number = 1; getline(&buf, &l, file_desc) != -1; len_number++)
	{
		format = monty_strtok(buf, len_number, format);
	}
	free(buf);
}


/**
 * monty_strtok - Tokenizes a line from a Monty script file.
 * @buf: Line from the Monty script file to be tokenized.
 * @len_number: Line number for error reporting.
 * @format: Current format (0 for stack, 1 for queue).
 * Return: format
 *
 * This function tokenizes the provided line using space and newline characters
 * as delimiters. It extracts the opcode and value, if present, and checks for
 * special opcodes "stack" and "queue" to update the format. Calls monty_find()
 * to process the opcode and value.
 */
int monty_strtok(char *buf, int len_number, int format)
{
	char *opcode, *va;
	const char *delimeters = "\n ";

	if (buf == NULL)
		handle_error(4);

	opcode = strtok(buf, delimeters);
	if (opcode == NULL)
		return (format);
	va = strtok(NULL, delimeters);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	monty_find(opcode, va, len_number, format);
	return (format);
}

/**
 * monty_find - find the appropriate function for the opcode
 * @opcode: opcode
 * @va: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @l: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void monty_find(char *opcode, char *va, int l, int format)
{
	int i;
	int f;

	instruction_t func_list[] = {
		{"push", add_to_line},
		{"pall", monty_print_add},
		{"pint", monty_print},
		{"pop", monty_pop},
		{"nop", monty_nop},
		{"swap", swap_two_elements},
		{"add", add_two_elements},
		{"sub", sub_two_elements},
		{"div", div_two_elements},
		{"mul", mul_two_elements},
		{"mod", mod_two_elements},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			monty_call(func_list[i].f, opcode, va, l, format);
			f = 0;
		}
	}
	if (f == 1)
		handle_error(3, l, opcode);
}

/**
 * monty_call - Finds and calls the appropriate Monty instruction function.
 * @func: pointer to the function.
 * @op: Opcode to be processed.
 * @va: Optional value associated with the opcode.
 * @l: Line number for error reporting.
 * @format: Current format (0 for stack, 1 for queue).
 *
 * This function iterates through the list of supported Monty instructions
 * and calls the corresponding function based on the provided opcode. Handles
 * special cases for comments(opcode starting with '#')an unknown instructions
 */
void monty_call(op_func func, char *op, char *va, int l, int format)
{
	stack_t *node;
	stack_t *head = NULL;
	int f;
	int i;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (va != NULL && va[0] == '-')
		{
			va = va + 1;
			f = -1;
		}
		if (va == NULL)
			handle_error(5, l);
		for (i = 0; va[i] != '\0'; i++)
		{
			if (isdigit(va[i]) == 0)
				handle_error(5, l);
		}
		node = monty_create(atoi(va) * f);
		if (format == 0)
			func(&node, l);
		if (format == 1)
			add_to_line(&node, l);
	}
	else
		func(&head, l);
}
