#include "../minishell.h"

int	check_env(char *str)
{
	char	*head;

	head = ft_strchr(str, '=');
	if (!head)
		return (0);
	if (head == str)
		return (0);
	while (*str)
	{
		if (is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

void	add_env(char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = mini.env;
	new_env = ft_calloc(sizeof(char **), env_len() + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(mini.env);
	mini.env = new_env;
}

int	is_include(char *str)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = mini.env;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_export(char **execute)
{
	int		pos;
	char	*tmp;
	int		i;

	i = 0;
	while (execute[i])
	{
		if (check_env(execute[i]))
		{
			pos = is_include(execute[i]);
			if (pos != -1)
			{
				tmp = mini.env[pos];
				mini.env[pos] = ft_strdup(execute[i]);
				free(tmp);
			}
			else
				add_env(execute[i]);
		}
		i++;
	}
	set_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
