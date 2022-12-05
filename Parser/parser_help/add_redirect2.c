#include "../../minishell.h"

char	*ft_redirect(t_shell *mini, int j, int i)
{
	if (mini->parse[j][i] == '>')
	{
		if (mini->parse[j][i + 1] == '>')
			return (strdup(">>"));
		return (strdup(">"));
	}
	else if (mini->parse[j][i] == '<')
	{
		if (mini->parse[j][i + 1] == '<')
			return (strdup("<<"));
		return (strdup("<"));
	}
	return (NULL);
}

int redirect_of_string_len(t_shell *mini, int i, int c) //ne kadar bir alan ayırmamız gerekiyor onu buluyoruz filename için.
{
	int	len;

	len = 0;
	while (mini->parse[i][c] != 0 && mini->parse[i][c] != 32 && mini->parse[i][c] != 34 && mini->parse[i][c] != 39)
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
