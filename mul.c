#include "monty.h"

/**
 * mul - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void mul(stack_t **stack, unsigned int line_number)
{
	char	*n;
	int		a;

	if (stack_len(*stack) < 2)
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't mul, stack to short", 2, 1);
		free(n);
		mexit();
	}
	a = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= a;
}
