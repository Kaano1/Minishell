#include "../minishell.h"

char	**set_env(char **env)
{
	size_t	i;
	size_t	len;
	char	**head;
	char	**mini;

	head = env;
	while (*head)
		head++;
	len = head - env;
	mini = ft_calloc(sizeof(char **), len + 1);
	i = -1;
	while (++i < len)
		mini[i] = ft_strdup(env[i]);
	return (mini);
}
