#include "../minishell.h"

int	count_null(char **parse, int count_parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_parse)
	{
		if (parse[i][0] == 0)
			j++;
		i++;
	}
	return (j);
}

char	**check_or_fix_switch(int count_parse)
{
	char	**mini_parse;
	int		null;
	int		i;
	int		j;

	null = count_null(mini.parse, count_parse);
	if (null == 0)
		return (mini.parse);
	i = 0;
	j = 0;
	mini_parse = malloc(sizeof(char *) * count_parse - null + 1);
	while (i < count_parse)
	{
		if (mini.parse[i][0] != 0)
			mini_parse[j++] = ft_strdup(mini.parse[i]);
		i++;
	}
	mini_parse[j] = 0;
	i = -1;
	while (++i < count_parse)
		free(mini.parse[i]);
	free(mini.parse);
	return (mini_parse);
}

char	*get_after_dollar(char *parse, int index)
{
	char	*str;
	int		i;

	i = index;
	while ((parse[i] != ' ' && parse[i] != 0) \
		&& (parse[i] != DOUBLE_Q && parse[i] != SIGNEL_Q))
		i++;
	if (i == index)
		return (0);
	str = malloc(sizeof(char) * (i - index) + 1);
	i = 0;
	while (parse[index] != ' ' && parse[index] != 0 \
	&& parse[index] != DOUBLE_Q && parse[index] != SIGNEL_Q)
	{
		str[i] = parse[index];
		i++;
		index++;
	}
	str[i] = 0;
	return (str);
}

