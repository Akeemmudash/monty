#include "monty.h"
/**
 * op_pchar - Prints the ASCII character value at the top of the stack,
 *             followed by a new line.
 *
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 *
 * Return: No return value.
 */

void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
