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

char	*split_env(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

char	*get_env(char *str)
{
	size_t	len;
	char	**env;
	char	*new_str;

	env = mini.env;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while (*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			return (split_env(*env));
		}
		env++;
	}
	free(new_str);
	return (ft_calloc(sizeof(char *), 1));
}

char	*get_after_dollar(char *parse, int index)
{
	char	*str;
	int		i;

	i = index;
	while (parse[i] != ' ' && parse[i] != 0 && parse[i] != 34 && parse[i] != 39)
		i++;
	if (i == index)
		return (0);
	str = malloc(sizeof(char) * (i - index) + 1);
	i = 0;
	while (parse[index] != ' ' && parse[index] != 0 \
	&& parse[index] != 34 && parse[index] != 39)
	{
		str[i] = parse[index];
		i++;
		index++;
	}
	str[i] = 0;
	return (str);
}

