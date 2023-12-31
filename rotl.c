#include "monty.h"

/**
 * rotl - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int n, tmp;
	stack_t *head = *stack;

	(void)line_number;
	if (!head)
		return;
	n = head->n;
	while (head->next)
		head = head->next;
	while (head)
	{
		tmp = head->n;
		head->n = n;
		n = tmp;
		head = head->prev;
	}
}
