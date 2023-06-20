#include "monty.h"

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_set(int *len, int *word, int *count, int *i)
{
	*len = 0;
	*word = 1;
	*count = 0;
	*i = 0;
}

int	count_word(char *str, char *sep)
{
	int	len;
	int	word;
	int	i;
	int	count;

	ft_set(&len, &word, &count, &i);
	while (str[i])
	{
		if (is_sep(str[i], sep))
		{
			word = 1;
		}
		else
		{
			if (word == 1)
				count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_dup(char *str, char *charset, int *index)
{
	char	*ptr;
	int		len;
	int		count;
	int		in;
	int		i;

	len = 0;
	count = 0;
	i = 0;
	while (charset[len])
		len++;
	while (is_sep(str[*index], charset) && str[*index])
		(*index)++;
	in = *index;
	while (!is_sep(str[*index], charset) && str[*index])
	{
		count++;
		(*index)++;
	}
	ptr = malloc(count + 1);
	while (i < count)
		ptr[i++] = str[in++];
	ptr[i] = '\0';
	return (ptr);
}

char	**split(char *str, char *charset)
{
	char	**ptr;
	int		count;
	int		i;
	int		index;

	index = 0;
	i = 0;
	count = count_word(str, charset);
	ptr = malloc(sizeof(char *) * (count + 1));
	while (i < count)
		ptr[i++] = ft_dup(str, charset, &index);
	ptr[i] = 0;
	return (ptr);
}
