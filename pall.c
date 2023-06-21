#include "monty.h"

/**
 * pall - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	while (head)
	{
		fprintf(stdout, "%d\n", head->n);
		head = head->next;
	}
}
