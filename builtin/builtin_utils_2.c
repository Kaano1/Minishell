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

/*void	set_paths(void)
{
	char	*paths;

	if (mini.path)
		free_array(mini.path);
	paths = get_env("PATH");
	if (!(*paths))
		mini.path = NULL;
	else
		mini.path = ft_mysplit(paths, ':', 1);
	free(paths);
}*/


int	env_len(void)
{
	char	**env;

	env = mini.env;
	while (*env)
		env++;
	return (env - mini.env);
}