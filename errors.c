#include "monty.h"

/**
 * print - Print message.
 * @str: arg 1.
 * @fd: arg 2.
 * @new: arg 3.
 * Return: the length.
 */
int print(char *str, int fd, int new)
{
	write(fd, str, strlen(str));
	if (new)
		return (write(fd, "\n", 1));
	return (1);
}
