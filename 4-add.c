#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: no return value.
*/
void op_add(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = h->n + h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
