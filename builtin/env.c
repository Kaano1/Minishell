#include "../minishell.h"

void	ft_env(void)
{
	char	**env;

	env = mini.env;
	while (*env)
	{
		put_strnl_fd(1, *env);
		env++;
	}
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
