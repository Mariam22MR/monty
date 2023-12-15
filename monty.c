#include "monty.h"
stack_t *head = NULL;

/*
 * monty_main - Main function for a Monty interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * This function serves as the entry point for the Monty interpreter.
 * It checks the number of command line arguments and exits with an error
 * message if not provided correctly. Opens the specified file and performs
 * cleanup through monty_free() before returning 0.
 */

int monty_main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	monty_free();
	return (0);
}

/*
 * monty_create - Creates a new stack node with the given value.
 * @n: Integer value to be stored in the new node.
 *
 * This function dynamically allocates memory for a new stack node, initializes
 * its fields with the provided value, and returns a pointer to the created node.
 * Exits with an error message if memory allocation fails (err code 4).
 */
stack_t *monty_create(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/*
 * monty_free - Frees the memory allocated for the stack nodes.
 *
 * This function iteratively frees the memory allocated for each node in the stack.
 * It starts from the head of the stack and proceeds until the end, updating the head
 * pointer and freeing each node. If the stack is already empty (head == NULL), the
 * function returns without performing any further actions.
 */
void monty_free(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/*
 * add_to_line - Adds a new node to the end of the stack.
 * @node: Pointer to the new node to be added.
 * @l: Unused parameter (line number).
 *
 * This function adds a new node to the end of the stack. If the stack is
 * empty (head == NULL), the new node becomes the head. Otherwise, it traverses
 * the stack to find the last node and appends the new node to it.
 * Exits with EXIT_FAILURE if the node or *node is NULL.
 */
void add_to_line(stack_t **node, __attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;

}
