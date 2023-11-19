#include "monty.h"
/**
 * op_pop - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: No return value.
 */
void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
