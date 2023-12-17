#include "monty.h"
stack_t *head = NULL;

/**
 * monty_main - Main function for a Monty interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 */
int monty_main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_open(argv[1]);
	monty_free();
	return (0);
}
/**
 * monty_create - Creates a new stack node with the given value.
 * @n: Integer value to be stored in the new node.
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

/**
 * monty_free - Frees the memory allocated for the stack nodes.
 * description: This function iteratively frees the memory allocated for each
 *	node.
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

/**
 * add_to_line - Adds a new node to the end of the stack.
 * @node: Pointer to the new node to be added.
 * @l: Unused parameter (line number).
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
