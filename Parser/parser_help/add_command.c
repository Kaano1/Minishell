#include "../../minishell.h"

int	check_string(char *str, int i) //we can fix this code and we could do it // 0 = command or flags or string but 1 = just string
{
	int	key;

	key = 0;
	while (str[i] == 34 || str[i] == 39)
	{
		key = 1;
		i++;
	}
	while (str[i] != 32 && str[i] != 0 && str[i] != 34 && str[i] != 39)
		i++;
	if (key == 1 && str[i] != 39 && str[i] != 34)
		return (0);
	return (1);
}

int	ft_word_count(char *str)
{
	int	i;
	int	key;
	int	len;

	len = 0;
	key = 0;
	i = 0;
	while (str[i])
	{
		if (key == 0 && str[i] != ' ')
		{
			key = 1;
			len++;
		}
		else if (key == 1 && str[i] == 32)
			key = 0;
		i++;
	}
	return (len);
}

void	where_is_command(int index, int *catch)
{
    int i;
	int	j;
	int	start;
	int	word;

	i = 1;
	start = where_is_start(i, mini.parse[index]);
	if (start == -1 || !check_string(mini.parse[index], start))
	{
		mini.iter->command[0] = 0;
		return ;
	}
	start = 0;
	mini.iter->command = ft_calloc(sizeof(char *), len_word(mini.parse[index], ' ') + 1);
	mini.iter->command[0] = ft_add(start, index, mini.parse, 1);
	word = ft_word_count(mini.parse[index]);
	i++;
	while (word != 1)
	{
		start = where_is_start(i, mini.parse[index]);
		j = start;
		while (mini.parse[index][j] == 34 || mini.parse[index][j] == 39)
			j++;
		if (mini.parse[index][j] == '-' && check_string(mini.parse[index], start))
			mini.iter->command[i - 1] = ft_add(start, index, mini.parse, 1);
		else
			break;
		i++;
	}
	if (word == 1)
		mini.iter->command[0] = ft_add(0, index, mini.parse, 1);
	*catch = i;
}
