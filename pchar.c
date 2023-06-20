#include "monty.h"

/**
 * pchar - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char *n, T[2];

	if (!(*stack))
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't pchar, stack empty", 2, 1);
		free(n);
		mexit();
	}
	if ((*stack)->n < 0 || (*stack)->n > 255)
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't pchar, value out of range", 2, 1);
		free(n);
		mexit();
	}
	T[0] = (*stack)->n;
	print(T, 1, 1);
}
