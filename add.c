#include "monty.h"

/**
 * add - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void add(stack_t **stack, unsigned int line_number)
{
	int		a;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		mexit();
	}
	a = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += a;
}
