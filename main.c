#include "monty.h"
global_t Global;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		print("USAGE: monty file", 2, 1);
		exit(EXIT_FAILURE);
	}
	init(av[1]);
	exic();
	return (0);
}
