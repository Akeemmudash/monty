#include "monty.h"
/**
 * op_pstr - Prints the string starting at the top of the stack,
 *            followed by a new line.
 *
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 *
 * Return: No return value.
 */
void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
