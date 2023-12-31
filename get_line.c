#include "monty.h"

/**
 * all - ...
 * @fd: Arg 1.
 * @left: arg 2.
 * Return: ...
 */
static char	*all(int fd, char *left)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!buffer)
		return (NULL);
	while (readed && !my_strchr(left, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		left = my_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

/**
 * get_line - ...
 * @line: Arg 1.
 * Return: ...
 */
static char	*get_line(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line, i);
	if (line[i] == '\n')
	{
		ptr[i] = '\n';
		ptr[i + 1] = '\0';
	}
	else
		ptr[i] = '\0';
	return (ptr);
}

/**
 * ft_left - ...
 * @line: Arg 1.
 * Return: ...
 */
static char	*ft_left(char *line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(my_strlen(line) - i + 1);
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line + i + 1, my_strlen(line) - i);
	ptr[my_strlen(line) - i] = '\0';
	return (ptr);
}

/**
 * get_next_line - ...
 * @fd: Arg 1.
 * Return: ...
 */
char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = all(fd, left);
	next_line = get_line(line);
	left = ft_left(line);
	Global.left = left;
	free(line);
	return (next_line);
}
