#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_number: line_line_number
* @file: poiner to monty file
* @content: line content
* Return: no return value.
*/
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t instructions[] = {
				{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	monty_context.value = strtok(NULL, " \n\t");
	while (instructions[i].opcode && op)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{	instructions[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && instructions[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
