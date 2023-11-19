#include "monty.h"



/**
 * op_stack - Prints the elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: No return value.
 */
void op_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	monty_context.stack_flag = 0;
}





/**
 * op_queue - Switches the stack to queue mode.
 *
 * @head: Pointer to the head of the queue.
 * @line_number: Line number where the operation occurs.
 * Return: No return value.
 */

void op_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	monty_context.stack_flag = 1;
}



/**
 * addqueue - Adds a node to the tail of the queue.
 *
 * @n: New value for the node.
 * @head: Pointer to the head of the queue.
 * Return: No return value.
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *result;

	result = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (result)
	{
		while (result->next)
			result = result->next;
	}
	if (!result)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		result->next = new_node;
		new_node->prev = result;
	}
}
