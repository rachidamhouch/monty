#include "monty.h"
global_t Global;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init(av[1]);
	exic();
	return (0);
}
