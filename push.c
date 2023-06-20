#include "monty.h"

int is_num(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void push(stack_t **stack, unsigned int line_number)
{
	if (!is_num(Global.inst[1]))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		mexit();
	}
	add_node_stack(stack, _atoi(Global.inst[1]));
}
