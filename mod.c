#include "monty.h"

/**
 * mod - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int		a;

	if (stack_len(*stack) < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		mexit();
	}
	if (!((*stack)->n))
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		mexit();
	}
	a = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n %= a;
}
