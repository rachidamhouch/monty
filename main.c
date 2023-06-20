#include "monty.h"
global_t Global;

/**
 * main - ...
 * @ac: Arg 1.
 * @av: arg 2.
 * Return: ...
 */
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
