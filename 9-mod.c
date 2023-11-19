#include "monty.h"
/**
 * op_mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 *
 * Return: No return value.
 */
void op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = h->next->n % h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
