#include "monty.h"
/**
 * op_push - Pushes a new node onto the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 * Return: no return value.
*/
void op_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (monty_context.value)
	{
		if (monty_context.value[0] == '-')
			j++;
		for (; monty_context.value[j] != '\0'; j++)
		{
			if (monty_context.value[j] > 57 || monty_context.value[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty_context.monty_file);
			free(monty_context.line_content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty_context.monty_file);
		free(monty_context.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(monty_context.value);
	if (monty_context.stack_flag == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * op_pall - Prints all elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number (not used in this context).
 * Return: no return value.
*/
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
