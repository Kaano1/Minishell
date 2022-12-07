#include "../minishell.h"

int	where_is_start(int count_word, char *str) //kaçıncı kelimeye gitmek istediğimizi söyleyelim bizi oraya götürsün
{
	int	i;
	int	key;
	int	len;

	i = 0;
	key = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != 32 && key == 0)
		{
			key = 1;
			len++;
		}
		else if (key == 1 && str[i] == 32)
			key = 0;
		if (len == count_word)
			break;
		i++;
	}
	return (i);
}

char	*ft_add(int row, int column, t_shell *mini) //ekleme işlemi yapıyor verdiğimiz başlangıç adresinden ilerliyip bunu yapıyor.
{
	int	i;
	char *str;

	i = row;
	str = 0;
	if (row == -1)
		return (NULL);
	while (mini->parse[column][i] != ' ' && mini->parse[column][i])
		i++;
	str = malloc(sizeof(char) *  (i - row + 1));
	if (!str)
		exit (-1);
	i = 0;
	while (mini->parse[column][row] && mini->parse[column][row] != ' ')
	{
		str[i] = mini->parse[column][row];
		row++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_add_string(t_shell *mini, int index, int start) //ahmet -d < "ceren" < noli naber | ceren < naptin
{
	char	**str;
	char	*result;
	int	j;
	int	i;

	str = ft_calloc(sizeof(char *), (len_word(mini->parse[index], 32) - start) + 1);
	j = 0;
	i = 0;
	while (start <= len_word(mini->parse[index], 32))
	{
		i = where_is_start(start, mini->parse[index]);
		str[j] = ft_add(i, index, mini);
		start++;
		j++;
	}
	result = ft_join_arg(str);
	return (result);
}

void	ft_add_struct(t_shell *mini)
{
	int	start;

	mini->path = ft_mysplit(get_env("PATH", mini), ':', 1);
	int i = 0;
		while(mini->path[i])
		{
			printf("%s:", mini->path[i]);
			i++;
		}
	exit (0);
	while (i < mini->pipe_count + 1)
	{write(1, "0k1\n", 4);
		mini->first_struct->command = where_is_command(i, mini, &start);
		write(1, "02\n", 4);
		mini->first_struct->string = ft_add_string(mini, i, start);
		mini->path = ft_mysplit(get_env("PATH", mini), ':', 1);
		i++;
	}
}
