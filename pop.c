#include "monty.h"

/**
 * pop - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		mexit();
	}
	tmp = *stack;
	(*stack) = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}
