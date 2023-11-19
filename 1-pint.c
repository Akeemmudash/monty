#include "monty.h"
/**
 * op_pint - Prints the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: no return value.
*/
void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
