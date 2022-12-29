#include "../../minishell.h"

int	env_len(void)
{
	char	**env;

	env = mini.env;
	while (*env)
		env++;
	return (env - mini.env);
}
