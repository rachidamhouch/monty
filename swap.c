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
	char	*n;
	int		a;

	if (stack_len(*stack) < 2)
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't swap, stack to short", 2, 1);
		free(n);
		mexit();
	}
	a = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = a;
}
