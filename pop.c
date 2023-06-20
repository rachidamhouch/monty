#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)
{
	char *n;
    stack_t *tmp;

	if (!(*stack))
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": can't pop an empty stack", 2, 1);
		free(n);
		mexit();
	}
	tmp = *stack;
    (*stack) = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(tmp);
}
