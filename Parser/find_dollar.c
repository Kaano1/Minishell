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
			if (mini->parse[i][j] == '$' && mini->parse[i][j + 1] != ' ' && mini->parse[i][j + 1] != 0)
			{
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