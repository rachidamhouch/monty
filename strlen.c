#include "monty.h"

/**
 *_strlen - calculate the length.
 *@s: arg 1.
 *Return:The length.
 */
size_t	_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}


/**
 * dlistint_len - function that return the number of elm.
 * @h: Arg 1.
 * Return: The number of elm.
 */
size_t stack_len(const stack_t *h)
{
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
