#include "monty.h"

int is_num(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
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
	char *n;

	if (!is_num(Global.inst[1]) || Global.inst[2])
	{
		n = _itoa(line_number);
		print("L", 2, 0);
		print(n, 2, 0);
		print(": usage: push integer", 2, 1);
		free(n);
		mexit();
	}
	add_node_stack(stack, _atoi(Global.inst[1]));
}
