#include "../minishell.h"

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

	if (!str)
		return (0);
	env = mini.env;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while (*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			free(str);
			return (split_env(*env));
		}
		env++;
	}
	free(new_str);
	free(str);
	return (ft_calloc(sizeof(char *), 1));
}
