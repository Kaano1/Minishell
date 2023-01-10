#include "../minishell.h"

int	check_single_quotes(int i, int j, int c_quotes)
{
	int	index;
	int	len;

	if (mini.parse[i][j] == ' ' || mini.parse[i][j] == 0)
		return (0);
	index = 0;
	len = 0;
	while (mini.all_line[index])
	{
		if (mini.all_line[index] == DOLLAR_C)
			len++;
		if (len == c_quotes)
			if (index != 0 && mini.all_line[index - 1] == SIGNEL_Q)
				return (0);
		index++;
	}
	return (1);
}

void	shorter(int i, int j, int c_quotes, char *tmp)
{
	if (check_single_quotes(i, j + 1, ++c_quotes))
	{
		tmp = get_env(get_after_dollar(mini.parse[i], j + 1));
		if (mini.parse[i][j + 1] == '?')
		{
			free(tmp);
			tmp = ft_itoa(mini.err);
			mini.parse[i] = switch_to_parse(tmp, i);
		}
		else if (!tmp)
			mini.parse[i] = switch_to_zero(i);
		else
			mini.parse[i] = switch_to_parse(tmp, i);
		free(tmp);
	}
}

char	**find_dollar_and_change(void)
{
	char	*parse;
	int		i;
	int		j;
	char	*tmp;
	int		c_quotes;

	i = 0;
	c_quotes = 0;
	while (mini.parse[i] != 0)
	{
		j = 0;
		parse = mini.parse[i];
		while (parse[j] != 0)
		{
			if (parse[j] == DOLLAR_C && valid_op(parse, j))
			{
				shorter(i, j, c_quotes, tmp);
				break;
			}
			j++;
			if (j > ft_strlen(parse))
				break;
		}
		i++;
	}
	return (check_or_fix_switch(i));
}
