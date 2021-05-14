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
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
