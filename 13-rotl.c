#include "monty.h"
/**
 * op_rotl - Rotates the stack to the top.
 *
 * @head: Pointer to the head of the stack.
 * @line_number: Line number where the operation occurs.
 *
 * Return: No return value.
 */

void op_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *result;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	result = (*head)->next;
	result->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = result;
}
