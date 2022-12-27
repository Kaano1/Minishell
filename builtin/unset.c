#include "../minishell.h"

void	remove_env(char *data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (mini.env[i])
	{
		if (ft_strncmp(mini.env[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(mini.env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_array(mini.env);
	mini.env = new_env;
}

void	ft_unset(char **execute)
{
	int		j;
	char	*data;

	j = 1;
	while (execute[j])
	{
		data = ft_strjoin(execute[j], "=");
		remove_env(data);
		free(data);
		j++;
	}
	set_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
