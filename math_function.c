#include "monty.h"
/**
 * fn_add - adds the top two elements of the stack.
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		new_node = tmp->next;
		new_node->n += tmp->n;
		free(tmp);
		*stack = new_node;
	}
}
