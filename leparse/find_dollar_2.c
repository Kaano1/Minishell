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
		if (mini.all_line[index] == '$')
			len++;
		if (len == c_quotes)
			if (mini.all_line[index - 1] == SIGNEL_Q)
				return (0);
		index++;
	}
	return (1);
}

void	shorter(int i, int j, int c_quotes, char *tmp) //echo $HOME
{
	if (check_single_quotes(i, j + 1, ++c_quotes))
	{
		tmp = get_env(get_after_dollar(mini.parse[i], j + 1));
		if (!tmp)
			mini.parse[i] = switch_to_zero(i);
		else
			mini.parse[i] = switch_to_parse(tmp, i);
	}
}

char	**find_dollar_and_change(void)
{
	int		i;
	int		j;
	char	*tmp;
	int		c_quotes;
	int		type;

	i = 0;
	c_quotes = 0;
	while (mini.parse[i])
	{
		j = 0;
		type = -1;
		while (mini.parse[i][j])
		{
			if ((mini.parse[i][j] == DOUBLE_Q || mini.parse[i][j] == SIGNEL_Q) && type == -1)
				type = mini.parse[i][j];
			if (mini.parse[i][j] == '$' && mini.parse[i][j + 1] != DOUBLE_Q && mini.parse[i][j + 1] != SIGNEL_Q)
				shorter(i, j, c_quotes, tmp);
			else if (mini.parse[i][j] == '$' && type == -1 && (mini.parse[i][j + 1] == DOUBLE_Q || mini.parse[i][j + 1] == SIGNEL_Q))
				mini.parse[i][j] = SPACE;
			j++;
			if (mini.parse[i][j] == type)
				type = -1;
		}
		i++;
	}
	return (check_or_fix_switch(i));
}
