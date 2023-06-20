#include "monty.h"
global_t Global;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	init(av[1]);
	exic();
	return (0);
}
