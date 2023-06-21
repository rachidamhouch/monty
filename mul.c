#include "monty.h"

/**
 * mul - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int		a;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		mexit();
	}
	a = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= a;
}
