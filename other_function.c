#include "monty.h"
/**
 * free_stack - frees a stack_t structure.
 * @stack: structure.
 *
 * Return: None.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
 * fn_swap - swaps the top two elements of the stack.
 * @stack:
 * @line_number:
 *
 * Return: None.
 */
void fn_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lines);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
