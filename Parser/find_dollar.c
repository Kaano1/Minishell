#include "../minishell.h"

int	count_null(t_shell *mini, int count_parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_parse)
	{
		if (mini->parse[i][0] == 0)
			j++;
		i++;
	}
	return (j);
}

char	**check_or_fix_switch(t_shell *mini, int count_parse)
{
	char	**mini_parse;
	int		null;
	int		i;
	int		j;

	null = count_null(mini, count_parse);
	if (null == 0)
		return (mini->parse);
	i = 0;
	j = 0;
	mini_parse = malloc(sizeof(char *) * count_parse - null + 1);
	while (i < count_parse)
	{
		if (mini->parse[i][0] != 0)
		{
			mini_parse[j] = ft_strdup(mini->parse[i]);
			j++;
		}
		i++;
	}
	mini_parse[j] = 0;
	i = -1;
	while (++i < count_parse)
		free(mini->parse[i]);
	free(mini->parse);
	return (mini_parse);
}

char	*get_env_osman(char *str, t_shell *mini)
{
	char	*string;
	int		i;
	int		j;
	int		d;
	int		longg;

	i = 0;
	string = 0;
	while (mini->env[i])
	{
		if ((ft_memcmp(mini->env[i], str, ft_strlen(str))) == 0)
		{
			if (mini->env[i][ft_strlen(str)] == '=')
			{
				d = 0;
				longg = ft_strlen(mini->env[i]) - ft_strlen(str);
				string = malloc(sizeof(char) * longg);
				j = ft_strlen(str) + 1;
				while (longg > d)
				{
					string[d] = mini->env[i][j];
					d++;
					j++;
				}
			}
		}
		i++;
	}
	if (!string)
		return (NULL);
	return (string);
}

char	*get_after_dollar_osman(char *parse, int index)
{
	char	*str;
	int		i;

	i = index;
	while (parse[i] != ' ' && parse[i] != 0)
		i++;
	if (i == index)
		return (0);
	str = malloc(sizeof(char) * (i - index) + 1);
	i = 0;
	while (parse[index] != ' ' && parse[index] != 0)
	{
		str[i] = parse[index];
		i++;
		index++;
	}
	str[i] = 0;
	return (str);
}

int	check_double_quotes(t_shell *mini, int i, int j)
{
	int	i;

	i = 0;
	while (mini->all_line[i])
	{
		if (mini->all_line[i] ==  34)
			i++;
	}
}

int	check_single_quotes(t_shell *mini, int i, int j)//continue...
{
	int	index;
	int	len;
	int	key;

	if (mini->parse[i][j] == ' ' || mini->parse[i][j] == 0)
		return (0);
	index = 0;
	len = 0;
	while (mini->all_line[index])
	{
		if (mini->all_line[index] != ' ' && key == 0)
		{
			len++;
			key = 1;
		}
		else if (mini->all_line[index] == ' ')
			key = 0;
		if (len == i)
			break;
		index++;
	}
	if (mini->all_line[index] == 39)
		return (0);
	else if (mini->all_line[index] == 34)
		return (check_double_quotes(mini, i, j));
	return (1);
}

char	**find_dollar_and_change(t_shell *mini)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	while (mini->parse[i])
	{
		j = 0;
		while (mini->parse[i][j])
		{
			if (mini->parse[i][j] == '$' && check_single_quotes(mini, i, j))
			{
				printf("%s", mini->parse[i]);
				tmp = get_env_osman(get_after_dollar_osman(mini->parse[i], j + 1), mini);
				if (!tmp)
					mini->parse[i] = switch_to_zero(i, mini);
				else
					mini->parse[i] = switch_to_parse(tmp, i, mini);
			}
			j++;
		}
		i++;
	}
	return (check_or_fix_switch(mini, i));
}