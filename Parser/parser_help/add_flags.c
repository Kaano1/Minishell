#include "../../minishell.h"

int		flags_check(int	i, t_shell *mini)
{
	int	j;

	j = 0;

	if (mini->check_parser[i] == 0)
		return (0);
	while (mini->check_parser[i][j] == 34)
		j++;
	if (j != 0 && mini->check_parser[i][j] == '-')
	{
		while (mini->check_parser[i][j] != ' ' && mini->check_parser[i][j] != '\t' && mini->check_parser[i][j] != 0)
			j++;
		if (mini->check_parser[i][j] == 0)
			return (1);
	}
	else if (j == 0 && mini->check_parser[i][0] == '-')
		return (1);
	return (0);
}

char	*double_flags_add(t_shell *mini, int index)
{
	char	*str;
	int	i;
	int	tmp_i;
	int	j;

	i = 0;
	j = 0;
	while (mini->check_parser[index][i] == 34)
		i++;
	tmp_i = i;
	while (mini->check_parser[index][tmp_i] != 0 && mini->check_parser[index][tmp_i] != 34)
		tmp_i++;
	str = malloc(sizeof(char) * (tmp_i - i) + 1);
	while (mini->check_parser[index][i] != 0 && mini->check_parser[index][i] != 34)
	{
		str[j] = mini->check_parser[index][i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

int	where_start_to_checkparser(t_shell *mini, int index)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (len != index && mini->check_parser[i] != 0)
	{
		if (mini->check_parser[i][0] == '|')
			len++;
		i++;
	}
	return (i);
}

char	**ft_flags_add(t_shell *mini, int index)
{
	char	**str;
	int	tmp_i;
	int	j;
	int	i;

	i = where_start_to_checkparser(mini, index);
	j = 0;
	if (mini->check_parser[i] == 0)
		return (0);
	i++;
	tmp_i = i;
	while (flags_check(i, mini))
		i++;
	str = malloc(sizeof(char *) * (i - tmp_i) + 1);
	i = tmp_i;
	while (flags_check(i, mini))
	{
		str[j] = double_flags_add(mini, i);
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}
