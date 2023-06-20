#include "monty.h"
#include "monty.h"

/**
 * swap - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int		a;

	if (stack_len(*stack) < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		mexit();
	}
	a = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = a;
}
