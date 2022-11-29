#include "../minishell.h"

int count_word(char *str)
{
	int i;
	int key;
	int word;

	i = 0;
	word = 0;
	key = 1;
	while (str[i])
	{
		if (str[i] == 39)
		{
			while (str[i] != 39 && str[i] != 0)
				i++;
			word++;
		}
		else if (str[i] == 34)
		{
			while (str[i] != 34 && str[i] != 0)
				i++;
			word++;
		}
		if (str[i] == ' ' && key)
		{
			word++;
			key = 0;
		}
	}
	return (0);
}

size_t	if_word_len(char const *s, char c, int key)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		if (s[len] == 34)
		{
			len++;
			while (s[len] != 34 && s[len] != 0)
				len++;
		}
		else if (s[len] == 39)
		{
			len++;
			while (s[len] != 39 && s[len] != 0)
				len++;
		}
		else
			len++;
	}
	return (len);
}

size_t	len_word(char const *s, char c, int key2)
{
	size_t	len;
	int		key;

	len = 0;
	key = 0;
	while (*s != '\0')
	{
		if (*s == 34 || *s == 39)
			key += 1;
		if (*s != c && (s[1] == '\0' || s[1] == c) && key % 2 == 0)
			len++;
		s++;
	}
	return (len);
}

void	mysplit_section(char ***res, char **s, int index, size_t *two_index, int key)
{
	int	i;

	i = *two_index;
	if (key == 1)
		res[0][index][i++] = *s[0];
	if (*s[0] == 34)
	{
		*s[0]++;
		while (*s[0] != 34 && *s[0] != 0)
			res[0][index][i++] = *s[0]++;
	}
	else if (*s[0] == 39)
	{
		*s[0]++;
		while (*s[0] != 39 && *s[0] != 0)
			res[0][index][i++] = *s[0]++;
	}
	if (key == 1)
		res[0][index][i++] = *s[0];
	*s[0]++;
	*two_index = i;
}

char	**ft_mysplit(char *s, char c, int key)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	if (!s)
		return (0);
	word_len = len_word(s, c, key);
	res = (char **)malloc(sizeof(char *) * word_len + 1);
	if (res == 0)
		return (0);
	index = 0;
	while (index < word_len)
	{
		while (*s == c && *s != '\0')
			if (*s == 34 && key == 0)
			{
				s++;
				while (*s != 34 && *s != 0)
					s++;
			}
			else if (*s == 39 && key == 0)
			{
				s++;
				while (*s != 39 && *s != 0)
					s++;
			}
			else
				s++;
		res[index] = (char *)malloc(sizeof(char) * if_word_len(s, c, key) + 1);
		two_index = 0;
		while (*s != c && *s != '\0')
			if (*s == 34 || *s == 39)
				mysplit_section(&res, &s, index, &two_index, key);
			else
				res[index][two_index++] = *s++;
		res[index][two_index] = '\0';
		index++;
	}
	res[index] = 0;
	return (res);
}
