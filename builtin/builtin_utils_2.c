#include "../minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	env_len(void)
{
	char	**env;

	env = mini.env;
	while (*env)
		env++;
	return (env - mini.env);
}

int	is_parent(void)
{
	return (mini.parent_pid == getpid());
}
