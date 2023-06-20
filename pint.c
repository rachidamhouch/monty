#include "monty.h"

/**
 * pint - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		mexit();
	}
	dprintf(1, "%d\n", (*stack)->n);
}
