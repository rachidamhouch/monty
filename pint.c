#include "monty.h"
void pint(stack_t **stack, unsigned int line_number)
{
	char *n;

	if (!(*stack))
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't pint, stack empty", 2, 1);
		free(n);
		mexit();
	}
	n = _itoa((*stack)->n);
	print(n, 1, 1);
	free(n);
}
