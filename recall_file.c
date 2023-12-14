#include "main.h"

/**
 * monty_open - opens a file
 * @fn: the file namepath
 * Return: void
 */

void monty_open(char *fn)
{
	FILE *fd = fopen(fn, "r");

	if (fn == NULL || fd == NULL)
		handle_error(2, fn);

	monty_read(fd);
	fclose(fd);
}


/**
 * monty_read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void monty_read(FILE *fd)
{
	int len_number, format = 0;
	char *buf = NULL;
	size_t l = 0;

	for (len_number = 1; getline(&buf, &l, fd) != -1; len_number++)
	{
		format = monty_strtok(buf, len_number, format);
	}
	free(buf);
}


/**
 * monty_strtok - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int monty_strtok(char *buf, int len_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
		handle_error(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	monty_find(opcode, value, len_number, format);
	return (format);
}

/**
 * monty_find - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void monty_find(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_line},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_elements},
		{"mul", mul_tow_elements},
		{"mod", mod_tow_elements},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			monty_call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, ln, opcode);
}


/**
 * monty_call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void monty_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handle_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handle_error(5, ln);
		}
		node = monty_create(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_line(&node, ln);
	}
	else
		func(&head, ln);
}
