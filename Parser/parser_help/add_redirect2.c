#include "../../minishell.h"

char	*ft_redirect(char **parse, int j, int i)
{
	if (parse[j][i] == '>')
	{
		if (parse[j][i + 1] == '>')
			return (strdup(">>"));
		return (strdup(">"));
	}
	else if (parse[j][i] == '<')
	{
		if (parse[j][i + 1] == '<')
			return (strdup("<<"));
		return (strdup("<"));
	}
	return (NULL);
}

int redirect_of_string_len(char **parse, int i, int c) //ne kadar bir alan ayırmamız gerekiyor onu buluyoruz filename için.
{
	int	len;

	len = 0;
	while (parse[i][c] != 0 && parse[i][c] != 32)
	{
		len++;
		c++;
	}
	return (len);
}

int	ft_redirect_len(char *str)
{
	int	i;
	int	len;
	int	key;

	i = 0;
	key = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == 39 && key == 1)
			key = 0;
		else if (str[i] == 34 && key == 2)
			key = 0;
		else if (str[i] == 39)
			key = 1;
		else if (str[i] == 34)
			key = 2;
		while ((str[i] == '<' || str[i] == '>') && key == 0)
		{
			i++;
			len++;
		}
		i++;
	}
	return (len);
}
