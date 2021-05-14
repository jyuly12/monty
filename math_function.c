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
		free_stack(stack);
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
/**
 * fn_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		new_node = tmp->next;
		new_node->n -= tmp->n;
		free(tmp);
		*stack = new_node;
	}
}
/**
 * fn_div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		new_node = tmp->next;
		new_node->n /= tmp->n;
		free(tmp);
		*stack = new_node;
	}
}
/**
 * fn_mul -  multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		new_node = tmp->next;
		new_node->n *= tmp->n;
		free(tmp);
		*stack = new_node;
	}
}
/**
 * fn_mod - computes the rest of the division of the
 * second top two elements of the stack
 * @stack: structure.
 * @line_number: line where is the function.
 *
 * Return: None.
 */
void fn_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		new_node = tmp->next;
		new_node->n %= tmp->n;
		free(tmp);
		*stack = new_node;
	}
}
