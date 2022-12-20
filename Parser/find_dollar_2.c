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
			if (mini.all_line[index - 1] == 39)
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
		if (!tmp)
			mini.parse[i] = switch_to_zero(i);
		else
			mini.parse[i] = switch_to_parse(tmp, i);
	}
}

char	**find_dollar_and_change(void)
{
	char	*tmp;
	int		i;
	int		j;
	int		c_quotes;

	i = 0;
	c_quotes = 0;
	while (mini.parse[i])
	{
		j = 0;
		while (mini.parse[i][j])
		{
			if (mini.parse[i][j] == '$')
				shorter(i, j, c_quotes, tmp);
			j++;
		}
		i++;
	}
	return (check_or_fix_switch(i));
}

void	ft_add_struct(void)
{
	int		start;
	int		i;

	i = 0;
	mini.iter = mini.first_struct;
	start = 0;
	while (mini.iter && i < mini.pipe_count + 1)
	{
		where_is_command(i, &start);
		mini.iter->string = ft_add_string(i, start);
		i++;
		mini.iter = mini.iter->next;
	}
	mini.iter = mini.first_struct;
}
