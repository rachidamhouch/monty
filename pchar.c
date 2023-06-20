#include "monty.h"

/**
 * pchar - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		mexit();
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		mexit();
	}
	dprintf(1, "%c\n", (*stack)->n);
}
