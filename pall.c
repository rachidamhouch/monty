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
	char	*n;

	(void)line_number;
	while (head)
	{
		n = _itoa(head->n);
		print(n, 1, 1);
		free(n);
		head = head->next;
	}
}
