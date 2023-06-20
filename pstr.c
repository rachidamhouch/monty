#include "monty.h"

/**
 * pstr - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	while (head && head->n > 0 && head->n < 128)
	{
		dprintf(1, "%c", head->n);
		head = head->next;
	}
	dprintf(1, "\n");
}
