#include "monty.h"
#define _LIMITS_ " \t\n"
/**
 * main - principal function.
 * @ac: number of parameters.
 * @av: parameter.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	char *line = NULL, *token, *ch;
	size_t len = 0;
	FILE *files;
	int num = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	files = fopen(av[1], "r");
	if (!files)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, files) != EOF)
	{
		token = strtok(line, _LIMITS_);
		num++;
		if (strcmp(token, "push") == 0)
		{
			ch = strtok(NULL, _LIMITS_);
			fn_push(&stack, num, ch);
		}
		else
		{
			select_fn(&stack, token, num);
		}
	}
	fclose(files);
	free(line);
	free_stack(&stack);
	return (0);
}
/**
 * select_fn - select the necessary function.
 * @stack: structure.
 * @token: function to select.
 * @line_number: line where is the function.
 *
 * Return: None
 */
void select_fn(stack_t **stack, char *token, unsigned int line_number)
{
	int i;

	instruction_t fn_op[] = {
		{"pall", fn_pall},
		{"pint", fn_pint},
		{"pop", fn_pop},
		{"add", fn_add},
		{NULL, NULL}};
	for (i = 0; fn_op[i].opcode != NULL; i++)
	{
		if (strcmp(token, fn_op[i].opcode) == 0)
		{
			(fn_op[i].f)(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
