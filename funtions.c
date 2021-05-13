#include "monty.h"
/**
 * fn_push - add new node in the stack.
 * @stack: structure
 * @line_number: line where is the function.
 * @n: integer.
 *
 * Return: None.
 */
void fn_push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new_node = NULL;

	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(n);
	new_node->next = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
* fn_pall - prints all the values on the stack, starting from the top.
* @stack: structure
* @line_number: line where is the function.
*
* Return: None.
*/
void fn_pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *temp = *stack;

	(void)line_number;
	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		i++;
	}
}
/**
* fn_pint -  prints the value at the top of the stack, followed by a new line.
* @stack: structure
* @line_number: line where is the function.
*
* Return: None.
*/

void fn_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
