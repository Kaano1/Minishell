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

void	ft_unset(void)
{
	char	*data;

	mini.iter->string++;
	while (*mini.iter->string)
	{
		data = ft_strjoin(mini.iter->string, "=");
		remove_env(data);
		free(data);
		mini.iter->string++;
	}
	set_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
