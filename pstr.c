#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	char	T[1];

	(void)line_number;
	while (head)
	{
		T[0] = head->n;
		print(T, 1, 0);
		head = head->next;
	}
	write(1, "\n", 1);
}
