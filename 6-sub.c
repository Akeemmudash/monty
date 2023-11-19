#include "monty.h"
/**
 * op_sub - Subtracts the top element of the
 * stack from the second top element.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: No return value.
 */

void op_sub(stack_t **head, unsigned int line_number)
{
	stack_t *result;
	int sus, nodes;

	result = *head;
	for (nodes = 0; result != NULL; nodes++)
		result = result->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = *head;
	sus = result->next->n - result->n;
	result->next->n = sus;
	*head = result->next;
	free(result);
}
