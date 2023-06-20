#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	char	*n;
	int		a;

	if (stack_len(*stack) < 2)
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't sub, stack to short", 2, 1);
		free(n);
		mexit();
	}
	a = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= a;
}
