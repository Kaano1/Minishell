#include "../../minishell.h"

int	get_string_start(char *str, int c_pipe)
{
	int	i;
	int	count;

	if (c_pipe == 0)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
		if (count == c_pipe)
			break;
	}
	return (i);
}

int	check_string(char *cod, int index)
{
	int	i;
	int	key;

	i = get_string_start(cod, index);
	key = 0;
	while (cod[i] == 32 || cod[i] == 39 || cod[i] == 34)
	{
		if (cod[i] == 39 || cod[i] == 34)
		{
			key = 1;
			i++;
			break;
		}
		i++;
	}
	if (key == 1)
	{
		while (cod[i] >= 97 && cod[i] <= 122)
			i++;
		if (cod[i] == 34 || cod[i] == 39)
			return (0);
		return (1);
	}
	return (0);
}

int where_is_command(int index, t_shell *mini)
{
    int i;

	i = 0;
	if (check_string(mini->all_line, index))
		return (-1);
	while (mini->parse[index][i] == 32 || mini->parse[index][i] == '\t')
		i++;
    return (i);
}
